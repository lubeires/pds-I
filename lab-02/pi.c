#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main() {
    double x, pi = 0;
    int i = 0;
    scanf("%lf", &x);
    do {
        pi += pow(-1, i) * 4 / (2 * i + 1);
        i++;
    } while (fabs(pi - M_PI) > x);
    printf("%d\n", i);
    return 0;
}