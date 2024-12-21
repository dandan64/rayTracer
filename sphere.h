#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "ray.h"
#include "rtweekend.h"

class sphere : public hittable{
public:
    sphere(const point3& center, double radius) : center(center), radius(radius){}

    bool hit(const ray& r, intreval ray_t, hit_record& rec) const override{
        vec3 oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius*radius;
        auto discriminant = h*h - a*c;

        if(discriminant < 0){
            return false;
        }
        auto sqrtd = std::sqrt(discriminant);
        // Find the nearest root that lies in the acceptable range.
        auto root = (h - sqrtd) / a;
        if(!ray_t.surrounds(root)) {
            root = (h + sqrtd) / a;
            if (!ray_t.surrounds(root)) {
                return false;
            }
        }
        rec.t = root;
        rec.p = r.at(rec.t);
//            rec.normal = (rec.p - center) / radius;
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_front_face(r, outward_normal);
        return true;
    }





private:
    point3 center;
    double radius;
};




#endif //SPHERE_H