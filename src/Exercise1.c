/*
1.	Write a program to construct the Pascal triangle with the given integer n.
Ex:
______________________________________
| Input: 3                           |
| Output:                            |
| 1                                  |
| 1 1                                |
| 1 2 1                              |
| 1 3 3 1                            |
|____________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// tinh tong hop c
int C (int a, int z){
	if(a==0||a==z) return 1;
	if(a==1) return z;
	return C(a-1, z-1) + C(a,z-1);
}

void Ex1(int n){
	//Your codes here
    for(int i = 0; i <= n; i++){
		for(int j = 0; j <= i; j++){
			printf("%d ",C(j,i));
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	int testcase = atoi(argv[1]);
	
	Ex1(testcase);
	return 0;
}
