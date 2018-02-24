#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
double dp1[1010], dp2[1010];
int ans1[1010], ans2[1010];
double data[1010];

int main(){
	ifstream in("C:\\temp.txt");
	int N, count1, count2;
	while (cin >> N){
		for (int i = 1; i <= N; ++i)
			cin >> data[i];
		count1 = count2 = 0;
		dp1[count1++] = data[1];
		ans1[1] = ans2[N] = 1;
		for (int i = 2; i <= N; ++i){
			if (dp1[count1 - 1] < data[i])
				dp1[count1++] = data[i];
			else
				*lower_bound(dp1, dp1 + count1, data[i]) = data[i];
			ans1[i] = count1;
		}

		dp2[count2++] = data[N];
		for (int i = N - 1; i >= 1; --i){
			if (dp2[count2 - 1] < data[i])
				dp2[count2++] = data[i];
			else
				*lower_bound(dp2, dp2 + count2, data[i]) = data[i];
			ans2[i] = count2;
		}
		int mmin = 99999;
		for (int i = 1; i <= N; ++i)
		for (int j = i + 1; j <= N; ++j){
			int tmp = N - (ans1[i] + ans2[j]);
			if (tmp < mmin)
				mmin = tmp;

		}
		cout << mmin << endl;



	}
	return 0;
}