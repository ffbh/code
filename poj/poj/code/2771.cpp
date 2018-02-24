#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
struct Node{
	int h;
	char c;
	string style, sport;
}data[510];
int ans;
vector<int> vi;
bool link[510][510];
int N;
void dfs(int k){
	bool f = 1;
	if (vi.size() > ans)
		ans = vi.size();
	if (vi.size() + N - k+1 <= ans )
		return;
	if (k == N + 1)
		return;
	for (int i = 0; i < vi.size(); ++i){
		int u = vi[i];
		if (!link[u][k]){
			f = 0;
			break;
		}
	}
	if (f){
		vi.push_back(k);
		dfs(k + 1);
		vi.pop_back();
	}
	dfs(k + 1);
}
int map[510][510];
int dp[510], now[510];
int n, Ans;
void DFS(int x, int sum)
{
	if (sum > Ans) Ans = sum;

	int able = 0;
	int tnow[510];
	for (int i = x + 1; i<= n; i++)
	{
		tnow[i] = now[i];
		if (now[i]) able++;
	}
	if (able + sum<= Ans) return;

	for (int i = x + 1; i<= n; i++)
	{
		if (!tnow[i]) continue;
		if (dp[i] + sum<= Ans) continue;
		for (int j = x + 1; j<= n; j++)
			now[j] = tnow[j] & map[i][j];
		DFS(i, sum + 1);
	}
}


int Max_Tuan()
{
	Ans = dp[n] = 1;
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = 1; j<= n; j++)
			now[j] = map[i][j];
		DFS(i, 1);
		dp[i] = Ans;
	}
	return Ans;
}







int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N;
		n = N;
		ans = 1;

		Ans = 1;
		memset(map, 0, sizeof(map));


		vi.clear();
		memset(link, 0, sizeof(link));
		for (int i = 1; i <= N; ++i){
			cin >> data[i].h >> data[i].c >> data[i].style >> data[i].sport;
		}
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j){
			if (abs(data[i].h - data[j].h) > 40 || data[i].c == data[j].c
				|| data[i].style != data[j].style || data[i].sport == data[j].sport)
				map[i][j] = map[j][i] = 1;
		}
	//	dfs(1);
		cout << Max_Tuan()<< endl;




	}






	return 0;
}