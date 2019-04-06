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

int N, B, F;

void input(){
	fflush(stdin);
	fflush(stdout);

	in >> N >> B >> F;

	FFLUAHALL
	fflush(stdin);
	fflush(stdout);
}
int ok[2000];
int ava[2010];
int getF(int k,int base){
	return k / 2 * 2 * base;
}


inline int get_block_num(int k,int b){
	int end = min(N, (k+1)*b);
	return end - k*b;
}


string ppp(string str){
	set<int> S;
	S.insert(1);
	S.insert(2);
	S.insert(3);
	S.insert(4);
	S.insert(5);
	S.insert(6);
	S.insert(7);
	S.insert(15);
	S.insert(16);
	S.insert(17);
	string ret = "";
	for (int i = 0; i < str.length(); ++i){
		if (S.count(i)){

		}
		else{
			ret += str[i];
		}
	}
	return ret;
}

int getALL(int st,int base){
	int sum = 0;
	for (int k = 0; k < base; ++k){
		if (st+k<N && ok[st + k] == 1)
			sum++;
	}
	return sum;
}



int main(){

	//for (int i = 0; i < 2000; ++i)
	//	ava[i] = 16;
	///*vector<pii> V = change("00011101",4);
	//for (auto vc : V){
	//	cout << vc.first << endl;
	//}*/

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		for (int i = 0; i < 2000; ++i)
			ava[i] = -1;
		memset(ok, 0, sizeof(ok));
		fflush(stdin);
		fflush(stdout);

		int need = (1024 - N) % 16;
		string tail = string(need, '1');

		string query, ans;
		vector<pii> V;
		query = "";
		for (int i = 0; i < N; ++i){
			char bit = '0' + ((i / 16) % 2);
			query += bit;
		}

		fflush(stdin);
		fflush(stdout);
			cout << query << endl;
		fflush(stdin);
		fflush(stdout);
		in >> ans;
	//	ans = ppp(query);
		ans += tail;
		fflush(stdin);
		fflush(stdout);
		int _pre;
		int _num;
		int bp = 0;
		for (int i = 0; i < ans.length(); ++i){
			if (i == 0){
				_pre = ans[i]; 
				_num = 1;
			}
			else if(_pre == ans[i]){
				_num++;
			}
			else{
				ava[(bp++) * 16] = _num;
				_pre = ans[i];
				_num = 1;
			}
		}
		ava[(bp++)*16] = _num;

		for (int P = 8; P >= 1; P /= 2){
			query = "";
			for (int i = 0; i < N; ++i){
				char bit = '0' + ((i / P) % 2);
				query += bit;
			}

			fflush(stdin);
			fflush(stdout);
				cout << query << endl;
				fflush(stdin);
				fflush(stdout);
				in >> ans;
		//	ans = ppp(query);
			ans += tail;
			fflush(stdin);
			fflush(stdout);

			if (P == 8){
				int t = 0;
			}
			int pos = 0;
			int op = 0;
			while (pos < ans.length()){
				if (ok[op] == -1){
					op += 2 * P;
				}
				int max_value = ava[op];
				int a = 0, b = 0;
				for (int k = 0; k < max_value; ++k){
					if (ans[pos] == '0'){
						a++;
					}
					else{
						b++;
					}
					pos++;
				}
				ava[op] = a;
				ava[op + P] = b;
				if (P == 8){
					int t = 0;
				}

				if (a == 0){
					for (int k = 0; k < P; ++k){
						ok[op + k] = -1;
					}
				}
				if (a == P){
					for (int k = 0; k < P; ++k){
						ok[op + k] = 1;
					}
				}
				op += P;
				if (b == 0){
					for (int k = 0; k < P; ++k){
						ok[op + k] = -1;
					}
				}
				if (b == P){
					for (int k = 0; k < P; ++k){
						ok[op + k] = 1;
					}
				}
				op += P;
			}
		}
		fflush(stdin);
		fflush(stdout);
		int num = 0;
		for (int i = 0; i < N;++i)
		if (ok[i] != 1){
			num++;
			cout << i << " ";
		}
		cout << endl;
		fflush(stdin);
		fflush(stdout);
//		assert(num == B);
		fflush(stdin);
		fflush(stdout);
		int JJJ = 1;
		in >> JJJ;
		assert(JJJ == 1);
		fflush(stdin);
		fflush(stdout);
		


	

	}


	return 0;
}





