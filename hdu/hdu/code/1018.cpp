#include <iostream>
using namespace std;
//the time limit
int dight(int n){
	int i = 1;
	while (n = n / 10)i++;
		
	return i;
}

int mul1(int n){
	int p[220000] = { 0 };
	int i;
	int t = 0;
	int k = 1;
	p[0] = 1;
	while (n--){
		for (i = 0; i<k; ++i){
			p[i] *= 2;
			p[i] += t;
			t = p[i] / 100000000;
			p[i] %= 100000000;
		}
		if (t)p[k++] = t;
	}
	return (k-1) * 8 + dight(p[k-1]);


}
int main(){
	int n;
	cin >> n;
	while (n--){
		int t;
		cin >> t;
		cout << mul1(t) << endl;
	}



	return 0;
}