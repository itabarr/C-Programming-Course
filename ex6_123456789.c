#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


#define ENTERING_QUESTION "Please choose a question by entering 1-5 (enter 0 to exit):" 
#define DYNAMIC_ALLOCATION_FAILED "dynamic allocation failed"

//Q1//
#define MAX_SIZE_INPUT 31
#define QUESTION1_INPUT_MESSAGE "Please enter binary number input:"
#define QUESTION1_OUTPUT_MESSAGE_DECIMAL "to decimal is:"
#define QUESTION1_OUTPUT_MESSAGE_HEXADECIMAL "to hexadecimal is:"
#define QUESTION1_ERROR_MESSAGE "invalid input, please try again."

//Q2//
#define QUESTION2_INPUT1_MESSAGE "Please enter num1 value:"
#define QUESTION2_INPUT2_MESSAGE "Please enter num2 value:"
#define QUESTION2_OUTPUT_MESSAGE "After swapping:"

//Q3//
#define QUESTION3_INPUT1_MESSAGE "Please enter an integer:"
#define QUESTION3_OUTPUT_MESSAGE "Output:"

//Q4//
#define QUESTION4_INPUT1_MESSAGE "Please enter an integer:"
#define QUESTION4_OUTPUT1_MESSAGE "in binary is a palindrome"
#define QUESTION4_OUTPUT0_MESSAGE "in binary is not a palindrome."

//Q5//
#define QUESTION5_INPUT1_MESSAGE "Please enter an integer:"
#define QUESTION5_OUTPUT1_MESSAGE "Output of Q5:"


int validate_binary_string(char *bin_str);
int strlen(char *bin_str);
int bin_str_to_int(char *bin_str);
char int_to_hex(int n);
int _minPowerOf2(int num);

void bin2hexanddec(char *bin_str)
{
	//Question 1
    int is_bin_str = validate_binary_string(bin_str);

    if (is_bin_str == 0){
        char bin_str[MAX_SIZE_INPUT];

        printf(QUESTION1_ERROR_MESSAGE);
        printf("\n");
        printf(QUESTION1_INPUT_MESSAGE);
        printf(" ");
        scanf("%s", &bin_str);
        
        bin2hexanddec(bin_str);
    }

    else{ 
        int bin_str_len = strlen(bin_str);
        int integer;

        
        integer = bin_str_to_int(bin_str);

        printf(QUESTION1_OUTPUT_MESSAGE_DECIMAL);
        printf(" %d\n" , integer);
        
        int mod = bin_str_len % 4;
        char hex[(MAX_SIZE_INPUT/4)+2+1+1] = {'\0'};

        hex[0] = '0';
        hex[1] = 'x';
        
		char tmp_str[5] = { '\0' };
        int hex_int;
        char hex_char;
        

        int j;
        for (j = 0; j < 4-mod; j++){
            tmp_str[j] = '0';
        }
        for (j=0; j < mod; j++){
            tmp_str[4-mod+j] = bin_str[j];
        }

        hex_int = bin_str_to_int(tmp_str);
        hex_char = int_to_hex(hex_int);
        hex[2] = hex_char;

        int i = mod;
        j = 3;
        if (mod == 0){
            j = 2;
        }

        while(*(bin_str+i) != '\0'){
            tmp_str[0] = *(bin_str+i);
            tmp_str[1] = *(bin_str+i+1);
            tmp_str[2] = *(bin_str+i+2);
            tmp_str[3] = *(bin_str+i+3);
            hex_int = bin_str_to_int(tmp_str);
            hex_char = int_to_hex(hex_int);
            hex[j] = hex_char;
            j = j+1;
            i = i+4;
        }
        hex[j] = '\0';

        printf(QUESTION1_OUTPUT_MESSAGE_HEXADECIMAL);
        printf(" %s" , hex);


    }
    
    
}

void swap(int* xp, int* yp)
{
	*xp=*xp+*yp;
    *yp=*xp-*yp;
    *xp=*xp-*yp;
}

