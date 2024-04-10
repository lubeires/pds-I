#include <stdio.h>

int main()
{
    int x, multiplos_de_2, multiplos_de_3, multiplos_de_5, multiplos_de_todos;
    multiplos_de_2 = multiplos_de_3 = multiplos_de_5 = multiplos_de_todos = 0;
    scanf("%d", &x);
    int i = 1;
    while (i <= x)
    {
        multiplos_de_2 += i % 2 == 0;
        multiplos_de_3 += i % 3 == 0;
        multiplos_de_5 += i % 5 == 0;
        multiplos_de_todos += i % 30 == 0;
        i++;
    }
    printf("Múltiplos de 2: %d\n", multiplos_de_2);
    printf("Múltiplos de 3: %d\n", multiplos_de_3);
    printf("Múltiplos de 5: %d\n", multiplos_de_5);
    printf("Múltiplos de todos: %d\n", multiplos_de_todos);

    return 0;
}