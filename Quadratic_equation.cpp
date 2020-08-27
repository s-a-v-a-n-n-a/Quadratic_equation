#include <stdio.h>
#include <math.h>

#define max(A, B) ((A) > (B) ? (A) : (B))
#define min(A, B) ((A) < (B) ? (A) : (B))

double discriminant(double a, double b, double c)
{
    return b*b - 4*a*c;
}

//функция для работы с константными выражениями
void const_eq(double c)
{
    if (c == 0)
        printf("All numbers are roots");
    else printf("No roots");
    return ;
}

//функция для работы с линейными уравнениями
void line_eq(double b, double c)
{
    printf("1 root, x = %lg", -c/b);
    return ;
}

//функция для работы с квадратными уравнениями
void sq_eq(double a, double b, double c)
{
    double discrim = discriminant(a, b, c);
    if (discrim < 0)
        printf("No roots");
    else if(discrim > 0)
    {
        double x1 = (-b + sqrt(discrim))/(2*a);
        double x2 = (-b - sqrt(discrim))/(2*a);
        printf("2 roots, x1 = %lg, x2 = %lg", min(x1, x2), max(x1, x2));
    }
    else printf("1 root, x = %lg", -b/(2*a));
    return ;
}

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;

    scanf("%lg %lg %lg", &a, &b, &c);

    if (a == 0 && b == 0)
            const_eq(c);
    else if (a == 0)
            line_eq(b, c);
    else sq_eq(a, b, c);
    return 0;
}
