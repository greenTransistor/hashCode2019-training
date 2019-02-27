#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 1001;
const int ATTEMPTS_COUNT = 10;

struct Rect {
	int x0, y0, x1, y1;
	Rect(x0, y0, x1, y1) {
		this->x0 = x0;
		this->y0 = y0;
		this->x1 = x1;
		this->y1 = y1;
	}
};

int r, c, l, h;
char a[MAX_SIZE][MAX_SIZE];
vector<Rect> rects[MAX_SIZE][MAX_SIZE];
vector<Rect> answer;

#include "partialSums.cpp"
#include "findBestRects.cpp"

int main() {
	ifstream inf("a_example.in");
	//ifstream inf("b_small.in");
	//ifstream inf("c_medium.in");
	//ifstream inf("d_big.in");
	inf >> r >> c >> l >> h;
	for (int i = 0; i < r; i++) {
		inf >> a[i];
	}
	inf.close();

	calcSum();
	findBestRects();

	return 0;
}
