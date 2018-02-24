#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
char data[1010];
int A[510];
int B[510];
int ans[1010];
int t[510][510], ll[510];
char op;
int al, bl;



int main(){
	ifstream in("C:\\input.txt");
	int N, len;
	cin >> N;
	while (N--){
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(ans, 0, sizeof(ans));
		memset(t, 0,sizeof(t));
		cin >> data;
		int ii, s, e;
		for (ii = 0; data[ii] >= '0'&&data[ii] <= '9'; ++ii);
		al = ii - 1;
		for (int j = 0; j <= al; ++j)
			A[j] = data[al - j]-'0';
		op = data[ii];
		for (ii++; data[ii]; ++ii);	
		bl = ii - al - 3;
		for (int j = 0; j <= bl; ++j)
			B[j] = data[ii - 1 - j]-'0';
	//	while (al && A[al] == 0) al--;
	//	while (bl && B[bl] == 0) bl--;

		if (op == '+'){///////qiandao 0000
			int ansl = max(al, bl)+1;
			int f = 0;
			for (int i = 0; i <= ansl; ++i){
				ans[i] = (A[i] + B[i] + f) % 10;
				f = (A[i] + B[i] + f) / 10;
			}
			while (ansl>0 && !ans[ansl]) ansl--;
			int l = max(max(al, bl + 1), ansl);
			for (int i = l; i >= 0; --i){
				if (i > al)
					putchar(' ');
				else
					putchar(A[i] + '0');
			}
			putchar('\n');
			for (int i = l; i >= 0; --i){
				if (i > bl + 1)
					putchar(' ');
				else if (i == bl + 1)
					putchar(op);
				else
					putchar(B[i] + '0');
			}
			putchar('\n');

			for (int i = l; i >= 0; --i){
				if (i > max(bl + 1,ansl))
					putchar(' ');
				else
					putchar('-');
			}
			putchar('\n');

			for (int i = l; i >= 0; --i){
				if (i > ansl)
					putchar(' ');
				else
					putchar(ans[i] + '0');
			}
			putchar('\n');

		}
		else if (op == '-'){
			int ansl = max(al, bl);
			int f = 0;
			for (int i = 0; i <= ansl; ++i){
				if (A[i] < B[i] + f){
					ans[i] = 10 + A[i] - B[i] - f;
					f = 1;
				}
				else{
					ans[i] = A[i] - B[i] - f;
					f = 0;
				}
			}
			while (ans[ansl] == 0 && ansl>0)ansl--;
			int l = max(max(al, bl + 1), ansl);
			for (int i = l; i >= 0; --i){
				if (i > al)
					putchar(' ');
				else
					putchar(A[i] + '0');
			}
			putchar('\n');
			for (int i = l; i >= 0; --i){
				if (i > bl + 1)
					putchar(' ');
				else if (i == bl + 1)
					putchar(op);
				else
					putchar(B[i] + '0');
			}
			putchar('\n');

			for (int i = l; i >= 0; --i){
				if (i > max( bl + 1,ansl))
					putchar(' ');
				else
					putchar('-');
			}
			putchar('\n');

			for (int i = l; i >= 0; --i){
				if (i > ansl)
					putchar(' ');
				else
					putchar(ans[i] + '0');
			}
			putchar('\n');
		}
		else{
			int f = 0;
			for (int i = 0; i <= bl; ++i){
				ll[i] = al + 1;
				for (int j = 0; j <= ll[i]; ++j){
					t[i][j] = (B[i] * A[j] + f) % 10;
					f = (B[i] * A[j] + f) / 10;
				}
				while (ll[i] && t[i][ll[i]]==0) ll[i]--;
				for (int j = 0; j <= ll[i]; ++j)
					ans[i + j] += t[i][j];

			}
			int ansl = (al+1) + (bl+1);
			f = 0;
			for (int i = 0; i <= ansl; ++i){
				int tmp = (ans[i] + f) / 10;
				ans[i] = (ans[i] + f) % 10;
				f = tmp;
			}
			while (ansl && ans[ansl] == 0) ansl--;
			int l = max(max(al, bl + 1), ansl);
			for (int i = l; i >= 0; --i){
				if (i > al)
					putchar(' ');
				else
					putchar(A[i] + '0');
			}
			putchar('\n');
			for (int i = l; i >= 0; --i){
				if (i > bl + 1)
					putchar(' ');
				else if (i == bl + 1)
					putchar(op);
				else
					putchar(B[i] + '0');
			}
			putchar('\n');

			for (int i = l; i >= 0; --i){
				if (i > max(bl + 1,ll[0]))
					putchar(' ');
				else
					putchar('-');
			}
			putchar('\n');

			for (int i = 0; i <= bl; ++i){
				for (int j = l - i; j >= 0; --j){
					if (j > ll[i])
						putchar(' ');
					else
						putchar(t[i][j] + '0');
				}
				putchar('\n');
			}

			if (bl){
				for (int i = l; i >= 0; --i){
					if (i > ansl)
						putchar(' ');
					else
						putchar('-');
				}
				putchar('\n');
				for (int i = l; i >= 0; --i){
					if (i > ansl)
						putchar(' ');
					else
						putchar(ans[i] + '0');
				}
				putchar('\n');
			}
		}
		putchar('\n');

	}
	return 0;
}