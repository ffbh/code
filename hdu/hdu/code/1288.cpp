#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int P;
int num[3];
int data[] = { 1, 5, 10 };
int ans[3];





int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> P){
		int sum = P;
		for (int i = 0; i < 3; ++i){
			cin >> num[i];
			sum += num[i];
		}
		if (sum == 0)
			break;
		sum = 0;
		for (int i = 0; i < 3; ++i)
			sum += num[i] * data[i];
		if (sum<P){
			cout << "Hat cannot buy tea." << endl;
			continue;
		}
		sum -= P;
		for (int i = 2; i >= 0; --i){
			int tmp = sum / data[i];
			if (tmp>num[i])
				tmp = num[i];
			ans[i] = num[i] - tmp;
			sum -= tmp*data[i];
		}
		if (sum)
			cout << "Hat cannot buy tea." << endl;
		else
			printf("%d YiJiao, %d WuJiao, and %d ShiJiao\n", ans[0], ans[1], ans[2]);
	}
	return 0;
}