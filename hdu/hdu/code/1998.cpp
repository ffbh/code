#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[21][21];
int N;
struct Point{
	int x, y;
};

Point getNext(const Point& p){
	Point n;
	n.x = (p.x - 1 + N) % N;
	n.y = (p.y + 1 ) % N;
	if (data[n.x][n.y] == 0)
		return n;
	n.x = (p.x + 1) % N;
	n.y = p.y;
	return n;
}


int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int cnt;
	while (T--){
		cin >> N;
		memset(data, 0, sizeof(data));
		int x, y, nextx, nexty;
		cnt = 1;
		Point temp;
		temp.x = 0;
		temp.y = N / 2;
		int M = N*N;
		while (M--){
			data[temp.x][temp.y] = cnt++;
			temp = getNext(temp);
		}
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j)
				printf("%4d", data[i][j]);
			putchar('\n');
		}
	}
	return 0;
}