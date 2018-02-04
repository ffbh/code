#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string s;
string pace[110][110];
int dp[110][110];
string get_V(string& p,int d){
	if (d == 1)
		return p;
	int left, right;
 	left = right = -1;
	for (int i = 0; i < p.length();++i)
	if (p[i] == '('){
		left = i;
		break;
	}
	for (int i = p.length() - 1; i >= 0; --i)
	if (p[i] == ')'){
		right = i;
		break;
	}
	if (left != -1 && right != -1){
		left++;
		return p.substr(left, right-left);
	}
	return p.substr(0,p.length()/d);
}

string IntToString(int v){
	string ret = "";
	while (v){
		ret += v % 10 + '0';
		v /= 10;
	}
	return string(ret.rbegin(), ret.rend());
}

int main(){
	ifstream in("C:\\temp.txt");
	string temp1, temp2, tmp1, tmp2, temp;
	cin >> s;
	int length = s.length();
	for (int i = 0; i < length; ++i)
	for (int j = i; j < length; ++j){
		dp[i][j] = 1;
		pace[i][j] = s.substr(i, j - i + 1);
	}
 	for (int len = 2; len <= length;++len)
	for (int i = 0; i + len - 1 < length; ++i){
		int j = i + len - 1;
		for (int k = i; k < j; ++k){
			temp1 = get_V(pace[i][k], dp[i][k]);
			temp2 = get_V(pace[k + 1][j], dp[k + 1][j]);
			tmp2 = pace[i][k] + pace[k + 1][j];
			if (temp1 == temp2){
				int flod = dp[i][k] + dp[k + 1][j];
				dp[i][j] = flod;
				tmp1 = IntToString(flod) + "(" + temp1 + ")";
				if (tmp1.length() < pace[i][j].length())
					pace[i][j] = tmp1;
			}
			if (tmp2.length() < pace[i][j].length()){
				pace[i][j] = tmp2;
				dp[i][j] = 1;
			}
		}
	}
	cout << pace[0][length - 1] << endl;
	return 0;
}