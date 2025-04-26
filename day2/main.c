#include <stdio.h>
#include "circle.h"
#include "square.h"
#include "rectangle.h"

int main() {
    printf("Area of Circle: %.2f\n", area_circle(5));
    printf("Area of Square: %.2f\n", area_square(4));
    printf("Area of Rectangle: %.2f\n", area_rectangle(5, 3));
    return 0;
}

