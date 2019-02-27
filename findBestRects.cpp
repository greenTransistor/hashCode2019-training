void findBestRects() {
	int maxWidth;
	int prevMaxWidth;
	int maxArea = h;
	pair<int, int> rectangleContent;
	Rect currentRect;

	for (int x = 0; x < c; x++) {
		for (int y = 0; y < r; y++) {
			prevMaxWidth = 0;
			for (int height = min(r - y, maxArea); height >= 1; height--) {
				maxWidth = min(c - x, maxArea / height);
				if (maxWidth == prevMaxWidth) {
					continue;
				}

				currentRect = Rect(x, y, x + maxWidth - 1, y + height - 1);
				rectangleContent = sumRect(currentRect);
				if (rectangleContent.first >= l && rectangleContent.second >= l) {
					rects[y][x].push_back(currentRect);
				}
				prevMaxWidth = maxWidth;
			}
		}
	}
}
