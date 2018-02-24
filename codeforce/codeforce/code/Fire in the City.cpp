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
using namespace std;
#define pii pair<long long,long long>
#define mp make_pair
long long n, m, k;
vector<pii> X, Y;


void input(){
//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n >> m >> k;
	for (long long i = 0; i < k; ++i){
		long long x, y;
		in >> x >> y;
		X.push_back(mp(x, y));
		Y.push_back(mp(y, x));
	}



}

long long caleX(long long mid){
	
	long long u = -1, d = -1;
	vector<long long> ans;
	ans.push_back(1);
	for (pii& p : Y){
		long long down = p.first + mid + 1;
		if (down <= m){
			ans.push_back(down);
		}
	}
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (long long down : ans){
		vector<pii> tmp;
		for (pii& p : Y){
			if (down <= p.first + mid && down >= p.first - mid){
				tmp.push_back(mp(p.second - mid, p.second + mid));
			}
		}
		sort(tmp.begin(), tmp.end());
		long long en = 0;
		for (pii& p : tmp){
			if (en >= n || p.first > en + 1)
				break;
			en = max(en, p.second);
		}
		if (en < n){
			u = down;
			break;
		}
	}

	

	ans.clear();
	ans.push_back(m);
	for (long long i = Y.size() - 1; i >= 0; --i){
		long long up = Y[i].first - mid - 1;
		if (up >= 1){
			ans.push_back(up);
		}
	}
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (long long up : ans){
		vector<pii> tmp;
		for (long long i = Y.size() - 1; i >= 0; --i){
			if (up <= Y[i].first + mid && up >= Y[i].first - mid){
				tmp.push_back(mp(Y[i].second - mid, Y[i].second + mid));
			}
		}

		sort(tmp.begin(), tmp.end());
		long long en = 0;
		for (pii& p : tmp){
			if (en >= n || p.first > en + 1)
				break;
			en = max(en, p.second);
		}
		if (en < n){
			d = up;
			break;
		}
	}
	if (u == -1 && d == -1){
		return 0;
	}

	return d - u + 1;
}


long long caleY(long long mid){

	long long u = -1, d = -1;
	vector<long long> ans;
	ans.push_back(1);
	for (pii& p : X){
		long long down = p.first + mid + 1;
		if (down <= n){
			ans.push_back(down);
		}
	}
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	
	for (long long down : ans){
		vector<pii> tmp;
		for (pii& p : X){
			if (down <= p.first + mid && down >= p.first - mid){
				tmp.push_back(mp(p.second - mid, p.second + mid));
			}
		}
		sort(tmp.begin(), tmp.end());
		
		long long en = 0;
		for (pii& p : tmp){
			if (en >= m || p.first > en + 1)
				break;
			en = max(en, p.second);
		}
		if (en < m){
			u = down;
			break;
		}
	}

	

	ans.clear();
	ans.push_back(n);
	for (long long i = X.size() - 1; i >= 0; --i){
		long long up = X[i].first - mid - 1;
		if (up >= 1){
			ans.push_back(up);
		}
	}
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (long long up : ans){
		vector<pii> tmp;
		for (long long i = X.size() - 1; i >= 0; --i){
			if (up <= X[i].first + mid && up >= X[i].first - mid){
				tmp.push_back(mp(X[i].second - mid, X[i].second + mid));
			}
		}

		sort(tmp.begin(), tmp.end());
		long long en = 0;
		for (pii& p : tmp){
			if (en >= m || p.first > en + 1)
				break;
			en = max(en, p.second);
		}
		if (en < m){
			d = up;
			break;
		}
	}
	if (u == -1 && d == -1){
		return 0;
	}


	return d - u + 1;
}




bool judge(long long mid){

	

	long long x_len = caleX(mid);
	long long y_len = caleY(mid);
	return max(x_len, y_len) / 2 <= mid;
}


int main(){
	input();

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());


	long long L = 0, R = max(n, m)+10;
	long long ans = R;
	while (L <= R){
		long long mid = (L + R) / 2;
		
		if (judge(mid)){
			ans = min(ans, mid);
			R = mid - 1;
		}
		else{
			L = mid + 1;
		}

	}

	cout << ans << endl;





	return 0;
}





