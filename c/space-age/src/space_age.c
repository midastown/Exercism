#include "space_age.h"
#include <stdio.h>

float convert_planet_age(planet_t planet, int64_t input) {
    double result;
    result = input / 31557600;
        
    if (planet == MERCURY) {
        result /= 0.2408467;
    } else if (planet == VENUS) {
        result /= 0.61519726;
    } else if (planet == MARS) {
        result /= 1.8808158;
    } else if (planet == JUPITER) {
        result /= 11.862615;
    } else if (planet == SATURN) {
        result /= 29.447498;
    } else if (planet == URANUS) {
        result /= 84.016846;
    } else if (planet == NEPTUNE) {
        result /= 164.79132;
    }

    return (float) result;


}
