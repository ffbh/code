#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int data[70];
bool vis[70];
int N;
int cutcount,cutsize;


bool dfs(int num, int pre,int pos){
	if (num == cutcount)return 1;
	bool sign = (pre == 0) ? 1 : 0;
	for (int i=pos; i < N; ++i){
		if (vis[i])continue;   
		if (pre + data[i]>cutsize)return 0;
		if (pre + data[i] == cutsize){
			vis[i] = 1;
			if (dfs(num + 1, 0,0))
				return 1;
			vis[i] = 0;
			return 0;
		}
		if (pre + data[i] < cutsize){
			vis[i] = 1;
			if (dfs(num, pre + data[i],i+1))
				return 1;
			vis[i] = 0;
			if (sign)return 0;
		 	while (data[i] == data[i+1])++i;
			
		}
	}
	return 0;
}


int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N&&N){
		int sum = 0;
		for (int i = 0; i < N; ++i){
			//in >> data[i];
			scanf("%d", &data[i]);
			sum += data[i];
		}
		sort(data, data + N);
		for (int i = 1; i <= sum;++i)
		if (sum % i == 0){
			memset(vis, 0, sizeof(vis));
			cutsize = i;
			cutcount = sum / i;
			if (dfs(1, 0,0)){
				cout << i << endl;
				break;
			}
		}
	
	
	}
	return 0;
}