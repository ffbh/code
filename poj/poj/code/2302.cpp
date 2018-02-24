#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
struct Node{
	int x, y;
}index[80];
bool mark[6][6];
int data[6][6];
int bin[80];

bool judge(int x, int y){
	mark[x][y] = 1;
	bool f = 1;
	if (x == y){
		for (int i = 1; i <= 5; ++i)
		if (!mark[i][i]){
			f = 0;
			break;
		}
	}
	else
		f = 0;

	if (f)
		return 1;
	f = 1;
	if (x + y == 6){
		for (int i = 1; i <= 5; ++i)
		if (!mark[i][6 - i]){
			f = 0;
			break;
		}
	}
	else
		f = 0;
	if (f)
		return 1;
	f = 1;
	for (int i = 1; i <= 5; ++i)
	if (!mark[i][y]){
		f = 0;
		break;
	}
	if (f)
		return 1;
	f = 1;
	for (int i = 1; i <= 5;++i)
	if (!mark[x][i]){
		f = 0;
		break;
	}
	return f;
}

int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	while (T--){
		memset(mark, 0, sizeof(mark));
		memset(index, -1, sizeof(index));
		for (int i = 1; i <= 5;++i)
		for (int j = 1; j <= 5; ++j){
			if (i == 3 && j == 3)
				continue;
			cin >> data[i][j];
			index[data[i][j]].x = i;
			index[data[i][j]].y = j; 
		}
		for (int i = 1; i <= 75; ++i)
			cin >> bin[i];
		int ans = -1;
		for (int i = 1; i <= 75; ++i){
			if (index[bin[i]].x == -1){
				if (!mark[3][3]){
					if (judge(3, 3)){
						ans = i;
						break;
					}
				}
				else
					continue;
			}
			else{
				if (judge(index[bin[i]].x, index[bin[i]].y)){
					ans = i;
					break;
				}
			}
		}
		printf("BINGO after %d numbers announced\n", ans);
	}
	return 0;
}