#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
char map[9][4];
int index[9];
bool vis[3000000];
double p[3000000];
struct Node{
	int a, b;
	Node(int c, int d){
		a = c;
		b = d;
	}
};
int HashCode(){
	int code = 0;
	for (int i = 0; i < 9; ++i)
		code = code * 5 + index[i];
	return code;
}
double dfs(int a, int b){
	double ret = 0;
	vector<Node> vn;
	bool f = 1;
	int code = HashCode();
	if (vis[code]){
		return p[code];
	}
	vis[code] = 1;
	
	for (int i = 0; i < 9; ++i){
		if (index[i] < 4){
			f = 0;
			break;
		}
	}
	if (f){
		return p[code] = 1.0;
	}
	for (int i = 0; i < 9; ++i){
		if (index[i] >= 4)
			continue;
		for (int j = i + 1; j < 9; ++j){
			if (index[j] < 4 && map[i][index[i]] == map[j][index[j]])
				vn.push_back(Node(i, j));
		}
	}
	for (int i = 0; i < vn.size(); ++i){
		double k = 1.0 / vn.size();
		index[vn[i].a]++;
		index[vn[i].b]++;
		ret += dfs(vn[i].a, vn[i].b)*k;
		index[vn[i].a]--;
		index[vn[i].b]--;
	}
	return p[code] = ret;
}

int main(){
	ifstream in("C:\\temp.txt");
	vector<Node> vn;
	//	memset(vis, 0, sizeof(vis));
	memset(index, 0, sizeof(index));
	double ans = 0;
	for (int i = 0; i < 9; ++i)
	for (int j = 3; j >= 0; --j){
		string s;
		cin >> s;
		map[i][j] = s[0];
	}
	for (int i = 0; i < 9; ++i){
		for (int j = i + 1; j < 9; ++j){
			if (map[i][index[i]] == map[j][index[j]])
				vn.push_back(Node(i, j));
		}
	}
	for (int i = 0; i < vn.size(); ++i){
		double k = 1.0 / vn.size();
		index[vn[i].a]++;
		index[vn[i].b]++;
		ans += dfs(vn[i].a, vn[i].b)*k;
		index[vn[i].a]--;
		index[vn[i].b]--;
	}
	printf("%.6f\n", ans);













	return 0;
}