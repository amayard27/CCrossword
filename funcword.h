#include <stdio.h>
#include <stdlib.h> //Andre Mayard, funcword.h, for calling libraries and prototypes
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define WORD_SIZE 15
#define MAX_WORDS 20


typedef struct {

	char word[WORD_SIZE + 1]; // 16 for null
	char orientation;
	bool solved;
	int length;
	int row; // for horizontal this would be which row it's in, for vertical it would be where it starts
	int col; // for vertical this would be which column it is in, for horizontal it would be where it starts	

} wordDetails;


char* scrambleWord(char [WORD_SIZE]);
void clueDisplay(wordDetails [MAX_WORDS], int);
void createBoard(char [][WORD_SIZE]);
int playActive(wordDetails [MAX_WORDS]);
char* upper(char [WORD_SIZE]);
void sortWords(wordDetails [MAX_WORDS], int);
int check(char [WORD_SIZE], int);
void solDisplay(char [][WORD_SIZE]);
void puzzDisplay(char [][WORD_SIZE]); 
int readFile(char *, wordDetails [MAX_WORDS]);
int readWrite(char *, wordDetails [MAX_WORDS]);
void solveIt(wordDetails [MAX_WORDS], int, char [][WORD_SIZE]);
bool incommon(char [], char[]);
bool neighbors(char [][WORD_SIZE], wordDetails, wordDetails, int);

void fsolDisplay(FILE *, char *, char [][WORD_SIZE]);
void fpuzzDisplay(FILE *, char *, char [][WORD_SIZE]); 
void fclueDisplay(FILE *, char *, wordDetails [MAX_WORDS], int);
void fsolveIt(FILE *, char *, wordDetails [MAX_WORDS], int, char [][WORD_SIZE]);
