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
#include <thread>

using namespace std;

const int THREADS_COUNT = 4;
bool used[MAX_SIZE][MAX_SIZE];
vector <Rect> answers[THREADS_COUNT];

int fitPosition(int str, int stc) {
	int i = stc + 1;
	while (i < r && !used[str][i]) {
		i++;
	}
	vector <Rect> rs = rects[str][stc];
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
				int pos = rand() % (maxFit + 1);
				Rect cur = rects[i][j][pos];
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
		s += (r.x1 - r.x0 + 1) * (r.y1 - r.y0 + 1);
	}
	return s;
}

void findOptimalSlicesThread(int thn) {
	int mxC = 0;
	vector <Rect> res;
	for (int i = 0; i < ATTEMPTS_COUNT; i++) {
		vector <Rect> curR = randomSlices();
		int curC = cellsCount(curR);
		if (curC > mxC) {
			mxC = curC;
			answers[thn] = curR;
		}
	}
} 

void findOptimalSlices() {
	thread* ths[THREADS_COUNT];
	for (int i = 0; i < THREADS_COUNT; i++) {
		ths[i] = new thread(findOptimalSlicesThread, i);
	}
	int mxC = 0;
	for (int i = 0; i < THREADS_COUNT; i++) {
		ths[i]->join();
		int curC = cellsCount(answers[i]);
		if (curC > mxC) {
			mxC = curC;
			answer = answers[i];
		}
	}
}
