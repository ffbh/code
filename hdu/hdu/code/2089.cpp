#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int dp[10][10];
int num1[8] = { 0, 1, 3, 5, 6, 7, 8, 9 };
int num2[9] = { 0, 1, 2, 3, 5, 6, 7, 8, 9 };
string dig;

bool ok(int n){
	int pre = -1;
	while (n){
		int now = n % 10;
		n /= 10;
		if (now == 4 || pre == 2 && now == 6)
			return 0;
		pre = now;
	}
	return 1;
}

int baoli(int n){
	int sum = 0;
	for (int i = 0; i <= n; ++i){
		if (ok(i))
			sum++;
	}

	return sum;
}


void Init(){
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 10; ++i){
		if (i != 4){
			dp[1][i] = 1;
		}
	}

	for (int len = 2; len < 10; ++len){
		for (int i = 0; i < 10; ++i){
			if (i == 4)
				dp[len][i] = 0;
			else if (i == 6){
				for (int j = 0; j < 8; ++j){
					dp[len][i] += dp[len - 1][num1[j]];
				}
			}
			else{
				for (int j = 0; j < 9; ++j){
					dp[len][i] += dp[len - 1][num2[j]];
				}
			}
		}


	}





}

void IntToString(int n){
	dig = "";
	while (n){
		dig += n % 10 + '0';
		n /= 10;
	}
	dig = string(dig.rbegin(), dig.rend());
}

int dfs(int pos, int pre,int len){
	int sum = 0;
	if (pre == 6){
		for (int i = 0; i < 8&&num1[i]<dig[pos]-'0'; ++i){
			sum += dp[len][num1[i]];
		}
		
	}
	else{
		for (int i = 0; i < 9 && num2[i] < dig[pos] - '0'; ++i){
			sum += dp[len][num2[i]];
		}
	}
	if (len > 1){
		if (dig[pos] - '0' == 4 || dig[pos] - '0' == 2 && pre == 6){
			
		}
		else
			sum += dfs(pos + 1, dig[pos] - '0', len - 1);
	}
	else {
		if (pre == 6)
			sum += dig[pos] - '0' != 4 && dig[pos] - '0' != 2;
		else
			sum += dig[pos] - '0' != 4;
	}
	return sum;
}

int getAns(int n){
	IntToString(n);
	return dfs(0, -1, dig.length());
}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	int a, b;
	int aimb = 1629, aima = 1;
	//cout << baoli(aimb)-baoli(aima-1) << endl;
	while (cin >> a >> b&&a + b){
		printf("%d\n", getAns(b) - getAns(a-1));

	}

	return 0;
}