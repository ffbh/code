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


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;

#define MAXN (int(1e5)+10)

int n, w, h;
int g[MAXN], p[MAXN], t[MAXN];
pii ans[MAXN];


void input(){
	in >> n >> w >> h;
//	scanf("%d%d%d", &n, &w, &h);
	for (int i = 1; i <= n; ++i){
		in >> g[i] >> p[i] >> t[i];
	//	scanf("%d%d%d", &g[i], &p[i], &t[i]);
		
	}

	

}


void getinput(int n,int w,int h){
	ofstream ou("C:\\input.txt");
	srand(time(0));
	ou << n << " " << w << " " << h << endl;
	for (int i = 1; i <= n; ++i){
		ou << rand() % 2 + 1 << " " << rand() % 99999 + 1 << " " << rand() % 100000 + 1 << endl;
	}
}

bool cmp(int a,int b){
	if (p[a] != p[b])
		return p[a] > p[b];
	else
		return t[a] > t[b];
}

bool cmp2(int a, int b){
	return p[a] < p[b];
}
int main(){

///	getinput(100000, 100000, 100000);
	//return 0;

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
	//	cout << "start" << endl;
	//	long start = clock();
		input();

	

		for (int i = 1; i <= n; ++i){
			if (g[i] == 1){
				ans[i].first = p[i];
				ans[i].second = h;
				
			}
			else{
				ans[i].first = w;
				ans[i].second = p[i];
			}
		}

		multimap<int, int> mmp;
		vector<int> X;
		for (int i = 1; i <= n; ++i){
			if (g[i] == 1){
				X.push_back(i);
			}
			else{
				mmp.insert(mp(p[i] - t[i], i));
			}
		}
		unordered_map<int, queue<pii>* > ump;
		unordered_map<int, vector<int>* > uvi;
		multimap<int, int>::iterator it = mmp.begin();
		while (it != mmp.end()){
			int key = it->first;
			queue<pii>* ptr = new queue<pii>();
			vector<int>* V = new vector<int>();
			while (it != mmp.end() && it->first == key){
				V->push_back(it->second);
				it++;
			}

			sort(V->begin(), V->end(), cmp2);
			for (int pos : *V){
				ptr->push(ans[pos]);
			}
			ump[key] = ptr;
			uvi[key] = V;
		}

		sort(X.begin(), X.end(),cmp);
		for (int pos : X){
			int key = p[pos] - t[pos];
			if (ump.count(key)){
				queue<pii> * ptr = ump[key];
				ptr->push(ans[pos]);
				ans[pos] = ptr->front();
				ptr->pop();
			}
		}

		unordered_map<int, vector<int>* >::iterator pp = uvi.begin();
		while (pp != uvi.end()){
			queue<pii>* ptr = ump[pp->first];
			vector<int>* V = pp->second;
			for (int pos : *V){
				ans[pos] = ptr->front();
				ptr->pop();
			}
			pp++;
		}

		for (int i = 1; i <= n; ++i)
			printf("%d %d\n", ans[i].first, ans[i].second);
	//	cout << "end" << endl;
	//	cout << clock() - start << endl;

	}


	return 0;
}





