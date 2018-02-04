#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N;
bool map[100][100];

int fun(int x,int y){
	if (map[x][y])
		return 0;
	int ans = 1;
	int minx = N, miny = N;
	for (int i = x+1; i < N;++i)
	if (map[i][y] == 0)
		ans++;
	else{
		minx = i;
		break;
	}

	for (int i = y+1; i < N;++i)
	if (map[x][i]==0)
		ans++;
	else{
		miny = i;
		break;
	}
	for (int i = x + 1; i < minx;++i)
	for (int j = y + 1; j < miny;++j)
	if (map[i][j]==0)
		ans++;
	else{
		miny = j;
		break;
	}
	return ans;
}


int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	while (cin >> N){
		for (int i = 0; i < N; ++i){
			cin >> s;
			for (int j = 0; j < N;++j)
			if (s[j] == '#')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
		int ans = 0;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j)
			ans += fun(i, j);
		cout << ans << endl;

	}





	return 0;
}