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

using namespace std;

bool used[MAX_SIZE][MAX_SIZE];

int fitPosition(int str, int stc) {
	int i = stc + 1;
	while (i < r && !used[str][i]) {
		i++;
	}
	Rect rs = rects[str][stc];
	int j = 0;
	while (j < rs.size() && rs[j].x1 < i) {
		j++;
	}
	return j - 1;
}

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
				if (rects[i][j].empty()) continue;
				int maxFit = fitPosition(i, j);
				if (maxFit == -1) continue;
				Rect cur = rects[i][j][rand() % (maxFit + 1)];
				for (int k = cur.y0; k <= cur.y1; k++) {
					for (int l = cur.x0; l <= cur.x1; l++) {
						used[k][l] = true;
					}
				}
				res.push_back(cur);
			}
		}
	}
	return res;
}

int cellsCount(vector <Rect> rs) {
	int s = 0;
	for (auto r : rs) {
		s += (r.x1 - r.x0) * (r.y1 - r.y0);
	}
	return s;
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
}
