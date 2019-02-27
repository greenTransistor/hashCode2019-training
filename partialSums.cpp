#include <iostream>

using namespace std;

pair <int, int> partSums[MAX_SIZE][MAX_SIZE];
int rowSums[MAX_SIZE][MAX_SIZE];

void calcSum(int n, int m){
	
	
	for (int i = 1; i < n; i++)
		for (int j = 0; j < m; j++)
			partSums[i][j] = partSums[i-1][j] + rowSums[i][j];
}

pair <int, int> sumRect(Rect r){
	
	
}
