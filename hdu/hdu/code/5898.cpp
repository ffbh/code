
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
			  using namespace std;
string LLToString(long long n, int base){
	string ret = "";
	while (n){
		ret += n % base + '0';
		n /= 10;
	}
	return string(ret.rbegin(), ret.rend());
}

bool judge(string s){
	int pos = 0;
	while (pos < s.length()){
		char c = s[pos];
		int tn = 0;
		while (pos < s.length() && s[pos] == c){
			pos++;
			tn++;
		}
		if (c == '0' && tn % 2 == 0 || c == '1'&&tn % 2 == 1)
			return 0;

	}
	return 1;
}

long long baoli(long long A){
	long long num = 0;
	for (int i = 1; i <= A; ++i){
		if (judge(LLToString(i, 2))){
			num++;
		}
	}
	return num;

}

long long dp[20][10][2];
int odd[5] = { 1, 3, 5, 7, 9 };
int even[5] = { 0, 2, 4, 6, 8 };

void Init(){
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 10; ++i)
		dp[1][i][1] = 1;
	for (int len = 2; len < 20; ++len){
		for (int i = 0; i < 10; ++i){

			if (i % 2 == 0){
				for (int k = 0; k < 5; ++k){
					dp[len][i][0] += dp[len - 1][even[k]][1];
					dp[len][i][1] += dp[len - 1][even[k]][0];

					dp[len][i][1] += dp[len - 1][odd[k]][0];
				}
			}
			else{
				for (int k = 0; k < 5; ++k){
					dp[len][i][0] += dp[len - 1][odd[k]][1];
					dp[len][i][1] += dp[len - 1][odd[k]][0];

					dp[len][i][1] += dp[len - 1][even[k]][1];
				}
			}
		}
	}
}

string digit;

long long dfs(int pos, int pre, int num){
	long long sum = 0;
	num %= 2;
	int len = digit.length() - pos;
	if (len == 0){
		return pre % 2 != num % 2;
	}
	int now = digit[pos] - '0';
	int start;
	if (pre == -1){
		start = 1;
	}
	else
		start = 0;
	for (int i = start; i < now; ++i){
		if (pre == -1){
			sum += dp[len][i % 2][1 - i % 2];
		}
		else if (pre % 2 == 0){
			if (i % 2 == 0){
				sum += dp[len][i][1 - num];
			}
			else{
				if (pre % 2 != num % 2){
					sum += dp[len][i][0];
				}
			}
		}
		else{
			if (i % 2 == 1){
				sum += dp[len][i][num];
			}
			else{
				if (pre % 2 != num % 2){
					sum += dp[len][i][1];
				}
			}
		}
	}
	if (pre == -1){
		sum += dfs(pos + 1, now, 1);
	}
	else if (now % 2 == pre % 2){
		sum += dfs(pos + 1, now, num + 1);
	}
	else{
		if (num % 2 != pre % 2){
			sum += dfs(pos + 1, now, 1);
		}
	}
	return sum;
}

long long getAns(long long N){
	digit = LLToString(N, 10);
	long long sum = dfs(0, -1, -1);
	int len = digit.length();
	digit = "";
	for (int i = 1; i < len; ++i){
		digit += '9';
		sum += dfs(0, -1, -1);
	}
	return sum;
}


int main(){
	ifstream in("C:\\input.txt");
	Init();
	//long long aim = 50830;
	//cout << baoli(aim) << endl;
	//cout << getAns(aim) << endl;
	int T, CASE = 1;
	cin >> T;
	long long A, B;
	while (T--){
		cin >> A >> B;
		printf("Case #%d: %lld\n", CASE++, getAns(B) - getAns(A - 1));



	}
















	return 0;
}
[Copy to Clipboard][Save to File]



Home | Top	Hangzhou Dianzi University Online Judge 3.0
Copyright © 2005 - 2017 HDU ACM Team.All Rights Reserved.
Designer & Developer : Wang Rongtao LinLe GaoJie GanLu
Total 0.000000(s)query 1, Server time : 2017 - 01 - 30 10 : 45 : 55, Gzip enabled	Administration