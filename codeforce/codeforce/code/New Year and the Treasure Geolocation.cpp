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

int n;
pii A[1010], B[1010];


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> A[i].first >> A[i].second;

	for (int i = 1; i <= n; ++i)
		in >> B[i].first >> B[i].second;






}

bool cmp(pii a ,pii b){
	if (a.first > b.first){
		return 1;
	}
	else if (a.first == b.first){
		return a.second > b.second;
	}
	else{
		return 0;
	}
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		sort(A + 1, A + n + 1);
		sort(B + 1, B + n + 1, cmp);

		cout << A[1].first + B[1].first << " " << A[n].second + B[n].second << endl;












	}


	return 0;
}





