#include <iostream>
void printArray(int array1[][9]);
void placeNumber(int num);
bool checkRow(int number, int i, int j);
bool checkColumn(int number,int i, int j);
int num;
int i, j, k, l, addRow, addCol, row, column, puzzleChoice;
int puzzleArray[9][9] = { {0,0,7, 0,0,9, 0,0,1} ,
						{9,3,0, 5,0,0, 0,4,0} ,
						{2,5,4, 0,0,0, 0,0,0} ,

						{0,1,0, 0,8,7, 0,2,3} ,
						{7,0,0, 0,0,0, 0,0,8} ,
						{4,8,0, 6,1,0, 0,7,0} ,

						{0,0,0, 0,0,0, 1,5,7} ,
						{0,9,0, 0,0,5, 0,6,2} ,
						{5,0,0, 2,0,0, 8,0,0 } };

int puzzleArray1[9][9]={{ 0,3,4, 8,0,0, 0,0,1 } ,
						{ 0,0,2, 0,9,0, 0,0,0 } ,
						{ 6,8,0, 0,0,0, 0,0,9 } ,

						{ 0,0,3, 4,0,7, 0,9,8 } ,
						{ 0,6,5, 9,1,8, 3,4,0 } ,
						{ 8,4,0, 5,0,2, 7,0,0 } ,

						{ 2,0,0, 0,0,0, 0,6,4 } ,
						{ 0,0,0, 0,4,0, 1,0,0 } ,
						{ 4,0,0, 0,0,1, 8,7,0 } };

int puzzleArray2[9][9] = {  { 9,0,0, 1,0,0, 0,0,0 } ,
							{ 7,0,2, 8,0,4, 3,0,0 } ,
							{ 0,0,4, 0,5,0, 0,0,7 } ,

							{ 5,4,9, 0,0,3, 8,7,0 } ,
							{ 0,2,0, 0,8,0, 0,3,0 } ,
							{ 0,7,8, 5,0,0, 1,2,4 } ,

							{ 1,0,0, 0,2,0, 9,0,0 } ,
							{ 0,0,6, 7,0,5, 2,0,8 } ,
							{ 0,0,0, 0,0,1, 0,0,5 } };

int puzzleArray3[9][9] = {  { 0,0,0, 0,1,0, 2,5,0 } ,
							{ 0,8,1, 5,0,2, 0,0,9 } ,
							{ 6,5,2, 0,0,0, 0,3,0 } ,

							{ 0,0,0, 3,0,0, 9,0,6 } ,
							{ 5,0,0, 1,9,8, 0,0,2 } ,
							{ 3,0,8, 0,0,6, 0,0,0 } ,

							{ 0,1,0, 0,0,0, 4,7,3 } ,
							{ 8,0,0, 7,0,3, 6,2,0 } ,
							{ 0,6,3, 0,4,0, 0,0,0 } };

int puzzleArray4[9][9] = {  { 0,0,7, 8,0,9, 0,0,1 } ,
							{ 9,0,0, 4,1,0, 0,3,0 } ,
							{ 0,1,4, 0,5,0, 8,0,0 } ,

							{ 4,0,0, 0,0,0, 0,8,3 } ,
							{ 0,0,0, 3,2,7, 0,0,0 } ,
							{ 7,5,0, 0,0,0, 0,0,2 } ,

							{ 0,0,2, 0,3,0, 6,4,0 } ,
							{ 0,6,0, 0,7,4, 0,0,5 } ,
							{ 3,0,0, 6,0,1, 2,0,0 } };
int puzzle[9][9];

int main()
{
	begin:
std::cout << "Enter number 1-5 to choose a puzzle: ";
std::cin >> puzzleChoice;
switch (puzzleChoice)
{
case 1:		memcpy(puzzle, puzzleArray, sizeof(puzzle)); break;
case 2:		memcpy(puzzle, puzzleArray1, sizeof(puzzle)); break;
case 3:		memcpy(puzzle, puzzleArray2, sizeof(puzzle)); break;
case 4:		memcpy(puzzle, puzzleArray3, sizeof(puzzle)); break;
case 5:		memcpy(puzzle, puzzleArray4, sizeof(puzzle)); break;
}
	std::cout << "Input puzzle: " << std::endl;
	printArray(puzzle);
	addRow = 0;
	addCol = 0;
	for (l = 1; l < 10; l++)//loop through cubes
	{
		if (l == 4 || l == 7)
		{
			addRow = addRow + 3;
			addCol = 0;
		}
		if (l != 1 && l != 4 && l != 7)
		{
			addCol = addCol + 3;//add 3 to col number
		}
		//Inner loop for each block of numbers
		for (k = 1; k < 10; k++)
		{//check block for numbers 1-9
			//int numcount = 1;
			bool numExists = false;
			for (i = 0; i < 3; i++)//loop through the first 3 colums of the block
			{
				for (j = 0; j < 3; j++)
				{//loop through the first 3 rows
					if (puzzle[i+addCol][j+addRow] == k)
					{
						numExists = true;
						break;
					}//if exists go to next number
				}
			}
			if (!numExists)
			{
				placeNumber(k);
			}
		}
	}
	std::cout << "Puzzle solution: " << std::endl;
	printArray(puzzle);
	goto begin;
	return 0;
}
void printArray(int array1[][9])
{
	for (int i = 0; i < 9; i++)
	{
		std::cout << "\n";
		if (i % 3 == 0) std::cout << "---------------------\n";
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0) std::cout << "|";
			std::cout << " " << array1[i][j];
		}
		std::cout << "|";
	}
	std::cout << "\n---------------------\n";
	std::cout << "Enter any character to continue";
	char c;
	std::cin >>c;//pauses program
}

void placeNumber(int number)
{//need to check entire row and column for the number
	bool noneInRow = false;
	bool noneInColumn = false;

	
	for (int i = 0 + addRow; i < 3 + addRow; i++)//loop through the first 3 colums
	{
	
		for (int j = 0 + addCol; j < 3 + addCol; j++)
		{
			//std::cout << "i = " << i << "j = " << j << std::endl;
			if (puzzle[i][j] == 0 && checkRow(number, i, j) && checkColumn(number, i, j))
			{				
				puzzle[i][j] = number;
				goto end;
			}
		}
	}	
end:
	return ;
}

bool checkRow(int number, int row, int col)
{
	bool numberNotInRow = true;
	for (int i = 0; i < 9; i++) 
	{
		if (puzzle[row][i] == number)
		{
			numberNotInRow = false;
		}
	}
	return numberNotInRow;
}

bool checkColumn(int number, int row, int col)
{
	bool numberNotInColumn = true;
	for (int i = 0; i < 9; i++) 
	{
		if (puzzle[i][col] == number)
		{
			numberNotInColumn = false;
		}
	}
	return numberNotInColumn;
}


