#include<iostream>
#include <cmath>
using namespace std;
int getc(int n){//得到n的层数
	int m = int(sqrt(n));
	if (m*m == n) return m;
	else  return m + 1;
}

int pos(int n){//得到n的列数
	if (n == 1) return 0;
	int m = getc(n);
	int mid = (m*m + (m - 1)*(m - 1)) / 2+1;
	return n - mid;

}

bool Isplus(int n){//判断是否为正三角
	int m = getc(n);
	return n % 2 && m % 2 || !(n % 2) &&!( m % 2);

}
int result(int h, int w){//h为层数差，w为列数差
	if (w <= h) return  2 * h ;
	else return 2 * h + w - h;

}
int main(){
	int n, m;
	while (cin>>m>>n){
		int mc = getc(m);
		int nc = getc(n);
		if (mc == nc) {
			cout << abs(m - n) << endl;
			continue;
		}
		int mp = pos(m);
		int np = pos(n);
		int h = abs(mc - nc);
		int w = abs(mp - np);
		if (Isplus(m) && Isplus(n) || !Isplus(m) && !Isplus(n))//如果两个数都是正三角
			cout << result(h, w) << endl;
		//两个数一正一反
		else if (m>n&&Isplus(m) || n>m&&Isplus(n))//两个数较大着为正三角
			cout << result(h +1 , w) - 1 << endl;
		else //两个数较大者为反三角
			cout << result(h - 1, w) + 1 << endl;
		
	}

	



	return 0;
}