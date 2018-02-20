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

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  



void input(){



}

LL sum[500010], x[500010], pos;

double cale(int p){
	LL s = sum[p] + x[pos];
	LL num = p + 1;
	return double(s) / num;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int Q;
		in >> Q;
		double ans = 0;
		pos = 1;



		while (Q-- > 0){
			int type;
			in >> type;
			if (type == 1){
				in >> x[pos];
				sum[pos] = sum[pos - 1] + x[pos];
				if (pos > 1){
					LL L, R;
					L = 1;
					R = pos - 1;
					while (L <= R){
						/*if (R - L < 5){
							for (int i = L; i <= R; ++i){
								double mmm = double(x[pos]) - cale(i);
								ans = max(ans, mmm);
							}
							break;
						}*/


						int len = (R - L + 1) / 3;
						int ml = L + len - 1;
						if (ml < L)
							ml = L;
						int mr = R - len + 1;
						if (mr > R)
							mr = R;
						double mml = double(x[pos]) - cale(ml);
						double mmr = double(x[pos]) - cale(mr);
						if (mml < mmr){
							L = ml + 1;
							ans = max(ans, mmr);
						}
						else{
							R = mr - 1;
							ans = max(ans, mml);
						}
					}


				}
				pos++;
			}
			else{
				printf("%.10f\n", ans);


			}
		


		}



	}


	return 0;
}





