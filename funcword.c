//Andre Mayard, funcword.c, for all of the function definitions

#include "funcword.h"


// creates the dotted board
// ////////////////////////////////////
void createBoard(char arr[][WORD_SIZE])
{
	for (int i = 0; i < WORD_SIZE; i++) {
		for (int j = 0; j < WORD_SIZE; j++) {
			arr[i][j] = '.';
		}
	}


}
// checks the input of the words
// /////////////////////////////////////
int check(char word[WORD_SIZE], int size)
{

	if (size == 1) return 0;
	for (int i = 0; i < size; i++) {
		if (!isalpha(word[i])) {
			return 0;
		}
	}



	return 1;
}

// solution displays
// ///////////////////////////////////
void solDisplay(char arr[][WORD_SIZE])
{
	printf("SOLUTION: \n");
	printf(" ");
	for (int j = 0; j < WORD_SIZE; j++) {
		printf("-");
	}
	printf("\n");

	for (int i = 0; i < WORD_SIZE; i++) {	
		for (int j = -1; j < WORD_SIZE + 1; j++) {	
			if (j == -1) {
				printf("|");
			} else if (j == WORD_SIZE) {
				printf("|\n");
			} else {
				printf("%c", arr[i][j]);
			}
		}
	}
	printf(" ");
	for (int x = 0; x < WORD_SIZE; x++) {
		printf("-");
	}
	printf("\n");

}

void fsolDisplay(FILE *fp, char *fileName, char arr[][WORD_SIZE])
{
	fp = fopen(fileName, "a");
	fprintf(fp, "SOLUTION: \n");
	fprintf(fp, " ");
	for (int j = 0; j < WORD_SIZE; j++) {
		fprintf(fp, "-");
	}
	fprintf(fp, "\n");

	for (int i = 0; i < WORD_SIZE; i++) {	
		for (int j = -1; j < WORD_SIZE + 1; j++) {	
			if (j == -1) {
				fprintf(fp, "|");
			} else if (j == WORD_SIZE) {
				fprintf(fp, "|\n");
			} else {
				fprintf(fp, "%c", arr[i][j]);
			}
		}
	}
	fprintf(fp, " ");
	for (int x = 0; x < WORD_SIZE; x++) {
		fprintf(fp, "-");
	}
	fprintf(fp, "\n");
	fclose(fp);
}


////////////////////////////////// puzzle displays
void puzzDisplay(char arr[][WORD_SIZE])
{

	printf("PUZZLE: \n");
	printf(" ");
	for (int j = 0; j < WORD_SIZE; j++) {
		printf("-");
	}
	printf("\n");

	for (int i = 0; i < WORD_SIZE; i++) {	
		for (int j = -1; j < WORD_SIZE + 1; j++) {	
			if (j == -1) {
				printf("|");
			} else if (j == WORD_SIZE) {
				printf("|\n");
			} else if (isalpha(arr[i][j])) {
				printf(" ");
			} else {
				printf("#");
			}
		}
	}
	printf(" ");
	for (int x = 0; x < WORD_SIZE; x++) {
		printf("-");
	}
	printf("\n");





}


void fpuzzDisplay( FILE *fp, char *fileName, char arr[][WORD_SIZE])
{
	fp = fopen(fileName, "a");
	fprintf(fp, "PUZZLE: \n");
	fprintf(fp, " ");
	for (int j = 0; j < WORD_SIZE; j++) {
		fprintf(fp, "-");
	}
	fprintf(fp, "\n");

	for (int i = 0; i < WORD_SIZE; i++) {	
		for (int j = -1; j < WORD_SIZE + 1; j++) {	
			if (j == -1) {
				fprintf(fp, "|");
			} else if (j == WORD_SIZE) {
				fprintf(fp, "|\n");
			} else if (isalpha(arr[i][j])) {
				fprintf(fp, " ");
			} else {
				fprintf(fp, "#");
			}
		}
	}
	fprintf(fp, " ");
	for (int x = 0; x < WORD_SIZE; x++) {
		fprintf(fp, "-");
	}
	fprintf(fp, "\n");
	fclose(fp);
}






