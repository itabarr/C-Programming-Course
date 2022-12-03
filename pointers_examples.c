#include <stdio.h>
#include <stdlib.h>

void swap(int *px, int*py);

int main()
{   
    printf("\n*** Simple Pointer Example ***\n");
    int x = 5;
    printf("Value of x is %d and it is located in %p.\n" , x, &x);

    int *px = &x;
    printf("Value of px is %p and it is located in %p.\n", px, &px);    

    int y = 8;
    printf("Value of y is %d and it is located in %p.\n" , y, &y);

    int *py = &y;
    printf("Value of py is %p and it is located in %p.\n", py, &py);

    swap(px, py);
    printf("After swap, value of x is %d and it is located in %p.\n" , x, &x);
    printf("After swap, value of y is %d and it is located in %p.\n" , y, &y);
	
    

    printf("\n*** Array Example ***\n");
    char example_string[7] = "Hello!";
    printf("Value of example_string is %s and it is located in %p.\n" , example_string, &example_string);

    int i;
    for (i = 0; i < 7; i++)
    {   
        if (i == 6){
            printf("Value of  example_string[%d] is %d (last byte) and it is located in %p\n", i, example_string[i], &example_string[i]);
            break;
        }

        printf("Value of  example_string[%d] is %c and it is located in %p\n", i, example_string[i], &example_string[i]);
    }

    printf("\n*** Dynamic Memory Allocation Example ***\n");

    float * pf = (float*) malloc(3 * sizeof(float));
    *(pf) = 1.1;
    *(pf+1) = 1.2;
    *(pf+2) = 1.3;
    
    printf("%p value %f\n" , pf, *pf);
    printf("%p value %f\n" , pf+1, *(pf+1));
    printf("%p value %f\n" , pf+2, *(pf+2));
    
    free(pf);

    return 0;




}

void swap(int *px, int *py){
    int temp = *px;
    *px = *py;
    *py = temp;
}