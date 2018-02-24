#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int ans;
	while (cin >> N){
		ans = 0;
		if (N <= 2)
			cout << 0 << endl;
		else{
			for (int i = 2; i <= 2* sqrt(N)+1; ++i){
				if (i % 2 && N%i==0){
					int k = i / 2 +1 ;
					int mid = N / i;
					if (k <= mid)
						ans++;
				}
				else if (i % 2 == 0 && N%i){
					int k = i / 2;
					int mid = N / i;
					double dd = double(N) / i - mid;
					dd *= 2;

					if (k <= mid &&(dd-int(dd))==0)
						ans++;
				}

			}
			cout << ans << endl;
		}

	}





	return 0;
}