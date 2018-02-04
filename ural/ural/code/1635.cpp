#include <iostream>
#include <string>
#include <fstream>
using namespace std;
char s[4010];
short dp[4010];
short pace[4010];
bool palindrome[4010][4010];
void Init(){
	int l, r;
	int len = strlen(s);
	for (int i = 0; i < len; ++i){
		l = r = i;
		while (l >= 0 && r < len&&s[l] == s[r]){
			palindrome[l][r] = 1;
			l--;
			r++;
		}
		l = i;
		r = i + 1;
		while (l >= 0 && r < len&&s[l] == s[r]){
			palindrome[l][r] = 1;
			l--;
			r++;
		}
	}
}

void Print(int x){
	if (pace[x] == 0){
		for (int i = pace[x]; i <= x; ++i)
			putchar(s[i]);
		putchar(' ');
	}
	else{
		Print(pace[x] - 1);
		for (int i = pace[x]; i <= x; ++i)
			putchar(s[i]);
		putchar(' ');
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	cin >> s;
	Init();
	int length = strlen(s);
	for (int i = 0; i < length; ++i){
		dp[i] = 1;
		pace[i] = i;
	}
	for (int i = 0; i < length; ++i){
		dp[i] = 8888;
		for (int j = i; j >= 0; --j)
		if (palindrome[j][i] && dp[i]>dp[j - 1] + 1){
			dp[i] = dp[j - 1] + 1;
			pace[i] = j;
		}
	}
	cout << dp[length-1] << endl;
	Print(length - 1);
	cout << endl;
	return 0;
}