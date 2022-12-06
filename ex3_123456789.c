#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 30

int q_1(char arr[]);

int q_2(char arr[], int k);

int q_3(char arr[]);

int q_4(char arr[]);

void str_to_int_arr(char arr[], int int_arr[]);
int char_to_int(char c);
void print_arr(int int_arr[], int size);
int num_of_elem(char arr[]);
int calc_size_of_arr(int arr[], int li, int ri);
int find_max_num(int int_arr[], int size);
int min(int a, int b);

int main()
{
    int q_num = 0, n = 0, res = 0, k = 0;
    char arr[MAX_SIZE];

    printf("Which question would you like to check?: ");
    scanf("%d", &q_num);
    printf("Please enter the input array: ");
    scanf("%s", arr);
    switch (q_num)
    {
    case 1:
        res = q_1(arr);
        printf("Result = %d", res);
        break;
    case 2:
        printf("Please enter k: ");
        scanf("%d", &k);
        res = q_2(arr, k);
        printf("Result = %d", res);
        break;
    case 3:
        res = q_3(arr);
        printf("Result = %d", res);
        break;
    case 4:
        res = q_4(arr);
        printf("Result = %d", res);
        break;
    default:
        printf("%d is an invalid input", q_num);
    }
    return 0;
}

int q_1(char arr[])
{
    int size_of_int_arr = num_of_elem(arr);
    int int_arr[MAX_SIZE];
    str_to_int_arr(arr, int_arr);

    //print_arr(int_arr , size_of_int_arr);

    int len_of_max_sum_sub = 1;
    int max_sum = int_arr[0];
    int cur_sum;
    int sub_len;
    int li;

    for (sub_len = 1; sub_len <= size_of_int_arr; sub_len++) {

        for (li = 0; li + sub_len <= size_of_int_arr; li++) {

            cur_sum = calc_size_of_arr(int_arr, li, li + sub_len - 1);
            //printf("%d %d %d %d\n" ,sub_len, li, li+sub_len-1, cur_sum);
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
                len_of_max_sum_sub = sub_len;
            }

        }
    }

    return len_of_max_sum_sub;
}

int q_2(char arr[], int k)
{
    int n = num_of_elem(arr);
    int int_arr[MAX_SIZE];
    str_to_int_arr(arr, int_arr);
    int width = 0;   //count of numbers that are smaller or equal to k

    for (int i = 0; i < n; i++) {
        if (int_arr[i] <= k)
            width++;
    }
    if (width <= 1) {
        return 0;
    }

    int curr = 0;
    for (int p = 0; p < width; p++) {
        if (int_arr[p] > k) {
            curr++;            //calculates swaps in first window
        }
    }

    int i = 1;
    int j = width;
    int count = curr;

    while (j < n) {

        if (int_arr[i - 1] <= k && arr[j] > k) {
            curr++;
        }
        else if (int_arr[i - 1] > k && arr[j] <= k) {
            curr--;
        }
        j++; i++;
        count = min(count, curr);

    }
    return count;
}

int q_3(char arr[])
{
    int size_of_int_arr = num_of_elem(arr);
    int int_arr[MAX_SIZE];
    str_to_int_arr(arr, int_arr);
    //print_arr(int_arr,size_of_int_arr);
    int i;
    int j;
    int cur_num;
    for (i = 0; i < size_of_int_arr; i++) {

        for (j = i + 1; j < size_of_int_arr; j++) {
            //printf("%d %d\n" , i,j);
            if (int_arr[i] == int_arr[j]) {
                //printf("found duplicate %d %d\n" , i,j);
                return 1;
            }
        }
    }
    return -1;
}

int q_4(char arr[])
{
    int size_of_int_arr = num_of_elem(arr);
    int int_arr[MAX_SIZE];
    str_to_int_arr(arr, int_arr);
    //print_arr(int_arr,size_of_int_arr);
    int max_height = find_max_num(int_arr, size_of_int_arr);

    int sum = 0;

    int i;
    int j;
    int l;
    int r;
    int has_left = 0;
    int has_right = 0;


    for (i = 0; i < size_of_int_arr; i++) {

        for (j = 0; j < max_height; j++) {


            if (int_arr[i] <= j) {
                //printf("%d %d not a tower ", i,j);

                for (l = i - 1; l >= 0; l--) {
                    if (int_arr[l] > j) {
                        has_left = 1;
                        //printf("has left ");
                        break;
                    }

                }

                for (r = i + 1; r < size_of_int_arr; r++) {
                    if (int_arr[r] > j) {
                        has_right = 1;
                        //printf("has right");
                        break;
                    }
                }

                //printf("\n");
                if (has_left & has_right) {
                    sum = sum + 1;
                }


            }

            else {
                //printf("%d %d a tower\n", i,j);
            }

            has_left = 0;
            has_right = 0;

        }
    }

    return sum;

    // HERE: define the function accordingly
}



void str_to_int_arr(char arr[], int int_arr[]) {

    int i = 0;
    int j = 0;
    int sign = 1;
    int k = 0;
    while (1) {

        if (arr[i] == '\0') {
            j = sign * j;
            //printf("current number is %d\n" , j);
            int_arr[k] = j;
            break;
        }
        else if(arr[i] == '"'){
            
        }
        else if (arr[i] == ',') {
            j = sign * j;
            int_arr[k] = j;

            //printf("current number is %d\n" , j);
            j = 0;
            sign = 1;
            k++;
        }

        else if (arr[i] == '-') {
            sign = -1;
        }
        else {
            //printf("%d\n" ,char_to_i(arr[i]) );
            j = char_to_int(arr[i]) + j * 10;
        }

        i++;
    }

}

int char_to_int(char c) {
    int i;

    switch (c)
    {
    case '-':
        i = -1;
        break;

    case '0':
        i = 0;
        break;
    case '1':
        i = 1;
        break;
    case '2':
        i = 2;
        break;
    case '3':
        i = 3;
        break;
    case '4':
        i = 4;
        break;
    case '5':
        i = 5;
        break;
    case '6':
        i = 6;
        break;
    case '7':
        i = 7;
        break;
    case '8':
        i = 8;
        break;
    case '9':
        i = 9;
        break;
    default:
        break;
    }

    return i;

}

void print_arr(int arr[], int size) {
    int i = 0;
    printf("\nMy Current Int Array: ");
    for (i; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int num_of_elem(char arr[]) {
    int i = 0;
    int n = 1;
    while (arr[i] != '\0') {
        if (arr[i] == ',') {
            n++;
        }
        i++;
    }
    return n;
}

int calc_size_of_arr(int arr[], int li, int ri) {
    int sum = 0;
    int i;
    for (i = li; i <= ri; i++) {
        sum = arr[i] + sum;
    };
    return sum;
}

int find_max_num(int arr[], int size) {
    int i;
    int max = arr[0];
    for (i = 1; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}
