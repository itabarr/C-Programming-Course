#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

void print_quadratic(double a, double b, double c);

int find_roots(double a, double b, double c, double* p1, double* p2);

int main()
{
    double a, b, c;
    printf("Please enter three numbers:\n");
    scanf("%lf%lf%lf", &a, &b, &c);

    double r1, r2;
    int n = find_roots(a, b, c, &r1, &r2);

    print_quadratic(a, b, c);
    printf(" = 0 has ");

    switch (n) {
    case 0:
        printf("no real roots\n");
        break;
    case 1:
        printf("one real root: %g\n", r1);
        break;
    case 2:
        printf("two real roots: %g and %g\n", r1, r2);
        break;
    case -1:
        printf("infinite real roots\n");
        break;
    default:
        printf("%d roots? impossible!\n", n);
    }

    return 0;
}

void print_quadratic(double a, double b, double c)
{   
    // Print section piece by piece with decisions on how to print.
    // Don't print if coef = 0, special cases for coef = 1,-1, special cases if the coef is "opener" 
    
    // Print x^2 part
    if (a !=0){
        if (a !=1 && a !=-1){
            printf("%gx^2", a);
        }

        else if (a ==1){
            printf("x^2");
        }

        else if (a == -1){
            printf("-x^2");
        }

    }

    // Print x part
    if (b !=0){
        if (b < 0){

            if (b !=-1){
                printf("%gx", b);
            }

            else if (b == -1){
                printf("-x^2");
            }

        }
        else{

            if (a == 0){

                if (b != 1){
                    printf("%gx", b);
                }
                
                else{
                    printf("x", b);
                }
            }

            else{
                if (b != 1){
                    printf("+%gx", b);
                }
                
                else{
                    printf("+x", b);
                }
                
            }
            
        }
    }

    // Print const part
    if (c !=0){
        if (c < 0){
            printf("%gx", b);
        }
        else{

            if (a == 0 && b==0){
                printf("%g", c);
            }

            else{
                printf("+%g", c);
            }
            
        }

    }

    // Print zero part
    if (a==0 && b==0 && c==0){
        printf("0");
    }



}

int find_roots(double a, double b, double c, double* p1, double* p2)
{
    if (a == 0) {
        // The equation is not a quadratic equation, but a linear equation
        if (b == 0) {
            // The equation is not a linear equation, but a constant
                if (c == 0) {
                // Every value of x is a solution
                    return -1;
                } 
                else {
                // There are no solutions
                return 0;
                }
        } 
        
        else {
            // The equation has a unique solution
            *p1 = -c / b;
            return 1;
        }
    }
    
    else {
        // The equation is a quadratic equation
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            // The equation has no real solutions
            return 0;
        } 
        
        else if (discriminant == 0) {
            // The equation has a unique real solution
            *p1 = -b / (2 * a);
            return 1;
        } 
        
        else {
            // The equation has two real solutions
            *p1 = (-b - sqrt(discriminant)) / (2 * a);
            *p2 = (-b + sqrt(discriminant)) / (2 * a);
            return 2;
        }
    }
}

