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


LL n;
char s1[1000010];
char s2[1000010];

void input(){
	in >> n;
	in >> s1;
	in >> s2;
	//scanf("%d", &n);
	//scanf("%s", s1);
	//scanf("%s", s2);
}
vector<pii> vp;

void ppp(int len,int st){
	if (len){
		vp.push_back(mp(len,st));
	}
}



void print(LL kp){
	printf("%lld\n", kp);
}


LL op(LL len){
	LL t =  len * (len + 1) / 2  - 1 ;
	assert(t >= 0);
	/*if (t < 0)
		t = 0;*/
	return t;
}

LL op2(LL len){
	LL t  = len * (len + 1) / 2;
	if (t < 0)
		t = 0;
	return t;
}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		vp.clear();
		int len = 0;
		int st = 0;
		for (int k = 0; k < n; ++k){
			if (s1[k] == s2[k]){
				ppp(len,st);
				len = 0;
				st = k + 1;
			}
			else{
				len++;
			}

			if (vp.size()> 2){
				break;
			}
		}
		ppp(len,st);







		if (vp.size() == 0){
			print(op2(n));
		}
		else if(vp.size()==1){
			LL a = op(vp[0].first);

			LL left = 0;
			LL right = 0;
			int pos = 0;
			while (s1[pos] == s2[pos]){
				left++;
				pos++;
			}
			pos = n - 1;
			while (s1[pos] == s2[pos]){
				right++;
				pos--;
			}

			a += 2 * left;
		
			a += 2 * right;
			
			print(a);
		}
		else if (vp.size() == 2){
			LL a = 6;
			/*int leng = vp[1].second - vp[0].first - vp[0].second;
			a += op2(leng);*/



			print(a);

		}
		else{
			print(0);
		}

	}


	return 0;
}





