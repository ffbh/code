#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>
using namespace std;
int N;
double MAP[31][31];
double rate[31];
bool vis[31];


bool spfa(int start){
	queue<int> qi;
	int temp;
	memset(vis, 0, sizeof(vis));
	memset(rate, 0, sizeof(rate));
	vis[start] = 1;
	qi.push(start);
	rate[start] = 1;
	while (!qi.empty()){
		temp = qi.front();
		qi.pop();
		vis[temp] = 0;
		for (int i = 1; i <= N; ++i)
		if (MAP[temp][i] && rate[i] < rate[temp] * MAP[temp][i]){
			rate[i] = rate[temp] * MAP[temp][i];
			if (!vis[i]){
				vis[i] = 1;
				qi.push(i);
			}
			if (rate[start]>1)return 1;
		}
	}
	return 0;
}




int main(){
	//ifstream in("C:\\temp.txt");
	map<string, int> msi;
	string s1,s2;
	double d;
	int CASE = 1;
	while (cin >> N&&N){
		msi.clear();
		memset(MAP, 0, sizeof(MAP));
		for (int i = 0; i < N; ++i){
			cin >> s1;
			msi[s1] = i+1;
		}
		int M;
		cin >> M;
		for (int i = 0; i < M; ++i){
			cin >> s1 >> d >> s2;
			MAP[msi[s1]][msi[s2]] = d;
		}
		bool flag = 0;
		for (int i = 1; i <= N;++i)
		if (spfa(i)){
			printf("Case %d: Yes\n",CASE++);
			flag = 1;
			break;
		}
		if (!flag)
			printf("Case %d: No\n", CASE++);
		
	}


	return 0;
}