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
int n;
pii a[100010];

bool vis[100010];
vector<vector<int> > ans;

void input(){
	in >> n;
	for (int i = 1; i <= n; ++i){
		in >> a[i].first;
		a[i].second = i;

	}


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		sort(a + 1, a + n + 1);
		memset(vis, 0, sizeof(vis));
	
		for (int i = 1; i <= n; ++i){
		
			if (!vis[i]){
				vector<int> tmp;
				int now = i;
				while (!vis[now]){
					tmp.push_back(now);
					vis[now] = 1;
					now = a[now].second;
				}
				ans.push_back(tmp);
			}
		}
		

		cout << ans.size() << endl;
		for (int k = 0; k < ans.size(); ++k){
			cout << ans[k].size() << " ";
			for (int p : ans[k]){
				cout << p << " ";
			}
			cout << endl;
		}







	}


	return 0;
}





