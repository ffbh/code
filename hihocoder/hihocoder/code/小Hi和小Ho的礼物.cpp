#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
struct Node{
	int val, num;
}data[1010];

unordered_map<int, long long> mii;
unordered_map<int, long long> mm;

void f(){
	ofstream out("C:\\input.txt");
	out << 1000 << endl;
	for (int i = 1; i <= 1000; ++i)
		out << i <<" ";
	out << endl;
}

int main(){
	ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i){
		int t;
		cin >> t;
		mii[t]++;
	}
	

	long long ans = 0;
	unordered_map<int, long long>::iterator it = mii.begin();

	int size = 0;
	while (it != mii.end()){
		data[size].val = it->first;
		data[size].num = it->second;
		size++;
		it++;
	}

	for (int i = 0; i < size; ++i){
		if (data[i].num >= 4){
			long long num = data[i].num;
			long long nn = num * (num - 1)*(num - 2)*(num - 3) / 4 / 3 / 2;
			ans += nn * 6;
		}
	}

	for (int i = 0; i < size; ++i){
		if (data[i].num >= 2){
			long long n1 = data[i].num*(data[i].num - 1) / 2;
			for (int j = i + 1; j < size; ++j){
				if (data[j].num >= 2){
					long long n2 = data[j].num*(data[j].num - 1) / 2;
					ans += n1*n2 * 4;
				}
			}
		}
	}
	
	for (int i = 0; i < size;++i)
	for (int j = i + 1; j < size; ++j){
		int val = data[i].val + data[j].val;
		long long num = data[i].num*data[j].num;
		ans += mm[val] * num * 2;
		mm[val] += num;
	}
		
	for (int i = 0; i < size; ++i){
		if (data[i].num >= 2){
			int val = data[i].val * 2;
			long long n1 = data[i].num*(data[i].num - 1) / 2;
			ans += n1 * mm[val] * 2;
		}

	}

	cout << ans << endl;


	return 0;
}