#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int num[5];
int data[] = { 1, 5, 10, 50, 100 };

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int ans1,ans2;
		int P;
		cin >> P;
		int sum = 0;
		ans1 = ans2 = 0;
		for (int i = 0; i < 5; ++i){
			cin >> num[i];
			ans2 += num[i];
			sum += data[i] * num[i];
		}
		if (sum<P){
			printf("-1 -1\n");
			continue;
		}
		sum -= P;
		for (int i = 4; i >= 0; --i){
			int tmp = P / data[i];
			if (tmp>num[i])
				tmp = num[i];
			ans1 += tmp;
			P -= tmp*data[i];
			tmp = sum / data[i];
			if (tmp > num[i])
				tmp = num[i];
			sum -= tmp*data[i];
			ans2 -= tmp;
		}
		if (P || sum)
			printf("-1 -1\n");
		else
			printf("%d %d\n", ans1, ans2);
	}
	return 0;
}