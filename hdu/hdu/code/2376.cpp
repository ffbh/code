#include <iostream> 
#include <string> 
#include <fstream> 
#include <vector> 
using namespace std;
#define MMAX (10010) 
struct Node{ int to, v; }; vector<Node> vn[MMAX];
double sum;
int N;
int dfs(int f, int u){
	int num, snum;
	num = 1;
	for (int i = 0; i < vn[u].size(); ++i){
		int son = vn[u][i].to;
		int v = vn[u][i].v;
		if (son == f) continue;
		snum = dfs(u, son); sum += double(v)*snum*(N - snum);
		num += snum;
	}
	return num;
}
int main(){
	ifstream in("C:\\temp.txt"); int T;
	cin >> T;
	while (T--){
		sum = 0;
		for (int i = 0; i < MMAX; ++i)
			vn[i].clear();
		cin >> N;
		for (int i = 0; i < N - 1; ++i){
			int a, b, c;
			cin >> a >> b >> c; vn[a].push_back(Node{ b, c }); vn[b].push_back(Node{ a, c });
		} dfs(-1, 0);
		int k = N*(N - 1) / 2; printf("%.7f\n", sum / k);
	} return 0;
}