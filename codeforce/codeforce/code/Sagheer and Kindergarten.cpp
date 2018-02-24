#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
#include <cassert>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back

int n, m, K, Q;


vector<int> vi[100010];
int toy[100010];
bool vis[100010];
int mark[100010];
int deep[100010];
void Init(){
	memset(toy, -1, sizeof(toy));


}

void input(){
	in >> n >> m >> K >> Q; 
	for (int i = 1; i <= K; ++i){
		int a, b;
		in >> a >> b;

		if (!vis[a]){
			if (toy[b] == -1){
				vi[0].push_back(a);
				toy[b] = a;
			}
			else{
				vis[a] = 1;
				vi[toy[b]].push_back(a);
				toy[b] = a;
			}
		}
	}

}
pii tree[100010];
int num[100010];
int ID;
int dfs(int p){
	num[p] = 1;
	tree[p].first = ID++;
	for (int son : vi[p]){
		if (p != 0 || !vis[son])
			num[p] += dfs(son);
	}
	tree[p].second = ID - 1;
	return num[p];
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		Init();
		input();

		for (int i = 1; i <= m; ++i){
			for (int j = 0; j < vi[i].size();++j){
				mark[vi[i][j]] = i;
				deep[vi[i][j]] = j;
			}
		}

		ID = 0;
		dfs(0);

		while (Q-- > 0){
			int a, b;
			in >> a >> b;
			b = toy[b];
			if (b == -1){
				cout << 0 << endl;

			}
			else if (tree[a].first <= tree[b].first&&tree[a].second >= tree[b].first){
				cout << num[a] << endl;
			}
			else{
				cout << 0 << endl;
			}


		}
		















	}


	return 0;
}





