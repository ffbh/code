#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool flag[20];
int index;
int  m;
int p[20];

bool Isprime(int a, int b){
	int sum = a + b;
	int lim = sqrt(sum);
	for (int i = 2; i <= lim; ++ i){
		if (sum % i == 0) return false;
	
	}
	return true;
}

void show(int pri,int count){
	if (index == m + 1){
		if (Isprime(1, p[m])){
			for (int i = 1; i <= m; ++i){
				cout << p[i];
				if (i != m ) cout << " ";
			}
			cout << endl;
		}
		else return;
	}
	for (int i = 2; i <= m; ++i)
		if (flag[i] == 0&&Isprime(pri,i)){
			flag[i] = 1;
			p[index] = i;
			++index;
			show(i,count);
			--index;
			flag[i] = 0;
		}
}

int main(){
	int count = 1;
	int bb = 0;
	while (cin >> m&&m){
		if (m == 1){
			cout << "Case " << count++ << ":" << endl;
			cout << 1 << endl<<endl;
			continue;
		}
		if (m % 2) continue;
		
		memset(flag, 0, sizeof(bool)* 20);
		index = 2;
		p[1] = 1;
		flag[1] = 1;
		cout << "Case " << count++ << ":" << endl;
		show(1,count);
		cout << endl;

	
	}

}