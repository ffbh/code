#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	int a, b;
};
Node data[10001];
_int64 dp[1000001];
int sum;

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (in >> N&&N){
		sum = 0;
		memset(data, 0, sizeof(data));
		for (int i = 0; i < N; ++i){
			in >> data[i].a >> data[i].b;
			sum += data[i].a*data[i].b;
		}
		if (sum % 3)
			cout << "sorry" << endl;
		else{
			sum /= 3;
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			for (int k = 0; k < N; ++k)
			for (int i = sum; i >= 0;--i)
			for (int j = 1; j <= data[k].b;++j)
			if (i - j*data[k].a >= 0)
				dp[i] = (dp[i] + dp[i - j*data[k].a]) % 10000;
			else break;
			if (dp[sum])
				cout << dp[sum] % 10000 << endl;
			else
				cout << "sorry" << endl;
		}
	}
	return 0;

}



