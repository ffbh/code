#include<iostream>
#include <cmath>
using namespace std;
int getc(int n){//�õ�n�Ĳ���
	int m = int(sqrt(n));
	if (m*m == n) return m;
	else  return m + 1;
}

int pos(int n){//�õ�n������
	if (n == 1) return 0;
	int m = getc(n);
	int mid = (m*m + (m - 1)*(m - 1)) / 2+1;
	return n - mid;

}

bool Isplus(int n){//�ж��Ƿ�Ϊ������
	int m = getc(n);
	return n % 2 && m % 2 || !(n % 2) &&!( m % 2);

}
int result(int h, int w){//hΪ�����wΪ������
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
		if (Isplus(m) && Isplus(n) || !Isplus(m) && !Isplus(n))//�������������������
			cout << result(h, w) << endl;
		//������һ��һ��
		else if (m>n&&Isplus(m) || n>m&&Isplus(n))//�������ϴ���Ϊ������
			cout << result(h +1 , w) - 1 << endl;
		else //�������ϴ���Ϊ������
			cout << result(h - 1, w) + 1 << endl;
		
	}

	



	return 0;
}