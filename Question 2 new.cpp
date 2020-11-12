// Question 2 new.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This function takes an array size and a character array as input, reallocates the memory 
// associated with the length of the array (default was set to 50 in main) and assings the 
// characters in the input array to a new array. (The question was a bit strange so I am assuming
// this is what I am meant to do). Each character array must end in \0 so that is the final element
// of the new array.
// This function is then called in main after asking the user to input the three strings 

char* create_char_array(int array_size, char str[]) {
    char* result;
    result = (char*)malloc(1 * sizeof(char));

    int i;
    for (i = 0; i < array_size; i++) {
        result[i] = str[i];
        realloc(result, (i + 1) * sizeof(char));
    }

    result[i] = '\0';
    return result;
}

int main() {
    int lengths[3];
    char str_1[50], str_2[50], str_3[50];

    char* result1, * result2, * result3;

    printf("Enter the first string: ");
    fgets(str_1, 50, stdin);
    lengths[0] = strlen(str_1);

    printf("Enter the second string: ");
    fgets(str_2, 50, stdin);
    lengths[1] = strlen(str_2);

    printf("Enter the third string: ");
    fgets(str_3, 50, stdin);
    lengths[2] = strlen(str_3);

    result1 = create_char_array(lengths[0], str_1);
    result2 = create_char_array(lengths[1], str_2);
    result3 = create_char_array(lengths[2], str_3);

    return 0;
}