#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;
int A[501];
int B[501];
int C[501];


int main(){
//	ifstream in("C:\\temp.txt");
	int a, b, c;
	int CASE = 1;
	set<int> si;
	while (cin >> a >> b >> c){
		si.clear();
		for (int i = 0; i < a; ++i)
			//	in >> A[i];
			scanf("%d", &A[i]);
		for (int i = 0; i < b; ++i)
			//	in >> B[i];
			scanf("%d", &B[i]);
		for (int i = 0; i < c; ++i)
			//	in >> C[i];
			scanf("%d", &C[i]);
		for (int i = 0; i < a;++i)
		for (int j = 0; j < b;++j)
			si.insert(A[i] + B[j]);
		int M;
		cin >> M;
		printf("Case %d:\n", CASE++);
		while (M--){
			int t;
		//	in >> t;
			scanf("%d", &t);
			bool flag = 0;
			for (int i = 0; i < c;++i)
			if (si.count(t - C[i])){
				flag = 1;
				break;
			}

			if (flag)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}