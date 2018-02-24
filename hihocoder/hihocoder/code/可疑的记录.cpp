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

int In[100010], Out[100010];
struct Node{
	int to, idx;
	Node(int a, int b){
		to = a;
		idx = b;
	}
};
vector<Node> vi[100010];
vector<Node> vp[100010];
vector<int> ans;
int N;
bool mark[100010];
int num, now_idx;
void dfs(int p){
	if (mark[p])
		return;
	num++;
	mark[p] = 1;
	for (int i = 0; i < vi[p].size(); ++i){
		if (vi[p][i].idx == now_idx)
			continue;
		int v = vi[p][i].to;
		
		dfs(v);
	}
}


bool judge(){
	memset(mark, 0, sizeof(mark));
	num = 0;
	dfs(1);
	return num == N;
}
int main(){
	ifstream in("C:\\input.txt");
	
	cin >> N;
	ans.clear();
	for (int i = 1; i <= N; ++i){
		int a, b;
		cin >> a >> b;
		vi[a].push_back(Node(b, i));
		vp[b].push_back(Node(a, i));
		Out[a]++;
		In[b]++;

		if (b == 1){
			ans.push_back(i);
		}
	}

	for (int i = 2; i <= N; ++i){
		if (In[i] >= 2){
			for (int k = 0; k < vp[i].size(); ++k){
				now_idx = vp[i][k].idx;
				if (judge()){
					ans.push_back(vp[i][k].idx);
				}

			}
		}

	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i){
		cout << ans[i] << " ";
	}
	cout << endl;











	return 0;
}