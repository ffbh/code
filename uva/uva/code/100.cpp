#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

int ans[1000010];

void cale(long long p){
	long long tp = p;
	int num = 0;
	while (1){
		if (p < 1000010 && ans[p]){
			ans[tp] = ans[p] + num;
			break;
		}
		if (p % 2 == 1){
			p = 3 * p + 1;
		}
		else{
			p /= 2;
		}
		num++;
	}

}

void Init(){
	ans[1] = 1;
	for (int i = 2; i < 1000010; ++i){
		cale(i);
	}

}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	int a, b;
	while (cin >> a >> b){
		int mmin = min(a, b);
		int mmax = max(a, b);
		int m_ans = 0;
		for (int i = mmin; i <= mmax; ++i)
			m_ans = max(m_ans, ans[i]);

		cout << a << " " << b << " " << m_ans << endl;


	}





	return 0;
}