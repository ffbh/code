#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int N,size;
int stick[25];
bool vis[25];
bool dfs(int num, int pre, int pos){
	if (num == 4)return 1;
	bool sign = pre == 0 ? 1 : 0;
	for (int i = pos; i < N; ++i){
		if (vis[i])continue;
		if (pre + stick[i]>size)
			return 0;
		if (pre + stick[i] == size){
			vis[i] = 1;
			if (dfs(num + 1, 0, 0))
				return 1;
			vis[i] = 0;
			return 0;
		}
		else{
			vis[i] = 1;
			if (dfs(num, pre + stick[i], i + 1))
				return 1;
			vis[i] = 0;
			if (sign)return 0;
			while (stick[i] == stick[i+1])i++;
		}
	
	
	}
	return 0;
}



int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int sum;
	while (T--){
		cin >> N;
		sum = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i){
		//	in >> stick[i];
			scanf("%d", &stick[i]);
			sum += stick[i];
		}
		if (sum % 4 != 0)
			printf("no\n");
		else{
			size = sum / 4;
			sort(stick, stick + N);
			if (dfs(1, 0, 0))
				cout << "yes" << endl;
			else
				cout << "no" << endl;



		}

	
	
	
	}

	return 0;
}