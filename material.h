#ifndef MATERIAL_H
#define MATERIAL_H

#include "hittable.h"

class matetial{
public:
    virtual ~matetial() = default;

    virtual  bool scatter(const ray& r_in, const hit_record& rec,
                          color& attenuation, ray& scattered) const{
        return false;
    }
};

class lambertian : public matetial{
public:
    lambertian(const color& albedo) : albedo(albedo){}

    bool scatter(const ray& _in, const hit_record& rec, color& attenuation, ray& scattered) const override{
        auto scatter_direction = rec.normal + random_unit_vector();
        scattered = ray(rec.p, scatter_direction);
        attenuation =albedo;
        return true;
    }



private:
    color albedo;
};


#endif //MATERIAL_H