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
using namespace std;
bool vis[110];
int ans[110];
int N, M, l[110];

int cale(int a,int b){
	if (a < b)
		return b - a;
	else{
		return N - a + b;
	}
}

bool work(){
	for (int i = 1; i < M; ++i){
		int a = l[i];
		int b = l[i + 1];
		int p = cale(a, b);
		if (ans[a] == -1){
			if (vis[p])
				return 0;
			vis[p] = 1;
			ans[a] = p;
		}
		else{
			if (ans[a] != p)
				return 0;
		}
	}
	queue<int> qi;
	for (int i = 1; i <= N;++i)
	if (vis[i] == 0){
		qi.push(i);
	}


	for (int i = 1; i <= N;++i)
	if (ans[i] == -1){
		ans[i] = qi.front();
		qi.pop();
	}


	return 1;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	memset(vis, 0, sizeof(vis));
	memset(ans, -1, sizeof(ans));
	in >> N >> M;
	for (int i = 1; i <= M; ++i)
		in >> l[i];
	

	if (work()){
		for (int i = 1; i <= N; ++i)
			cout << ans[i] << " ";
		cout << endl;
	}
	else{
		cout << -1 << endl;
	}
















	return 0;
}





