#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int mark[10010];
int year[10010], size;
int a, y, b;
int main(){
	//ifstream in("C:\\input.txt");
	int N;
	int mmax = -1;
	int CASE = 1;
	while (cin >> N&&N){
		size = 0;
		cin >> y >> a >> b;
		if (mmax < a)
			mmax = a;
		b -= a;
		while (y < 10000){
			year[size] = y;
			mark[size++] = 1;
			y += b;
		}
		while (--N){
			cin >> y >> a >> b;
			if (mmax < a)
				mmax = a;
			int len = b - a;
			int m = y - a;
			for (int i = 0; i < size; ++i){
				if (mark[i]){
					if (year[i] < a)
						mark[i] = 0;
					else{
						if ((year[i] - a) % len != m)
							mark[i] = 0;
					}
				}
			}
		}
		printf("Case #%d:\n", CASE++);
		bool f = 0;
		for (int i = 0; i < size;++i)
		if (mark[i]){
			printf("The actual year is %d.\n", year[i]);
			f = 1;
			break;
		}
		if (!f)
			printf("Unknown bugs detected.\n");
		cout << endl;
	}
	return 0;
}