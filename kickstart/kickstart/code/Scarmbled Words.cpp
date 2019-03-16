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

string s;
char s1, s2;
LL L,N, A, B, C, D;
char str[1000010];
LL X[1000010];
void input(){
	in >> L;
	getline(in, s);
	getline(in, s);
	in >> s1 >> s2 >> N >> A >> B >> C >> D;
}



bool mark[26];
unordered_map<LL,int> M;


void Init(){
	for (int i = 0; i < 26; ++i){
		mark[i] = 0;
	}
	M.clear();

}


LL mod = (LL)1e9 + 7, seed = 64757639, seedhead = 78654391, seedbody = 34567821;
LL Hash(int st,int en,int z[26]){
	//LL head = (st * seedhead % mod * seed % mod + en)*seedhead % mod*seed%mod;
	LL head = ((st * seedhead +en)% mod )*seedhead % mod;
	LL body = 0;
	for (int i = 0; i < 26; ++i){
		body = ((body * seed + (i + 97) * z[i] % mod * seedbody % mod)) % mod;
	}
	return head * body % mod;
}


int main(){

	int CPP = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		Init();
		input();

		str[0] = '-';
		str[1] = s1;
		str[2] = s2;
		X[1] = (LL)str[1];
		X[2] = (LL)str[2];
	//	V[str[1] - 'a'].push_back(1);
	//	V[str[2] - 'a'].push_back(2);
		for (int k = 3; k <= N; ++k){
			//xi = (A * xi - 1 + B * xi - 2 + C) modulo D.
			//We define Si = char(97 + (xi modulo 26)), for all i = 3 to N.
			X[k] = (A * X[k-1] + B * X[k-2] + C) % D;
			str[k] = char(97 + X[k] % 26);
		//	V[str[k] - 'a'].push_back(k);
			mark[str[k]-'a'] = 1;
		}
		




		stringstream ss(s);
		string t;
		set<int> DS;
		LL ans = 0;
		while (ss >> t){
			if (t.length() == 1){
				if (mark[t[0] - 'a']){
					ans++;
				}
			}
			int tt[26] = { 0 };
			for (int i = 1; i < t.length() - 1; ++i){
				tt[t[i] - 'a']++;
			}
			DS.insert(t.length());
			LL HH = Hash(t[0], t.back(), tt);
			M[HH]++;
		}

		int tmp[26];
		for (int k : DS){
			memset(tmp, 0, sizeof(tmp));
			int sl = 1;
			int sr = k;
			for (int i = sl; i <= sr; ++i){
				tmp[str[i] - 'a']++;
			}
			while (sr <= N){
				tmp[str[sl] - 'a']--;
				tmp[str[sr] - 'a']--;
				LL h = Hash(str[sl], str[sr], tmp);
			//	tmp[str[sl] - 'a']++;
				tmp[str[sr] - 'a']++;
				if (M.count(h)){
					ans += M[h];
					M.erase(h);
				}
				
			//	tmp[str[sl] - 'a']--;
				sl++;
				sr++;
				tmp[str[sr] - 'a']++;
			}
		}


		printf("Case #%d: %d\n", CPP++, ans);










	}


	return 0;
}





