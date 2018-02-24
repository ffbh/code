#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;

int a[11][10][4][100010];
int h[266];
string s;
int N;

int lowbit(int x){
	return x&(-x);
}

void upd(int l,int d,int c,int x,int val){
	while (x <= N){
		a[l][d][c][x] += val;
		x += lowbit(x);
	}
}


int qur(int l,int d,int c,int x){
	int sum = 0;
	while (x > 0){
		sum += a[l][d][c][x];
		x -= lowbit(x);
	}
	return sum;
}


void change(string& t,int p){
	for (int i = 0; i < p; ++i)
		t = t.back() + t.substr(0, t.length() - 1);
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	h['A'] = 0;
	h['T'] = 1;
	h['G'] = 2;
	h['C'] = 3;
	in >> s;
	s = '0' + s;
	memset(a, 0, sizeof(a));
	N = s.length() - 1;
	for (int L = 1; L <= 10; ++L){
		for (int i = 1; i <= N; ++i){
			upd(L, i%L, h[s[i]], i, 1);
		}
	}






	int K;
	in >> K;
	while (K-- > 0){
		int code;
		in >> code;
	
		if (code == 1){
			int x;
			char c;
			in >> x >> c;

			for (int L = 1; L <= 10; ++L){
				upd(L, x%L, h[s[x]], x, -1);
				upd(L, x%L, h[c], x, 1);
			}
			s[x] = c;
		}
		else{
			int l, r;
			string temp;
			in >> l >> r >> temp;
			int len = temp.length();
			int p = l%len;
			change(temp, p);
			int ans = 0;
			for (int i = 0; i < temp.length(); ++i){
				ans += qur(len, i%len, h[temp[i]], r) - qur(len, i%len, h[temp[i]], l - 1);
			}
			printf("%d\n", ans);
		}






	}











	return 0;
}





