#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[1000001];
void fun(int n){
	int ans = n;
	while (n){
		ans += n % 10;
		n /= 10;
	}
	if (ans <= 1000000)
		dp[ans] = 1;
}

int main(){
	ifstream in("C:\\temp.txt");
	for (int i = 1; i <= 1000000; ++i){
		if (dp[i] == 0)
			printf("%d\n", i);
		fun(i);
	}
	return 0;
}