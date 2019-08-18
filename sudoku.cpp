#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//function prototypes
void changeRow(int array[][9]);
void changeColumn(int array[][9]);
void changeQuadrant(int array[][9]);
void crossHatching(int array[][9], int quadrant, int amountOfZeroes);

//array
int unsolvedPuzzle[9][9] = 

{
	//1st       2nd        3rd
	{5, 3, 4, 0 ,7, 0, 9, 1, 2},
	{6, 0, 0, 1, 9, 5, 0, 0, 8},
	{0, 9, 8, 0, 0, 0, 0, 6, 0},
	//4th       5th        6th
	{8, 0, 0, 0, 6, 0, 0, 0, 3},
	{4, 0, 0, 8 ,0, 3, 0, 0, 1},
	{7, 0, 0, 0, 2, 0, 0, 0, 6},
	//7th       8th        9th
	{0, 6, 0, 0, 0, 0, 2, 8, 4},
	{2, 8, 7, 4, 1, 9, 0, 0, 5},
	{3, 4, 5, 0, 8, 0, 0, 7, 9}
};

int solvedPuzzle[9][9] = 

{
	//1st       2nd        3rd
	{5, 3, 4, 6 ,7, 8, 9, 1, 2},
	{6, 7, 2, 1, 9, 5, 3, 4, 8},
	{1, 9, 8, 3, 4, 2, 5, 6, 7},
	//4th       5th        6th
	{8, 5, 9, 7, 6, 1, 4, 2, 3},
	{4, 2, 6, 8 ,5, 3, 7, 9, 1},
	{7, 1, 3, 9, 2, 4, 8, 5, 6},
	//7th       8th        9th
	{9, 6, 1, 5, 3, 7, 2, 8, 4},
	{2, 8, 7, 4, 1, 9, 6, 3, 5},
	{3, 4, 5, 2, 8, 6, 1, 7, 9}
};

