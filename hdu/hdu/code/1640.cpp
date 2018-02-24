#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
char s1[30], s2[30], tmp[30];
int dp[30][30], pace[30][30];
int prenum, realpos;

void PrintPath(int a, int b){
	if (a == 2 && b == 1){
		int t = 0;
	}
	if (a == 0 && b == 0){

	}
	else{
		if (pace[a][b] == 0){
			PrintPath(a - 1, b - 1);

		}
		else if (pace[a][b] == 1){
			PrintPath(a - 1, b - 1);
			printf("C%c%02d", s2[prenum + a], prenum + a);

		}
		else if (pace[a][b] == 2){
			PrintPath(a, b - 1);
			printf("I%c%02d", s2[prenum + a + 1], prenum + a + 1);
			prenum++;

		}
		else{
			PrintPath(a - 1, b);
			//	printf("D%c%02d", s1[prenum + a+delp], prenum + a);
			printf("D%c%02d", s1[a], prenum + a);
			prenum--;


		}
	}
}


int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	string s;
	while (getline(in,s) && s!="#"){
		int pos;
		for (int i = 0; i < s.length();++i)
		if (s[i] == ' '){
			pos = i;
			break;
		}
		for (int i = 0; i < 30; ++i){
			s1[i] = s2[i] = '\0';
		}
		int ap = 1;
		for (int i = 0; i < pos; ++i){
			if (s[i] != ' ')
			s1[ap++] = s[i];
		}
		int bp = 1;
		for (int i = pos + 1; i < s.length(); ++i){
			if (s[i] != ' ')
			s2[bp++] = s[i];
		}
		int al = strlen(s1 + 1);
		int bl = strlen(s2 + 1);
		for (int i = 0; i < 30; ++i)
		for (int j = 0; j < 30; ++j)
			dp[i][j] = 0;
		prenum = 0;
		if (s1[1] == s2[1])
			dp[1][1] = 0;
		else{
			dp[1][1] = 1;
		}
		dp[0][0] = 0;
		for (int i = 1; i <= al; ++i){
			dp[i][0] = dp[i - 1][0] + 1;
			pace[i][0] = 3;
		}
		for (int i = 1; i <= bl; ++i){
			dp[0][i] = dp[0][i - 1] + 1;
			pace[0][i] = 2;;
		}
		for (int i = 1; i <= al; ++i)
		for (int j = 1; j <= bl; ++j){

			if (i == 3 && j == 3){
				int t = 0;
			}


			if (s1[i] == s2[j]){
				dp[i][j] = dp[i - 1][j - 1];
				pace[i][j] = 0;
			}
			else{
				dp[i][j] = 999999;
				if (dp[i][j] > dp[i - 1][j - 1] + 1){
					dp[i][j] = dp[i - 1][j - 1] + 1;
					pace[i][j] = 1;//change
				}

				if (dp[i][j] > dp[i][j - 1] + 1){
					dp[i][j] = dp[i][j - 1] + 1;
					pace[i][j] = 2;//insert
				}

				if (dp[i][j] > dp[i - 1][j] + 1){
					dp[i][j] = dp[i - 1][j] + 1;
					pace[i][j] = 3;//delete
				}
			}
		}
		PrintPath(al, bl);
		cout << "E" << endl;
	}



	return 0;
}