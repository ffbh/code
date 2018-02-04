/*#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
const int MMAX = 100010;
const int MAXM = 1010;
int n;
int cntA[MMAX], cntB[MMAX], ch[MMAX], sa[MMAX], Rank[MMAX], tsa[MMAX], A[MMAX], B[MMAX];

void slove()
{
	for (int i = 0; i < MAXM; i++) cntA[i] = 0;
	for (int i = 1; i <= n; i++) cntA[ch[i]] ++;
	for (int i = 1; i < MAXM; i++) cntA[i] += cntA[i - 1];
	for (int i = n; i; i--) sa[cntA[ch[i]] --] = i;
	Rank[sa[1]] = 1;
	for (int i = 2; i <= n; i++)
	{
		Rank[sa[i]] = Rank[sa[i - 1]];
		if (ch[sa[i]] != ch[sa[i - 1]]) Rank[sa[i]] ++;
	}
	for (int l = 1; Rank[sa[n]] < n; l <<= 1)
	{
		for (int i = 0; i <= n; i++) cntA[i] = 0;
		for (int i = 0; i <= n; i++) cntB[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			cntA[A[i] = Rank[i]] ++;
			cntB[B[i] = (i + l <= n) ? Rank[i + l] : 0] ++;
		}
		for (int i = 1; i <= n; i++) cntB[i] += cntB[i - 1];
		for (int i = n; i; i--) tsa[cntB[B[i]] --] = i;
		for (int i = 1; i <= n; i++) cntA[i] += cntA[i - 1];
		for (int i = n; i; i--) sa[cntA[A[tsa[i]]] --] = tsa[i];
		Rank[sa[1]] = 1;
		for (int i = 2; i <= n; i++)
		{
			Rank[sa[i]] = Rank[sa[i - 1]];
			if (A[sa[i]] != A[sa[i - 1]] || B[sa[i]] != B[sa[i - 1]]) Rank[sa[i]] ++;
		}
	}
}
bool has[1010];
int getEqualCharNum(int c, int d){
	int num = 0;
	while (c <= n&&d <= n&&ch[c] == ch[d]){
		num++;
		c++;
		d++;
	}
	return num;
}

int main(){
	ifstream in("C:\\input.txt");
	in >> n;
	int ans = 0;
	for (int i = 0; i <= n; ++i){
		in >> ch[i];
		if (has[ch[i]])
			ans = 1;
		else
			has[ch[i]] = 1;
	}
	if (ans == 0){
		printf("%d\n", ans);
		return 0;
	}
	slove();
	for (int i = 1; i <= n; ++i){
		int a = sa[i], b = -1;
		for (int j = i + 1; j <= n; ++j){
			if (abs(a - sa[j]) >= ans){
				b = sa[j];
				break;
			}
		}
		if (b != -1){
			int ret = getEqualCharNum(a, b);
			ans = max(ans, ret);
		}
	}
	printf("%d\n", ans);

	return 0;
}*/