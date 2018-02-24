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
int data[50], size;
int sorted[50];
stringstream ss;
string s;

void flip(int l,int r){
	while (l < r){
		swap(data[l], data[r]);
		l++;
		r--;
	}
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	int mmin, mmax, mmin_idx, mmax_idx;
	while (getline(in, s)){
		ss.clear();
		ss.str(s);
		size = 1;
		while (ss >> data[size])
			size++;
		size--;
		for (int i = 1; i < size; ++i)
			cout << data[i] << " ";
		cout << data[size] << endl;
		for (int i = 1; i <= size; ++i){
			sorted[i] = data[i];
		}
		sort(sorted + 1, sorted + size + 1);
		for (int k = size; k >= 1; --k){
			if (data[k] == sorted[k])
				continue;
			int idx;
			for (int j = 1; j < k; ++j){
				if (data[j] == sorted[k]){
					idx = j;
					break;
				}
			}
			if (idx != 1){
				cout << size + 1 - idx << " ";
				flip(1, idx);
			}
			cout << size + 1 - k << " ";
			flip(1, k);
		}
		cout << 0 << endl;


	}



	return 0;
}