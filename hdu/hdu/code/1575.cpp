#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	int num[15][15];
	Node mul(Node& m,int n){
		Node res;
		for (int i = 0; i < n;++i)
		for (int j = 0; j < n; ++j){
			res.num[i][j] = 0;
			for (int k = 0; k < n; ++k)
				res.num[i][j] += num[i][k] * m.num[k][j];
			res.num[i][j] %= 9973;
		}
		return res;
	}
};
Node date;
int N;
Node quickmod(Node a,int K){
	Node m;
	memset(m.num, 0, sizeof(m.num));
	for (int i = 0; i <= 12; ++i)
		m.num[i][i] = 1;
	while (K > 0){
		if (K & 1)
			m = m.mul(a,N);
		a = a.mul(a,N);
		K /= 2;
	}
	return m;
}


int main(){
//	ifstream in("C:\\temp.txt");
	int T;
	int  K;
	cin >> T;
	while (T--){
		cin >> N >> K;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j)
			//	in >> date.num[i][j];
			scanf("%d", &date.num[i][j]);
		Node dd = quickmod(date, K);
		_int64 ans = 0;
		for (int i = 0; i < N; ++i)
			ans += dd.num[i][i];
		cout << ans % 9973 << endl;
	}

	return 0;
}