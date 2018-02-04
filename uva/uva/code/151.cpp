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

bool vis[110];

int cale(int n,int m){
	memset(vis, 0, sizeof(vis));
	int now = 1, pos = 1;
	int rest = n-1;
	vis[1] = 1;
	//cout << 1 << " ";
	while (rest > 1){
		now = 1;
		while (now != m){
			if (!vis[pos]){
				now++;
			}
			if (pos == n){
				pos = 1;
			}
			else{
				pos++;
			}
		}
		while (vis[pos]){
			if (pos == n){
				pos = 1;
			}
			else{
				pos++;
			}
		}

		vis[pos] = 1;
		rest--;
	//	cout << pos << " ";
	}
	while (vis[pos]){
		if (pos == n){
			pos = 1;
		}
		else{
			pos++;
		}
	}
//	cout << endl;
	return pos;
}


int math_cale(int n,int m){
	n--;
	int s = 0;
	for (int i = 2; i <= n; ++i){
		s = (s + m) % i;
	}
	s += 2;
	return s;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	int n;
	while (in >> n&&n != 0){
		for (int i = 1;; ++i){
			if (math_cale(n, i) == 13){
				cout << i << endl;
				break;
			}
		}
	}




	return 0;
}