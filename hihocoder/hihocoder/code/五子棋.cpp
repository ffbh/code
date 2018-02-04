#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int map[20][20];
char s[20];
int dir[4][2] = { 1, 0, 0, 1, 1, 1 ,1,-1};
bool judge(int x,int y){

	for (int i = 0; i < 4; ++i){
		bool ok = 1;
		for (int j = 1; j <= 4; ++j){
			int nowx = x + j * dir[i][0];
			int nowy = y + j * dir[i][1];
			if (nowx>15 || nowx<1 || nowy>15 || nowy < 1){
				ok = 0;
				break;
			}
			if(map[x][y] != map[nowx][nowy]){
				ok = 0;
				break;
			}
			
		}
		if (ok)
				return 1;
	}
	return 0;

}

int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	bool white, black;
	while (T--){
		white = black = 0;
		for (int i = 1; i <= 15; ++i){

			cin >> s + 1;
			for (int j = 1; j <= 15;++j)
			if (s[j] == '.')
				map[i][j] = 0;
			else if (s[j] == 'W')
				map[i][j] = 1;
			else
				map[i][j] = -1;
		}
		for (int i = 1; i <= 15;++i)
		for (int j = 1; j <= 15; ++j){
			if (map[i][j] == 1 && !white){
				white = judge(i, j);
			}
			if (map[i][j] == -1 && !black){
				black = judge(i, j);
			}
		}
		if (white && black)
			cout << "Both" << endl;
		else if (white && !black)
			cout << "White" << endl;
		else if (!white && black)
			cout << "Black" << endl;
		else
			cout << "None" << endl;
	}
	return 0;
}