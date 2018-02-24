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

int n, m, k, q;
struct Node{
	int t;
	pii position;
	bool operator<(const Node& p)const{
		if (t != p.t)
			return t < p.t;
		else
			return position < p.position;
	}
};

vector<Node> V;
vector<int> T;
void input(){
	in >> n >> m >> k >> q;
	for (int i = 1; i <= q; ++i){
		Node tmp;
		in >> tmp.position.first >> tmp.position.second >> tmp.t;
		V.push_back(tmp);
		T.push_back(tmp.t);
	}
	sort(V.begin(), V.end());
	sort(T.begin(), T.end());
	T.erase(unique(T.begin(), T.end()), T.end());
}

int mmp[510][510];

bool slove(int t){
	memset(mmp, 0, sizeof(mmp));
	for (Node& p : V){
		if (p.t > t)
			break;
		mmp[p.position.first][p.position.second] = 1;
	}
	for (int i = 1; i <= n;++i)
	for (int j = 1; j <= m; ++j)
		mmp[i][j] += mmp[i - 1][j] + mmp[i][j - 1] - mmp[i - 1][j - 1];

	for (int i = 1; i + k - 1 <= n; ++i)
	for (int j = 1; j + k - 1 <= m; ++j){
		int ei = i + k - 1, ej = j + k - 1;
		int num = mmp[ei][ej] - mmp[ei][j - 1] - mmp[i - 1][ej] + mmp[i - 1][j - 1];
		if (num == k*k)
			return 1;

	}
	return 0;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int L = 0, R = T.size() - 1;
		int ans = T.size();
		while (L <= R){
			int mid = (L + R) / 2;
			int t = T[mid];
			if (slove(t)){
				R = mid - 1;
				ans = mid;
			}
			else{
				L = mid + 1;
			}

		}


		if (ans == T.size()){
			cout << -1 << endl;
		}
		else{
			cout << T[ans] << endl;
		}










	}


	return 0;
}





