#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
struct Node{
	int val, num;
}data[50010];
int T, N,K, Index;

bool judge(){
	for (int i = 0; i < Index; ++i)
	if (data[i].num > 0){
		for (int j = 1; j < K; ++j){
			if (data[i + j].num < data[i].num || data[i + j].val != data[i].val + j){
				return 0;
			}
			data[i + j].num -= data[i].num;
		}
	
	}
	return 1;
}

int main(){
	//ifstream in("C:\\input.txt");
	
	cin >> T;
	while (T--){
		cin >> N >> K;
		Index = 0;
		int pre ,num;
		cin >> pre;
		num = 1;
		while (--N){
			int t;
			cin >> t;
			if (pre == t)
				num++;
			else{
				data[Index].val = pre;
				data[Index].num = num;
				Index++;

				pre = t;
				num = 1;
			}
		}
		data[Index].val = pre;
		data[Index].num = num;
		Index++;



		if (N % K != 0 || !judge())
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	


	return 0;
}