#include<iostream>
using namespace std;
int fun(int n){
	int m = n % 10;
	if (m == 0 || m == 1 || m == 5 || m == 6)
		return m;
	else if (m == 3 || m == 2 || m == 7 || m == 8){
		n = n % 4 + 4;
		int old = m;
		m = 1;
		for (int i = 0; i < n; ++i)
			m *= old;
		return m % 10;
	}
	else{
		n = n % 2 + 2;
		int old = m;
		for (int i = 0; i < n - 1; ++i)
			m *= old;
		return m % 10;
	}
}
int main(){
	int n, m;
	cin >> n;
	while (n--){
		scanf("%d", &m);
		cout << fun(m) << endl;

	}



	return 0;
}