#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//-----------------------------------------------------------------------------------------------------------------------------------------------
//ПРОТОТИП
unsigned int method_choose( void );
double function ( double x );
void print_result (double a, double b, unsigned int n, double I);
double l_re_method ( double a, double b, unsigned int n);
double r_re_method ( double a, double b, unsigned int n);
double trapezoid_method ( double a, double b, unsigned int n);
double simpss_method ( double a, double b, unsigned int n);

double e = 0.00001;

//-----------------------------------------------------------------------------------------------------------------------------------------------
//ВИКЛИК
int main()
{

unsigned int variant;
double a;
double b;
unsigned int n, N;
double I, I1, I2;

//задання меж інтегралу та кількості інтервалів розділення
    printf("\nEnter the left boundary (a): ");
    scanf("%lf", &a);
    printf("\nEnter the right boundary (b): ");
    scanf("%lf", &b);
    printf("\nEnter the number of partition intervals (n): ");
    scanf("%u", &n);
//----------------------------------------------------------
    variant= method_choose();

    switch(variant)
    {
        case 1:// метод лівих прямокутників

            I = l_re_method(a, b, n);
            print_result(a, b, n, I);

            N = 0;
            do
            {
                N = N + 2;
                I1=l_re_method(a, b, N);
                I2=l_re_method(a, b, N+2);
            }
             while( fabs(I2-I1) > e );

            printf("\n N=%u", N);
            printf("\n***************************");

        break;

        case 2: // метод правих прямокутників

            I = r_re_method(a, b, n);
            print_result(a, b, n, I);

            N = 0;
            do
            {
                N = N + 2;
                I1=r_re_method(a, b, N);
                I2=r_re_method(a, b, N+2);
            }
             while( fabs(I2-I1) > e );

            printf("\n N=%u", N);
            printf("\n***************************");

        break;

        case 3: // метод трапецій

            I = trapezoid_method(a, b, n);
            print_result(a, b, n, I);

            N = 0;
            do
            {
                N = N + 2;
                I1=trapezoid_method(a, b, N);
                I2=trapezoid_method(a, b, N+2);
            }
             while( fabs(I2-I1) > e );

            printf("\n N=%u", N);
            printf("\n***************************");

        break;


        case 4: // метод парабол

            I = simpss_method(a, b, n);
            print_result(a, b, n, I);

            N = 0;
            do
            {
                N = N + 2;
                I1=simpss_method(a, b, N);
                I2=simpss_method(a, b, N+2);
            }
             while( fabs(I2-I1) > e );

            printf("\n N=%u", N);
            printf("\n****************************");

        break;
    }

     return 0;
}


//-----------------------------------------------------------------------------------------------------------------------------------------------

//ОПИС

//Вибір методу для обчислення інтегралу

unsigned int method_choose( void )
{
    unsigned int var;

    printf("\nChoose the method of calculating:");
    printf("\n\n\t1.By Left Rectangles method.");
    printf("\n\t2.By Right Rectangles method.");
    printf("\n\t3.By Trapezoid method.");
    printf("\n\t4.By Simps's method.\n");
    scanf("%u", &var);

    while( var !=1 & var !=2 & var!=3 & var != 4 )
    {
        printf("\nError. Wrong metod. Enter metod again 1, 2, 3, or 4: ");
        scanf("%u", &var);
    }

    return var;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------


//Обчислення інтегралу за методом лівих прямокутників

double l_re_method ( double a, double b, unsigned int n)
{
    double h;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for ( int k = 0; k <= n-1; k++)
    {
      sum = sum + function(x);
      x = x + h;
    }

    return sum * h;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//Обчислення інтегралу за методом правих прямокутників

double r_re_method ( double a, double b, unsigned int n)
{
    double h;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for ( int k = 1; k <= n; k++)
    {
      sum = sum + function(x);
      x = x + h;
    }

    return sum * h;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//Обчислення інтегралу за методом трапецій

double trapezoid_method ( double a, double b, unsigned int n)
{
    double h;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for ( int k = 1; k <= n-1; k++)
    {
      sum = sum + (function(x)+function(x+h))/2;
      x = x + h;
    }

    return sum * h;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//Обчислення інтегралу за методом Сімпсона(парабол)

double simpss_method ( double a, double b, unsigned int n)
{
    double h;
    double x;
    double sum = 0;
    unsigned int k;

    h = ( b - a ) / n;
    x = a;

    for ( int k = 1; k < n-1; k++)
    {
      sum = sum + (function(x)+4*function(x+h/2)+function(x+h))/6;
      x = x + h;
    }

    return sum * h;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//Вивід заданих даних та результату

void print_result (double a, double b, unsigned int n, double I)
{
    system("cls");
    printf("\n***************************");
    printf("\n*         Data          *");
    printf("\n***************************");
    printf("\n a=%.2lf b=%.2lf n=%u ", a, b, n );
    printf("\n***************************");
    printf("\n*         Result          *");
    printf("\n***************************");
    printf("\n Integral= %.8lf", I);


}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//Вивід заданих даних та результату
double function ( double x )
{
    double y;

    y = x/pow(x,2)-1;

    return y;
}
