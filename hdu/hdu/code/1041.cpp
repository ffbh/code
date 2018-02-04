#include <iostream>
using namespace std;


void show(int* p){
	int k = 0;
	while (p[k]) k++;
	cout << p[k - 1];
	for (int j = k - 2; j >= 0; --j)
		printf("%07d", p[j]);
	cout << endl;
}
void mul(int* p){//大数的乘法，乘以2
	int i;
	int t=0;
	for (i = 0; p[i]; ++i){
		p[i] *= 2;
		p[i] += t;
		t = p[i] / 10000000;
		p[i] %= 10000000;
	}
	if (t)p[i] = t;
	
	
}

void add(int* p1, int* p2){//p1+=p2;
	int temp[80] = { 0 };
	for (int j = 0; p1[j]; ++j)
		temp[j] = p1[j];
	int i = 0;
	int t = 0;
	while (p1[i] && p2[i]){
		p1[i] += p2[i];
		p1[i] += t;
		t = p1[i] / 10000000;
		p1[i] %= 10000000;
		i++;
	}
	while (t){
		p1[i] += t;
		t = p1[i] / 10000000;
		p1[i] %= 10000000;
		i++;
	}
	for (int j = 0; p1[j]; ++j)
		p2[j] = temp[j];

}


int main(){
	
	int n;
	int p1[80];
	int p2[80];
	while (cin >> n){
		if (n == 1){
			cout << 0 << endl;
			continue;
		}
		else if (n == 2 || n == 3){
			cout << 1 << endl;
			continue;
		}
		memset(p1, 0, 80 * sizeof(int));
		memset(p2, 0, 80 * sizeof(int));
		p1[0] = 1;
		p2[0] = 1;
		n -= 3;
		while (n-->0){
			mul(p2);
			add(p1, p2);
		}
		show(p1);
	
	}
	
	
	

	return 0;
}