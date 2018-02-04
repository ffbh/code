#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool ok[10000100];

int main(){
	ifstream in("C:\\temp.txt");
	int T, K, N;
	cin >> T;
	while (T--){
		memset(ok, 0, sizeof(ok));
		ok[0] = 1;
		double temp;
  		cin >> temp >> N;
        K = int(temp * 1000);
		while (N--){
			int t;
			cin >> t;
			t *= 1000;
			while (t % 2 == 0)
				t /= 2;
			for (int i = 0; i <= K;++i)
			if (ok[i])
				ok[i + t] = 1;
		}
		if (ok[K])
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}