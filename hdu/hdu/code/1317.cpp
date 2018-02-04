#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> vi[110];
bool vis[110];
int value[110];

int OUT[110];
int enemey[110];
bool dfs(int n){
	vis[n] = 1;
	int size = vi[n].size();
	for (int i = 0; i < size; ++i){
		int j = vi[n][i];
		if (j == N)return 1;
		if (!vis[j] && dfs(j))return 1;
	}
	return 0;
}



int spfa(){
	memset(vis, 0, sizeof(vis));
	memset(enemey, 0, sizeof(enemey));
	memset(OUT, 0, sizeof(OUT));
	queue<int> qi;
	enemey[1] = 100;
	vis[1] = 1;
	qi.push(1);
	while (!qi.empty()){
		int ff = qi.front();
		vis[ff] = 0;
		OUT[ff]++;
		if (OUT[ff] >= N)return ff;//������Ȩ��·�е�����ڵ�
		qi.pop();
		int size = vi[ff].size();
		for (int i = 0; i < size; ++i){
			int son = vi[ff][i];
			if (son == N)return 1;
			if (enemey[ff] + value[son]>enemey[son]){
				enemey[son] = value[son]+enemey[ff];
				if (!vis[son]){
					qi.push(son);
					vis[son] = 1;
				}
			}
		}
	}
	return 0;
}

int main(){
	//ifstream in("C:\\temp.txt");
	int K;
	while (cin >> N&&N > 0){
		for (int i = 0; i < 110; ++i)
			vi[i].clear();
		memset(value, 0, sizeof(value));
		for (int i = 1; i <=N; ++i){
		//in >> value[i] >> K;
			scanf("%d%d", &value[i], &K);
			for (int j = 0; j < K; ++j){
				int t;
		//		in >> t;
				scanf("%d", &t);
				vi[i].push_back(t);
			}
		}
		
		int qq;
		if (qq = spfa()){
			memset(vis, 0, sizeof(vis));
			if (dfs(qq))printf("winnable\n");//qqΪ1����㣩��������Ȩ��·�еĵ�
			else
				printf("hopeless\n");
		}
		else
			printf("hopeless\n");
	
	}//while




	return 0;
}



/*С�������������
6
0 2 2 5
1 1 3
1 1 4
1 1 2
-100 1 6
0 0

����㵽�յ���ͨ��������Ȩ��·��һ����winable
��Ϊ��Ȩ��·�еĽڵ㲻һ����ͨ���յ㣬
����Ҫ����Ȩ��·�еĽڵ㵽�յ��Ƿ���ͨ�ж�
*/