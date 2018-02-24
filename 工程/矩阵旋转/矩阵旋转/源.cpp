#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
const int N = 5;

int data[N + 1][N + 1], temp[N + 1][N + 1];
void show(){
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= N; ++j)
			cout << data[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

/*void clockwiserotate(){
	for (int i = 1; i <= (N+1)/2;++i)
	for (int j = 1; j <= N/2;++j){
	//	vis[i][j] = vis[j][N - i + 1] = vis[N - i + 1][N - j + 1] = vis[N - j + 1][i] = 1;
		int tmp = data[i][j];
		data[i][j] = data[j][N - i + 1];
		data[j][N - i + 1] = data[N - i + 1][N - j + 1];
		data[N - i + 1][N - j + 1] = data[N - j + 1][i];
		data[N - j + 1][i] = tmp;
	}

}*/


void clockwiserotatepart(int sx,int ex,int sy,int ey){
	int n = ex - sx + 1;
	for (int i = sx; i <= (sx+ex)/2;++i)
	for (int j = sy; j <= (sy+ey-1)/2; ++j){
	/*	vis[i][j] = vis[j + sx - sy][n - i + sx + sy - 1] 
			= vis[n - i + 2 * sx - 1][n - j + 2 * sy - 1]
			= vis[n - j + sx + sy - 1][i - sx + sy] = 1;*/
		int tmp = data[i][j];
		data[i][j] = data[j + sx - sy][n - i + sx + sy - 1];
		data[j + sx - sy][n - i + sx + sy - 1] = data[n - i + 2 * sx - 1][n - j + 2 * sy - 1];
		data[n - i + 2 * sx - 1][n - j + 2 * sy - 1] = data[n - j + sx + sy - 1][i - sx + sy];
		data[n - j + sx + sy - 1][i - sx + sy] = tmp;
	}
}

int main(){
	ifstream in("C:\\input.txt");
	int s = 10;
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= N; ++j)
		data[i][j] = s++;
	show();

//	clockwiserotate();
//	clockwiserotatepart(1, 3, 2, 4);
	clockwiserotatepart(2, 3, 3, 4);

	show();













	return 0;
}