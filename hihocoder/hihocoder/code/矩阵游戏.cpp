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
int N, ans[10][10];
int p;
bool judge(int x,int y){
	if (x == -2)
		return 0;
	int k = y*(1 - x);
	k = 1 - k;
	if (k % (x + 2) == 0){
		p = k / (x + 2);
		return 1;
	}

	return 0;

}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;


	in >> N;

	bool ok = 0;
	for (int i = 1; i <= N; ++i){
		in >> ans[1][i];
		if (ans[1][i])
			ok = 1;
	}
	if (!ok){
		cout << "No" << endl;
		return 0;
	}

	if (N == 1){
		if (ans[1][1] == 1){
			cout << 1 << endl;
		}
		else{
			cout << "No" << endl;
		}
		return 0;
	}



	for (int i = 2; i <= N; ++i)
	for (int j = 1; j <= N; ++j){
		if (i == j)
			ans[i][j] = 1;
		else
			ans[i][j] = 0;
	}

	bool d = 0;
	for (int i = 2; i <= N; ++i){
		if (judge(ans[1][1], ans[1][i])){
			ans[i][1] = ans[1][1] - 1;
			ans[i][i] = p;
			d = 1;
			break;

		}
	}

	if (d){
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j < N; ++j)
				cout << ans[i][j] << " ";
			cout << ans[i][N] << endl;
		}
	}
	else{
		cout << "No" << endl;
	}


	return 0;
}