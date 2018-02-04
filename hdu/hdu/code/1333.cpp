#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int prime[3000];//1229
int k;
bool Isprime(int n){
	for (int i = 2; i <= sqrt(n);++i)
	if (n%i == 0)return 0;
	return 1;
}
int getNum(int n){
	int sum = 0;
	while (n){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

bool Issmart(int n){
	int m = n;
	int pre = getNum(m);
	int ans = 0;
	
	if (Isprime(m))return 0;

	for (int j = 0;sqrt(m)>=prime[j]&&j<k ;++j)
	while (m%prime[j] == 0){
		ans += getNum(prime[j]);
		m /= prime[j];
	}
	if (m>1)
	ans += getNum(m);
	return  ans == pre;
}
int main(){
//	ifstream in("C:\\temp.txt");
	k = 0;
	for (int i = 2; i <= 11000;++i)
	if (Isprime(i))prime[k++] = i;
	
	int M;
	while (cin >> M&&M>0)
	for (int i = M+1;;++i)
	if (Issmart(i)){
		cout << i << endl;
		break;
	}

		
	
	
	
	

	return 0;
}

