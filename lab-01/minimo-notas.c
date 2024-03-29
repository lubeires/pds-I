#include <stdio.h>

int main() {
    int valor, cedulas;
    scanf("%d", &valor);

    cedulas = valor/100;
    printf("100: %d\n", cedulas);

    valor -= cedulas * 100;
    cedulas = valor/50;
    printf("50: %d\n", cedulas);

    valor -= cedulas * 50;
    cedulas = valor/20;
    printf("20: %d\n", cedulas);

    valor -= cedulas * 20;
    cedulas = valor/10;
    printf("10: %d\n", cedulas);

    valor -= cedulas * 10;
    cedulas = valor/5;
    printf("5: %d\n", cedulas);

    valor -= cedulas * 5;
    cedulas = valor/2;
    printf("2: %d\n", cedulas);

    valor -= cedulas * 2;
    cedulas = valor;
    printf("1: %d\n", cedulas);
}