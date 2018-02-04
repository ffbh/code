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
using namespace std;

bool vis[2010];
int p[2010], N;
long long g[2010];
vector<int> d;
int cale(int id){
	for (int i = 0; i < 2010; ++i)
		g[i] = 1e18;
	vector<int> vi;
	for (int i = 0; i < N; ++i){
		if (p[i] == id){
			g[i] = 0;
			vi.push_back(i);
		}
	}
	
	for (int i = 0; i < vi.size(); ++i){
		int pos;
		pos = vi[i];
		while (!g[pos]){
			int npos = (pos + 1) % N;
			g[npos] = min(g[npos], d[pos] + g[pos]);
			pos = npos;
		}
		pos = vi[i];
		while (!g[pos]){
			int npos = (pos - 1 + N) % N;
			g[npos] = min(g[npos], d[npos] + g[pos]);
			pos = npos;
		}
	}
	vector<long long> ans;
	int spos = vi[0];
	int npos = (spos + 1) % N;
	long long mmax = 0;
	while (1){
		
		if (g[npos] == 0){
		
			ans.push_back(mmax);
			mmax = 0;
		}
		else{
			mmax = max(mmax, g[npos]);
		}
		if (spos == npos)
			break;
		npos = (npos + 1) % N;

	}
	sort(ans.begin(), ans.end());
	return ans.back() + ans[ans.size() - 2];
}


class CircleCity {
public:
	int findMin(vector <int> dist, int k) {
		d = dist;
		memset(vis, 0, sizeof(vis));
		int sum = 0;
		for (int a : dist)
			sum += a;
		int avg = sum / k;
		int start = 0;
		int idx = 1;
		N = dist.size();
		long long ans = 1e18;
		while (!vis[start]){
			vis[start] = 1;
			p[start] = idx;
			int pos = (start + 1)%N;
			sum = dist[start];
			while (pos != start){
				if (sum >= avg){
					p[pos] = idx;
					vis[pos] = 1;
					sum = 0;
				}
				else{
					sum += dist[pos];
					pos = (pos + 1) % N; 
				}
			}
			long long ret = cale(idx);
			ans = min(ans, ret);

			idx++;
			start++;
		}


		return (int)ans;




	}
};


#if 1
int main(){
	





	CircleCity so;
	cout << so.findMin(vector<int>({ 3, 5, 4 }),3) << endl;


	return 0;
}
#endif




