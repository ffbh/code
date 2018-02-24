#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
vector<int> vi[10010];
int f[10010];
int out[10010];
int A[10010];
int B[10010];
bool vis[10010];
int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}


int main(){
	//ifstream in("C:\\temp.txt");
	int N, M;
	int a, b;
	char op;
	bool UNCERTAIN;
	queue<int> qi;
	int sum;
	int size;
 	while (cin >> N >> M){
		size = 0;
		sum = N;
		UNCERTAIN = 0;
		memset(vis, 0, sizeof(vis));
		while (!qi.empty())
			qi.pop();
		for (int i = 0; i < N; ++i){
			f[i] = i;
			vi[i].clear();
		}
		memset(out, 0, sizeof(out));
		while (M--){
			cin >> a >> op >> b;
			if (op == '='){
				int fa = find(a);
				int fb = find(b);
				if (fa != fb){
					f[fa] = fb;
					sum--;
				}
			}
			else{
				if (op == '<')
					swap(a, b);
				A[size] = a;
				B[size] = b;
				size++;
			}
		}
		for (int i = 0; i < size; ++i){
			int fa = find(A[i]);
			int fb = find(B[i]);
			vi[fa].push_back(fb);
			out[fb]++;
		}
		for (int i = 0; i < N; ++i){
			int fi = find(i);
			if (!vis[fi]&&out[fi] == 0){
				qi.push(fi);
				vis[fi] = 1;
			}
		}
		while (!qi.empty()){
			if (qi.size()>1)
				UNCERTAIN = 1;
			int ff = qi.front();
			qi.pop();
			sum--;
			ff = find(ff);
			for (int i = 0; i < vi[ff].size(); ++i)
			if (out[vi[ff][i]])
			if (--out[vi[ff][i]] == 0)
				qi.push(vi[ff][i]);
		}

		if (sum>0)
			cout << "CONFLICT" << endl;
		else if (UNCERTAIN)
			cout << "UNCERTAIN" << endl;
		else
			cout << "OK" << endl;
	}
	return 0;
}