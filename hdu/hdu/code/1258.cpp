#include <iostream>
//#include <fstream>
using namespace std;
int a[15], res[15];
int sum,N;

bool dfs(int s,int t,int v){
	bool flag = 0;
	if (v > sum)
		return 0;
	if (v == sum){
		for (int i = 0; i < t - 1; ++i)
			printf("%d+", res[i]);
		printf("%d\n", res[t - 1]);
		return 1;
	}
	for (int i = s; i < N; ++i){
		res[t] = a[i];
		if (dfs(i + 1, t + 1, v + a[i])){
			while (a[i + 1] == a[i])i++;
			flag = 1;
		}
			
	
			
	}
	return flag;
}

int main(){
//	ifstream in("C:\\temp.txt");
	int t;
	while (cin >> sum >> N){
		if (N == 0)break;
		memset(a, -1, sizeof(a));
		for (int i = 0; i < N; ++i)
			cin >> a[i];
		printf("Sums of %d:\n", sum);
		int ans = dfs(0, 0, 0);
		if (!ans)
			printf("NONE\n");
	}//while

	return 0;
}