#include <iostream>
//#include <fstream>
#include <cmath>
using namespace std;
int prime[5000];
int cnt;
bool Isprime(int n){
	for (int i = 2; i <= sqrt(n);++i)
	if (n%i == 0)return 0;
	return 1;
}
int main(){
//	ifstream in("C:\\temp.txt");
	cnt = 0;
	for (int i=2;i<35000;++i)
	if (Isprime(i))
		prime[cnt++] = i;
	int M;
	while (cin >> M&&M){
		int count = 0;
		int low = 0;
		int high = cnt - 1;
		while (low <= high){
			if (prime[low] + prime[high] == M){
				low++;
				high--;
				count++;
				continue;
			}
			if (prime[low] + prime[high] < M)
				low++;
			else high--;
		}
		
		cout << count << endl;
	}
	return 0;
}