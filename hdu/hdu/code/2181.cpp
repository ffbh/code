#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector<int> vi[21];
int CASE;
void fun(int& a, int& b, int& c){
	if (a > b)
		swap(a, b);
	if (a > c)
		swap(a, c);
	if (b > c)
		swap(b, c);
}
bool vis[21];
int pace[21];
int M;
void dfs(int n,int num){
	if (num == 19){
		for (int i = 0; i < vi[n].size();++i)
		if (M == vi[n][i]){
			printf("%d:  ", CASE++);
			for (int j = 0; j < num; ++j)
				printf("%d ", pace[j]);
			printf("%d ", n);
			printf("%d\n", M);
		}
		return;
	}
	vis[n] = 1;
	for (int i = 0; i < vi[n].size(); ++i){
		int son = vi[n][i];
		if (!vis[son]){
			vis[son] = 1;
			pace[num] = n;
			dfs(son,num+1);
			vis[son] = 0;
		}
	}
}
int main(){
	//ifstream in("C:\\temp.txt");
	for (int i = 1; i <= 20; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		fun(a, b, c);
		vi[i].push_back(a);
		vi[i].push_back(b);
		vi[i].push_back(c);
	}
	while (cin >> M&&M){
		CASE = 1;
		dfs(M, 0);
	}




	return 0;
}