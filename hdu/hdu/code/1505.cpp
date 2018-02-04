#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M;
bool map[1010][1010];
int temp[1010][1010];


int getMax(int x, int y){
	
	if (map[x][y] == 0)return 0;
	int res = 1;//必须赋值为1，,因为sub矩阵中可能含有只有1个F的情况
	temp[x][y] = 1;
	int minn=N;
	int minm=M;
	for (int i = x + 1; i < N;++i)
	if (map[i][y]){
		temp[i][y] = temp[i - 1][y] + 1;
		if (res < temp[i][y])
			res = temp[i][y];
	}
	else {
		minn = i;
		break;
	}

	for (int i = y + 1; i < M;++i)
	if (map[x][i]){
		temp[x][i] = temp[x][i - 1] + 1;
		if (res < temp[x][i])
			res = temp[x][i];
	}
	else {
		minm = i;
		break;
	}
	

	for (int i = x + 1; i < minn;++i)
	for (int j = y + 1; j < minm; ++j){
		if (map[i][j]){
			temp[i][j] = temp[i - 1][j] + temp[i][j - 1] - temp[i - 1][j - 1] + 1;
			if (res < temp[i][j])
				res = temp[i][j];
		}
		else {
			minn = min(minn, i);
			minm = min(minm, j);
			break;
		}
	}
		
	return res;


}


bool GetInput(){
	char inn;
	while (inn = getchar())
	if (inn == 'R')
		return 0;
	else if (inn == 'F')
		return 1;
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	char c;
	while (T--){
		cin >> N >> M;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j)
			map[i][j] = GetInput();
	/*	{	in >> c;
			if (c == 'F')
				map[i][j] = 1;
			else map[i][j] = 0;
		}*/
		int ans = 0;
		for (int i=0;i<N;++i)
		for (int j = 0; j < M; ++j)
		if(map[i][j]){
			int res = getMax(i, j);
			if (res>ans)
				ans = res;
		}
		cout << ans*3 << endl;
	
	
	}
	return 0;
}