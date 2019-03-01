#include <stdio.h>

void printArray(char *arr, int row, int col, int set[]) {
	printf("0 | ");
	for (register int j = 0; j < col; j++) 
		printf("%d ", *(arr + j));
	printf("\n");
	
	for (register int i = 1; i < row; i++) {
			printf("%d | ", set[i-1]); 
		for (register int j = 0; j < col; j++) {
			printf("%d ", *((arr+i*col) + j));
		}
		printf("\n");
	}
}

int isSubsetSum(int set[], int n, int sum) {
	// Make array with (set element X sum)  

	char dp[n+1][sum+1];

	// Make base condition for 0
	dp[0][0] = 1;
	for (register int j = 1; j < sum+1; j++)
		dp[0][j] = 0;

	// Make dp array
	for (register int i = 1; i < n+1; i++) {
		for (register int j = 0; j < sum+1; j++) {
			if (set[i-1] == j) {
				dp[i][j] = 1;
			}
			else if (set[i-1] > j) {
				dp[i][j] = dp[i-1][j];		
			} else if (set[i-1] < j) {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
			}
		}
	}
	
	//printArray((char *)dp, n+1, sum+1, set);

	return dp[n][sum];
}

int main()
{
	int set[] = {3, 34, 4, 12, 5, 2};
	int sum = 1;
	int n = sizeof(set) / sizeof(set[0]);

	if (isSubsetSum(set, n, sum) == 1)
		printf("Found a subset with given sum\n");
	else
		printf("No subset with given sum\n");

	return 0;
}