//////////////////////////////////////////// clue displays
void clueDisplay(wordDetails wordArray[MAX_WORDS], int size)
{

	srand(time(NULL));
	printf("\n\nCLUES:\n");
	printf("Location | Direction | Anagram\n");
	
	for (int i = 0; i < size; i++) {
		char direction[10];
		if (wordArray[i].orientation == 'h') {
			strcpy(direction, "Across");
		} else {
			strcpy(direction, "Down");
		}
		if (wordArray[i].solved) {
			printf("%5d,%2d | %9s | %s\n", wordArray[i].row, wordArray[i].col, direction, scrambleWord(wordArray[i].word));
		}
	}





}

void fclueDisplay(FILE *fp, char *fileName, wordDetails wordArray[MAX_WORDS], int size)
{
	fp = fopen(fileName, "a");
	srand(time(NULL));
	fprintf(fp, "\n\nCLUES:\n");
	fprintf(fp, "Location | Direction | Anagram\n");
	
	for (int i = 0; i < size; i++) {
		char direction[10];
		if (wordArray[i].orientation == 'h') {
			strcpy(direction, "Across");
		} else {
			strcpy(direction, "Down");
		}
		if (wordArray[i].solved) {
			fprintf(fp, "%5d,%2d | %9s | %s\n", wordArray[i].row, wordArray[i].col, direction, scrambleWord(wordArray[i].word));
		}
	}


	fclose(fp);


}

/////////////////////// scrambles a word
char* scrambleWord( char word[WORD_SIZE])
{

	int wordLen = strlen(word);
	for (int i = 0; i < wordLen; i++) {
		int j = rand() % wordLen;
		char temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	}
	


	return word;

}



// converts a given word to the uppercase of that word
// //////////////////////////////////////////
char* upper(char givenWord[WORD_SIZE])
{
	int length;
	length = strlen(givenWord);


	for (int i = 0; i < length; i++) {
		if (islower(givenWord[i])) {
			givenWord[i] = toupper(givenWord[i]);
		}
	}


	return givenWord;

}

int readWrite(char *fileIn, wordDetails wordArray[MAX_WORDS])
{
	FILE *fp1 = fopen(fileIn, "r");

	if (fp1 == NULL) {
		printf("Sorry, the file could not be opened.\n");
		return -1;
	}

	char wordAttempt[1000];
	int count = 0;
	int checker;

	while (count < MAX_WORDS) {
		fscanf(fp1, " %s", wordAttempt);
		if (feof(fp1)) break;
		checker = check(wordAttempt, strlen(wordAttempt));
	
		if (strcmp(wordAttempt, ".") == 0) {

			return count;
		} else if ((strlen(wordAttempt) <= WORD_SIZE) && checker != 0) {
			strcpy(wordAttempt,upper(wordAttempt));
			strcpy(wordArray[count].word, wordAttempt);
			wordArray[count].length = strlen(wordAttempt);
			count++;
			if (count == MAX_WORDS) return count;
		}
	}
	fclose(fp1);
		 
}



// for reading the file and making a puzzle based off the words in the file
// //////////////////////////////////////////////////////////////
int readFile(char *filename, wordDetails wordArray[MAX_WORDS])
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Sorry, the file could not be opened.\n");
		return -1; // no count will be less than 0, to use in the main function
	}

	char wordAttempt[1000];
	int count = 0;
	int checker;

	while (count < MAX_WORDS) {
		fscanf(fp, " %s", wordAttempt); // scans the file word attempt
		if (feof(fp)) break;
		checker = check(wordAttempt, strlen(wordAttempt));
		
		if (strcmp(wordAttempt,".") == 0) { // compares string
		
			return count;			

		} else if ((strlen(wordAttempt) > WORD_SIZE) || checker == 0) {
			printf("Sorry but a word, %s, has encountered a problem (word size or non-alpha character)\n", wordAttempt);
		} else {
			strcpy(wordAttempt,upper(wordAttempt));
			strcpy(wordArray[count].word, wordAttempt);
			wordArray[count].length = strlen(wordAttempt);
			count++;
			if (count == MAX_WORDS) return count;
		}
	}
	
// function returns the count of words


}


 ///////////////////////////////////////////
