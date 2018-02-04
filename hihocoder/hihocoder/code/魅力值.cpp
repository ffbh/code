#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
	int u, m, ans;
};
struct Dp{
	int sum, num;
}dp[110];
int N, M;
int map[110][110];


/*void flody(){
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= N; ++j){
		dist[i][j] = map[i][j];
		citynum[i][j] = 0;
	}

	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= N;++j)
	for (int k = 1; k <= N; ++k){
		if (dist[i][j] > dist[i][k] + dist[k][j] ){
			dist[i][j] = dist[i][k] + dist[k][j];
			citynum[i][j] = citynum[i][k] + citynum[k][j] + 1;
		}

	}

	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= N; ++j)
			cout << dist[i][j] << " ";
		cout << endl;
		
	}
	cout << endl;
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= N; ++j)
			cout << citynum[i][j] << " ";
		cout << endl;

	}
}*/

double p[110];

int spfaLast(int s, int m){
	queue<Node> qn;
	Node temp1, temp2;
	int ans = 0;
	temp1.u = s;
	temp1.m = m;
	temp1.ans = 0;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		if (ans < temp1.ans)
			ans = temp1.ans;
		for (int i = 1; i <= N; ++i){
			if (i == temp1.u)
				continue;
			temp2.u = i;
			temp2.ans = temp1.ans + 1;
			temp2.m = temp1.m - map[temp1.u][temp2.u];
			if (temp2.m >= 0)
				qn.push(temp2);
		}
	}
	return ans;
}


int spfaFirst(int s){
	for (int i = 0; i < 110; ++i)
		p[i] = 1e18;
	queue<int> qn;
	qn.push(s);
	Dp next, real;
	int ans = 0;
	while (!qn.empty()){
		int temp = qn.front();
		qn.pop();
		for (int i = 1; i <= N; ++i){
			if (i == temp || i == s)
				continue;
			next.num = dp[temp].num + 1;
			next.sum = dp[temp].sum + map[temp][i];
			real.num = next.num + 1;
			real.sum = next.sum + map[i][s];
			if (double(real.sum) / real.num < p[i]){
				p[i] = double(real.sum) / real.num;
				dp[i] = next;
				qn.push(i);
			}
		}
	}
	for (int i = 1; i <= N; ++i){
		if (i == s)
			continue;
		int cost = dp[i].sum + map[i][s];
		int num = dp[i].num + 1;
		int tmp_ans = M / cost*num;
		tmp_ans += spfaLast(s, M % cost);
		if (ans < tmp_ans)
			ans = tmp_ans;

	}
	return ans;
}






int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= N; ++j)
		cin >> map[i][j];
	int ans = 0;
	for (int i = 1; i <= N; ++i){
		int t_ans = spfaFirst(i);
		if (t_ans > ans)
			ans = t_ans;
	}
	cout << ans << endl;
	return 0;
}