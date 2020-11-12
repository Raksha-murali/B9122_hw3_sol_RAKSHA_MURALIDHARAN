// Homework 3 Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>]
#include <stdio.h>
#include <String>
using namespace std;
#define SIZE 20

// This function takes a string as an input and has variables for each of the 
// vowels and initialised it to zero. Then using a for loop, I go character by
// character to determine if it is an upper case or lower case vowel and update the
// counter. It is finally called in the main function where the vowel counter is 
// printed. If the user inputs a string with less than 20 characters, an error will
// appear.

int* vowelcounter(string str){
	int i, count_a, count_e, count_i, count_o, count_u;
	
	count_a = 0;
	count_e = 0;
	count_i = 0;
	count_o = 0;
	count_u = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (str[i] == 'a' || str[i] == 'A')
			count_a++;
		else if (str[i] == 'e' || str[i] == 'E')
			count_e++;
		else if (str[i] == 'i' || str[i] == 'I')
			count_i++;
		else if (str[i] == 'o' || str[i] == 'O')
			count_o++;
		else if (str[i] == 'u' || str[i] == 'U')
			count_u++;
	}

	int* vowels;
	vowels = (int*)malloc(sizeof(int) * 5);

	vowels[0] = count_a;
	vowels[1] = count_e;
	vowels[2] = count_i;
	vowels[3] = count_o;
	vowels[4] = count_u;


	return vowels;

}


int main()
{	
	int* array;
	char str[SIZE];
	printf("Type in the required string: ");
	fgets(str, SIZE, stdin);
	
	array = vowelcounter(str);
	printf("\nThe number of A's is %d", array[0]);
	printf("\nThe number of E's is %d", array[1]);
	printf("\nThe number of I's is %d", array[2]);
	printf("\nThe number of O's is %d", array[3]);
	printf("\nThe number of U's is %d", array[4]);



	
	return 0;
}
	