int minPowerOf2(int num)
{
    int j = 0;
	int i = 1;
    while(1){
        if (num <= i){
            return i;
        }
        i = i*2;
        j = j+1;
    }
    
}

int isPalindrome(int num)
{   
    int org_num = num;
    int pow = _minPowerOf2(num);
    int rev = 0;
    for (int i=0 ; i<pow ;i++){
        rev = rev * 2 + num % 2;
        num = num / 2 ;
    }
	
    //printf("%d %d\n", org_num , rev);
    if (org_num == rev){
        return 1;
    }
    return 0;
}

int swap_even_odd(int num)
{
    unsigned int _num = (unsigned int)num;
    unsigned int even_digits = _num & 0xAAAAAAAA;
    unsigned int odd_digits = _num & 0x55555555;
    even_digits = even_digits / 2;
    odd_digits = odd_digits * 2;

    int new_num = (int)(even_digits | odd_digits);

    return new_num;

}

int validate_binary_string(char *bin_str){
    char s;
    int i = 0;

    while (*(bin_str+i) != '\0'){
        if (*(bin_str+i) != '0' & *(bin_str+i) != '1'){
            return 0;
        }
        i++;

    }

    return 1; 
}

int strlen(char *bin_str){
    int i = 0;

    while (*(bin_str+i) != '\0'){
        i++;

    }

    return i; 
}

int bin_str_to_int(char *bin_str){
    int bin_str_len = strlen(bin_str);
    int integer = 0;
    int i;
        int pow = 1;
        
        for (i = 0; i < bin_str_len; i++){
            if (*(bin_str+(bin_str_len-i-1)) == '1'){
                integer = integer + pow;
            }

            pow = pow*2;
                
        }
    return integer;

}

char int_to_hex(int n){
    char hex[17] = "0123456789ABCDEF";
    return hex[n];

}

int _minPowerOf2(int num)
{
    int j = 0;
	int i = 1;
    while(1){
        if (num <= i){
            return j;
        }
        i = i*2;
        j = j+1;
    }
    
}

int main()
{   
    
    char bin_str[MAX_SIZE_INPUT];
    int num1, num2;
    int q_num;

    printf(ENTERING_QUESTION);
    printf("\n");
	scanf("%d", &q_num);
    switch (q_num)
	{
    
    case 0:
        return 0;

	case 1:
		printf(QUESTION1_INPUT_MESSAGE);
        printf(" ");
        scanf("%s", &bin_str);
        
        bin2hexanddec(bin_str);
		printf("\n");
		break;
	case 2:
        
		printf(QUESTION2_INPUT1_MESSAGE);
        printf(" ");
        scanf("%d", &num1);
        
    
        printf(QUESTION2_INPUT2_MESSAGE);
        printf(" ");
        scanf("%d", &num2);
        
        
        swap(&num1, &num2);
        printf(QUESTION2_OUTPUT_MESSAGE);
        printf(" num1=%d, num2=%d", num1,num2);
		printf("\n");
		break;

	case 3:
        
		printf(QUESTION3_INPUT1_MESSAGE);
        printf(" ");
        scanf("%d", &num1);

        num2 = minPowerOf2(num1);
        printf(QUESTION3_OUTPUT_MESSAGE);
        printf(" %d" ,num2);
		printf("\n");
		break; 
    
    case 4:
        printf(QUESTION4_INPUT1_MESSAGE);
        printf(" ");
        scanf("%d", &num1);
        num2 = isPalindrome(num1);
        if (num2){
            printf("%d %s" , num1, QUESTION4_OUTPUT1_MESSAGE);
        }
        else{
            printf("%d %s" , num1, QUESTION4_OUTPUT0_MESSAGE);
        }
		printf("\n");
        break;
    case 5:
       
        printf(QUESTION5_INPUT1_MESSAGE);
        printf(" ");
        scanf("%d", &num1);
        num2 = swap_even_odd(num1);

        printf(QUESTION5_OUTPUT1_MESSAGE);
        printf(" %d" ,num2);
		printf("\n");
        break;


	default:
		break;
	}
    
    main();
	return 0;
}