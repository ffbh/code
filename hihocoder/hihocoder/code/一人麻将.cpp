#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
int card[3][11];

string s;

int mark[4];
bool dfs(int dept){
	if (dept == 4){
		for (int i = 0; i < 3;++i)
		if (mark[i] == 0)
			return 1;
		return 0;
	}
	for (int i = 0; i < 3;++i)
	for (int j = 0; j < 10; ++j){
		if (card[i][j] >= 3){
			card[i][j] -= 3;
			mark[i]++;
			bool ret = dfs(dept + 1);
			mark[i]--;
			card[i][j] += 3;
			if (ret)
				return 1;
		}
	}
	for (int i = 0; i < 3;++i)
	for (int j = 2; j <= 8; ++j){
		if (card[i][j - 1] && card[i][j] && card[i][j + 1]){
			card[i][j - 1]--;
			card[i][j]--;
			card[i][j + 1]--;
			mark[i]++;
			bool ret = dfs(dept + 1);
			mark[i]--;
			card[i][j - 1]++;
			card[i][j]++;
			card[i][j + 1]++;
			if (ret)
				return 1;

		}

	}

	return 0;


}

bool judge(){

	for (int i = 0; i < 3; ++i){

		for (int j = 1; j < 10; ++j){
			if (card[i][j] >= 2){
				card[i][j] -= 2;
				mark[i]++;
				bool ret = dfs(0);
				mark[i]--;
				card[i][j] += 2;
				if (ret)
					return ret;
			}
		}
	}
	return 0;
}

bool judgeTwo(){
	int data[3];
	for (int k = 0; k < 3; ++k){
		data[k] = 0;
		for (int i = 0; i < 10; ++i){
			data[k] += card[k][i] / 2;
		}
	}
	return data[0] + data[1] >= 7 || data[0] + data[2] >= 7 || data[1] + data[2] >= 7;
}


int main(){
	ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	memset(card, 0, sizeof(card));
	for (int i = 0; i < 14; ++i){
		cin >> s;
		int num = 0;
		for (int j = 1; j < s.length(); ++j){
			num = num * 10 + s[j] - '0';

		}
		card[s[0] - 'a'][num]++;
	}

	bool ok = 0;
	int ans;
	if (judge() || judgeTwo()){
		ans = 0;
		ok = 1;
	}
	for (int k = 1; k <= N; ++k){
		cin >> s;
		int num = 0;
		for (int i = 1; i < s.length(); ++i){
			num = num * 10 + s[i] - '0';

		}
		card[s[0] - 'a'][num]++;
		if (!ok&&(judge() || judgeTwo())){
			ok = 1;
			ans = k;
		}
	}

	if (ok)
		cout << ans << endl;
	else
		cout << -1 << endl;

	return 0;
}