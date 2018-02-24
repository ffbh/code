#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream in("C:\\temp.txt");
vector<int> vi[101000];
bool vis[101000];
int dd[101000];
bool mark[101000];


int bfs(int r){
	memset(vis, 0, sizeof(vis));
	vis[r] = 1;
	queue<int> qi;
	qi.push(r);
	int temp;
	int ans = 0;
	while (!qi.empty()){
		temp = qi.front();
		qi.pop();
		ans++;
		int size = vi[temp].size();
		for (int i = 0; i < size; ++i){
			int son = vi[temp][i];
			if (!vis[son]){
				vis[son] = 1;
				qi.push(son);
			}
			else
				return -1;
		}



	}
	return ans;



}

int main(){
	int a, b;
	int CASE = 1;
	while (1){
		memset(dd, 0, sizeof(dd));
		memset(mark, 0, sizeof(mark));
		for (int i = 0; i < 101000; ++i)
			vi[i].clear();
		scanf("%d%d", &a, &b);
	//	in >> a >> b;
		dd[b] = 1;
		mark[a] = mark[b] = 1;
		if (a < 0 && b < 0)break;
		vi[a].push_back(b);
		if (a == 0 && b == 0){
			printf("Case %d is a tree.\n", CASE++);
			continue;
		}
		
		while (1){
			scanf("%d%d", &a, &b);
		//	in >> a >> b;
			if (a == 0 && b == 0)
				break;
			vi[a].push_back(b);
			dd[b] = 1;
			mark[a] = mark[b] = 1;
		}
		int root;
		int rnum = 0;
		int num = 0;
		for (int i = 0; i < 100010;++i)
		if (mark[i]){
			num++;
			if (dd[i] == 0){
				root = i;
				rnum++;
				if (rnum >= 2)
					break;
			}
			else if (dd[i]>1){
				rnum = 2;
				break;
			}
		}
		if (rnum == 1 && bfs(root) == num)
			printf("Case %d is a tree.\n", CASE++);
		else
			printf("Case %d is not a tree.\n", CASE++);


		
	}

	return 0;
}