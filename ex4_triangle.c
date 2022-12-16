#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

// TESTED WITH VISUAL STUDIO 2019 AND ALL EXAMPLES IN EX4 PDF

// Comments:
// 1. It seems like they have a mistake with example 2, because the solution is not true
// 2. They have a problem with structure declaration, it is not how it should be done , added correction
// 3. To determine if a triange is right i used pythagorean theorem, but because we are using floats the equations should have a threshold.
// need to ask them what is the correct threshold (and if this is ok..) 

// Fix struct declaration
typedef struct point Point;
typedef struct triangle Triangle;

struct point {
    double x, y;
};

struct triangle {
    Point p, q, r;
};

void print_point(Point p);

double distance(Point p, Point q);

void side_lengths(Triangle const* t, double* a, double* b, double* c);

void print_triangle(Triangle const* t);

double perimeter(Triangle const* t);

double area(Triangle const* t);

bool is_right(Triangle const* t);

double double_abs(double a);

int main()
{
    Point p = { .x = 0, .y = 0 };
    Point q = { .x = 0, .y = 13 };
    Point r = { .x = 12, .y = 0 };

    Triangle t = {
        .p = p,
        .r = r,
        .q = q
    }; // t.q is the origin
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

void side_lengths(Triangle const* t, double* a, double* b, double* c)
{
    //double d = distance((*t).p, (*t).q);
    *a = distance((*t).p, (*t).q);
    *b = distance((*t).q, (*t).r);
    *c = distance((*t).r, (*t).p);
    
}

void print_triangle(Triangle const* t)
{

    printf("triangle with corners ");
    printf("(%g,%g)", (*t).p.x, (*t).p.y);
    printf(", ");
    printf("(%g,%g)", (*t).q.x, (*t).q.y);
    printf(" and ");
    printf("(%g,%g)", (*t).r.x, (*t).r.y);
}

double perimeter(Triangle const* t)
{
    double a, b,c;
    side_lengths(t,&a,&b,&c);

    double per = a + b +c;
    return per;
}

double area(Triangle const* t)
{   
    
    double a, b,c, s, area;
    side_lengths(t,&a,&b,&c);
    
    // Calculate are with Heron's formula
    s = (a + b + c) / 2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));

    return area;
}

bool is_right(Triangle const* t)
{
    double a, b,c, s, area;
    side_lengths(t,&a,&b,&c);

    // Determine if right using  pythagorean theorem:
    if (abs(a*a - (b*b + c*c))<0.000001 || abs(b*b -(a*a + c*c))<0.000001 || abs(c*c - (b*b + a*a)) < 0.000001){
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