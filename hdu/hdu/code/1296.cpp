#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;
bool OP[20];
int cnt;
bool X;//真代表存在X的指数为1的项

bool ok(char c){
	return c >= '0'&&c <= '9';
}

int getK(string& s){
	int k = 0;
	cnt = 0;
	int x = 0;
	int len = s.length();
	if (s[0] != '-')
		OP[cnt++] = 1;
	if (s[0] == 'X'){
		s[0] = '1';
		x++;
	}
	for (int i = 0; i < len;++i)
	if (s[i] == '^'){
		s[i] = ' ';
		k++;
	}
	else if (s[i] == 'X'){
		if (ok(s[i-1])){
			s[i] = ' ';
			x++;
		}
		else{
			s[i] = '1';
			x++;
		}
	}
	else if (s[i] == '+' || s[i] == '-'){
		OP[cnt++] = s[i] == '+';
		s[i] = ' ';
	}
	X = (k != x);
	return k;
}

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	stringstream ss;
	string s;
	int ans;
	int a, b;
	while (cin >> N){
		cin >> s;
		ans = 0;
		int k = getK(s);
		ss.clear();
		ss.str(s);
		for (int i = 0; i < k; ++i){
			ss >> a >> b;
			if (OP[i])
				ans += a*pow(N, b);
			else
				ans -= a*pow(N, b);
		}
		a = b = 0;//清0
		ss >> a >> b;
		if (X){
			if (OP[k])
				ans += a*N;
			else
				ans -= a*N;
		}
		else{
			if (OP[k])
				ans += a;
			else
				ans -= a;
		}
		if (OP[k + 1])//若字符串流提早结束，则加0或减0无影响
			ans += b;
		else
			ans -= b;
		cout << ans << endl;
	}

	return 0;
}