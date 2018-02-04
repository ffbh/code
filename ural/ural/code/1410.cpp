#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;
int dp[10010][2];
int data[10010], size;
stringstream ss;
int main(){
	ifstream in("C:\\input.txt");
	size = 0;
	string s;
	while (cin >> s){
		for (int i = 0; i < s.length(); ++i){
			if (!islower(s[i]) && !isupper(s[i]))
				s[i] = ' ';
		}
		ss.clear();
		ss.str(s);
		while (ss >> s){
			data[size] = s.length();
			size++;
		}
	}
	size--;
	if (size < 0){
		cout << 0 << endl;
	}
	else{
		dp[0][1] = data[0];
		dp[0][0] = 0;
		dp[1][0] = data[0];
		dp[1][1] = data[1];
		for (int i = 2; i <= size; ++i){
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = max(dp[i - 1][0], dp[i - 2][1]) + data[i];
		}

		cout << max(dp[size][0], dp[size][1]) << endl;
	}

	return 0;
}