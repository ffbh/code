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
#include <cassert>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif



typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)
#define rson (root<<1|1)
#define FFLUAHALL fflush(stdin);fflush(stdout);



LL N, K;
LL A[100010], B[100010];
LL L[100010], R[100010];
LL Lnum[100010], Rnum[100010];

void getLR(){
	vector<pii> V;
	for (int i = 1; i <= N; ++i){
		while (!V.empty() && V.back().first < A[i]){
			R[V.back().second] = i - 1;
			V.pop_back();
		}
		V.push_back(mp(A[i], i));
	}
	while (!V.empty()){
		R[V.back().second] = N;
		V.pop_back();
	}

	V.clear();
	for (int i = N; i >= 1; --i){
		while (!V.empty() && V.back().first <= A[i]){
			L[V.back().second] = i + 1;
			V.pop_back();
		}
		V.push_back(mp(A[i], i));
	}
	while (!V.empty()){
		L[V.back().second] = 1;
		V.pop_back();
	}
}



void input(){
	in >> N >> K;
	for (int i = 1; i <= N; ++i) {
		in >> A[i];
	//	A[i]++;
	}
	for (int i = 1; i <= N; ++i) {
		in >> B[i];
	//	B[i]++;
	}

}
vector<pii> VV;
void _init(){
	//memset(A, 0, sizeof(A));
	//memset(B, 0, sizeof(B));
	//memset(L, 0, sizeof(L));
	//memset(R, 0, sizeof(R));
	//memset(Lnum, 0, sizeof(Lnum));
	//memset(Rnum, 0, sizeof(Rnum));
	//VV.clear();
}




int bsl(int l,int d){//value not index
	int L = 0, R = VV.size() - 1, ans = -1;
	while (L <= R){
		int mid = (L + R) / 2;
		if (l >= VV[mid].first){
			ans = mid;
			R = mid - 1;
		}
		else{
			L = mid + 1;
		}
	}
	if (ans == -1){
		return d;
	}
	return VV[ans - 1].second + 1;
}


int bsr(int r,int d){
	int L = 0, R = VV.size() - 1, ans = -1;
	while (L <= R){
		int mid = (L + R) / 2;
		if (r >= VV[mid].first){
			ans = mid;
			R = mid - 1;
		}
		else{
			L = mid + 1;
		}
	}
	if (ans == -1){
		return d;
	}
	return VV[ans - 1].second - 1;

}

void getLRM(){
	VV.clear();
	VV.push_back(mp(10000000, 0));
	for (int i = 1; i <= N; ++i){
	
		while (!VV.empty() && VV.back().first <= B[i]){
			VV.pop_back();
		}
		VV.push_back(mp(B[i], i));
		int ll = A[i] - K;
		int rr = A[i] + K;
		LL lll = bsl(rr, i + 1);
		LL rrr = bsl(ll - 1, i + 1);
		assert(lll <= rrr);
		L[i] = max(L[i], lll);
		lll = max(lll, L[i]);
		if (lll <= rrr){
			Lnum[i] = rrr - lll;
		}
		else{
			Lnum[i] = 0;
		}
		
	}

	VV.clear();
	VV.push_back(mp(10000000, N + 1));
	for (int i = N; i >= 1; --i){
		while (!VV.empty() && VV.back().first <= B[i]){
			VV.pop_back();
		}
		VV.push_back(mp(B[i], i));
		int ll = A[i] - K;
		int rr = A[i] + K;
		LL rrr = bsr(rr, i - 1);
		LL lll = bsr(ll - 1, i - 1);
		assert(lll <= rrr);
		rrr = min(rrr, R[i]);
		R[i] = min(rrr, R[i]);
		if (rrr >= lll){
			Rnum[i] = rrr - lll;
		}
		else{
			Rnum[i] = 0;
		}
	}

}



void getInput(int n,int m){
	ofstream out("C:\\input.txt");

	srand(time(0));
	int k = abs(rand()) % m;
	//cout << "k" << k << endl;
	out << 1 << endl;
	out << n << " " << k << endl;
	for (int i = 1; i <= n; ++i){
		out << abs(rand())%m  << " ";
	}
	out << endl;
	for (int i = 1; i <= n; ++i){
		out << abs(rand())%m  << " ";
	}
	out << endl;
	out.close();
}

