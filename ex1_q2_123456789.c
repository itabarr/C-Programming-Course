#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{   
    int input_int;
    int output_int = 0;
    
    int digit;
    int i = 1;

	printf("Enter a number to reverse: ");
    scanf("%d", &input_int);

    while(input_int / i != 0){
        // get the i digit
        digit = (input_int / i) - (input_int / (i * 10)) * 10;

        // move the previous digit one left and add new digit
        output_int = output_int * 10 + digit;

        i = i *10;
    }
    

    printf("Reverse of number is: ");
    printf("%d", output_int);
	return 0;
}