int playActive(wordDetails wordArray[MAX_WORDS])
{
	char wordAttempt[1000]; // for if they input a word that is larger than what is supposed to, it doesn't store memory where it can't
	int count = 0;
	int checker;

	
	printf("Enter the words for the crossword followed by a \".\"\n");
	while (count < MAX_WORDS) {
		
		scanf(" %s", wordAttempt);
		checker = check(wordAttempt, strlen(wordAttempt)); // gives a number more than 0 if it is not valid

		if (wordAttempt[0] == '.') {
			if (count == 0) return -1;
			return count;
		} else if ((strlen(wordAttempt) > WORD_SIZE) || (checker == 0)) {
			
			printf("Sorry but that word, %s, has encountered a problem (word size or non-alpha characters)\n", wordAttempt);
		} else {
			strcpy(wordAttempt,upper(wordAttempt));
			strcpy(wordArray[count].word, wordAttempt);
			wordArray[count].length = strlen(wordAttempt);
			count++;
			if (count == MAX_WORDS) return count;
	
		}
	}

}


// for checking if there are neighbors
//////////////////////////////////////////////////
bool neighbors(char arr[][WORD_SIZE], wordDetails word1, wordDetails word2, int thing2)
{


	int count = 0;
	int count2 = 0;


	if (word1.orientation == 'h') {


		for (int i = word2.col - thing2; i < word1.length + word2.col - thing2; i++) {
			if (arr[word1.row][i] == word1.word[count]) count2++;
			if (i != word2.col && (arr[word1.row][i] != word1.word[count])) {

				if (i == word2.col - thing2) { // if at first index and horizontal, check above, below, and to to left

					if (isalpha(arr[word1.row][i]) || (isalpha(arr[word1.row+1][i])) || (isalpha(arr[word1.row-1][i])) || (isalpha(arr[word1.row][word1.col-1]))) {

						return true;

					}	

				} else if (i == word1.length + word2.col - thing2 - 1) { // if at last index and horizontal, check above, below, and to the right


					if (isalpha(arr[word1.row][i]) || (isalpha(arr[word1.row+1][i])) || (isalpha(arr[word1.row-1][i])) || (isalpha(arr[word1.row][i+1]))) {

						return true;

					}

	
				} else { // checks above and below


					if (isalpha(arr[word1.row][i]) || (isalpha(arr[word1.row+1][i])) || (isalpha(arr[word1.row-1][i]))) {

						return true;


					}

				}

			}

			count++;

		}


	} else if (word1.orientation == 'v') {


		for (int j = word2.row - thing2; j < word1.length + word2.row - thing2; j++){

			if (arr[j][word1.col] == word1.word[count]) count2++;
			if (j != word2.row && (arr[j][word1.col] != word1.word[count])) {


				if (j == word2.row - thing2) { // if it is at the first index and is vertical, check above and to the right and left


					if (isalpha(arr[j][word1.col]) || (isalpha(arr[j][word1.col+1])) || (isalpha(arr[j][word1.col-1])) || (isalpha(arr[j-1][word1.col]))) {

						return true;

					}

				} else if (j == word1.length + word2.row - thing2 - 1) { // if it is the last index and is vertical, check below and right and left


					if (isalpha(arr[j][word1.col]) || (isalpha(arr[j][word1.col+1])) || (isalpha(arr[j][word1.col-1])) || (isalpha(arr[j+1][word1.col]))) {

						return true;

					}


				} else { // checks left and right


					if (isalpha(arr[j][word1.col]) || (isalpha(arr[j][word1.col+1])) || (isalpha(arr[j][word1.col-1]))) {


						return true;

					}
				}
			}
			count++; // keep counting in the for loop for the index
		}
	}


	if (count2 == strlen(word1.word)) return true;
	return false;


}
					



