#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
using namespace std;
map<int, int> mii;
map<int, int> postm;
set<int> vis;
int post[50], pre[50], N;
bool start;
struct Node{
	int l, r, val;
}data[2000];
int size;

int alloc(int v){
	data[size].l = data[size].r = -1;
	data[size].val = v;
	postm[v] = size;
	return size++;
}

void dfs(int root){
	if (root == -1)
		return ;
	dfs(data[root].l);
	if (!start){
		start = 1;
		cout << data[root].val;
	}
	else{
		cout << " " << data[root].val;
	}
	
	dfs(data[root].r);
}
int main(){
	//ifstream in("C:\\input.txt");
	mii.clear();
	postm.clear();
	vis.clear();
	start = 0;
	size = 0;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> post[i];
	for (int i = 1; i <= N; ++i){
		cin >> pre[i];
		mii[pre[i]] = i;
	}
	bool ok = 1;
	alloc(post[1]);

	for (int i = 2; i <= N; ++i){
		if (vis.count(post[i]))
			continue;
		int fa = post[i-1];
		int faidx = postm[fa];
		int preidx = mii[fa];
		if (preidx > 1){
			if (post[i] == pre[preidx - 1]){
				ok = 0;
				data[faidx].l = alloc(post[i]);
				vis.insert(post[i]);
			}
			else{
				data[faidx].l = alloc(post[i]);
				data[faidx].r = alloc(pre[preidx - 1]);
				vis.insert(post[i]);
				vis.insert(pre[preidx - 1]);
			}
		}
		else{
			cout << "fuck" << endl;
		}
	}
	if (ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	dfs(0);
	cout << endl;













	return 0;
}