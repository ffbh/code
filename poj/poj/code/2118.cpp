#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int K;
const int MOD = 10000;
struct Mate{
	int data[110][110];
}D1, D2;
Mate mul(Mate& a,Mate& b){
	Mate c;
	for (int i = 1; i <= K;++i)
	for (int j = 1; j <= K; ++j){
		c.data[i][j] = 0;
		for (int k = 1; k <= K; ++k)
			c.data[i][j] = (c.data[i][j]+a.data[i][k] * b.data[k][j])%MOD;
	}
	return c;
}


Mate cale(Mate a,int p){
	Mate tmp;
	memset(tmp.data, 0, sizeof(tmp.data));
	for (int i = 1; i <= K; ++i)
		tmp.data[i][i] = 1;
	while (p >= 1){
		if (p % 2)
			tmp = mul(tmp, a);
		a = mul(a, a);
		p /= 2;
	}
	return tmp;
}


int main(){
	ifstream in("C:\\input.txt");
	int p;
	while (cin >> K&&K){
		for (int i = 1; i <= K; ++i)
			cin >> D1.data[1][i];
		memset(D2.data, 0, sizeof(D2.data));
		for (int i = K; i >= 1; --i)
			cin >> D2.data[i][K];
		for (int i = 2; i <= K; ++i)
			D2.data[i][i - 1] = 1;
		cin >> p;
		if (p < K){
			cout << D1.data[1][p + 1] << endl;
		}
		else{
			D2 = cale(D2, p - K + 1);
			int ans = 0;
			for (int i = 1; i <= K; ++i)
				ans = (ans+D1.data[1][i] * D2.data[i][K])%MOD;
			cout << ans << endl;
		}
	}

	return 0;
}