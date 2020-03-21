#include <iostream>
#include <vector>
#include <queue>

/*
题目描述：二维矩阵中的数字0表示背景，1表示前景，前景可以上下左右判断是否相连接，现在设定
相连接的前景个数不得小于4，否则认为是噪声，实现该算法，获取所有有效的前景坐标
（字节跳动面试题）
*/

struct Point {
	int x;
	int y;
	Point(int x, int y):x(x),y(y) {}
};


std::vector<Point>  denoise1(std::vector<std::vector<int> > matrix, int threshold) {
	std::vector<Point> res;
	std::vector<std::vector<int> > viewed(matrix.size(), std::vector<int>(matrix[0].size(), 0));

	std::queue<Point> queue;

	for (int i = 0; i < matrix.size(); i ++) {
		for (int j = 0; j < matrix[0].size(); j ++) {
			if (viewed[i][j] == 0) {
				viewed[i][j] = 1;
				if (matrix[i][j] == 1) {
					
					std::vector<Point> set;
					int count = 0;
					queue.push(Point(i, j));

					while (!queue.empty()) {
						Point point = queue.front();
						queue.pop();
						count++;
						set.push_back(point);
	
						if (point.x - 1 >= 0 && point.x - 1 < matrix.size() && viewed[point.x - 1][point.y] == 0) {
							viewed[point.x - 1][point.y] = 1;
							if (matrix[point.x - 1][point.y] == 1) {
								queue.push(Point(point.x - 1, point.y));
							}
						}
						if (point.x + 1 >= 0 && point.x + 1 < matrix.size() && viewed[point.x + 1][point.y] == 0) {
							viewed[point.x + 1][point.y] = 1;
							if (matrix[point.x + 1][point.y] == 1) {
								queue.push(Point(point.x + 1, point.y));
							}
						}
						if (point.y - 1 >= 0 && point.y - 1 < matrix[0].size() && viewed[point.x][point.y - 1] == 0) {
							viewed[point.x][point.y - 1] = 1;
							if (matrix[point.x][point.y - 1] == 1) {
								queue.push(Point(point.x, point.y - 1));
							}
						}
						if (point.y + 1 >= 0 && point.y + 1 < matrix[0].size() && viewed[point.x][point.y + 1] == 0) {
							viewed[point.x][point.y + 1] = 1;
							if (matrix[point.x][point.y + 1] == 1) {
								queue.push(Point(point.x, point.y + 1));
							}
						}
					}
					if (count >= threshold) {
						res.assign(set.begin(), set.end());
					}
				}
			}
		}
	}
	
	return res;
}


int main() {

	std::vector<std::vector<int> > matrix = {
		{0, 0, 0, 1, 1},
		{1, 1, 1, 0, 1},
		{0, 1, 1, 0, 0},
		{1, 1, 1, 1, 1}
	};
	int threshold = 4;

	std::vector<Point> res = denoise1(matrix, threshold);

	for (int i = 0; i < res.size(); i ++) {
		std::cout << "(" << res[i].x << "," << res[i].y << ")" << std::endl;
	}

	return 0;
}