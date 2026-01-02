// Andre Mayard, crossword.c
//

#include "funcword.h"

int main(int argc, char *argv[]) {

	int count = 0;	
	wordDetails wordArray[MAX_WORDS]; 
	char sampleArray[WORD_SIZE][WORD_SIZE];
	createBoard(sampleArray);




	if (argc == 1) {
		count = playActive(wordArray);
		
		if (count != -1) {
			printf("\nAnagram Crossword Puzzle Generator\n");
			printf("----------------------------------\n\n");
			sortWords(wordArray, count);
			printf("\n\n");
			solveIt(wordArray, count, sampleArray);
			solDisplay(sampleArray);
			puzzDisplay(sampleArray);
			clueDisplay(wordArray, count);
		}
	} else if (argc == 2) {
		//outputOnly();
		count = readFile(argv[1], wordArray); 
		if (count != -1) {
			printf("\nAnagram Crossword Puzzle Generator\n");
			printf("----------------------------------\n\n");
			sortWords(wordArray, count);
			printf("\n\n");
			solveIt(wordArray, count, sampleArray);
			solDisplay(sampleArray);
			puzzDisplay(sampleArray);
			clueDisplay(wordArray, count);
			
		}
	} else if (argc == 3) {
		FILE *fp;
		count = readWrite(argv[1], wordArray);
		if (count != -1) {
			sortWords(wordArray, count);
			fsolveIt(fp, argv[2], wordArray, count, sampleArray);
			fsolDisplay(fp, argv[2], sampleArray);
			fpuzzDisplay(fp, argv[2], sampleArray);
			fclueDisplay(fp, argv[2], wordArray, count);
		}
	} else {
		printf("Too many, sorry\n");
		return 1;
	}






	return 0;
}


