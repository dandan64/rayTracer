#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include "intreval.h"
#include <cstdlib>


using std::make_shared;
using std::shared_ptr;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degree_to_radians(double degrees){
    return degrees * pi /180.0;
}

inline double random_double(){
    //return a rand real in [0,1)
    return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double  max){
    return min + (max - min)*random_double();
}
#include "color.h"
#include "ray.h"
#include "vec3.h"

#endif //RTWEEKEND_H