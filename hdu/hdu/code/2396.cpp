#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N;
struct Node{
	int a, b;
}data[15];
bool vis[15];
int card[20];
bool dfs(int pos, int num){
	if (num == 1){
		for (int i = 1; i < N;++i)
		if (!vis[i]){
			if (card[pos] == data[i].a)
				return card[0] == data[i].b;
			else if (card[pos] == data[i].b)
				return card[0] == data[i].a;
			else return 0;
		}
		int k = 0;
		k /= k;
	}
	for (int i = 1; i < N;++i)
	if (!vis[i]){
		if (data[i].a == card[pos]){
			vis[i] = 1;
			card[pos + 1] = data[i].b;
			if (dfs(pos + 1, num - 1))
				return 1;
			vis[i] = 0;
		}
		else if (data[i].b == card[pos]){
			card[pos + 1] = data[i].a;
			vis[i] = 1;
			if (dfs(pos + 1, num - 1))
				return 1;
			vis[i] = 0;
		}
	}
	return 0;
}


int main(){
	ifstream in("C:\\temp.txt");
	int CASE = 1;
	while (cin >> N&&N){
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i)
			cin >> data[i].a >> data[i].b;
		card[0] = data[0].a;
		card[1] = data[0].b;
		if (dfs(1, N - 1))
			printf("Set #%d: YES\n", CASE++);
		else
			printf("Set #%d: NO\n", CASE++);
	}
	return 0;
}