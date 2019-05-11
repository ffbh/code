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

void _init(){



}
vector<pii> VV;
int binary_search_min(int l, int r){

	int L = 0, R = VV.size() - 1, ans = -1;
	while (L <= R){
		int mid = (L + R) / 2;
		if (l <= VV[mid].first && VV[mid].first <= r){
			ans = mid;
			R = mid - 1;
		}
		else if (VV[mid].first < l){
			R = mid - 1;
		}
		else{
			L = mid + 1;
		}
	}
	if (ans == -1){
		return -1;
	}
	if (ans == 0){
		ans = 1;
	}
	else{
		ans = VV[ans - 1].second + 1;
	}
	return ans;
}

int binary_search_max(int l, int r){

	int L = 0, R = VV.size() - 1, ans = -1;
	while (L <= R){
		int mid = (L + R) / 2;
		if (l <= VV[mid].first && VV[mid].first <= r){
			ans = VV[mid].second;
			L = mid + 1;
		}
		else if (VV[mid].first < l){
			R = mid - 1;
		}
		else{
			L = mid + 1;
		}
	}
	return ans;
}

int binary_search_min2(int l, int r){
	int L = 0, R = VV.size() - 1, ans = -1;
	while (L <= R){
		int mid = (L + R) / 2;
		if (l <= VV[mid].first && VV[mid].first <= r){
			ans = mid;
			R = mid - 1;
		}
		else if (VV[mid].first < l){
			R = mid - 1;
		}
		else{
			L = mid + 1;
		}
	}

	if (ans == -1){
		return -1;
	}



	if (ans == 0){
		ans = N;
	}
	else{
		ans = VV[ans - 1].second - 1;
	}
	return ans;
}

int binary_search_max2(int l, int r){

	int L = 0, R = VV.size() - 1, ans = -1;
	while (L <= R){
		int mid = (L + R) / 2;
		if (l <= VV[mid].first && VV[mid].first <= r){
			ans = VV[mid].second;
			L = mid + 1;
		}
		else if (VV[mid].first < l){
			R = mid - 1;
		}
		else{
			L = mid + 1;
		}
	}
	return ans;
}

void getLRM(){
	VV.clear();
	for (int i = 1; i <= N; ++i){
		while (!VV.empty() && VV.back().first <= B[i]){
			VV.pop_back();
		}
		VV.push_back(mp(B[i], i));
		int ll = A[i] - K;
		int rr = A[i] + K;
		int lll = binary_search_min(ll, rr);
		int rrr = binary_search_max(ll, rr);
		assert(lll <= rrr);
		assert(lll >= 1&&lll <= i || lll==-1);
		assert(rrr >= 1&&rrr <= i || rrr==-1);
		if (lll == -1){
			assert(rrr == -1);
			Lnum[i] = 0;
			
		}
		else if(L[i] <= lll){
			L[i] = lll;
			Lnum[i] = abs(rrr - lll) + 1;
		}
		else if (L[i] <= rrr){
			Lnum[i] = abs(rrr - L[i]) + 1;
		}
		else{
			Lnum[i] = 0;
		}
	}

	VV.clear();
	for (int i = N; i >= 1; --i){
		while (!VV.empty() && VV.back().first <= B[i]){
			VV.pop_back();
		}
		VV.push_back(mp(B[i], i));
		int ll = A[i] - K;
		int rr = A[i] + K;
		int rrr = binary_search_min2(ll, rr);
		int lll = binary_search_max2(ll, rr);
		assert(lll <= rrr);
		assert(lll >= i&&lll <= N || lll==-1);
		assert(rrr >= i&&rrr <= N || lll==-1);
		if (lll == -1){
			assert(rrr == -1);
			Rnum[i] = 0;
			
		}
		else if (R[i] >= rrr){
			R[i] = rrr;
			Rnum[i] = abs(rrr - lll) + 1;
		}
		else if (R[i] >= lll){
			Rnum[i] = abs(R[i] - lll)  + 1;
		}
		else{
			Rnum[i] = 0;
		}
	}

}

int p = 0;
void getInput(int n,int m){
	ofstream out("C:\\input.txt");

	srand(time(0));
	int k = abs(rand()) % m;
	cout << "k" << k << endl;
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
//	int ll = 5;
//	int rr = 20;
////	int rrr = binary_search_min2(ll, rr);
////	int lll = binary_search_max2(ll, rr);
//	int lll = binary_search_min(ll, rr);
//	int rrr = binary_search_max(ll, rr);
//	cout << lll << " " << rrr << endl;


//	return 0;

	int CPP = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
	//	getInput(10, 1000);
		_init();
		input();

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

		/*for (int i = 1; i <= N / 2; ++i){
			swap(A[i], A[N - i + 1]);
			swap(B[i], B[N - i + 1]);
		}*/

		/*getLR();


		getLRM();
*/

		//LL ans2 = 0;
		//for (int i = 1; i <= N; ++i){
		//	LL l_num = i - L[i] + 1;
		//	LL r_num = R[i] - i + 1;
		//	assert(l_num >= 0 && r_num >= 0);
		//	assert(Lnum[i] >= 0 && Rnum[i] >= 0);
		//	//		assert(Lnum[i] <= l_num && Rnum[i] <= r_num);
		//	ans2 += Lnum[i] * r_num + Rnum[i] * l_num - Lnum[i] * Rnum[i];

		//}

		////assert(ans == ans2);
		//if (ans != ans2){
		//	break;
		//}

		printf("Case #%d: %lld\n", CPP++, ans);






	}


	return 0;
}