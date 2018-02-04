#include <iostream>
#include <fstream>
using namespace std;
int ans[6];
int num[20];
int N;
void dfs(int n,int m){
	for (int i = n; i < N; ++i){
		ans[m] = num[i];
		if (m < 5)
			dfs(i + 1, m + 1);
		else{
			for (int k = 0; k < 5; ++k)
				printf("%d ", ans[k]);
			printf("%d\n", ans[5]);
		}
	}
}

int main(){
	//ifstream in("C:\\temp.txt");
	
	int ok = 0;
	while (cin >> N&&N){
		if (ok == 1)cout << endl;
		ok = 1;
		for (int i = 0; i < N; ++i)
			cin >> num[i];
		dfs(0, 0);
	
	}

	return 0;
}