#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct point {
    double x, y;
} Point;

typedef struct triangle {
    Point p, q, r;
} Triangle;

void print_point(Point p);

double distance(Point p, Point q);

void print_triangle(Triangle const* t);

double perimeter(Triangle const* t);

double area(Triangle const* t);

bool is_right(Triangle const* t);

// Define more helper function than given
void side_lengths(Triangle const* t, double* a, double* b, double* c);

double double_abs(double a);

int main()
{
    Point p = { .x = 0, .y = 0 };
    Point q = { .x = 0, .y = 13 };
    Point r = { .x = 13, .y = 0 };

    Triangle t = {
        .p = p,
        .r = r,
        .q = q
    }; 
    

    double per = perimeter(&t);
    double ar = area(&t);
    printf("The perimeter of a ");
    print_triangle(&t);
    printf(" is %g\n", per);

    printf("The area of a ");
    print_triangle(&t);
    printf(" is %g\n", ar);

    printf("The ");
    print_triangle(&t);
    if (is_right(&t))
    {
        printf(" is a right angle triangle\n");
    }
    else
        printf(" is not a right angle triangle\n");
    return 0;
}

void print_point(Point p)
{
    printf("(%g, %g)", p.x, p.y);
}

double distance(Point p, Point q)
{
    double dx = p.x - q.x;
    double dy = p.y - q.y;
    return sqrt(dx * dx + dy * dy);
}

void print_triangle(Triangle const* t)
{
    double p_x = round((*t).p.x * 10000.0) / 10000.0 ; 
    double p_y = round((*t).p.y * 10000.0) / 10000.0 ;
    double q_x = round((*t).q.x * 10000.0) / 10000.0 ;
    double q_y = round((*t).q.y * 10000.0) / 10000.0 ;
    double r_x = round((*t).r.x * 10000.0) / 10000.0 ;
    double r_y = round((*t).r.y * 10000.0) / 10000.0 ;

    printf("triangle with corners "); 
    printf("(%g,%g)", p_x, p_y);
    printf(", ");
    printf("(%g,%g)", q_x, q_y);
    printf(" and ");
    printf("(%g,%g)", r_x, r_y);
}

void side_lengths(Triangle const* t, double* a, double* b, double* c)
{
    //double d = distance((*t).p, (*t).q);
    *a = distance((*t).p, (*t).q);
    *b = distance((*t).q, (*t).r);
    *c = distance((*t).r, (*t).p);
    
}

double perimeter(Triangle const* t)
{
    double a, b,c;
    side_lengths(t,&a,&b,&c);

    double per = a + b +c;
    per = round(per * 10000.0) / 10000.0 ; // round to 4 digits
    return per;
    
}

double area(Triangle const* t)
{
    double a, b,c, s, area;
    side_lengths(t,&a,&b,&c);
    
    // Calculate are with Heron's formula
    s = (a + b + c) / 2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    area = round(area * 10000.0) / 10000.0 ; 

    return area;
}

bool is_right(Triangle const* t)
{
    
    double a_sqr = ((*t).p.x - (*t).q.x) * ((*t).p.x - (*t).q.x) + ((*t).p.y - (*t).q.y) * ((*t).p.y - (*t).q.y);
    double b_sqr = ((*t).q.x - (*t).r.x) * ((*t).q.x - (*t).r.x) + ((*t).q.y - (*t).r.y) * ((*t).q.y - (*t).r.y);
    double c_sqr = ((*t).r.x - (*t).p.x) * ((*t).r.x - (*t).p.x) + ((*t).r.y - (*t).p.y) * ((*t).r.y - (*t).p.y);
    
    // Determine if right using  pythagorean theorem:
    if (a_sqr  == b_sqr + c_sqr || b_sqr == a_sqr + c_sqr || c_sqr == b_sqr + a_sqr ){
        return 1;
    }

    return 0;
}

double double_abs(double a){
    if (a > 0){
        return a;
    }

    return -a;
}