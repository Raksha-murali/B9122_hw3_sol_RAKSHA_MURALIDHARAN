// Question 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h> 

using namespace std;

// This function below takes a pointer to an array and the length of
// the array as inputs and through loops, calculates the mean and variance
// and returns an array pointer containing both. It is then called in the 
// main function and the output is saved in a text file called data_mv

double* compute_mv(double *pd, int len) {
	double sum = 0;
	for (int i = 0; i < len; i++) {
		sum += pd[i];
	}
	double mean = sum / len;

	double var_sum = 0;
	for (int j = 0; j < len; j++) {
		var_sum += pow((pd[j]-mean),2);
	}
	double variance = var_sum / len;

	double* array;
	array = (double*)malloc(sizeof(double) * 2);
	array[0] = mean;
	array[1] = variance;

	return array;
}


int main() 
{
	int size, i;
	double *arr1, *result;
	printf("Enter the size of the array: ");
	scanf_s("%d", &size);
	arr1 = (double*)malloc(sizeof(double) * size);


	for (int i=0; i < size; i++) {
		printf("Enter digit %d: ", i);
		scanf_s("%lf", &arr1[i]);
	}

	result = compute_mv(arr1,size);
	FILE* values = fopen("data_mv.txt", "w");
	fprintf(values, "Mean is %lf. \nVariance is %lf.", result[0], result[1]);
	fclose(values);
	return 0;
}

