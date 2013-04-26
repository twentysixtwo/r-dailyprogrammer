/*
Challenge 122 (Easy) Words with Ordered Vowels

Find words in a word list that contain all the vowels in alphabetical order,
non-repeated, where vowels are defined as A E I O U Y

Input - A text file with one word on each line.
Output - All words in the list that contains all the vowels A E I O U Y in alphabetical order.

Sample 
Input - Use word list
Output - abstemiously ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int isVowel(char ch) {
	switch(ch) {
		case 'a': return 1;
		break;
		case 'e': return 2;
		break;
		case 'i': return 3;
		break;
		case 'o': return 4;
		break;
		case 'u': return 5;
		break;
		case 'y': return 6;
		break;
		default: return -1;
	}
}

int err_exit(int code,char** argv) {	
	switch(code) {
		case 1: 
			printf("Expected one argument of text file.\nUsage: %s [Text file]\n",argv[0]);
			exit(1);
		break;
		case 2:
			printf("Expected readable text file.\nUsage: %s [Text file]\n",argv[0]);
			exit(1);
		default: 
			printf("Usage: %s [Text file]\n",argv[0]);
			exit(1);
		break;
	}
	exit(1);
}

int main(int argc, char** argv) {
	//Expect one input of a text file, Test with stat
	if (argc != 2) { err_exit(1,argv); }	
	FILE *fp;
	//Open file. Read line (One word). Check isVowel >0 && ==lastVowel+1
	fp = fopen(argv[1],"r");
	if (fp != NULL) {
		int lastVowel;
		char ch[256];
		char lastWord[256];
		while(fscanf(fp,"%s",ch)!=EOF) {
			lastVowel = 0;
			int i = 0;
			if(strcmp(lastWord,ch)==0) { goto end; }	
			strcpy(lastWord,ch);
			while(ch[i]!=NULL) {
				int thisChar = isVowel(ch[i]);
				if (thisChar > 0) { //if thisChar is a vowel, it must be lastVowel+1 otherwise next word.
					if (thisChar == lastVowel+1) {
						lastVowel = thisChar;
					} else { break; }
				}
				i++;
			}
			if(lastVowel == 6) {
				printf("%s ",ch);
			}
		}
	end:
	fclose(fp);
	printf("\n");
	} else { err_exit(2,argv); }
		
	return 0;	
}