// solves the puzzle
//////////////////////////////////////////////////
void solveIt(wordDetails wordArray[MAX_WORDS], int count, char arr[][WORD_SIZE])
{
	// wordArray for the words, count to go through a loop for each word, board array to place words
	//
	
	
	int diff = WORD_SIZE - wordArray[0].length;

	// setting elements of the  first word	
	wordArray[0].orientation = 'h';
	wordArray[0].row = 7;
	char *p = wordArray[0].word;
	

	// placing the first word in the middle
	for (int i = 0; i < WORD_SIZE; i++) {  
		if (i >= diff/2 && i < wordArray[0].length + diff/2) {
			if (i == diff/2) wordArray[0].col = i;
			arr[7][i] = *p;
			p++;
		}
	}
	
	


	// for all other words to place
	int ind = 1;
	int match1, match2;
	int count2 = 0;
	int check = 0;



	// for all other words not designated a place, we find one
	while (ind < count) {

		wordArray[ind].solved = false;


		for (int i = 0; i < ind; i++) {


			check = 0;
		
			
			if (incommon(wordArray[ind].word, wordArray[i].word) && !wordArray[ind].solved) {
			
				if (wordArray[i].orientation == 'h') {
			

					// check column it starts in, length
					for (int col = wordArray[i].col; col < wordArray[i].length + wordArray[i].col; col++) {
					

						for (int k = 0; k < wordArray[ind].length; k++) {
					
							if (wordArray[ind].word[k] == arr[wordArray[i].row][col]) {
					

								match1 = col; // this is the column that is constant no matter what
								match2 = k; // this is where in the word that is being placed the match of the two words is
								wordArray[ind].col = match1;
					

								// checking boundaries
								if ((wordArray[i].row - match2 >= 0) && (wordArray[ind].length + wordArray[i].row - match2 < WORD_SIZE) && !wordArray[ind].solved) {

									// setting the row and orientation of the word to be placed
									wordArray[ind].row = wordArray[i].row - match2;
									wordArray[ind].orientation = 'v';

									// if there is no neighbors, run another statement
									if (!neighbors(arr, wordArray[ind], wordArray[i], match2)) {


										count2 = 0; // setting the count to be 0 when not in the for loop so it is able to go through
												
										for (int row = wordArray[i].row - match2; row < wordArray[ind].length + wordArray[i].row - match2; row++) {
							
											arr[row][match1] = wordArray[ind].word[count2];
											count2++;




										}
					
										wordArray[ind].solved = true;
										check = 1;
										break;
									} else {
										wordArray[ind].solved = false;
									}
								} else {
									wordArray[ind].solved = false;
								}
							}
						}
						if (check) break;	
					}

					

				} else if (wordArray[i].orientation == 'v') {
					// check row it starts in, length
					for (int row = wordArray[i].row; row < wordArray[i].length + wordArray[i].row; row++) {

						// for indexing the array
						for (int k = 0; k < wordArray[ind].length; k++) {

							
							if (wordArray[ind].word[k] == arr[row][wordArray[i].col]) {


								match1 = row; // this is where the row will be 
								match2 = k; // where in the word that is about to be placed that the match is
								wordArray[ind].row = match1;


								// checking boundaries
								if ((wordArray[i].col - match2 >= 0) && (wordArray[ind].length + wordArray[i].col - match2 < WORD_SIZE) && !wordArray[ind].solved) {
										

									// setting column of first letter and orientation
									wordArray[ind].col = wordArray[i].col - match2;
									wordArray[ind].orientation = 'h';

									// checking if there are neighbors
									if (!neighbors(arr, wordArray[ind], wordArray[i], match2)) {


										count2 = 0; // for loop needs count to be 0

										for (int col = wordArray[i].col - match2; col < wordArray[ind].length + wordArray[i].col - match2; col++) {
												

											arr[match1][col] = wordArray[ind].word[count2];
											count2++;
										}
				
										wordArray[ind].solved = true;
										check = 1;
										break;
									} else {
										wordArray[ind].solved = false;
									}
								} else {
									wordArray[ind].solved = false;
								
								 
								}		
							}
						}
						if (check) break;
						
					}

					
					
				}
		
			}		
		}
		if (!wordArray[ind].solved) printf("%s was skipped\n\n", wordArray[ind].word);
		ind++;
			
	}



}

