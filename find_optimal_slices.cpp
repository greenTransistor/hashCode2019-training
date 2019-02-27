#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <set>

using namespace std

bool used[MAX_SIZE][MAX_SIZE];



vector <Rect> randomSlices() {
	vector <Rect> res;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			used[i][j] = false;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!used[i][j]) {
				Rect cur = randomRect(i, j);
			}
		}
	}
}

void findOptimalSlices() {
	int mxC = 0;
	for (int i = 0; i < ATTEMPTS_COUNT; i++) {
		vector <Rect> curR = randomSlices();
		int curC = cellsCount(curSl);
		if (curC > mxC) {
			mxC = curC;
			answer = curR;
		}
	}
	return optR;
}

int main() {
	findOptimalSlices();
}

