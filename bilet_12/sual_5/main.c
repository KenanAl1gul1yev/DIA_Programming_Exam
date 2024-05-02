#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    printf("Type n: ");
    scanf("%d", &n);

    double sum = 0;
    for (double i = 1; i <= n; i++) sum += pow(-1, i + 1)/i ;

    printf("Sum : %lf", sum);

    return 0;
}
