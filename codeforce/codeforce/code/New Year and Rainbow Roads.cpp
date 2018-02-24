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


int N;
vector<LL> G;
vector<LL> B;
vector<LL> R;
vector<pair<LL, char> > BRG;
void input(){
	in >> N;
	for (int i = 1; i <= N; ++i){
		int p;
		char c;
		in >> p >> c;
		BRG.push_back(mp(p, c));
		if (c == 'G'){
			G.push_back(p);
		
		}
		else if (c == 'B'){
			B.push_back(p);
			
		}
		else{
			R.push_back(p);
		
		}
	}


}
bool bbb, rrr;
LL bpre, bans, rpre, rans, bmin, bmax, rmin, rmax;

void fff(int L,int R){
	bbb = rrr = 0;
	bans = rans = 0;
	bmin = rmin = 1e18;
	bmax = rmax = 0;
	for (int i = L; i <= R; ++i){
		if (BRG[i].second == 'B'){
			if (bbb){
				bans = max(bans, BRG[i].first - bpre);
			}
			bbb = 1;
			bpre = BRG[i].first;
			bmin = min(bmin, BRG[i].first);
			bmax = max(bmax, BRG[i].first);
		}
		else if(BRG[i].second=='R'){
			if (rrr){
				rans = max(rans, BRG[i].first - rpre);
			}
			rrr = 1;
			rpre = BRG[i].first;
			rmin = min(rmin, BRG[i].first);
			rmax = max(rmax, BRG[i].first);

		}
		else{



			assert(0);
		}


	}



}

LL cale(vector<pair<LL, char> >& A){
	int apos, bpos;
	apos = 0;
	while (apos < A.size() && A[apos].second != 'G')
		apos++;
	bpos = apos + 1;
	while (bpos < A.size() && A[bpos].second != 'G')
		bpos++;
	LL ans = 0;

	fff(0,apos-1);
	if (bbb){
		ans += A[apos].first - bmin;
	}
	if (rrr){
		ans += A[apos].first - rmin;
	}

	while (bpos < A.size()){
		if (apos + 1 < bpos){
		
			fff(apos + 1, bpos - 1);
			assert(bbb || rrr);
			
			if (bbb){
				bans = max(bans, bmin - A[apos].first);
				bans = max(bans, A[bpos].first - bmax);
			}
			if (rrr){
				rans = max(rans, rmin - A[apos].first);
				rans = max(rans, A[bpos].first - rmax);
			}

			if (bbb && rrr){
				LL temp = 0;
				temp += (A[bpos].first - A[apos].first);
				if (bbb){
					temp -= bans;
					temp += (A[bpos].first - A[apos].first);
				}
				if (rrr){
					temp -= rans;
					temp += (A[bpos].first - A[apos].first);
				}

				temp = min(temp, 2 * (A[bpos].first - A[apos].first));

				ans += temp;


			}
			else{
				ans += (A[bpos].first - A[apos].first);
				if (bbb){
					ans -= bans;
					ans += (A[bpos].first - A[apos].first);
				}
				if (rrr){
					ans -= rans;
					ans += (A[bpos].first - A[apos].first);
				}
			}

		}
		else{
			ans += A[bpos].first - A[apos].first;

		}
		apos = bpos;
		bpos = apos + 1;
		while (bpos < A.size() && A[bpos].second != 'G')
			bpos++;
	}
	fff(apos + 1, A.size()-1);
	if (bbb){
		ans += bmax - A[apos].first;
	}
	if (rrr){
		ans += rmax - A[apos].first ;
	}

	return ans;

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		LL ans = 0;
		if (G.empty()){
		
			if (!B.empty())
				ans += B.back() - B[0];
			if (!R.empty())
				ans += R.back() - R[0];

		}
		else{
		
			ans = cale(BRG);

		}

		cout << ans << endl;














	}


	return 0;
}





