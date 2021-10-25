/*
3.	Input an array of n x n (n is even). Sort the first diagonal in
increasing order and the second diagonal in decreasing order.
First diagonal starts with element [0,0], second diagonal starts with elements [n-1,0]
Ex:
_________________________________________________________________
| Input: 4(edge) 10 21 12 53 64 53 86 72 68 99 10 11 12 13 14 15 |
| The converted 2D array will be like this:                      |
| 10 21 12 53                                                    |
| 64 53 86 72                                                    |
| 68 99 10 11                                                    |
| 12 13 14 15                                                    |
| Output:                                                        |
| 10 21 12 12                                                    |
| 64 10 53 72                                                    |
| 68 86 15 11                                                    |
| 99 13 14 53                                                    |
|________________________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void Array2Dconverter(int arr[], int a[SIZE][SIZE], int m, int n)
{
	int row, column;
	int counter = 0;
	//Convert 1D array to 2D array
	for (row = 0; row <= (m - 1); row ++){
		for (column = 0; column <= (n - 1); column ++){
			a[row][column] = arr[counter];
			counter++;
		}
	}
}

void printArray(int a[SIZE][SIZE], int m, int n)
{
	int row, column;

	for (row = 0; row <= (m - 1); row ++){
		for (column = 0; column <= (n - 1); column ++){
			printf("%d ", a[row][column]);
		}
		printf("\n");
	}
}

void Ex3(int in_arr[], int n){
	int a[SIZE][SIZE];
	Array2Dconverter(in_arr,a,n,n);
	//Your codes here
	for(int col =0; col <= n; col++){
        for(int row =0; row <= n; row++){
         for(int sort_col = col +1; sort_col <= n; sort_col++){
             for(int sort_row = row +1 ; sort_row <= n; sort_row++){  
                 if(col==row && sort_col == sort_row && a[row][col] < a[sort_row][sort_col]){
                    int temp = a[row][col];
					a[row][col] = a[sort_row][sort_col];
					a[sort_row][sort_col] = temp;
                 }
                 if(col+row == n+1 && sort_col + sort_row == n+1 && a[row][col] > a[sort_row][sort_col]){
                    int temp = a[row][col];
					a[row][col] = a[sort_row][sort_col];
					a[sort_row][sort_col] = temp;
                 }
            
            }
         }
         
        }
    }
	printArray(a,n,n);
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	int edge = atoi(argv[1]);
	argc-=2;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+2]);
	}

	Ex3(testcase, edge);
	
	return 0;
}



/*

  21 10 53 12 
  53 64 72 86 
  99 68 11 10 
  13 12 15 14 

11 10 53 12 
53 14 13 86 
99 68 21 10 
72 12 15 64

*/