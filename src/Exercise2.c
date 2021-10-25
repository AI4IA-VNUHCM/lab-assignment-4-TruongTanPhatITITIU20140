/*
2.	Write a program to input an array of m x n.
Sort the odd col in increasing order and the
even col in decreasing order.
Ex:
___________________________________________________________________________________
| Input: 5(row) 4(col) 10 21 12 53 64 53 86 72 68 99 10 11 12 13 14 15 16 17 18 19 |
| The converted 2D array will be like this:                                        |
| 10 21 12 53                                                                      |
| 64 53 86 72                                                                      |
| 68 99 10 11                                                                      |
| 12 13 14 15                                                                      |
| 16 17 18 19                                                                      |
| Output:                                                                          |
| 68 13 86 11                                                                      |
| 64 17 18 15                                                                      |
| 16 21 14 19                                                                      |
| 12 53 12 53                                                                      |
| 10 99 10 72                                                                      |
|__________________________________________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void Array2Dconverter(int arr[], int a[SIZE][SIZE], int m, int n)
{
	int row, col;
	int counter = 0;
	//Convert 1D array to 2D array
	for (row = 0; row <= (m - 1); row ++){
		for (col = 0; col <= (n - 1); col ++){
			a[row][col] = arr[counter];
			counter++;
		}
	}
}

void printArray(int a[SIZE][SIZE], int m, int n)
{
	int row, col;

	for (row = 0; row <= (m - 1); row ++){
		for (col = 0; col <= (n - 1); col ++){
			printf("%d ", a[row][col]);
		}
		printf("\n");
	}
}

void Ex2(int arr[], int m, int n){
	int a[SIZE][SIZE];
	Array2Dconverter(arr,a,m,n);
	//Your codes here
	int col, row;
	for(col = 0; col < n; col++){
		for(row = 0; row < m; row++){
			for(int sort = row + 1; sort < m; sort++){
					if((a[row][col] - a[sort][col]) * ((col % 2 + 1) * 2 - 3) > 0){
							int temp = a[row][col];
							a[row][col] = a[sort][col];
							a[sort][col] = temp;
					}
			}
		}
	}
	printArray(a, m, n);
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);
	argc-=3;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+3]);
	}

	Ex2(testcase, row, col);
	
	return 0;
}
