#include <stdio.h>

int main() {
    int a, b, primo;
    scanf("%d %d", &a, &b);
    if (a <= 0 || b >= 10000) return 1;
    for (int num = a; num <= b; num++) {
        primo = 1;
        for (int divisor = num / 2; divisor > 1; divisor--) {
            if (num % divisor == 0) {
                primo = 0;
                break;
            }
        }
        if (primo) printf("%d\n", num);
    }
    return 0;
}