int main(){
//	N = 1000;
//	VV.clear();
//	/*VV.push_back(mp(20, 999));
//	VV.push_back(mp(15, 100));
//	VV.push_back(mp(12, 50));
//	VV.push_back(mp(10, 30));
//	VV.push_back(mp(5, 20));*/

//	VV.push_back(mp(20, 20));
//	VV.push_back(mp(15, 30));
//	VV.push_back(mp(12, 50));
//	VV.push_back(mp(10, 100));
//	VV.push_back(mp(5, 999));
//
	//int ll = 20;
	//int rr = 20;
//	int rrr = binary_search_min2(ll, rr);
//	int lll = binary_search_max2(ll, rr);

	//int lll = binary_search_min(ll, rr);
	//int rrr = binary_search_max(ll, rr);
	//cout << lll << " " << rrr << endl;


//	return 0;

	//N = 5;
	//A[1] = 8;
	//A[2] = 8;
	//A[3] = 8;
	//A[4] = 8;
	//A[5] = 8;
	//getLR();
	//for (int i = 1; i <= N; ++i){
	//	cout << L[i] << " ";
	//}
	//cout << endl;
	//for (int i = 1; i <= N; ++i){
	//	cout << R[i] << " ";
	//}
	//cout << endl;



	/*1
		10 1
		8 2 3 5 1 0 9 4 6 3
		0 4 3 1 1 7 8 5 8 2*/


	//1
	//	5 18
	//	55 34 72 23 1
	//	58 50 23 33 99


	////getInput(8, 10);
//	getInput(5, 100);
	int CPP = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		
		_init();
		input();

		
		//LL kkk = 0;
		//for (int i = 1; i <= N; ++i){
		//	LL sa = -1, sb = -1;
		//	for (int j = i; j <= N; ++j){
		//		sa = max(sa, A[j]);
		//		sb = max(sb, B[j]);
		//		if (abs(sa - sb) <= K){
		//			kkk++;
		//		}
		//	}
		//}
	//	cerr << "kkkk" << kkk << endl;





		getLR();
		getLRM();


		LL ans = 0;
		for (int i = 1; i <= N; ++i){
			LL l_num = i - L[i] + 1;
			LL r_num = R[i] - i + 1;
			assert(l_num >= 0 && r_num >= 0);
			assert(Lnum[i] >= 0 && Rnum[i] >= 0);
	//		assert(Lnum[i] <= l_num && Rnum[i] <= r_num);
		
			ans += Lnum[i] * r_num + Rnum[i] * l_num - Lnum[i] * Rnum[i];

		}

		//for (int i = 1; i <= N; ++i){
		//	swap(A[i], B[i]);
		//}
		//if (kkk != ans){
		//	cout << kkk << " " << ans << endl;
		//}
		//assert(kkk == ans);

	//	getLR();
	//	getLRM();


	//	LL ans2 = 0;
	//	for (int i = 1; i <= N; ++i){
	//		LL l_num = i - L[i] + 1;
	//		LL r_num = R[i] - i + 1;
	//		assert(l_num >= 0 && r_num >= 0);
	//		assert(Lnum[i] >= 0 && Rnum[i] >= 0);
	//		//		assert(Lnum[i] <= l_num && Rnum[i] <= r_num);
	//		ans2 += Lnum[i] * r_num + Rnum[i] * l_num - Lnum[i] * Rnum[i];

	//	}
	////	cout << ans << " " << ans2 << endl;
	//	if (ans != ans2){
	//		cerr << N << " " << K << endl;
	//		for (int i = 1; i <= N; ++i){
	//			cerr << A[i] << " ";
	//		}
	//		cerr << endl;
	//		for (int i = 1; i <= N; ++i){
	//			cerr << B[i] << " ";
	//		}
	//		cerr << endl;
	//		cerr << "test " << ans << " " << ans2 << endl;
	//	}
	//	assert(ans == ans2);

		printf("Case #%d: %lld\n", CPP++, ans);







	}


	return 0;
}