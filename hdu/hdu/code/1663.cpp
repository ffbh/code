#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;

int num[10];

void _cale_digit(int n){
	while (n){
		num[n % 10]++;
		n /= 10;
	}
}

void _cale_one_to_N(int n){
	memset(num, 0, sizeof(num));
	for (int i = 1; i <= n; ++i)
		_cale_digit(i);
	for (int i = 0; i <= 9; ++i){
		cout << i << ":" << num[i] << " ";
	}
	cout << endl;
}

int dp[10][10][10], temp[10];
void Init(){
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= 9; ++i)
	for (int j = 1; j <= i; ++j)
		dp[1][i][j] = 1;
	for (int len = 2; len < 10; ++len){
		int sum = (len - 2)*((int)pow(10, len - 2) - 1);
		int first_digit_num = (int)pow(10, len - 2) - 1;
		for (int t = 0; t < 10; ++t){
			dp[len][1][t] = dp[len - 1][9][t];
			temp[t] = dp[len - 1][1][t];
			//	sum -= temp[t];
			sum -= dp[len - 1][1][t];
		}
		dp[len][1][1]++;
		dp[len][1][0] += len - 1;
		dp[len][1][9] += first_digit_num;
		temp[1]--;
		temp[0] -= len - 2;
		sum += (1 + len - 2);
		temp[0] += sum;
		for (int t = 0; t < 10; ++t){
			dp[len][1][t] += temp[t];
		}

		first_digit_num = (int)pow(10, len - 1) - 1;
		sum = (len - 1)*((int)pow(10, len - 1) - 1);
		for (int t = 0; t < 10; ++t){
			temp[t] = dp[len][1][t];
			sum -= temp[t];
		}
		temp[1]--;
		temp[0] -= len - 1;
		sum += (1 + len - 1);
		temp[0] += sum;

		for (int k = 2; k <= 9; ++k){
			for (int t = 0; t < 10; ++t){
				dp[len][k][t] = dp[len][k - 1][t];
				dp[len][k][t] += temp[t];
			}
			dp[len][k][k]++;
			dp[len][k][0] += len - 1;
			dp[len][k][k - 1] += first_digit_num;
		}
	}

}

void getAns(int tp[10], int N){
	int t_N = N;

	for (int t = 0; t < 10; ++t)
		tp[t] = 0;
	int digits[10];
	int dig_len = 1;
	while (N){
		digits[dig_len++] = N % 10;
		N /= 10;
	}
	int all_digit = 0;
	for (int i = 1; i < dig_len - 1; ++i){
		int num1;
		if (i != 1)
			num1 = (pow(10, i) - pow(10, i - 1));
		else
			num1 = 9;
		int num2 = i;
		all_digit += num1*num2;
	}
	int num1 = t_N - pow(10, dig_len - 2) + 1;
	int num2 = dig_len - 1;
	all_digit += num1*num2;
	int sum = 0;
	for (int len = 1; len < dig_len; ++len){
		tp[digits[len]] += sum;
		sum += digits[len] * (int)pow(10, len - 1);
		for (int t = 0; t < 10; ++t){
			tp[t] += dp[len][digits[len]][t];
		}
	}
	for (int i = 1; i < 10; ++i){
		all_digit -= tp[i];
	}
	tp[0] = all_digit;

}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	int a, b, A[10], B[10];
	while (cin >> a >> b&&a + b){
		if (a < b)
			swap(a, b);
		getAns(A, a);
		getAns(B, b - 1);
		for (int i = 0; i < 9; ++i)
			printf("%d ", A[i] - B[i]);
		printf("%d\n", A[9] - B[9]);
	}













	return 0;
}