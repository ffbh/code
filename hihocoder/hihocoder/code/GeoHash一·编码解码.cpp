#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;
#define Exp (1e-9)
map<char, int> mci;
map<int, char> mic;

void Init(){
	bool v[250] = { 0 };
	v['a'] = v['i'] = v['l'] = v['o'] = 1;
	for (char c = '0'; c <= '9'; ++c){
		mci[c] = c - '0';
		mic[c - '0'] = c;
	}
	int id = 10;
	for (char c = 'a'; c <= 'z'; ++c){
		if (v[c])
			continue;
		mci[c] = id;
		mic[id] = c;
		id++;
	}
}

bool graterequal(double x,double y){
	return fabs( x - y ) < Exp ||  x > y;

}


int data[1010];



int main(){
	//ifstream in("C:\\input.txt");
	Init();
	int N, M;
	while (cin >> N >> M){
		while (N--){
			double x, y;
			cin >> x >> y;
			double l, r, m;
			int index;
			l = -90;
			r = 90;
			index = 2;
			while (index <= 50){
				m = (l + r) / 2;
				if (graterequal(x, m)){
					data[index] = 1;
					l = m;
				}
				else{
					data[index] = 0;
					r = m;
				}
				index += 2;
			}

			l = -180;
			r = 180;
			index = 1;
			while (index <= 50){
				m = (l + r) / 2;
				if (graterequal(y, m)){
					data[index] = 1;
					l = m;
				}
				else{
					data[index] = 0;
					r = m;
				}
				index += 2;
			}
			int id = 0;
			for (int i = 1; i <= 50; ++i){
				id = id * 2 + data[i];
				if (i % 5 == 0){
					printf("%c", mic[id]);
					id = 0;
				}
			}
			printf("\n");
		}


		while (M--){
			string s;
			cin >> s;
			memset(data, 0, sizeof(data));
			for (int i = 0; i < s.length(); ++i){
				int id = mci[s[i]];
				int e = (i + 1) * 5;
				while (id){
					data[e] = id % 2;
					id /= 2;
					e--;
				}
			}
			int len = s.length();
			len *= 5;
			double l, r, m;
			int index;
			l = -90;
			r = 90;
			index = 2;
			while (index <= len){
				m = (l + r) / 2;
				if (data[index]){
					l = m;
				}
				else{
					r = m;
				}
				index += 2;
			}
			printf("%.6f ", (l + r) / 2.0);

			l = -180;
			r = 180;
			index = 1;
			while (index <= len){
				m = (l + r) / 2;
				if (data[index]){
					l = m;
				}
				else{
					r = m;
				}
				index += 2;
			}
			printf("%.6f\n", (l + r) / 2.0);
		}


	}












	return 0;
}