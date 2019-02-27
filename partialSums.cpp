#include <iostream>


pair<int, int> partSums[MAX_SIZE][MAX_SIZE];
pair<int, int> rowSums[MAX_SIZE][MAX_SIZE];

void addToPair(pair <int, int>& p, char c){
	
	if (c == 'M') p.first++;
	else p.second++;
}

pair <int, int> pairSum(pair <int, int> p1, pair <int, int> p2){
	return make_pair(p1.first + p2.first, p1.second + p2.second);
}

pair <int, int> pairOp(pair <int, int> p){
	return make_pair(-p.first, -p.second);
}

void calcSum(){
	
	for (int i = 0; i < r; i++){
		rowSums[i][0] = make_pair(0,0);
		addToPair(rowSums[i][0], a[i][0]);
		for (int j = 1; j < c; j++){
			rowSums[i][j] = rowSums[i][j-1];
			addToPair(rowSums[i][j], a[i][j]);			
		}
			
	}
	
	for (int j = 0; j < r; j++)
		partSums[0][j] = rowSums[0][j];
	
	for (int i = 1; i < r; i++)
		for (int j = 0; j < c; j++)
			partSums[i][j] = pairSum(partSums[i-1][j], rowSums[i][j]);
}

pair <int, int> sumRect(Rect r){
	
	int x0 = r.x0,
		y0 = r.y0,
		x1 = r.x1,
		y1 = r.y1;
		
	pair<int,int> rect0 = ((x0 > 0 && y0 > 0) ? partSums[x0-1][y0-1] : make_pair(0,0)),
				  rect1 = (x0 > 0 ? partSums[x0-1][y1] : make_pair(0,0)),
				  rect2 = (y0 > 0 ? partSums[x1][y0-1] : make_pair(0,0)),
				  rect3 = partSums[x1][y1];
			
	return pairSum(rect3, pairSum(pairOp(rect1), pairSum(pairOp(rect2), rect0)));
}
