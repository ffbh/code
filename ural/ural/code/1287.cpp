#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
bool mm[1500][1500];
bool vis[1500][1500][4];
int dirs[4][2] = { 1, 0, 0, 1, 1, 1 ,1,-1};
int N;
int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N){
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < N; ++j){
					mm[i][j] = (s[j] == 's');//s 1 S 0
			}
		}
		int Sans=0, sans=0;

		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j){
			bool c = mm[i][j];
			for (int k = 0; k < 4; ++k){
				int num;
				if (vis[i][j][k]){
				//	cout << "skip" << endl;
					continue;
				}
				int nx = i, ny = j;
				for (num = 1; num <= N; ++num){
					nx += dirs[k][0];
					ny += dirs[k][1];
					if (ny<0 ||nx >= N || ny >= N || mm[nx][ny] != c){
						break;
					}
					vis[nx][ny][k] = 1;
				}
				if (c){
					sans = max(sans, num);
				}
				else{
					Sans = max(Sans, num);
				}
			}
		}
		if (Sans > sans){
			cout << "S" << endl << Sans << endl;
		}
		else if (Sans == sans){
			cout << "?" << endl << Sans << endl;
		}
		else{
			cout << "s" << endl << sans << endl;
		}
	}


	return 0;
}