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
	int l, r;
	bool operator<(const Node& p)const{
		return l < p.l;
	}
}dA[100010], dB[100010];
vector<Node> A, B;
int N, M;



void Union(Node* p,int n,vector<Node>& P){
	sort(p, p + n);
	for (int i = 0; i < n; ++i){
		if (P.empty() || p[i].l > P.back().r){
			P.push_back(p[i]);
		}
		else{
			P.back().r = max(P.back().r, p[i].r);
		}
	}
}




int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	in >> N >> M;
	for (int i = 0; i < N; ++i){
		in >> dA[i].l >> dA[i].r;
		if (dA[i].l>dA[i].r)
			swap(dA[i].l, dA[i].r);
	}

	for (int i = 0; i < M; ++i){
		in >> dB[i].l >> dB[i].r;
		if (dB[i].l>dB[i].r)
			swap(dB[i].l, dB[i].r);
	}

	Union(dA, N, A);
	Union(dB, M, B);

	int pos = 0;
	int ans = 0;
	for (int i = 0; i < B.size() && pos < A.size(); ++i){
		while (pos < A.size() && B[i].l >= A[pos].r ){
			ans += A[pos].r - A[pos].l;
			pos++;
		}
		if (pos == A.size())
			break;
		if (B[i].r <= A[pos].l){
			continue;
		}

		if (B[i].l > A[pos].l){
			ans += B[i].l - A[pos].l;
		
		}
		A[pos].l = max(B[i].r, A[pos].l);

		if (A[pos].l >= A[pos].r){
			pos++;
			i--;
		}
	}

	while (pos < A.size()){
		ans += A[pos].r - A[pos].l;
		pos++;
	}

	cout << ans << endl;



	return 0;
}