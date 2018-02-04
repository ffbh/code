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

int N, a[1010];

int lf[1010];

void up(vector<int> v){
	memset(lf, 0, sizeof(lf));
	vector<int> t = v;
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());
	int pos = 0;
	reverse(v.begin(), v.end());
	for (int p : v){
		if (p == t[pos]){
			lf[p] = -1;
			pos++;
		}
	}
	lf[N] = v.size();
	for (int i = N - 1; i >= 0; --i)
		lf[i] = lf[i + 1] + lf[i];
}

int dp[1010];
int data[1010];
int down(vector<int> v){

	if (v.size() == 0)
		return 0;
	int p = 0;
	reverse(v.begin(), v.end());
	for (int val : v){
		if (p == 0 || data[p-1] < val){
			data[p++] = val;
		}
		else{
			*lower_bound(data, data + p, val) = val;
		}

	}
	
	return v.size()-p;
}




bool vis[1010];
int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> N;
	for (int i = 1; i <= N; ++i)
		in >> a[i];

	int pos = -1;
	for (int i = 1; i <= N; ++i){
		if (a[i] == N){
			pos = i;
			break;
		}
	}
	vector<int> temp;

	

	int ans = 2222222, ret;
	ret = 0;
	if (a[1] != N)
		ret = 1;
	temp.clear();
	for (int i = 1; i <= N; ++i){
		if (a[i] != N)
			temp.push_back(a[i]);
	}
	ret += down(temp);
	ans = min(ans, ret);

	temp.clear();



	if (pos != 1){
	
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i < pos; ++i){
			temp.push_back(a[i]);
		}

		up(temp);

		vector<pair<int, int> > all;
		for (int i = pos + 1; i <= N; ++i){
			all.push_back(make_pair(a[i], i));
		}
		all.push_back(make_pair(0, N + 1));
		sort(all.begin(), all.end());
		reverse(all.begin(), all.end());


		int pre = pos;
		vector<int> vi;
		for (pair<int, int> p : all){
			vi.clear();
			int num = 0;
			for (int i = pos + 1; i < p.second; ++i){
				if (!vis[i]){
					vi.push_back(a[i]);
				}
				else{
					num++;
				}
			}
			bool ok = !vis[p.second];
			for (int i = p.second + 1; i <= N; ++i){
				if (!vis[i]){
					vi.push_back(a[i]);
				}
				else
					num++;
			}
			
			ret = lf[p.first] + num + down(vi) + (p.first != 0);

			int a1 = lf[p.first];
			int a2 = down(vi);

			ans = min(ans, ret);

			if (!ok)
				break;
			for (int k = pre + 1; k < p.second; ++k){
				vis[k] = 1;
			}
			
			pre = p.second;

			
		}


		

		
	}

	cout << ans << endl;



	return 0;
}





