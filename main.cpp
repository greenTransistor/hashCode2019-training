#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//Configurable, more = better result but worse performance (1000 for big is 65 seconds on Intel Core i5-7200U)
const int ATTEMPTS_COUNT = 10;

const int FILES_COUNT = 4;
const string FILE_NAMES[FILES_COUNT] = {"a_example", "b_small", "c_medium", "d_big"};
const int MAX_SIZE = 1001;

struct Rect {
	int x0, y0, x1, y1;
	Rect() {}
	Rect(int x0, int y0, int x1, int y1) {
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
#include "find_optimal_slices.cpp"

int main() {
	string fileName, inputFileName, outputFileName;
	for (int fileIndex = 0; fileIndex < FILES_COUNT; fileIndex++) {
		fileName = FILE_NAMES[fileIndex];
		inputFileName = fileName + ".in";
		outputFileName = fileName + ".out";

		ifstream inf(inputFileName);
		inf >> r >> c >> l >> h;
		for (int i = 0; i < r; i++) {
			inf >> a[i];
		}
		inf.close();

		calcSum();
		findBestRects();
		findOptimalSlices();

		ofstream outf(outputFileName);
		outf << answer.size() << "\n";
		for (int i = 0; i < answer.size(); i++) {
			outf << answer[i].y0 << " " << answer[i].x0 << " " << answer[i].y1 << " " << answer[i].x1 << "\n";
		}
		outf.close();
	}

	return 0;
}
