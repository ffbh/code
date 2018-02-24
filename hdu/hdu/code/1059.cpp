#include <iostream>
using namespace std;
int num[7];
bool dp[220000];
int TTT;


void ZeroOnePack(int v, int w){
	for (int i = TTT; i >= w;--i)
	if (dp[i - w])
		dp[i] = 1;
}

void CompletePack(int v,int w){
	for (int i = w; i <= TTT;++i)
	if (dp[i - w])
		dp[i] = 1;
}

int main(){
	int sum;
	int c=1;
	int ok = 0;
	int CASE = 1;
	while (1){
		if (ok)cout << endl;
		ok = 1;
		
		sum = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= 6; ++i){
			cin >> num[i];
			sum += num[i] * i;
		}
		if (sum == 0)break;
		printf("Collection #%d:\n", CASE++);
		if (sum % 2){
			cout << "Can't be divided." << endl;
			continue;
		}
		TTT = sum / 2;
		dp[0] = 1;
		for (int k = 1; k <= 6; ++k){
			if (num[k] * k >= TTT)
				CompletePack(k, k);
			else{
				int ff = 1;
				while (num[k] > ff){
					ZeroOnePack(ff*k, ff*k);
					num[k] -= ff;
					ff *= 2;
				}
				if (num[k]>0)
				ZeroOnePack(num[k] * k, num[k] * k);
			}
		}
		if (dp[TTT])
			cout << "Can be divided." << endl;
		else
			cout << "Can't be divided." << endl;





	}


	return 0;
}