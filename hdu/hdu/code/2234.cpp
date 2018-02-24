#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
int map[5][5];
int MAXSTEP;
bool OK(){
	if (map[1][1] == map[1][2]){
		for (int i = 1; i <= 4;++i)
		for (int j = 2; j <= 4;++j)
		if (map[i][j] != map[i][1])
			return 0;
		return 1;
	}
	else {
		for (int i = 1; i <= 4; ++i)
		for (int j = 2; j <= 4; ++j)
		if (map[j][i] != map[1][i])
			return 0;
		return 1;
	}
}


void change(int n){
	int temp;
	if (abs(n) <= 4){
		if (n > 0){
			temp = map[n][4];
			for (int i = 4; i > 1; --i)
				map[n][i] = map[n][i - 1];
			map[n][1] = temp;
		}
		else{
			n = -n;
			temp = map[n][1];
			for (int i = 2; i <= 4; ++i)
				map[n][i - 1] = map[n][i];
			map[n][4] = temp;
		}
	}
	else{
		if (n > 0){
			n -= 4;
			temp = map[4][n];
			for (int i = 4; i > 1; --i)
				map[i][n] = map[i - 1][n];
			map[1][n] = temp;
		}
		else{
			n = -n; 
			n -= 4;
			temp = map[1][n];
			for (int i = 2; i <= 4; ++i)
				map[i - 1][n] = map[i][n];
			map[4][n] = temp;
		}
	}
}

bool dfs(int u){
	if (u == MAXSTEP)
		return 0;
	for (int i = 1; i <= 8; ++i){
		change(i);
		if (OK()||dfs(u+1))
			return 1;
		change(-i);
	}
	for (int i = -8; i <= -1; ++i){
		change(i);
		if (OK() || dfs(u + 1))
			return 1;
		change(-i);
	}
	return 0;
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		for (int i = 1; i <= 4;++i)
		for (int j = 1; j <= 4; ++j)
			cin>>map[i][j];
		if (OK()){
			cout << 0 << endl;
			continue;
		}
		for (MAXSTEP = 1; MAXSTEP <= 5; ++MAXSTEP){
			if (dfs(0))
				break;
		}
		if (MAXSTEP <= 5)
			cout << MAXSTEP << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}