void fsolveIt(FILE *fp, char *fileName, wordDetails wordArray[MAX_WORDS], int count, char arr[][WORD_SIZE])
{
	// wordArray for the words, count to go through a loop for each word, board array to place words
	//
	fp = fopen(fileName, "a");
	
	int diff = WORD_SIZE - wordArray[0].length;

	// setting elements of the  first word	
	wordArray[0].orientation = 'h';
	wordArray[0].row = 7;
	char *p = wordArray[0].word;
	

	// placing the first word in the middle
	for (int i = 0; i < WORD_SIZE; i++) {  
		if (i >= diff/2 && i < wordArray[0].length + diff/2) {
			if (i == diff/2) wordArray[0].col = i;
			arr[7][i] = *p;
			p++;
		}
	}
	
	


	// for all other words to place
	int ind = 1;
	int match1, match2;
	int count2 = 0;
	int check = 0;



	// for all other words not designated a place, we find one
	while (ind < count) {

		wordArray[ind].solved = false;


		for (int i = 0; i < ind; i++) {


			check = 0;
		
			
			if (incommon(wordArray[ind].word, wordArray[i].word) && !wordArray[ind].solved) {
			
				if (wordArray[i].orientation == 'h') {
			

					// check column it starts in, length
					for (int col = wordArray[i].col; col < wordArray[i].length + wordArray[i].col; col++) {
					

						for (int k = 0; k < wordArray[ind].length; k++) {
					
							if (wordArray[ind].word[k] == arr[wordArray[i].row][col]) {
					

								match1 = col; // this is the column that is constant no matter what
								match2 = k; // this is where in the word that is being placed the match of the two words is
								wordArray[ind].col = match1;
					

								// checking boundaries
								if ((wordArray[i].row - match2 >= 0) && (wordArray[ind].length + wordArray[i].row - match2 < WORD_SIZE) && !wordArray[ind].solved) {

									// setting the row and orientation of the word to be placed
									wordArray[ind].row = wordArray[i].row - match2;
									wordArray[ind].orientation = 'v';

									// if there is no neighbors, run another statement
									if (!neighbors(arr, wordArray[ind], wordArray[i], match2)) {


										count2 = 0; // setting the count to be 0 when not in the for loop so it is able to go through
												
										for (int row = wordArray[i].row - match2; row < wordArray[ind].length + wordArray[i].row - match2; row++) {
							
											arr[row][match1] = wordArray[ind].word[count2];
											count2++;




										}
					
										wordArray[ind].solved = true;
										check = 1;
										break;
									} else {
										wordArray[ind].solved = false;
									}
								} else {
									wordArray[ind].solved = false;
								}
							}
						}
						if (check) break;	
					}

					

				} else if (wordArray[i].orientation == 'v') {
					// check row it starts in, length
					for (int row = wordArray[i].row; row < wordArray[i].length + wordArray[i].row; row++) {

						// for indexing the array
						for (int k = 0; k < wordArray[ind].length; k++) {

							
							if (wordArray[ind].word[k] == arr[row][wordArray[i].col]) {


								match1 = row; // this is where the row will be 
								match2 = k; // where in the word that is about to be placed that the match is
								wordArray[ind].row = match1;


								// checking boundaries
								if ((wordArray[i].col - match2 >= 0) && (wordArray[ind].length + wordArray[i].col - match2 < WORD_SIZE) && !wordArray[ind].solved) {
										

									// setting column of first letter and orientation
									wordArray[ind].col = wordArray[i].col - match2;
									wordArray[ind].orientation = 'h';

									// checking if there are neighbors
									if (!neighbors(arr, wordArray[ind], wordArray[i], match2)) {


										count2 = 0; // for loop needs count to be 0

										for (int col = wordArray[i].col - match2; col < wordArray[ind].length + wordArray[i].col - match2; col++) {
												

											arr[match1][col] = wordArray[ind].word[count2];
											count2++;
										}
				
										wordArray[ind].solved = true;
										check = 1;
										break;
									} else {
										wordArray[ind].solved = false;
									}
								} else {
									wordArray[ind].solved = false;
								
								 
								}		
							}
						}
						if (check) break;
						
					}

					
					
				}
		
			}		
		}
		if (!wordArray[ind].solved) fprintf(fp, "%s was skipped\n\n", wordArray[ind].word);
		ind++;
			
	}


	fclose(fp);
}







// incommon function from exam 1
// ////////////////////////////////
bool incommon(char s1[], char s2[])
{
	int i = 0;
	int j = 0;

	while (s1[i] != '\0') {
		j = 0;
		while (s2[j] != '\0') {
			if (s1[i] == s2[j]) {
				return true;
			}
			j++;
		}
		i++;
	}



	return false;

}







// bubble sorting words
// ////////////////////////////////////////////////////////
void sortWords(wordDetails wordArray[MAX_WORDS], int count)
{

	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (wordArray[i].length < wordArray[j].length) {
				wordDetails tempWord = wordArray[i];
				wordArray[i] = wordArray[j];
				wordArray[j] = tempWord;
			}
		}
	}	

	

}

