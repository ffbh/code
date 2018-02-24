#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int num[20];
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	while (cin >> num[0] && num[0]>=0){
		N = 1;
		int ans = 0;
		while (scanf("%d", &num[N]) && num[N])N++;
		//while (in >> num[N] && num[N])N++;
		sort(num, num + N);
		for (int i = 0; i < N;++i)
		for (int j = i + 1; j < N && 2 * num[i] >= num[j];++j)
		if (num[i] * 2 == num[j])ans++;
		cout << ans << endl;




	}

	return 0;
}