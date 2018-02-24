#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;
#define MMAX ((int)2e6 + 10)
char ans[MMAX];
int N;
int f[MMAX];

int find(int x){
	if (f[x] == x)
		return x;
	else
		return f[x] = find(f[x]);
}

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> N;


	for (int i = 1; i < MMAX; ++i)
		f[i] = i;


	for (int i = 1; i<MMAX; ++i)
		ans[i] = 'a';
	int epos = 0;
	while (N-- > 0){
		string s;
		int k;
		in >> s;
		scanf("%d", &k);
		while (k-- > 0){
			int p;
		//	in >> p;
			scanf("%d", &p);
			epos = max(epos, p + (int)s.length() - 1);

			int st = p;
			int en = p + s.length() - 1;
			for (int i = st; i <= en; ++i){
				int fi = find(i);
				if (fi == i){
					ans[i] = s[i - st];
					f[i] = i + 1;
				}
				else{
					i = fi - 1;
				}
			}
		}
	}
	for (int i = 1; i <= epos; ++i)
		putchar(ans[i]);
	cout << endl;















	return 0;
}





