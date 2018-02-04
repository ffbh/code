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
#define MAXN (31800)
int n, a[110];


bool vis[MAXN];
vector<int> prime;
void Init(){
	for (int i = 2; i < MAXN; ++i){
		if (!vis[i]){
			prime.push_back(i);
			for (int j = i + i; j < MAXN; j += i){
				vis[j] = 1;
			}

		}




	}



}


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}

unordered_map<int, vector<int>* > mmp;

void put(int p,int num){
	if (!mmp.count(p)){
		mmp[p] = new vector<int>();
	}
	mmp[p]->push_back(num);
}

unordered_map<int, int> SG;

int dfs(int k){
	if (k == 0)
		return 0;
	if (SG.count(k))
		return SG[k];
	set<int> si;
	int hbit ;
	for (int i = 30; i >= 0; --i){
		if (k & (1 << i)){
			hbit = i;
			break;
		}
	}
	vector<int> dig;
	for (int i = 0; i < 31; ++i){
		if (k & (1 << i)){
			dig.push_back(i);
		}
	}
	for (int i = 1; i <= hbit; ++i){
		int g = 0;
		for (int d : dig){
			if (d > i){
				g |= (1 << (d - i));
			}
			else if (d < i){
				g |= (1 << d);
			}
		}
		si.insert(dfs(g));
	}
	int sg = 0;
	while (si.count(sg))
		sg++;
	return SG[k] = sg;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		Init();

		for (int i = 1; i <= n; ++i){
			int p = a[i];
			for (int div : prime){
				int num = 0;
				while (p%div == 0){
					num++;
					p /= div;
				}
				if (num){
					put(div, num);

				}
			}
			if (p != 1){
				put(p, 1);
			}
		}

		
		unordered_map<int, vector<int>* >::iterator it = mmp.begin();
		int ans = 0;

		while (it != mmp.end()){
			vector<int>& tmp = *(it->second);
			int key = 0;
			for (int t : tmp){
				key |= (1 << t);
			}
			ans ^= dfs(key);
			it++;
		}

		if (ans){
			cout << "Mojtaba" << endl;
		}
		else{
			cout << "Arpa" << endl;
		}








	}


	return 0;
}





