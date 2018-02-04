/*#include <iostream>
#include <cmath>
//#include <fstream>
using namespace std;
int prime[1500];//1229
bool IsPrime(int n){
	for (int i = 2; i <= sqrt(n);++i)
	if (n%i == 0)return 0;
	return 1;
}



int main(){
//	ifstream in("C:\\temp.txt");
	int k = 0;
	for (int i = 2; i < 10000; ++i)
	if (IsPrime(i))prime[k++] = i;
	int m;
	int a, b;
	while (cin >> m){
		for (int i = 0; i < 1229; ++i)
		for (int j = i ; j < 1229; ++j){
			if (prime[j] >= m)break;
			if (prime[i] + prime[j] == m){
				a = i;
				b = j;
			}
		}
		printf("%d %d\n", prime[a], prime[b]);
	}

	return 0;
}*/

#include <iostream>
#include <cmath>
using namespace std;
bool IsPrime(int n){
	for (int i = 2; i <= sqrt(n); ++i)
	if (n%i == 0)return 0;
	return 1;
}

int main(){
	int N;
	while (cin >> N){
		int a, b;
		a = b = N / 2;
		while (1){
			if (IsPrime(a) && IsPrime(b)){
				printf("%d %d\n", a, b);
				break;
			}
			a--;
			b++;
		
		}
		
	
	}


}