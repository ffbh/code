#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int MMAX = 50 * 10000 * 2;
int Hash[2*MMAX];
int data[4];
int num[110];

int main(){
	//	ifstream in("C:\\temp.txt");
	for (int i = 1; i <= 100; ++i)
		num[i] = i*i;
	int ans;
	while (cin >> data[0] >> data[1] >> data[2] >> data[3]){
		sort(data, data + 4);
		if (data[0] > 0 || data[3] < 0)
			cout << 0 << endl;
		else{
			int ans = 0;
			int zero = 0;
			memset(Hash, 0, sizeof(Hash));
			for (int i = 1; i <= 100; ++i)
			for (int j = 1; j <= 100; ++j){
				int s = data[0] * num[i] + data[1] * num[j];
				Hash[s + MMAX] += 4;
			}
			for (int i = 1; i <= 100; ++i)
			for (int j = 1; j <= 100; ++j){
				int s = data[2] * num[i] + data[3] * num[j];
				ans += Hash[MMAX - s]*4;
			}
			cout << ans  << endl;
		}
	}

	return 0;
}