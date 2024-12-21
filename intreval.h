#ifndef INTREVAL_H
#define INTREVAL_H
#include <limits>

class intreval {
public:
    double min, max;

    intreval() : min(std::numeric_limits<double>::infinity()), max(-std::numeric_limits<double>::infinity()) {}
    intreval(double min, double max) : min(min), max(max) {}

    double size(){
        return max - min;
    }

    bool contains(double x) const{
        return min <= x && x <= max;
    }
    bool surrounds(double  x) const{
        return min< x && x < max;
    }

    double  clamp(double x) const{
        if(x < min) return min;
        if(x > max) return max;
        return x;
    }


    static const intreval empty, universe;
};

const intreval intreval::empty = intreval(std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity());
const intreval intreval::universe = intreval(-std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());

#endif //INTREVAL_H
