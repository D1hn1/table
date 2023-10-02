#include <iostream>
#include <vector>
#include <string.h>

char CORNER = '+';
char ROOF 	= '-';
char FLOOR 	= '-';
char WALL 	= '|';
char SPACE 	= ' ';

int NUM_LIST = 0;
std::vector<char*> lista = {};

int findLargestWord ( int numArgs, char *argv[] )
{
	int finalNum = 0;
	for ( int x = 1; x < numArgs; x++ ) {
		int actualLen = strlen(argv[x]);

		if ( actualLen > finalNum ) {
			finalNum = actualLen;
		};
	};
	return finalNum;
}

int findNumOfComas ( int numArgs, char *argv[] )
{
	int num = 1;
	for ( int x = 1; x < numArgs; x++ ) {
		int sizeWord = strlen(argv[x]);
		for ( int y = 0; y < sizeWord; y++ ) {
			if ( argv[x][y] == ',' ) {
				num++;
			};
		};
	};

	return num;
}

int wordsUntilFirstComa ( int numArgs, char* argv[] )
{
	int num = 0;
	for ( int x = 1; x < numArgs; x++ ) {
		int sizeWord = strlen(argv[x]);
		for ( int y = 0; y < sizeWord; y++ ) {
			if ( argv[x][y] == ',' ) {
				return num;
			};
		};
		num++;
	};
	return 1;
}

void createRoof ( int numArguments, int sizeOfBiggestWord, char* argv[] )
{
	for ( int x = 0; x < wordsUntilFirstComa(numArguments, argv); x++ ) {
		std::cout << CORNER;

		for ( int y = 0; y < sizeOfBiggestWord; y++ ) {
			std::cout << ROOF;
		};

	};
	std::cout << CORNER << std::endl;
}

void constructWords ( int numArg, char* argv[] )
{
	bool to_append = false;
	for ( int x = 1; x < numArg; x++ ) {
		for ( int y = 0; y < strlen(argv[x]); y++ ) {
			if ( argv[x][y] != ',' ) {
				if ( y == 1 ) {
					to_append = true;
					break;
				};
			} else {
				to_append = false;
				break;
			};
		};
		if ( to_append ) {lista.push_back(argv[x]);};
	};
}

void createWalls ( int numArgs, char* argv[], int largestWord )
{
	for ( int x = 0; x < wordsUntilFirstComa(numArgs, argv); x++ ) {
		std::cout << WALL;

		std::cout << lista[NUM_LIST];
		NUM_LIST++;
		
		if ( strlen(lista[NUM_LIST-1]) != largestWord ) {
			for ( int y = 0; y < ( largestWord - strlen(lista[NUM_LIST - 1]) ); y++ ) {
				std::cout << SPACE;
			};
		};
	};
	std::cout << WALL;
}

void constructTable ( int numArgs, char* argv[] )
{
	int biggestWord = findLargestWord(numArgs, argv);
	int numOfComas	= findNumOfComas(numArgs, argv);

	for ( int z = 0; z < numOfComas; z++ ) {

		std::cout << std::endl;
		createRoof(numArgs, biggestWord, argv);
		createWalls(numArgs, argv, biggestWord);	

		if ( z == ( numOfComas - 1 ) ) {
			std::cout << std::endl;
			createRoof(numArgs, biggestWord, argv);
		};
	};
	
}

int main( int argc, char *argv[] )
{
	constructWords(argc, argv);
	constructTable(argc, argv);
	return 0;
}
