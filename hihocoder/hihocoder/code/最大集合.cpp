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

int A[100010], N;
int g[100010];
bool vis[100010];

int dfs(int p){
	if (vis[p])
		return g[p];
	vis[p] = 1;
	if (A[p] == p){
		return g[p] = 1;
	}
	else{
		g[p] = dfs(A[p]) + 1;
		return g[p];
	}
}

int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;

	in >> N;
	for (int i = 1; i <= N; ++i)
		in >> A[i];


	for (int i = 1; i <= N; ++i){
		dfs(i);
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		ans = max(g[i], ans);
	cout << ans << endl;



	return 0;
}