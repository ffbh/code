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
#define MMAX 32000
vector<int> prime;
bool vis[MMAX];

void Init(){
	
	for (int i = 2; i < MMAX; ++i){
		if (!vis[i]){
			prime.push_back(i);
			for (int j = i + i; j < MMAX; j += i)
				vis[j] = 1;
		}
	}

}

bool test(int a,int b){
	if (a > b)
		swap(a, b);
	for (int i = 0; i * 3 <= a; ++i){
		if ((a - 3 * i) * 2 == b - 3 * i)
			return 1;
	}
	return 0;
}

bool judge(vector<pair<int, int> >& A, vector<pair<int, int> >& B){
	if (A.size() != B.size())
		return 0;
	for (int i = 0; i < A.size(); ++i){
		if (A[i].first != B[i].first)
			return 0;
		if (!test(A[i].second, B[i].second))
			return 0;
	}
	return 1;
}

int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	//cout << sqrt(1e9) << endl;

	Init();



	int N, a, b ;
//	in >> N;
	scanf("%d", &N);
	vector<pair<int, int> > A, B;
	while (N-- > 0){
	//	in >> a >> b;
		scanf("%d%d", &a, &b);
		A.clear();
		B.clear();
		for (int i = 0; i < prime.size() && a != 1; ++i){
			int num = 0;
			while (a%prime[i] == 0){
				num++;
				a /= prime[i];
			}
			if (num){
				A.push_back(make_pair(prime[i], num));
			}
		}
		if (a != 1){
			A.push_back(make_pair(a, 1));
		}


		for (int i = 0; i < prime.size() && b != 1; ++i){
			int num = 0;
			while (b%prime[i] == 0){
				num++;
				b /= prime[i];
			}
			if (num){
				B.push_back(make_pair(prime[i], num));
			}
		}
		if (b != 1){
			B.push_back(make_pair(b, 1));
		}

		if (judge(A, B))
			printf("YES\n");
		else{
			printf("NO\n");
		}
		


	}















	return 0;
}





