#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
const int N = 1010;
map<string, int> msi;
int f[N], size;
bool vis[N];

void init(){
	for (int i = 0; i < N; ++i)
		f[i] = i;
	memset(vis, 0, sizeof(vis));
	size = 1;
	msi.clear();
}


int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

void Union(int a, int b){
	f[a] = b;
}


int main(){
	ifstream in("C:\\input.txt");
	string s;
	init();
	while (in >> s){
		for (int i = 0; i < s.length(); i += 2){
			string tmp = s.substr(i, 2);
			if (!msi.count(tmp)){
				vis[size] = 1;
				msi[tmp] = size;
			}
			else{
				Union( find(msi[tmp]),size);
			}
		}
		size++;
	}
	set<int> si;
	for (int i = 1; i < size;++i)
	if (vis[i])
		si.insert(find(i));
	cout << si.size() << endl;
	return 0;
}