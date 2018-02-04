#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <list>
using namespace std;
int n, m, k;
bool vis[30];

void oput(int p){
	if (p >= 0){
	//	printf("⊔");
		printf("%3d", p);
	}
	else{
	//	printf("⊔⊔");
		printf("%3d", p);
	}
}

int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	while (cin >> n >> k >> m){
		if (n == 0 && m == 0 && k == 0)
			break;
		
		for (int i = 0; i < 30; ++i)
			vis[i] = 0;
		int rest = n;
		int a, b;
		a = 1;
		b = n;
		while(rest >0){
			int ak = k%rest;
			int bm = m%rest;
			if (ak == 0)
				ak = rest;
			if (bm == 0)
				bm = rest;
			while (ak > 0){
				if (!vis[a]){
					ak--;
				}
				if (ak > 0){
					if (a == n)
						a = 1;
					else
						a++;
				}

			}

			while (bm > 0){
				if (!vis[b]){
					bm--;
				}
				if (bm > 0){
					if (b == 1)
						b = n;
					else
						b--;
				}
			}
			vis[a] = vis[b] = 1;
			if (a == b){
				rest--;
				oput(a);
			}
			else{
				rest -= 2;
				oput(a);
				oput(b);
			}

			if (rest)
				cout << ",";

		}

		cout << endl;


	}





	return 0;
}