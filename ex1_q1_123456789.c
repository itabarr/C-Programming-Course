#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    int n;
    int i = 1;
    
	printf("Input: n = ");
    scanf("%d", &n);
    printf("Output: ");
    while (i <= n) {
        // dont print space in the first iteration
        if (i == 1) {
            printf("%d", i);
        }
        // calculate residue for each n,i
        else if ((n-((n/i)*i)) == 0){
            printf(" %d", i);
        };
        i++;
    };
    
	return 0;
}

