#include <stdio.h>

int main()
{
    int i = 233;
    do
    {
        printf("%d\n", i);
        i += i > 300 && i < 400 ? 3 : 5;
    } while (i <= 457);
    return 0;
}