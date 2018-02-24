#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
struct Node{
	int x, y;
};
int data[101][101];
int dp[101][101];
bool IN(Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}

int DFS(const Node& p){
	if (p.x == N - 1 && p.y == M - 1)
		return 1;
	if (data[p.x][p.y] == 0)
		return 0;
	if (dp[p.x][p.y] != -1)
		return dp[p.x][p.y];
	dp[p.x][p.y] = 0;
	Node temp;
	for (int k = 1; k <= data[p.x][p.y]; ++k)
	for (int i = 0; i <= k; ++i){
		temp.x = p.x + i;
		temp.y = p.y + k - i;
		if (IN(temp))
			dp[p.x][p.y] += DFS(temp);
	}
	return dp[p.x][p.y]%=10000;
}

int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j){
		//	in >> data[i][j];
			scanf("%d", &data[i][j]);
			dp[i][j] = -1;
		}
		Node s;
		s.x = s.y = 0;
		cout << DFS(s) << endl;
	}
	return 0;
}