int main() {

	//declarations
	int checkIfSudokuIsSolved = 0;

	//sudoku unsolved
	cout << "This is the unsolved sudoku puzzle: " << endl;

	for (int unsolvedSudokuDisplayRow = 0; unsolvedSudokuDisplayRow < 9; unsolvedSudokuDisplayRow++)
	{
		for (int unsolvedSudokuDisplayColumn = 0; unsolvedSudokuDisplayColumn < 9; unsolvedSudokuDisplayColumn++)
		{
			cout << unsolvedPuzzle[unsolvedSudokuDisplayRow][unsolvedSudokuDisplayColumn] << " ";
		}
		cout << endl;
	}


	//calculations
	while (checkIfSudokuIsSolved != 81)
	{
		checkIfSudokuIsSolved = 0;
		changeRow(unsolvedPuzzle);
		changeColumn(unsolvedPuzzle);
		changeQuadrant(unsolvedPuzzle);
		for (int rowCheck = 0; rowCheck < 9; rowCheck++)
			for (int columnCheck = 0; columnCheck < 9; columnCheck++)
			{
				if (unsolvedPuzzle[rowCheck][columnCheck] == solvedPuzzle[rowCheck][columnCheck])
				{
					checkIfSudokuIsSolved++;
				}
			}
	}
	//sudoku solved
	cout << endl;
	cout << "This is the solved sudoku puzzle: " << endl;
	for (int unsolvedSudokuDisplayRow = 0; unsolvedSudokuDisplayRow < 9; unsolvedSudokuDisplayRow++)
	{
		for (int unsolvedSudokuDisplayColumn = 0; unsolvedSudokuDisplayColumn < 9; unsolvedSudokuDisplayColumn++)
		{
			cout << unsolvedPuzzle[unsolvedSudokuDisplayRow][unsolvedSudokuDisplayColumn] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

//function definitions
void changeRow(int array[][9])
{
	
	for (int row = 0; row < 9; row++)
	{
		//declarations
		int rowOneZeroCounter = 0;
		int rowTwoZeroCounter = 0;
		int rowThreeZeroCounter = 0;
		int rowFourZeroCounter = 0;
		int rowFiveZeroCounter = 0;
		int rowSixZeroCounter = 0;
		int rowSevenZeroCounter = 0;
		int rowEightZeroCounter = 0;
		int rowNineZeroCounter = 0;
		int moreThanOneNumberChange = 0;
		vector<int> columnItems;

		//calculations
		for (int item = 0; item < 9; item++)
		{
			if (array[row][item] == 0)
			{
				switch (row)
				{
				case 0:
					rowOneZeroCounter += 1;
					break;
				case 1:
					rowTwoZeroCounter += 1;
					break;
				case 2:
					rowThreeZeroCounter += 1;
					break;
				case 3: 
					rowFourZeroCounter += 1;
					break;
				case 4:
					rowFiveZeroCounter += 1;
					break;
				case 5:
					rowSixZeroCounter += 1;
					break;
				case 6: 
					rowSevenZeroCounter += 1;
					break;
				case 7:
					rowEightZeroCounter += 1;
					break;
				case 8:
					rowNineZeroCounter += 1;
					break;
				default:
					cout << "";
					break;
				}
			} // determines if a zero is present, if so increase the counter
		} // checking each item in the row
		if (rowOneZeroCounter >= 3 || rowTwoZeroCounter >= 3 || rowThreeZeroCounter >= 3 || 
			rowFourZeroCounter >= 3 || rowFiveZeroCounter >= 3 || rowSixZeroCounter >= 3 || 
			rowSevenZeroCounter >= 3 || rowEightZeroCounter >= 3 || rowNineZeroCounter >= 3)
		{
			cout << "";
		} //too many zeroes, move on to another row

		else if (rowOneZeroCounter == 0 && rowTwoZeroCounter == 0 && rowThreeZeroCounter == 0 &&
			rowFourZeroCounter == 0 && rowFiveZeroCounter == 0 && rowSixZeroCounter == 0 &&
			rowSevenZeroCounter == 0 && rowEightZeroCounter == 0 && rowNineZeroCounter == 0)
		{
			cout << "";
		} //if all the numbers are they, don't do anything

		else
		{
			for (int column = 0; column < 9; column++)
			{
				if (array[row][column] == 0)
				{
					for (int checkingAllRowsInTheColumn = 0; checkingAllRowsInTheColumn < 9; checkingAllRowsInTheColumn++)
					{
						if (array[checkingAllRowsInTheColumn][column] != 0)
						{
							columnItems.push_back(array[checkingAllRowsInTheColumn][column]);
						} // go down the different rows of a column, place non-zero numbers into a vector to help solve sudoku
						//store it in a vector
					}
					for (int missingNumber = 1; missingNumber <= 9; missingNumber++)
					{
						if (missingNumber != array[row][0] && missingNumber != array[row][1] && missingNumber != array[row][2] &&
							missingNumber != array[row][3] && missingNumber != array[row][4] && missingNumber != array[row][5] &&
							missingNumber != array[row][6] && missingNumber != array[row][7] && missingNumber != array[row][8] &&
							find(columnItems.begin(), columnItems.end(), missingNumber) == columnItems.end())
						{
							array[row][column] = missingNumber;
							moreThanOneNumberChange++;
						} //if missing number doesn't equal numbers in row or columns, then place it in the empty spot
					} //checking for missing number in the row
					if (moreThanOneNumberChange > 1)
					{
						array[row][column] = 0;
					} // if you change the number twice, reset to 0 so sudoku can be solved
					columnItems.clear(); //clear all items in vector so next row can use them
					moreThanOneNumberChange = 0;
				}
			} //second iteration through row
		} // not that many zeroes can solve this
	} // checking each row
} //void changeRow(int array[][9])

void changeColumn(int array[][9])
{

	for (int column = 0; column < 9; column++)
	{
		//declarations
		int columnOneZeroCounter = 0;
		int columnTwoZeroCounter = 0;
		int columnThreeZeroCounter = 0;
		int columnFourZeroCounter = 0;
		int columnFiveZeroCounter = 0;
		int columnSixZeroCounter = 0;
		int columnSevenZeroCounter = 0;
		int columnEightZeroCounter = 0;
		int columnNineZeroCounter = 0;
		int moreThanOneNumberChange = 0;
		vector<int> rowItems;

		//calculations
		for (int item = 0; item < 9; item++)
		{
			if (array[item][column] == 0)
			{
				switch (column)
				{
				case 0:
					columnOneZeroCounter += 1;
					break;
				case 1:
					columnTwoZeroCounter += 1;
					break;
				case 2:
					columnThreeZeroCounter += 1;
					break;
				case 3:
					columnFourZeroCounter += 1;
					break;
				case 4:
					columnFiveZeroCounter += 1;
					break;
				case 5:
					columnSixZeroCounter += 1;
					break;
				case 6:
					columnSevenZeroCounter += 1;
					break;
				case 7:
					columnEightZeroCounter += 1;
					break;
				case 8:
					columnNineZeroCounter += 1;
					break;
				default:
					cout << "";
					break;
				}
			} // determines if a zero is present, if so increase the counter
		} // checking each item in the column
		if (columnOneZeroCounter >= 3 || columnTwoZeroCounter >= 3 || columnThreeZeroCounter >= 3 ||
			columnFourZeroCounter >= 3 || columnFiveZeroCounter >= 3 || columnSixZeroCounter >= 3 ||
			columnSevenZeroCounter >= 3 || columnEightZeroCounter >= 3 || columnNineZeroCounter >= 3)
		{
			cout << "";
		} //too many zeroes, move on to another column

		else if (columnOneZeroCounter == 0 && columnTwoZeroCounter == 0 && columnThreeZeroCounter == 0 &&
			columnFourZeroCounter == 0 && columnFiveZeroCounter == 0 && columnSixZeroCounter == 0 &&
			columnSevenZeroCounter == 0 && columnEightZeroCounter == 0 && columnNineZeroCounter == 0)
		{
			cout << "";
		} //if all the numbers are they, don't do anything

		else
		{	
			for (int row = 0; row < 9; row++)
			{
				if (array[row][column] == 0)
				{
					for (int checkingAllColumnsInTheRow = 0; checkingAllColumnsInTheRow < 9; checkingAllColumnsInTheRow++)
					{
						if (array[row][checkingAllColumnsInTheRow] != 0)
						{
							rowItems.push_back(array[row][checkingAllColumnsInTheRow]);
						} // go down the different columns of a row, place non-zero numbers into a vector to help solve sudoku
						//store it in a vector
					}
					for (int missingNumber = 1; missingNumber <= 9; missingNumber++)
					{
						if (missingNumber != array[0][column] && missingNumber != array[1][column] && missingNumber != array[2][column] &&
							missingNumber != array[3][column] && missingNumber != array[4][column] && missingNumber != array[5][column] &&
							missingNumber != array[6][column] && missingNumber != array[7][column] && missingNumber != array[8][column] &&
							find(rowItems.begin(), rowItems.end(), missingNumber) == rowItems.end())
						{
							array[row][column] = missingNumber;
							moreThanOneNumberChange++;
						} //if missing number doesn't equal numbers in row or columns, then place it in the empty spot
					} //checking for missing number in the row
					if (moreThanOneNumberChange > 1)
					{
						array[row][column] = 0;
					} // if you change the number twice, reset to 0 so sudoku can be solved
					rowItems.clear(); //clear all items in vector so next column can use them
					moreThanOneNumberChange = 0;
				}
			} //second iteration through column
		} // not that many zeroes can solve this
	} // checking each column
} //void changecolumn(int array[][9])

void changeQuadrant(int array[][9])
{
	int quadrantOneZeroCounter = 0;
	int quadrantTwoZeroCounter = 0;
	int quadrantThreeZeroCounter = 0;
	int quadrantFourZeroCounter = 0;
	int quadrantFiveZeroCounter = 0;
	int quadrantSixZeroCounter = 0;
	int quadrantSevenZeroCounter = 0;
	int quadrantEightZeroCounter = 0;
	int quadrantNineZeroCounter = 0;

	for (int rowOfQuadrantOne = 0; rowOfQuadrantOne <= 2; rowOfQuadrantOne++)
		for (int columnOfQuandrantOne = 0; columnOfQuandrantOne <= 2; columnOfQuandrantOne++)
		{
			if (array[rowOfQuadrantOne][columnOfQuandrantOne] == 0)
			{
				quadrantOneZeroCounter++; //track the amount of zeroes in a quadrant
			}
		} // checking the first quandrant

	for (int rowOfQuadrantTwo = 0; rowOfQuadrantTwo <= 2; rowOfQuadrantTwo++)
		for (int columnOfQuandrantTwo = 3; columnOfQuandrantTwo <= 5; columnOfQuandrantTwo++)
		{
			if (array[rowOfQuadrantTwo][columnOfQuandrantTwo] == 0)
			{
				quadrantTwoZeroCounter++; //track the amount of zeroes in a quadrant
			}
		} // checking the second quandrant

	for (int rowOfQuadrantThree = 0; rowOfQuadrantThree <= 2; rowOfQuadrantThree++)
		for (int columnOfQuandrantThree = 6; columnOfQuandrantThree <= 8; columnOfQuandrantThree++)
		{
			if (array[rowOfQuadrantThree][columnOfQuandrantThree] == 0)
			{
				quadrantThreeZeroCounter++; //track the amount of zeroes in a quadrant
			}
		} // checking the third quandrant

	for (int rowOfQuadrantFour = 3; rowOfQuadrantFour <= 5; rowOfQuadrantFour++)
		for (int columnOfQuandrantFour = 0; columnOfQuandrantFour <= 2; columnOfQuandrantFour++)
		{
			if (array[rowOfQuadrantFour][columnOfQuandrantFour] == 0)
			{
				quadrantFourZeroCounter++; //track the amount of zeroes in a quadrant
			}
		} // checking the fourth quandrant

	for (int rowOfQuadrantFive = 3; rowOfQuadrantFive <= 5; rowOfQuadrantFive++)
		for (int columnOfQuandrantFive = 3; columnOfQuandrantFive <= 5; columnOfQuandrantFive++)
		{
			if (array[rowOfQuadrantFive][columnOfQuandrantFive] == 0)
			{
				quadrantFiveZeroCounter++; //track the amount of zeroes in a quadrant
			}
		} // checking the fifth quandrant

	for (int rowOfQuadrantSix = 3; rowOfQuadrantSix <= 5; rowOfQuadrantSix++)
		for (int columnOfQuandrantSix = 6; columnOfQuandrantSix <= 8; columnOfQuandrantSix++)
		{
			if (array[rowOfQuadrantSix][columnOfQuandrantSix] == 0)
			{
				quadrantSixZeroCounter++; //track the amount of zeroes in a quadrant
			}
		} // checking the sixth quandrant

	for (int rowOfQuadrantSeven = 6; rowOfQuadrantSeven <= 8; rowOfQuadrantSeven++)
		for (int columnOfQuandrantSeven = 0; columnOfQuandrantSeven <= 2; columnOfQuandrantSeven++)
		{
			if (array[rowOfQuadrantSeven][columnOfQuandrantSeven] == 0)
			{
				quadrantSevenZeroCounter++; //track the amount of zeroes in a quadrant
			}
		} // checking the seventh quandrant

	for (int rowOfQuadrantEight = 6; rowOfQuadrantEight <= 8; rowOfQuadrantEight++)
		for (int columnOfQuandrantEight = 3; columnOfQuandrantEight <= 5; columnOfQuandrantEight++)
		{
			if (array[rowOfQuadrantEight][columnOfQuandrantEight] == 0)
			{
				quadrantEightZeroCounter++; //track the amount of zeroes in a quadrant
			}
		} // checking the eighth quandrant

	for (int rowOfQuadrantNine = 6; rowOfQuadrantNine <= 8; rowOfQuadrantNine++)
		for (int columnOfQuandrantNine = 6; columnOfQuandrantNine <= 8; columnOfQuandrantNine++)
		{
			if (array[rowOfQuadrantNine][columnOfQuandrantNine] == 0)
			{
				quadrantNineZeroCounter++; //track the amount of zeroes in a quadrant
			}
		} // checking the ninth quandrant

	//SOLVING THE SUDOKU PUZZLE

	if (quadrantOneZeroCounter == 1)
	{
		for (int missingNumber = 1; missingNumber < 10; missingNumber++)
			for (int rowOfQuadrantOne = 0; rowOfQuadrantOne <= 2; rowOfQuadrantOne++)
				for (int columnOfQuandrantOne = 0; columnOfQuandrantOne <= 2; columnOfQuandrantOne++)
				{
					if (array[rowOfQuadrantOne][columnOfQuandrantOne] == 0)
					{
						if (missingNumber != array[0][0] && missingNumber != array[0][1] && missingNumber != array[0][2] &&
							missingNumber != array[1][0] && missingNumber != array[1][1] && missingNumber != array[1][2] &&
							missingNumber != array[2][0] && missingNumber != array[2][1] && missingNumber != array[2][2])
						{
							array[rowOfQuadrantOne][columnOfQuandrantOne] = missingNumber;
						} //change zero to the missing number

					} //if a zero is found do this
				} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
					//number of a quadrant
	} //checking quadrant if only one zero is missing, if so replace zero with missing number

	else if (quadrantTwoZeroCounter == 1)
	{
		for (int missingNumber = 1; missingNumber < 10; missingNumber++)
			for (int rowOfQuadrantTwo = 0; rowOfQuadrantTwo <= 2; rowOfQuadrantTwo++)
				for (int columnOfQuandrantTwo = 3; columnOfQuandrantTwo <= 5; columnOfQuandrantTwo++)
				{
					if (array[rowOfQuadrantTwo][columnOfQuandrantTwo] == 0)
					{
						if (missingNumber != array[0][3] && missingNumber != array[0][4] && missingNumber != array[0][5] &&
							missingNumber != array[1][3] && missingNumber != array[1][4] && missingNumber != array[1][5] &&
							missingNumber != array[2][3] && missingNumber != array[2][4] && missingNumber != array[2][5])
						{
							array[rowOfQuadrantTwo][columnOfQuandrantTwo] = missingNumber;
						}//change zero to the missing number

					} //if a zero is found do this
				} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
					//number of a quadrant
	} //checking quadrant if only one zero is missing, if so replace zero with missing number

	else if (quadrantThreeZeroCounter == 1)
	{
		for (int missingNumber = 1; missingNumber < 10; missingNumber++)
			for (int rowOfQuadrantThree = 0; rowOfQuadrantThree <= 2; rowOfQuadrantThree++)
				for (int columnOfQuandrantThree = 6; columnOfQuandrantThree <= 8; columnOfQuandrantThree++)
				{
					if (array[rowOfQuadrantThree][columnOfQuandrantThree] == 0)
					{
						if (missingNumber != array[0][6] && missingNumber != array[0][7] && missingNumber != array[0][8] &&
							missingNumber != array[1][6] && missingNumber != array[1][7] && missingNumber != array[1][8] &&
							missingNumber != array[2][6] && missingNumber != array[2][7] && missingNumber != array[2][8])
						{
							array[rowOfQuadrantThree][columnOfQuandrantThree] = missingNumber;
						}//change zero to the missing number

					} //if a zero is found do this
				} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
					//number of a quadrant
	} //checking quadrant if only one zero is missing, if so replace zero with missing number

	else if (quadrantFourZeroCounter == 1)
	{
		for (int missingNumber = 1; missingNumber < 10; missingNumber++)
			for (int rowOfQuadrantFour = 3; rowOfQuadrantFour <= 5; rowOfQuadrantFour++)
				for (int columnOfQuandrantFour = 0; columnOfQuandrantFour <= 2; columnOfQuandrantFour++)
				{
					if (array[rowOfQuadrantFour][columnOfQuandrantFour] == 0)
					{
						if (missingNumber != array[3][0] && missingNumber != array[3][1] && missingNumber != array[3][2] &&
							missingNumber != array[4][0] && missingNumber != array[4][1] && missingNumber != array[4][2] &&
							missingNumber != array[5][0] && missingNumber != array[5][1] && missingNumber != array[5][2])
						{
							array[rowOfQuadrantFour][columnOfQuandrantFour] = missingNumber;
						}//change zero to the missing number

					} //if a zero is found do this
				} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
					//number of a quadrant
	} //checking quadrant if only one zero is missing, if so replace zero with missing number

	else if (quadrantFiveZeroCounter == 1)
	{
		for (int missingNumber = 1; missingNumber < 10; missingNumber++)
			for (int rowOfQuadrantFive = 3; rowOfQuadrantFive <= 5; rowOfQuadrantFive++)
				for (int columnOfQuandrantFive = 3; columnOfQuandrantFive <= 5; columnOfQuandrantFive++)
				{
					if (array[rowOfQuadrantFive][columnOfQuandrantFive] == 0)
					{
						if (missingNumber != array[3][3] && missingNumber != array[3][4] && missingNumber != array[3][5] &&
							missingNumber != array[4][3] && missingNumber != array[4][4] && missingNumber != array[4][5] &&
							missingNumber != array[5][3] && missingNumber != array[5][4] && missingNumber != array[5][5])
						{
							array[rowOfQuadrantFive][columnOfQuandrantFive] = missingNumber;
						}//change zero to the missing number

					} //if a zero is found do this
				} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
					//number of a quadrant
	} //checking quadrant if only one zero is missing, if so replace zero with missing number

	else if (quadrantSixZeroCounter == 1)
	{
		for (int missingNumber = 1; missingNumber < 10; missingNumber++)
			for (int rowOfQuadrantSix = 3; rowOfQuadrantSix <= 5; rowOfQuadrantSix++)
				for (int columnOfQuandrantSix = 6; columnOfQuandrantSix <= 8; columnOfQuandrantSix++)
				{
					if (array[rowOfQuadrantSix][columnOfQuandrantSix] == 0)
					{
						if (missingNumber != array[3][6] && missingNumber != array[3][7] && missingNumber != array[3][8] &&
							missingNumber != array[4][6] && missingNumber != array[4][7] && missingNumber != array[4][8] &&
							missingNumber != array[5][6] && missingNumber != array[5][7] && missingNumber != array[5][8])
						{
							array[rowOfQuadrantSix][columnOfQuandrantSix] = missingNumber;
						}//change zero to the missing number

					} //if a zero is found do this
				} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
					//number of a quadrant
	} //checking quadrant if only one zero is missing, if so replace zero with missing number
	
	else if (quadrantSevenZeroCounter == 1)
	{
		for (int missingNumber = 1; missingNumber < 10; missingNumber++)
			for (int rowOfQuadrantSeven = 6; rowOfQuadrantSeven <= 8; rowOfQuadrantSeven++)
				for (int columnOfQuandrantSeven = 0; columnOfQuandrantSeven <= 2; columnOfQuandrantSeven++)
				{
					if (array[rowOfQuadrantSeven][columnOfQuandrantSeven] == 0)
					{
						if (missingNumber != array[6][0] && missingNumber != array[6][1] && missingNumber != array[6][2] &&
							missingNumber != array[7][0] && missingNumber != array[7][1] && missingNumber != array[7][2] &&
							missingNumber != array[8][0] && missingNumber != array[8][1] && missingNumber != array[8][2])
						{
							array[rowOfQuadrantSeven][columnOfQuandrantSeven] = missingNumber;
						}// change zero to the missing number
					
					} //if zero is found do this
				} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
					//number of a quadrant
	} //checking quadrant if only one zero is missing, if so replace zero with missing number

	else if (quadrantEightZeroCounter == 1)
	{
	for (int missingNumber = 1; missingNumber < 10; missingNumber++)
		for (int rowOfQuadrantEight = 6; rowOfQuadrantEight <= 8; rowOfQuadrantEight++)
			for (int columnOfQuandrantEight = 3; columnOfQuandrantEight <= 5; columnOfQuandrantEight++)
			{
				if (array[rowOfQuadrantEight][columnOfQuandrantEight] == 0)
				{
					if (missingNumber != array[6][3] && missingNumber != array[6][4] && missingNumber != array[6][5] &&
						missingNumber != array[7][3] && missingNumber != array[7][4] && missingNumber != array[7][5] &&
						missingNumber != array[8][3] && missingNumber != array[8][4] && missingNumber != array[8][5])
					{
						array[rowOfQuadrantEight][columnOfQuandrantEight] = missingNumber;
					}// change zero to the missing number

				} //if zero is found do this
			} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
				//number of a quadrant
	} //checking quadrant if only one zero is missing, if so replace zero with missing number

	else if (quadrantNineZeroCounter == 1)
	{
	for (int missingNumber = 1; missingNumber < 10; missingNumber++)
		for (int rowOfQuadrantNine = 6; rowOfQuadrantNine <= 8; rowOfQuadrantNine++)
			for (int columnOfQuandrantNine = 6; columnOfQuandrantNine <= 8; columnOfQuandrantNine++)
			{
				if (array[rowOfQuadrantNine][columnOfQuandrantNine] == 0)
				{
					if (missingNumber != array[6][6] && missingNumber != array[6][7] && missingNumber != array[6][8] &&
						missingNumber != array[7][6] && missingNumber != array[7][7] && missingNumber != array[7][8] &&
						missingNumber != array[8][6] && missingNumber != array[8][7] && missingNumber != array[8][8])
					{
						array[rowOfQuadrantNine][columnOfQuandrantNine] = missingNumber;
					}// change zero to the missing number

				} //if zero is found do this
			} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
				//number of a quadrant
	} //checking quadrant if only one zero is missing, if so replace zero with missing number

	if (quadrantOneZeroCounter > 1)
	{
		crossHatching(unsolvedPuzzle, 1, quadrantOneZeroCounter);
	}

	else if (quadrantTwoZeroCounter > 1)
	{
		crossHatching(unsolvedPuzzle, 2, quadrantTwoZeroCounter);
	}

	else if (quadrantThreeZeroCounter > 1)
	{
		crossHatching(unsolvedPuzzle, 3, quadrantThreeZeroCounter);
	}

	else if (quadrantFourZeroCounter > 1)
	{
		crossHatching(unsolvedPuzzle, 4, quadrantFourZeroCounter);
	}

	else if (quadrantFiveZeroCounter > 1)
	{
		crossHatching(unsolvedPuzzle, 5, quadrantFiveZeroCounter);
	}

	else if (quadrantSixZeroCounter > 1)
	{
		crossHatching(unsolvedPuzzle, 6, quadrantSixZeroCounter);
	}

	else if (quadrantSevenZeroCounter > 1)
	{
		crossHatching(unsolvedPuzzle, 7, quadrantSevenZeroCounter);
	}

	else if (quadrantEightZeroCounter > 1)
	{
		crossHatching(unsolvedPuzzle, 8, quadrantEightZeroCounter);
	}

	else if (quadrantNineZeroCounter > 1)
	{
		crossHatching(unsolvedPuzzle, 9, quadrantNineZeroCounter);
	}

} //void changeQuadrant(int array[][9])


void crossHatching(int array[][9], int quadrant, int amountOfZeroes)
{
	vector<int> crossHatchingRowItems;
	vector<int> crossHatchingColumnItems;
	int moreThanOneNumberChange = 0;
	switch (quadrant)
	{
	case 1:
		for (int rowOfQuadrantOne = 0; rowOfQuadrantOne <= 2; rowOfQuadrantOne++)
			for (int columnOfQuandrantOne = 0; columnOfQuandrantOne <= 2; columnOfQuandrantOne++)
			{
				if (array[rowOfQuadrantOne][columnOfQuandrantOne] == 0)
				{
					for (int checkingAllRowsOfThisZero = 0; checkingAllRowsOfThisZero < 9; checkingAllRowsOfThisZero++)
					{
						if (array[checkingAllRowsOfThisZero][columnOfQuandrantOne] != 0)
						{
							crossHatchingColumnItems.push_back(array[checkingAllRowsOfThisZero][columnOfQuandrantOne]);
						} // go down the different rows of a column, place non-zero numbers into a vector to help solve sudoku
					}

					for (int checkingAllColumnsOfThisZero = 0; checkingAllColumnsOfThisZero < 9; checkingAllColumnsOfThisZero++)
					{
						if (array[rowOfQuadrantOne][checkingAllColumnsOfThisZero] != 0)
						{
							crossHatchingRowItems.push_back(array[rowOfQuadrantOne][checkingAllColumnsOfThisZero]);
						} // go down the different columns of a row, place non-zero numbers into a vector to help solve sudoku
						//store it in a vector
					}
						
					for (int missingNumber = 1; missingNumber <= 9; missingNumber++)
					{
						if (missingNumber != array[0][0] && missingNumber != array[0][1] && missingNumber != array[0][2] &&
							missingNumber != array[1][0] && missingNumber != array[1][1] && missingNumber != array[1][2] &&
							missingNumber != array[2][0] && missingNumber != array[2][1] && missingNumber != array[2][2] &&
							find(crossHatchingRowItems.begin(), crossHatchingRowItems.end(), missingNumber) == crossHatchingRowItems.end() &&
							find(crossHatchingColumnItems.begin(), crossHatchingColumnItems.end(), missingNumber) == crossHatchingColumnItems.end())
						{
							array[rowOfQuadrantOne][columnOfQuandrantOne] = missingNumber;
							moreThanOneNumberChange++;
						} //if missing number doesn't equal numbers in row or columns, then place it in the empty spot
					} //checking for missing number in the row
					if (moreThanOneNumberChange > 1)
					{
						array[rowOfQuadrantOne][columnOfQuandrantOne] = 0;
					} // if you change the number twice, reset to 0 so sudoku can be solved
					crossHatchingRowItems.clear(); //clear all items in vector so next row can use them
					crossHatchingColumnItems.clear(); //clear all items in vector so next row can use them
					moreThanOneNumberChange = 0;

				} //if a zero is found do this
			} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
				//number of a quadrant
		break;
	case 2:
		for (int rowOfQuadrantOne = 0; rowOfQuadrantOne <= 2; rowOfQuadrantOne++)
			for (int columnOfQuandrantOne = 3; columnOfQuandrantOne <= 5; columnOfQuandrantOne++)
			{
				if (array[rowOfQuadrantOne][columnOfQuandrantOne] == 0)
				{
					for (int checkingAllRowsOfThisZero = 0; checkingAllRowsOfThisZero < 9; checkingAllRowsOfThisZero++)
					{
						if (array[checkingAllRowsOfThisZero][columnOfQuandrantOne] != 0)
						{
							crossHatchingColumnItems.push_back(array[checkingAllRowsOfThisZero][columnOfQuandrantOne]);
						} // go down the different rows of a column, place non-zero numbers into a vector to help solve sudoku
					}

					for (int checkingAllColumnsOfThisZero = 0; checkingAllColumnsOfThisZero < 9; checkingAllColumnsOfThisZero++)
					{
						if (array[rowOfQuadrantOne][checkingAllColumnsOfThisZero] != 0)
						{
							crossHatchingRowItems.push_back(array[rowOfQuadrantOne][checkingAllColumnsOfThisZero]);
						} // go down the different columns of a row, place non-zero numbers into a vector to help solve sudoku
						//store it in a vector
					}

					for (int missingNumber = 1; missingNumber <= 9; missingNumber++)
					{
						if (missingNumber != array[0][3] && missingNumber != array[0][4] && missingNumber != array[0][5] &&
							missingNumber != array[1][3] && missingNumber != array[1][4] && missingNumber != array[1][5] &&
							missingNumber != array[2][3] && missingNumber != array[2][4] && missingNumber != array[2][5] &&
							find(crossHatchingRowItems.begin(), crossHatchingRowItems.end(), missingNumber) == crossHatchingRowItems.end() &&
							find(crossHatchingColumnItems.begin(), crossHatchingColumnItems.end(), missingNumber) == crossHatchingColumnItems.end())
						{
							array[rowOfQuadrantOne][columnOfQuandrantOne] = missingNumber;
							moreThanOneNumberChange++;
						} //if missing number doesn't equal numbers in row or columns, then place it in the empty spot
					} //checking for missing number in the row
					if (moreThanOneNumberChange > 1)
					{
						array[rowOfQuadrantOne][columnOfQuandrantOne] = 0;
					} // if you change the number twice, reset to 0 so sudoku can be solved
					crossHatchingRowItems.clear(); //clear all items in vector so next row can use them
					crossHatchingColumnItems.clear(); //clear all items in vector so next row can use them
					moreThanOneNumberChange = 0;

				} //if a zero is found do this
			} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
				//number of a quadrant
		break;
	case 3:
		for (int rowOfQuadrantOne = 0; rowOfQuadrantOne <= 2; rowOfQuadrantOne++)
			for (int columnOfQuandrantOne = 6; columnOfQuandrantOne <= 8; columnOfQuandrantOne++)
			{
				if (array[rowOfQuadrantOne][columnOfQuandrantOne] == 0)
				{
					for (int checkingAllRowsOfThisZero = 0; checkingAllRowsOfThisZero < 9; checkingAllRowsOfThisZero++)
					{
						if (array[checkingAllRowsOfThisZero][columnOfQuandrantOne] != 0)
						{
							crossHatchingColumnItems.push_back(array[checkingAllRowsOfThisZero][columnOfQuandrantOne]);
						} // go down the different rows of a column, place non-zero numbers into a vector to help solve sudoku
					}

					for (int checkingAllColumnsOfThisZero = 0; checkingAllColumnsOfThisZero < 9; checkingAllColumnsOfThisZero++)
					{
						if (array[rowOfQuadrantOne][checkingAllColumnsOfThisZero] != 0)
						{
							crossHatchingRowItems.push_back(array[rowOfQuadrantOne][checkingAllColumnsOfThisZero]);
						} // go down the different columns of a row, place non-zero numbers into a vector to help solve sudoku
						//store it in a vector
					}

					for (int missingNumber = 1; missingNumber <= 9; missingNumber++)
					{
						if (missingNumber != array[0][6] && missingNumber != array[0][7] && missingNumber != array[0][8] &&
							missingNumber != array[1][6] && missingNumber != array[1][7] && missingNumber != array[1][8] &&
							missingNumber != array[2][6] && missingNumber != array[2][7] && missingNumber != array[2][8] &&
							find(crossHatchingRowItems.begin(), crossHatchingRowItems.end(), missingNumber) == crossHatchingRowItems.end() &&
							find(crossHatchingColumnItems.begin(), crossHatchingColumnItems.end(), missingNumber) == crossHatchingColumnItems.end())
						{
							array[rowOfQuadrantOne][columnOfQuandrantOne] = missingNumber;
							moreThanOneNumberChange++;
						} //if missing number doesn't equal numbers in row or columns, then place it in the empty spot
					} //checking for missing number in the row
					if (moreThanOneNumberChange > 1)
					{
						array[rowOfQuadrantOne][columnOfQuandrantOne] = 0;
					} // if you change the number twice, reset to 0 so sudoku can be solved
					crossHatchingRowItems.clear(); //clear all items in vector so next row can use them
					crossHatchingColumnItems.clear(); //clear all items in vector so next row can use them
					moreThanOneNumberChange = 0;

				} //if a zero is found do this
			} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
				//number of a quadrant
		break;
	case 4:
		for (int rowOfQuadrantOne = 3; rowOfQuadrantOne <= 5; rowOfQuadrantOne++)
			for (int columnOfQuandrantOne = 0; columnOfQuandrantOne <= 2; columnOfQuandrantOne++)
			{
				if (array[rowOfQuadrantOne][columnOfQuandrantOne] == 0)
				{
					for (int checkingAllRowsOfThisZero = 0; checkingAllRowsOfThisZero < 9; checkingAllRowsOfThisZero++)
					{
						if (array[checkingAllRowsOfThisZero][columnOfQuandrantOne] != 0)
						{
							crossHatchingColumnItems.push_back(array[checkingAllRowsOfThisZero][columnOfQuandrantOne]);
						} // go down the different rows of a column, place non-zero numbers into a vector to help solve sudoku
					}

					for (int checkingAllColumnsOfThisZero = 0; checkingAllColumnsOfThisZero < 9; checkingAllColumnsOfThisZero++)
					{
						if (array[rowOfQuadrantOne][checkingAllColumnsOfThisZero] != 0)
						{
							crossHatchingRowItems.push_back(array[rowOfQuadrantOne][checkingAllColumnsOfThisZero]);
						} // go down the different columns of a row, place non-zero numbers into a vector to help solve sudoku
						//store it in a vector
					}

					for (int missingNumber = 1; missingNumber <= 9; missingNumber++)
					{
						if (missingNumber != array[3][0] && missingNumber != array[3][1] && missingNumber != array[3][2] &&
							missingNumber != array[4][0] && missingNumber != array[4][1] && missingNumber != array[4][2] &&
							missingNumber != array[5][0] && missingNumber != array[5][1] && missingNumber != array[5][2] &&
							find(crossHatchingRowItems.begin(), crossHatchingRowItems.end(), missingNumber) == crossHatchingRowItems.end() &&
							find(crossHatchingColumnItems.begin(), crossHatchingColumnItems.end(), missingNumber) == crossHatchingColumnItems.end())
						{
							array[rowOfQuadrantOne][columnOfQuandrantOne] = missingNumber;
							moreThanOneNumberChange++;
						} //if missing number doesn't equal numbers in row or columns, then place it in the empty spot
					} //checking for missing number in the row
					if (moreThanOneNumberChange > 1)
					{
						array[rowOfQuadrantOne][columnOfQuandrantOne] = 0;
					} // if you change the number twice, reset to 0 so sudoku can be solved
					crossHatchingRowItems.clear(); //clear all items in vector so next row can use them
					crossHatchingColumnItems.clear(); //clear all items in vector so next row can use them
					moreThanOneNumberChange = 0;

				} //if a zero is found do this
			} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
				//number of a quadrant
		break;
	case 5:
		for (int rowOfQuadrantOne = 3; rowOfQuadrantOne <= 5; rowOfQuadrantOne++)
			for (int columnOfQuandrantOne = 3; columnOfQuandrantOne <= 5; columnOfQuandrantOne++)
			{
				if (array[rowOfQuadrantOne][columnOfQuandrantOne] == 0)
				{
					for (int checkingAllRowsOfThisZero = 0; checkingAllRowsOfThisZero < 9; checkingAllRowsOfThisZero++)
					{
						if (array[checkingAllRowsOfThisZero][columnOfQuandrantOne] != 0)
						{
							crossHatchingColumnItems.push_back(array[checkingAllRowsOfThisZero][columnOfQuandrantOne]);
						} // go down the different rows of a column, place non-zero numbers into a vector to help solve sudoku
					}

					for (int checkingAllColumnsOfThisZero = 0; checkingAllColumnsOfThisZero < 9; checkingAllColumnsOfThisZero++)
					{
						if (array[rowOfQuadrantOne][checkingAllColumnsOfThisZero] != 0)
						{
							crossHatchingRowItems.push_back(array[rowOfQuadrantOne][checkingAllColumnsOfThisZero]);
						} // go down the different columns of a row, place non-zero numbers into a vector to help solve sudoku
						//store it in a vector
					}

					for (int missingNumber = 1; missingNumber <= 9; missingNumber++)
					{
						if (missingNumber != array[3][3] && missingNumber != array[3][4] && missingNumber != array[3][5] &&
							missingNumber != array[4][3] && missingNumber != array[4][4] && missingNumber != array[4][5] &&
							missingNumber != array[5][3] && missingNumber != array[5][4] && missingNumber != array[5][5] &&
							find(crossHatchingRowItems.begin(), crossHatchingRowItems.end(), missingNumber) == crossHatchingRowItems.end() &&
							find(crossHatchingColumnItems.begin(), crossHatchingColumnItems.end(), missingNumber) == crossHatchingColumnItems.end())
						{
							array[rowOfQuadrantOne][columnOfQuandrantOne] = missingNumber;
							moreThanOneNumberChange++;
						} //if missing number doesn't equal numbers in row or columns, then place it in the empty spot
					} //checking for missing number in the row
					if (moreThanOneNumberChange > 1)
					{
						array[rowOfQuadrantOne][columnOfQuandrantOne] = 0;
					} // if you change the number twice, reset to 0 so sudoku can be solved
					crossHatchingRowItems.clear(); //clear all items in vector so next row can use them
					crossHatchingColumnItems.clear(); //clear all items in vector so next row can use them
					moreThanOneNumberChange = 0;

				} //if a zero is found do this
			} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
				//number of a quadrant
		break;
	case 6:
		for (int rowOfQuadrantOne = 3; rowOfQuadrantOne <= 5; rowOfQuadrantOne++)
			for (int columnOfQuandrantOne = 6; columnOfQuandrantOne <= 8; columnOfQuandrantOne++)
			{
				if (array[rowOfQuadrantOne][columnOfQuandrantOne] == 0)
				{
					for (int checkingAllRowsOfThisZero = 0; checkingAllRowsOfThisZero < 9; checkingAllRowsOfThisZero++)
					{
						if (array[checkingAllRowsOfThisZero][columnOfQuandrantOne] != 0)
						{
							crossHatchingColumnItems.push_back(array[checkingAllRowsOfThisZero][columnOfQuandrantOne]);
						} // go down the different rows of a column, place non-zero numbers into a vector to help solve sudoku
					}

					for (int checkingAllColumnsOfThisZero = 0; checkingAllColumnsOfThisZero < 9; checkingAllColumnsOfThisZero++)
					{
						if (array[rowOfQuadrantOne][checkingAllColumnsOfThisZero] != 0)
						{
							crossHatchingRowItems.push_back(array[rowOfQuadrantOne][checkingAllColumnsOfThisZero]);
						} // go down the different columns of a row, place non-zero numbers into a vector to help solve sudoku
						//store it in a vector
					}

					for (int missingNumber = 1; missingNumber <= 9; missingNumber++)
					{
						if (missingNumber != array[3][6] && missingNumber != array[3][7] && missingNumber != array[3][8] &&
							missingNumber != array[4][6] && missingNumber != array[4][7] && missingNumber != array[4][8] &&
							missingNumber != array[5][6] && missingNumber != array[5][7] && missingNumber != array[5][8] &&
							find(crossHatchingRowItems.begin(), crossHatchingRowItems.end(), missingNumber) == crossHatchingRowItems.end() &&
							find(crossHatchingColumnItems.begin(), crossHatchingColumnItems.end(), missingNumber) == crossHatchingColumnItems.end())
						{
							array[rowOfQuadrantOne][columnOfQuandrantOne] = missingNumber;
							moreThanOneNumberChange++;
						} //if missing number doesn't equal numbers in row or columns, then place it in the empty spot
					} //checking for missing number in the row
					if (moreThanOneNumberChange > 1)
					{
						array[rowOfQuadrantOne][columnOfQuandrantOne] = 0;
					} // if you change the number twice, reset to 0 so sudoku can be solved
					crossHatchingRowItems.clear(); //clear all items in vector so next row can use them
					crossHatchingColumnItems.clear(); //clear all items in vector so next row can use them
					moreThanOneNumberChange = 0;

				} //if a zero is found do this
			} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
				//number of a quadrant
		break;
	case 7:
		for (int rowOfQuadrantOne = 6; rowOfQuadrantOne <= 8; rowOfQuadrantOne++)
			for (int columnOfQuandrantOne = 0; columnOfQuandrantOne <= 2; columnOfQuandrantOne++)
			{
				if (array[rowOfQuadrantOne][columnOfQuandrantOne] == 0)
				{
					for (int checkingAllRowsOfThisZero = 0; checkingAllRowsOfThisZero < 9; checkingAllRowsOfThisZero++)
					{
						if (array[checkingAllRowsOfThisZero][columnOfQuandrantOne] != 0)
						{
							crossHatchingColumnItems.push_back(array[checkingAllRowsOfThisZero][columnOfQuandrantOne]);
						} // go down the different rows of a column, place non-zero numbers into a vector to help solve sudoku
					}

					for (int checkingAllColumnsOfThisZero = 0; checkingAllColumnsOfThisZero < 9; checkingAllColumnsOfThisZero++)
					{
						if (array[rowOfQuadrantOne][checkingAllColumnsOfThisZero] != 0)
						{
							crossHatchingRowItems.push_back(array[rowOfQuadrantOne][checkingAllColumnsOfThisZero]);
						} // go down the different columns of a row, place non-zero numbers into a vector to help solve sudoku
						//store it in a vector
					}

					for (int missingNumber = 1; missingNumber <= 9; missingNumber++)
					{
						if (missingNumber != array[6][0] && missingNumber != array[6][1] && missingNumber != array[6][2] &&
							missingNumber != array[7][0] && missingNumber != array[7][1] && missingNumber != array[7][2] &&
							missingNumber != array[8][0] && missingNumber != array[8][1] && missingNumber != array[8][2] &&
							find(crossHatchingRowItems.begin(), crossHatchingRowItems.end(), missingNumber) == crossHatchingRowItems.end() &&
							find(crossHatchingColumnItems.begin(), crossHatchingColumnItems.end(), missingNumber) == crossHatchingColumnItems.end())
						{
							array[rowOfQuadrantOne][columnOfQuandrantOne] = missingNumber;
							moreThanOneNumberChange++;
						} //if missing number doesn't equal numbers in row or columns, then place it in the empty spot
					} //checking for missing number in the row
					if (moreThanOneNumberChange > 1)
					{
						array[rowOfQuadrantOne][columnOfQuandrantOne] = 0;
					} // if you change the number twice, reset to 0 so sudoku can be solved
					crossHatchingRowItems.clear(); //clear all items in vector so next row can use them
					crossHatchingColumnItems.clear(); //clear all items in vector so next row can use them
					moreThanOneNumberChange = 0;

				} //if a zero is found do this
			} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
				//number of a quadrant
		break;
	case 8:
		for (int rowOfQuadrantOne = 6; rowOfQuadrantOne <= 8; rowOfQuadrantOne++)
			for (int columnOfQuandrantOne = 3; columnOfQuandrantOne <= 5; columnOfQuandrantOne++)
			{
				if (array[rowOfQuadrantOne][columnOfQuandrantOne] == 0)
				{
					for (int checkingAllRowsOfThisZero = 0; checkingAllRowsOfThisZero < 9; checkingAllRowsOfThisZero++)
					{
						if (array[checkingAllRowsOfThisZero][columnOfQuandrantOne] != 0)
						{
							crossHatchingColumnItems.push_back(array[checkingAllRowsOfThisZero][columnOfQuandrantOne]);
						} // go down the different rows of a column, place non-zero numbers into a vector to help solve sudoku
					}

					for (int checkingAllColumnsOfThisZero = 0; checkingAllColumnsOfThisZero < 9; checkingAllColumnsOfThisZero++)
					{
						if (array[rowOfQuadrantOne][checkingAllColumnsOfThisZero] != 0)
						{
							crossHatchingRowItems.push_back(array[rowOfQuadrantOne][checkingAllColumnsOfThisZero]);
						} // go down the different columns of a row, place non-zero numbers into a vector to help solve sudoku
						//store it in a vector
					}

					for (int missingNumber = 1; missingNumber <= 9; missingNumber++)
					{
						if (missingNumber != array[6][3] && missingNumber != array[6][4] && missingNumber != array[6][5] &&
							missingNumber != array[7][3] && missingNumber != array[7][4] && missingNumber != array[7][5] &&
							missingNumber != array[8][3] && missingNumber != array[8][4] && missingNumber != array[8][5] &&
							find(crossHatchingRowItems.begin(), crossHatchingRowItems.end(), missingNumber) == crossHatchingRowItems.end() &&
							find(crossHatchingColumnItems.begin(), crossHatchingColumnItems.end(), missingNumber) == crossHatchingColumnItems.end())
						{
							array[rowOfQuadrantOne][columnOfQuandrantOne] = missingNumber;
							moreThanOneNumberChange++;
						} //if missing number doesn't equal numbers in row or columns, then place it in the empty spot
					} //checking for missing number in the row
					if (moreThanOneNumberChange > 1)
					{
						array[rowOfQuadrantOne][columnOfQuandrantOne] = 0;
					} // if you change the number twice, reset to 0 so sudoku can be solved
					crossHatchingRowItems.clear(); //clear all items in vector so next row can use them
					crossHatchingColumnItems.clear(); //clear all items in vector so next row can use them
					moreThanOneNumberChange = 0;

				} //if a zero is found do this
			} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
				//number of a quadrant
		break;
	case 9:
		for (int rowOfQuadrantOne = 6; rowOfQuadrantOne <= 8; rowOfQuadrantOne++)
			for (int columnOfQuandrantOne = 6; columnOfQuandrantOne <= 8; columnOfQuandrantOne++)
			{
				if (array[rowOfQuadrantOne][columnOfQuandrantOne] == 0)
				{
					for (int checkingAllRowsOfThisZero = 0; checkingAllRowsOfThisZero < 9; checkingAllRowsOfThisZero++)
					{
						if (array[checkingAllRowsOfThisZero][columnOfQuandrantOne] != 0)
						{
							crossHatchingColumnItems.push_back(array[checkingAllRowsOfThisZero][columnOfQuandrantOne]);
						} // go down the different rows of a column, place non-zero numbers into a vector to help solve sudoku
					}

					for (int checkingAllColumnsOfThisZero = 0; checkingAllColumnsOfThisZero < 9; checkingAllColumnsOfThisZero++)
					{
						if (array[rowOfQuadrantOne][checkingAllColumnsOfThisZero] != 0)
						{
							crossHatchingRowItems.push_back(array[rowOfQuadrantOne][checkingAllColumnsOfThisZero]);
						} // go down the different columns of a row, place non-zero numbers into a vector to help solve sudoku
						//store it in a vector
					}

					for (int missingNumber = 1; missingNumber <= 9; missingNumber++)
					{
						if (missingNumber != array[6][6] && missingNumber != array[6][7] && missingNumber != array[6][8] &&
							missingNumber != array[7][6] && missingNumber != array[7][7] && missingNumber != array[7][8] &&
							missingNumber != array[8][6] && missingNumber != array[8][7] && missingNumber != array[8][8] &&
							find(crossHatchingRowItems.begin(), crossHatchingRowItems.end(), missingNumber) == crossHatchingRowItems.end() &&
							find(crossHatchingColumnItems.begin(), crossHatchingColumnItems.end(), missingNumber) == crossHatchingColumnItems.end())
						{
							array[rowOfQuadrantOne][columnOfQuandrantOne] = missingNumber;
							moreThanOneNumberChange++;
						} //if missing number doesn't equal numbers in row or columns, then place it in the empty spot
					} //checking for missing number in the row
					if (moreThanOneNumberChange > 1)
					{
						array[rowOfQuadrantOne][columnOfQuandrantOne] = 0;
					} // if you change the number twice, reset to 0 so sudoku can be solved
					crossHatchingRowItems.clear(); //clear all items in vector so next row can use them
					crossHatchingColumnItems.clear(); //clear all items in vector so next row can use them
					moreThanOneNumberChange = 0;

				} //if a zero is found do this
			} //must check the missing number between 1 and 10, of this series of rows, of this series of columns to get the missing
				//number of a quadrant
		break;
	default:
		cout << "";
		break;
	}
} // void crossHatching(int array[][9], int quadrant, int amountOfZeroes)

