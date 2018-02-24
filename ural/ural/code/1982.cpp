#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
#define INF (1<<28)
int data[110][110];
int dist[110];
bool vis[110];
int num[110];

int main(){
	ifstream in("C:\\temp.txt");
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= K; ++i)
		cin >> num[i];
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= N; ++j)
		cin >> data[i][j];
	for (int i = 1; i <= K;++i)
	for (int j = 1; j <= K; ++j)
		data[num[i]][num[j]] = 0;
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		dist[i] = data[1][i];
	vis[1] = 1;
	for (int k = 0; k < N - 1; ++k){
		int u, mmin;
		mmin = INF;
		for (int i = 1; i <= N;++i)
		if (!vis[i] && dist[i] < mmin){
			u = i;
			mmin = dist[i];
		}
		ans += mmin;
		vis[u] = 1;
		for (int i = 1; i <= N;++i)
		if (dist[i] >  data[u][i])
			dist[i] =  data[u][i];
	}
	cout << ans << endl;
	return 0;
}