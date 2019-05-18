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
#define FFLUAHALL 	fflush(stdin);fflush(stdout);

void _init(){



}

int a[6] = { 4, 8, 15, 16, 23, 42 };

void input(){
	
}


int tttt[] = { 4, 8, 15, 16, 23, 42 };

//int query(int a,int b){
//	a--;
//	b--;
//	return tttt[a] * tttt[b];
//}

int query(int a,int b){
	FFLUAHALL;
	cout << "? " << a << " " << b << endl;
	FFLUAHALL;
	int tt;
	in >> tt;
	return tt;
}

pii getP(int v){
	for (int i = 0; i < 6;++i)
	for (int j = 0; j < 6; ++j){
		if (a[i] * a[j] == v){
			return  mp(a[i], a[j]);
		}
	}
	assert(0);
}

int ans[10];


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		

		
		pii ab = getP(query(1, 2));
		pii cd = getP(query(3, 4));
		pii ac = getP(query(1, 3));

		if (ab.first == ac.first || ab.first == ac.second){
			ans[1] = ab.first;
			ans[2] = ab.second;
		}
		else{
			ans[2] = ab.first;
			ans[1] = ab.second;
		}

		if (cd.first == ac.first || cd.first == ac.second){
			ans[3] = cd.first;
			ans[4] = cd.second;
		}
		else{
			ans[4] = cd.first;
			ans[3] = cd.second;
		}

		ans[5] = round(sqrt(query(5, 5)));

		set<int> S;
		for (int i = 1; i <= 5; ++i){
			S.insert(ans[i]);
		}
		for (int i = 0; i < 6; ++i){
			if (!S.count(a[i])){
				ans[6] = a[i];
				break;
			}
		}

		cout << "!";
		for (int i = 1; i <= 6; ++i){
			cout << " " << ans[i];
		}
		cout << endl;




	}


	return 0;
}





