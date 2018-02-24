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
string str;
int pm[210];
int X, Y;
vector<int> vi;
int val;
int vis[201][200010];
bool dfs(int dept,int m){
	if (dept == vi.size()){
		return (m+val)%X == Y;
	}
	if (vis[dept][m] != -1)
		return vis[dept][m];
	int idx = vi[dept];
	int start;
	if (idx == 0)
		start = 1;
	else
		start = 0;
	vis[dept][m] = 0;
	for (int i = start; i < 10; ++i){
		str[idx] = i + '0';
		if (dfs(dept + 1, (m + i*pm[idx]) % X)){
			vis[dept][m] = 1;
			break;
		}
	}

	return vis[dept][m];

}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	in >> str >> X >> Y;
	if (X <= Y){
		cout << "No solution" << endl;
		return 0;
	}
	if (str.length() == 1 && str[0] == '?' && Y == 0){
		cout << 0 << endl;
		return 0;
	}

	memset(vis, -1, sizeof(vis));
	int len = str.length() - 1;
	pm[len] = 1;
	for (int i = len - 1; i >= 0; --i){
		pm[i] = (pm[i + 1] * 10) % X;
	}

	val = 0;
	int t;
	for (int i = 0; i < str.length(); ++i){
		if (str[i] == '?'){
			vi.push_back(i);
			t = 0;
		}
		else{
			t = str[i] - '0';
		}
		val = (val * 10 + t) % X;
	}
	if (dfs(0, 0)){
		cout << str << endl;
	}
	else{
		cout << "No solution" << endl;
	}
	return 0;
}