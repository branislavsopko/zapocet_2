#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h> 
#include <ctype.h>  

int is_white(const char c){
    if(c == ' ' || c == '\t' || c == '\n'){
        return 1;
    }
    return 0;
}

void change_whites(char string[]){
    if(string == NULL){
        return;
    }
    for(int i = 0; i < strlen(string); i++){
        if(string[i] == ' ' || string[i] == '\n'){
            string[i] = '.';
        }
    }
}

int guess_eval(const int guess, const int my_number){
    if(guess == my_number){
        return 1;
    }else if(guess < my_number){
        return 2;
    }else{
        return 0;
    }
}

int leap_year(const int year){
    if(year % 400 == 0){
        return 1;
    }else if(year % 100 == 0){
        return 0;
    }else if(year % 4 == 0){
        return 1;
    }else{
        return 0;
    }
}

int count_positives(const int size, const int array[]){
    int count = 0;
    if(array == NULL){
        return -1;
    }
    for(int i = 0; i < size; i++){
        if(array[i] > 0){
            count ++;
        }
    }
    return count;
}

int count_whites(const char string[]){
    int count = 0;
    if(string == NULL){
        return -1;
    }
    for(int i = 0; i < strlen(string); i++){
        if(string[i] == ' ' || string[i] == '\n'){
            count++;
        }
    }
    return count;
}

int direction_correction(const int degree){
    if(degree < 0 || degree % 90 != 0){
        return -1;
    }else{ 
        return(degree % 360);
    }
}

int all_positives(const int size, const int array[]){
    if(array == NULL){
        return -1;
    }
    for(int i = 0; i < size; i++){
        if(array[i] <= 0){
            return 0;
        }
    }
    return 1;
}

int last_positive(const int size, const int array[]){
    if(array == NULL){
        return -1;
    }
    for(int i = size - 1; i >= 0; i--){
        if(array[i] > 0){
            return array[i];
        }
    }
    return -1;
}

int binary_num(const int num){
    if(num < -1000 || num > 1000 ){
        return -1;
    }else if(num == 1 || num == 0){
        return 1;
    }else{
        return 0;
    }
}

void swap_sign(const int size, int array[]){
    if(array == NULL){
        return;
    }
    for(int i = 0; i < size; i++){
        array[i] = -array[i];
    }
}

int div_by_3(const int num){
    if(num % 3 ==0){
        return 1;
    }else{
        return 0;
    }
}

int same_case(const char a, const char b){ 
    if(!isalpha(a) || !isalpha(b)){
        return -1;
    }
    if((islower(a) && islower(b)) || (isupper(a) && isupper(b))){
        return 1;
    }
    return 0;
}

void string_to_upper(char string[]){ 
    if(string == NULL){
        return;
    }
    for(int i = 0; string[i] != '\0'; i++){
        string[i] = toupper(string[i]);
    }
}

int find_first_A(char string[]){
    if(string == NULL){
        return -1;
    }
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == 'A' || string[i] == 'a'){
            return i;
        }
    }
    return -1;
}

int is_prime(const int num){
    if(num == 1 || num == 0){
        return 0;
    }
    if(num == 2){
        return 1;
    }
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}



int main(){
    //is_white() function
    printf("%d %d\n", is_white('#'), is_white(' '));
    //change_whites function
    char str[] = "Hello world!";
    change_whites(str);
    printf("%s\n", str);
    //guess_oval function
    printf("%d %d %d \n", guess_eval(34, 34), guess_eval(22, 34), guess_eval(34, 22));
    //leap_year function
    printf("%d %d %d\n", leap_year(4000), leap_year(3000), leap_year(3004));
    //count_positives function
    const int array1[] = {1, 2, 0, 3, 4, 0};
    const int array2[] = {1, 2, 6, 3, 4, 7};
    const int array3[] = {-1, -2, 0, -3, 0, -2};
    printf("%d %d %d\n", count_positives(6, array1), count_positives(6, array2), count_positives(6, array3));
    //count_whites function
    const char string[] = "Hello, how are you?";
    printf("%d\n", count_whites(string));
    return 0;
    //direction_correction function
    printf("%d %d %d\n", direction_correction(540),direction_correction(-90),direction_correction(180));
    //all_positives function
    const int array1[] = {1, 2, 0, 3, 4, 0};
    const int array2[] = {1, 2, 6, 3, 4, 7};
    const int array3[] = {-1, -2, 0, -3, 0, -2};
    printf("%d %d %d\n", all_positives(6, array1), all_positives(6, array2), all_positives(6, array3));
    //last_positive function
    const int array1[] = {0, 5, 6};
    const int array2[] = {-1, 0, -6, -2};
    printf("%d %d\n",last_positive(3, array1),last_positive(4, array2));
    //binary_num function
    printf("%d %d %d\n", binary_num(-1001), binary_num(3), binary_num(1));
    //swap_sign function
    int array[] = {1, 2, 0, -3, -4, 0};
    int size = 6;
    swap_sign(size, array);
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    //div_by_3 function
    printf("%d %d %d \n", div_by_3(-3), div_by_3(30), div_by_3(8));
    //same_case function
    printf("%d ", same_case('a', 'f')); 
    printf("%d ", same_case('L', 'g')); 
    printf("%d\n", same_case('#', 'P'));
    //string_to_upper function
    char text[] = "ahoj";
    string_to_upper(text);
    printf("%s\n", text);
    //find_first_A function
    printf("%d\n", find_first_A("Tomorrow afternoon"));
    printf("%d\n", find_first_A("No 'A' here!"));      
    printf("%d\n", find_first_A(NULL));                 
    printf("%d\n", find_first_A("abc"));
    // is_prime function
    printf("%d %d\n", is_prime(49), is_prime(31));


    return 0;
}