#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int prime[200];
bool Isprime(int n){
	for (int i = 2; i <= sqrt(n);++i)
	if (n%i == 0)return 0;
	return 1;
}
int main(){
	//ifstream in("C:\\temp.txt");
	int k = 1;
	for (int i = 1; i <= 1000;++i)
	if (Isprime(i))
		prime[k++] = i;
	int N, C;
	
	while (cin >> N >> C){
		printf("%d %d:", N, C);
		int low = 1;
		int high = k - 1;
		int mid;
		while (low <= high){
			mid = (low + high) / 2;
			if (prime[mid] < N)
				low = mid + 1;
			else if (prime[mid] == N)
				break;
			else high = mid - 1;
		}
		if (prime[mid] <= N)
			mid++;
		mid--;
		if (mid % 2 == 1){
			if (2 * C - 1 <= mid){
				int mm = mid / 2;
				for (int i = mm - C+2 ; i < mm + C; ++i)
					printf(" %d", prime[i]);
				printf(" %d\n", prime[mm + C]);
			}
			else{
				for (int i = 1; i < mid; ++i)
					printf(" %d", prime[i]);
				printf(" %d\n", prime[mid]);
			}
		}
		else{
			if (2 * C <= mid){
				int mm = mid / 2;
				for (int i = mm - C + 1; i < mm + C; ++i)
					printf(" %d", prime[i]);
				printf(" %d\n", prime[mm + C]);
			}
			else{
				for (int i = 1; i < mid; ++i)
					printf(" %d", prime[i]);
				printf(" %d\n", prime[mid]);
			}
		}
		cout << endl;
	}
		
	return 0;
}