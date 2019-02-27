#include <fstream>
#include <iostream>

using namespace std;

const int MAX_SIZE = 1001;

int r, c, l, h;
char a[MAX_SIZE][MAX_SIZE];

int main() {
	ifstream inf("a_example.in");
	//ifstream inf("b_small.in");
	//ifstream inf("c_medium.in");
	//ifstream inf("d_big.in");
	inf >> r >> c >> l >> h;
	inf.close();

	return 0;
}
