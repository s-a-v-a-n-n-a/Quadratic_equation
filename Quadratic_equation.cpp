#include <stdio.h>
#include <assert.h>
#include <math.h>

#define INF -1

//-------------------------------------------------------
// Swaps to numbers
//
// Parameters:
//
// a1   address of the first number
// a2   address of the second number
//-------------------------------------------------------
void swap(double *a1, double *a2);

//-------------------------------------------------------
// Finds a discriminant
//
// Parameters:
//
// a    the first  coefficient
// b    the second coefficient
// c    the third  coefficient
//
// Returns:
//
// the discriminant
//-------------------------------------------------------
double discriminant(double a, double b, double c) ;


//-------------------------------------------------------
// Solves a const equation c = 0
//
// Parameters:
//
// c    the third coefficient
//
// Returns:
//
// flag     the number of roots
//-------------------------------------------------------
int const_eq(double c) ;

//-------------------------------------------------------
// Solves a line equation bx + c = 0 when b != 0
//
// Parameters:
//
// b    the second coefficient
// c    the third  coefficient
//
// Returns:
//
// flag     the number of roots
// x1       the root
//-------------------------------------------------------
int line_eq(double b, double c, double *x1);


//-------------------------------------------------------
// Solves a square equation ax^2 + bx + c = 0 when a != 0
//
// Parameters:
//
// a    the first  coefficient
// b    the second coefficient
// c    the third  coefficient
//
// Returns:
//
// flag     the number of roots
// x1       the first root
// x2       the second root
//-------------------------------------------------------
int sq_eq(double a, double b, double c, double *x1, double *x2);

void unit_tests_for_consteq();

void unit_tests_for_line_eq();

void unit_tests_for_squareq();

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;

    int kol = 0;

    double x1 = 0;
    double x2 = 0;

    unit_tests_for_consteq();
    unit_tests_for_line_eq();
    unit_tests_for_squareq();

    scanf("%lg %lg %lg", &a, &b, &c);

    if (a == 0 && b == 0)
    {
            kol = const_eq(c);
            if (kol == 0)
                printf("All numbers are roots\n");
            else
                printf("No roots");
    }
    else if (a == 0)
    {
            kol = line_eq(b, c, &x1);
            if (kol == -2)
                printf("This is not a line equation\n");
            else
                printf("1 root, x = %lg", x1);
    }
    else
    {
        kol = sq_eq(a, b, c, &x1, &x2);
        if (kol == -2 )
            printf("This is not a square equation\n");
        else if (kol == 0)
            printf("No roots\n");
        else if (kol == 2)
            printf("2 roots, x1 = %lg, x2 = %lg\n", x1, x2);
        else
            printf("1 root, x = %lg\n", x1);
    }
    return 0;
}

void swap(double *a1, double *a2)
{
    double tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}

double discriminant(double a, double b, double c)
{
    return b*b - 4*a*c;
}

int const_eq(double c)
{
    if (c == 0)
    {
        return INF;
    }
    else
    {
        return 0;
    }
}

int line_eq(double b, double c, double *x1)
{
    if (b == 0)
    {
        return -2;
    }

    *x1 = -c/b;
    return 1;
}

int sq_eq(double a, double b, double c, double *x1, double *x2)
{
    if (a == 0)
    {
        return -2;
    }

    double discrim = discriminant(a, b, c);
    if (discrim < 0)
    {
        return 0;
    }
    else if(discrim > 0)
    {
        *x1 = (-b + sqrt(discrim))/(2*a);
        *x2 = (-b - sqrt(discrim))/(2*a);

        if (*x1 > *x2)
            swap(x1, x2);
        return 2;
    }
    else
    {
        b = (b == 0) ? -b : b;
        *x1 = -b/(2*a);
        return 1;
    }
}

void unit_tests_for_consteq()
{
    {
        int res = const_eq(100);
        assert(res ==  0);
    }

    {
        int res = const_eq(0);
        assert(res ==  INF);
    }
}

void unit_tests_for_line_eq()
{
    {
        double x1 = 0;

        int res = line_eq(5, 2, &x1);
        assert(res ==  1);
        assert(x1 == -0.4);
    }

    {
        double x1 = 0;

        int res = line_eq(0, 9, &x1);
        assert(res ==  -2);
    }
}

void unit_tests_for_squareq()
{
    {
        double x1 = 0;
        double x2 = 0;

        int res = sq_eq(0, 5, 2, &x1, &x2);
        assert(res ==  -2);
    }

    {
        double x1 = 0;
        double x2 = 0;

        int res = sq_eq(1, 4, 4, &x1, &x2);
        assert(res ==  1);
        assert(x1 == -2);
    }

    {
        double x1 = 0;
        double x2 = 0;

        int res = sq_eq(1, 2, 5, &x1, &x2);
        assert(res ==  0);
    }

    {
        double x1 = 0;
        double x2 = 0;

        int res = sq_eq(1, -2, -3, &x1, &x2);
        assert(res ==  2);
        assert(x1 == -1);
        assert(x2 == 3);
    }
}
