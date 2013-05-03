/* 
Challenge #111 [Easy] Star Delete
Write a function that, given a string, removes from the string any * char, or any char that's one to the left or right. 

Examples
adf*lp --> adp
a*o --> 
*dech* --> ec
de**po --> do
sa*n*ti --> si
abc --> abc
*/

#include <stdio.h>
#include <string.h>

void delStar(char str[]) {
	int len = strlen(str);
	for (int i=0; i<len; i++) {
		if((str[i+1]!='*') && (str[i-1]!='*') && (str[i]!='*')) printf("%c",str[i]);
	}
	printf("\n");	
}

int main(int argc, char** argv) {
	delStar(argv[1]);
	return 0;
}
