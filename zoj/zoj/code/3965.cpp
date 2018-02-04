#pragma comment(linker, "/STACK:10240000000,10240000000")
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

int T, N;
int A[100010], B[100010];
int f[100010];
int ma[100010], mb[100010];
bool inn[100010];

void tle(){
	cout << "wa" << endl;
	double p = 1.9;
	for (int i = 0; i < 1e10; ++i){
		p = pow(p, p);
	}
	p += 10;
}

void dfs(int la, int ra, int lb, int rb, int fa){
	stack<int> ss;
	while (la <= ra){

		if (A[la] == B[lb]){
			f[A[la]] = fa;
			if (inn[fa] == 0){
				inn[fa] = 1;
				ss.push(fa);
			}
			fa = A[la];
			la++;
			lb++;
		}
		else{
			int na = ma[B[lb]];
			int nb = mb[A[la]];
			f[A[la]] = f[B[lb]] = fa;
			int nra = na - 1 - la;
			int nrb = nb - 1 - lb;
			dfs(la + 1, na - 1, nb + 1, nb + nra, A[la]);
			dfs(na + 1, na + nrb, lb + 1, nb - 1, B[lb]);
			int num = nra + nrb + 2;
			la += num;
			lb += num;
			if (!ss.empty()){
				fa = ss.top();
				ss.pop();
			}
		}
	}
}



int main(){
	//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> T;
	while (T-- > 0){
		in >> N;
		for (int i = 1; i <= N; ++i){
			inn[i] = 0;
			//	in >> A[i];
			scanf("%d", &A[i]);
			ma[A[i]] = i;
		}
		for (int i = 1; i <= N; ++i){
			//in >> B[i];
			scanf("%d", &B[i]);
			mb[B[i]] = i;
		}
		f[A[1]] = 0;
		dfs(2, N, 2, N, A[1]);
		for (int i = 1; i < N; ++i)
			printf("%d ", f[i]);
		printf("%d\n", f[N]);
	}
	return 0;
}