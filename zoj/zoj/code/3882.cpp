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
vector<int> vi[110];
int n;
bool vis[110];

bool dfs_A(int);
bool dfs_B(int);

bool dfs_A(int rest){
	if (rest == 0)
		return 0;
	vector<int> tmp;
	for (int i = 1; i <= n; ++i){
		if (vis[i])
			continue;
		tmp.clear();
		for (int k = 0; k < vi[i].size(); ++k){
			if (!vis[vi[i][k]]){
				vis[vi[i][k]] = 1;
				tmp.push_back(vi[i][k]);
			}
		}
		bool ret = dfs_B(rest - tmp.size());
		
		for (int k = 0; k < tmp.size(); ++k){
			vis[tmp[k]] = 0;
		}

		if (!ret)
			return 1;
	}
	return 0;
}


bool dfs_B(int rest){
	if (rest == 0)
		return 0;
	vector<int> tmp;
	for (int i = 1; i <= n; ++i){
		if (vis[i])
			continue;
		tmp.clear();
		for (int k = 0; k < vi[i].size(); ++k){
			if (!vis[vi[i][k]]){
				vis[vi[i][k]] = 1;
				tmp.push_back(vi[i][k]);
			}
		}
		bool ret = dfs_A(rest - tmp.size());

		for (int k = 0; k < tmp.size(); ++k){
			vis[tmp[k]] = 0;
		}

		if (!ret)
			return 1;
	}
	return 0;
}

int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;

	for (int i = 1; i < 110;++i)
	for (int j = 1; j <= i; ++j){
		if (i%j == 0){
			vi[i].push_back(j);
		}
	}

	while (cin >> n){
		memset(vis, 0, sizeof(vis));
		if (n > 0){
			cout << "win" << endl;
		}
		else{
			cout << "fail" << endl;
		}



	}














	return 0;
}