#include <iostream>
using namespace std;
#define MAXN 1000000
int num[MAXN] = { 0 };
struct TEMP{
	int sum;
	int time;
};

TEMP use(int nn){
	int time = 0;
	long long int n = nn;
	while (n >= MAXN){
		if (n % 2) n = 3 * n + 1;
		else n /= 2;
		time++;
	}
	TEMP t;
	t.sum = int(n);
	t.time = time;
	return t;
}

int fun(int n){
	if (n == 1)return 1;
	if (n % 2){
		if (3 * n + 1 < MAXN){
			if (num[3 * n + 1] == 0)
				num[3 * n + 1] = fun(3 * n + 1);
			return num[3 * n + 1] + 1;
		}
		else  {
			TEMP t=use(3*n+1);
			if (num[t.sum] == 0)
				num[t.sum] = fun(t.sum);
			return fun(t.sum) + t.time + 1;
		}
		
	}
	else {
		if (n / 2 < MAXN){
			if (num[n / 2] == 0)
			num[n / 2] = fun(n / 2);
		return num[n / 2] + 1;
		}
		else {
			TEMP t=use(n / 2);
			if (num[t.sum] == 0)
				num[t.sum] = fun(t.sum);
			return fun(t.sum) + t.time + 1;
		}
		
	}

}

int MAX(int a, int b){
	return a > b ? a : b;
}
int MIN(int a, int b){
	return a < b ? a : b;
}

int main(){
	for (int i = 1; i<MAXN; ++i)
		if (num[i] == 0)
			num[i] = fun(i);

		int i, j;
		int mi, mj;
		while (cin >> i >> j){
			cout << i << " " << j << " ";
			mi = MIN(i, j);
			mj = MAX(i, j);
			int max = 0;
			for (; mi <= mj;++mi)
				if (max < num[mi]) 
					max = num[mi];
				cout << max << endl;
		
		}



	return 0;

}