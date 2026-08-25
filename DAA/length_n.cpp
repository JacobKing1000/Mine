#include <stdio.h>
#include <stdbool.h>

bool is_point_inside_finger(double x, double y) {

    if (x >= -1.2 && x <= 1.2) {
        if (y >= -1.0 && y <= 6.0) {
            return true;
        }
    }

    double hand_base_radius_sq = (x * x) + (y * y);
    if (hand_base_radius_sq <= 16.0 && y <= 0.0) {
        return true;
    }


    if (x >= -4.0 && x < -1.2) {
        if (y >= -1.5 && y <= 1.5) {
            return true;
        }
    }

    if (x > 1.2 && x <= 4.0) {
        if (y >= -1.5 && y <= 1.5) {
            return true;
        }
    }

    return false;
}

int main() {

    int width = 50;
    int height = 30;


    for (int i = 0; i < height; i++) {

        double y = 6.5 - ((double)i * 9.0 / (double)height);

        for (int j = 0; j < width; j++) {
            // Map matrix column j across to Cartesian x coordinate system
            double x = -5.0 + ((double)j * 10.0 / (double)width);


            if (is_point_inside_finger(x, y)) {
                // A calculation match outputs a high-density matrix dot
                printf("*");
            } else {
                // Out of mathematical bounds outputs an empty matrix space
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}