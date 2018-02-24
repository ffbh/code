#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[4][50];
bool vis[50][50][50][50];
int ptr[4];
int tar[10];
int ptrb;
int mmax;
int Del(int n){
	int ret = tar[n];
	for (int i = n; i < ptrb; ++i)
		tar[i] = tar[i + 1];
	ptrb--;
	return ret;
}

void getBack(int n, int num){
	for (int i = ptrb; i>n; --i)
		tar[i] = tar[i - 1];
	tar[n] = num;
	ptrb++;
}

void dfs(int num){
	if (vis[ptr[0]][ptr[1]][ptr[2]][ptr[3]])
		return;
	vis[ptr[0]][ptr[1]][ptr[2]][ptr[3]] = 1;
	if (num > mmax)
		mmax = num;
	if (ptrb == 5)
		return;
	for (int i = 0; i < ptrb; ++i){
		for (int j = 0; j < 4;++j)
		if (ptr[j] <= data[j][0] && data[j][ptr[j]] == tar[i]){
			int ret = Del(i);
			ptr[j]++;
			dfs(num + 2);
			ptr[j]--;
			getBack(i, ret);
		}
	}
	for (int j = 0; j < 4; ++j)
		if (ptr[j] <= data[j][0]){
			tar[ptrb] = data[j][ptr[j]];
			ptrb++;
			ptr[j]++;
			dfs(num);
			ptr[j]--;
			ptrb--;
		}
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	//cin >> T;
	scanf("%d", &T);
	while (T--){
		mmax = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < 4; ++i){
			ptr[i] = 1;
			//cin >> data[i][0];
			scanf("%d", &data[i][0]);
			for (int j = 1; j <= data[i][0]; ++j)
				//cin >> data[i][j];
				scanf("%d", &data[i][j]);
		}
		ptrb = 0;
		dfs(0);
		cout << mmax << endl;
	}





	return 0;
}