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
int N,  t;
vector<int> vi[8000];
int mark[8000];
int num1[8000],num2[8000] ,ans;

void Init(){
	for (int i = 0; i < 8000; ++i){
		vi[i].clear();
		mark[i] = 0;
		num1[i] = num2[i] = 0;
	}
	ans = 0;
}

int main(){
	ifstream in("C:\\input.txt");
	while (in >> N){
		Init();

		for (int i = 1; i <= N; ++i){
			in >> num1[i];
			for (int j = 0; j < num1[i]; ++j){
				in >> t;
				vi[i].push_back(t);
			}
		}

		for (int i = 1; i <= N; ++i){
			if (num1[i]>1){
				bool f = 1;
				for (int j = 0; j < vi[i].size(); ++j){
					if (num2[vi[i][j]] > 0){
						f = 0;
						break;
					}
				}
				if (!f)
					continue;
				mark[i] = 1;
				ans++;
				for (int j = 0; j < vi[i].size(); ++j){
					num1[vi[i][j]]--;
					if (mark[vi[i][j]])
						num2[vi[i][j]]++;
				}
			}
		}
		if (ans <= N / 2){
			cout << ans << endl;
			for (int i = 1; i <= N;++i)
			if (mark[i] == 1)
				cout << i << " ";
		}
		else{
			cout << N - ans << endl;
			for (int i = 1; i <= N; ++i)
			if (mark[i] == 0)
				cout << i << " ";

		}
		if (ans)
			cout << endl;

	}


	return 0;
}