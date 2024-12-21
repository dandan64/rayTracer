cmake_minimum_required(VERSION 3.22)
project(rayTracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(rayTracer
        main.cpp
        vec3.h
        color.h
        ray.h
        sphere.h
        hittable.h
        hittable_list.h
        rtweekend.h
        intreval.h
        camera.h
        material.h)
