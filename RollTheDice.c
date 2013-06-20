#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* 
Given string NdM 
N - Positive integer, number of dies to roll (1 - 100 inclusive)
M - Positive integer >=2, number of faces on the die (2 - 100 inclusive)

Ex. 2d20, roll 20 sided die 2 times.  
*/

int main(void) {
	int n, numRolls, numSides;
	char d, newLine;
	
	while(1) {
		printf("Input : ");

		//no input sanity checking
		n = scanf("%d%c%d%c",&numRolls,&d,&numSides,&newLine);

		if((tolower(d) == 'd') && (numRolls >= 1) && (numRolls <= 100) && (numSides >= 2) && (numSides <=100)) {
			//printf("read: %d%c%d\n",numRolls,d,numSides);
			
			srand(time(NULL));
			for (int x = 0; x<numRolls; x++) {
				printf("%d ", rand() % numSides +1);
			}
			printf("\n");
		}
		else printf("Bad input format. Read : %d%c%d%c\n",numRolls,d,numSides,newLine);
	}
	return 0;
}
