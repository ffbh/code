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
int price[] = { 1, 2, 4, 10, 20, 40 };
int num[6];
int cnum[6];
int aim;
#define MMAX (420)
#define MID (210)
int dp[MMAX], temp[MMAX];
int cale(){
	for (int i = 0; i < MMAX; ++i)
		dp[i] = -1;
	dp[MID] = 0;
	for (int k = 0; k < 6; ++k){
		if (num[k] == 0)
			continue;
		for (int i = 0; i < MMAX; ++i)
			temp[i] = -1;
		for (int i = 0; i < MMAX; ++i){
			if (dp[i] != -1){
				for (int j = 1; j <= num[k]; ++j){
					int val,moneynum;
					val = i + j*price[k];
					moneynum = dp[i] + j;
					if (val>0 && val<MMAX&&(temp[val]==-1||temp[val]>moneynum)){
						temp[val] = moneynum;
					}
				/*	val = i - j*price[k];
					moneynum = dp[i] + j;
					if (val>0 && val<MMAX && (temp[val] == -1 || temp[val]>moneynum)){
						temp[val] = moneynum;
					}*/
				}
			}
		}

		for (int i = 0; i < MMAX; ++i){
			if (temp[i] != -1){
				if (dp[i] == -1 || dp[i]>temp[i]){
					dp[i] = temp[i];
				}
			}
		}

	}

	for (int k = 0; k < 6; ++k){
		if (cnum[k] == 0)
			continue;
		for (int i = 0; i < MMAX; ++i)
			temp[i] = -1;
		for (int i = 0; i < MMAX; ++i){
			if (dp[i] != -1){
				for (int j = 1; j <= cnum[k]; ++j){
					int val, moneynum;

					val = i - j*price[k];
					moneynum = dp[i] + j;
					if (val>0 && val<MMAX && (temp[val] == -1 || temp[val]>moneynum)){
					temp[val] = moneynum;
					}
				}
			}
		}

		for (int i = 0; i < MMAX; ++i){
			if (temp[i] != -1){
				if (dp[i] == -1 || dp[i]>temp[i]){
					dp[i] = temp[i];
				}
			}
		}

	}

	return dp[aim+MID];

}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	while (1){
		int sum = 0;
		for (int i = 0; i < 6; ++i){
			in >> num[i];
			sum += num[i];
			cnum[i] = 100 / price[i];
		}
		if (sum == 0)
			break;

		double tmp;
		in >> tmp;
		aim = round(tmp * 20);

		printf("%3d\n", cale());
	}
	
	
	return 0;
}