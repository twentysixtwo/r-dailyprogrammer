#include <stdio.h> //printf
#include <stdlib.h> //atoi

/*
Challenge 123 (Easy) Sum Them Digits

Digital root of the number

Input - A positive integer, possibly 0
Output - An integer between 0 and 9, the digital root of the number

Sample
Input - 31337
Output - 8, because 3+1+3+3+7=17 and 1+7=8

Challenge
1073741824

No sanity checking on input arguments
*/
int digitalSum(int input) {
	int sum = 0;

	while (input>9) {
		sum += input%10;
		input /= 10;
	}
	sum += input;

	if (sum>9) {
		return digitalSum(sum);
	} else
		return sum;
}

int main(int argc, char** argv) {
	if(argc<2) return printf("Usage : %s [Number]\n", argv[0]);
		
	for (int i=1; i<argc; i++) {
		int input = atoi(argv[i]);
		printf("Digital sum of %d = %d\n", input, digitalSum(input));
	}
	return 0;
}
