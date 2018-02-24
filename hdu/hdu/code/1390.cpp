#include <iostream>
#include <fstream>
using namespace std;
int ans[1000];
int k;
int main(){
	ifstream in("C:\\temp.txt");
	int N,M;
	cin >> N;
	while (N--){
		cin >> M;
		k = 0;
		int t = 0;
		for (int i = 1; i <= 10000000; i *= 2,t++)
		if (M&i)
			ans[k++] = t;
		for (int i = 0; i < k - 1; ++i)
			printf("%d ", ans[i]);
		printf("%d\n",ans[k - 1]);
	}

	return 0;
}