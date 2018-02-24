#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;
int N, tmp, t;
vector<int> vi[100010];
vector<int> q;
int num[100010];
unordered_set<int> usi;
int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N){
		for (int i = 1; i <= N; ++i){
			cin >> tmp;
			int sum = 0;
			for (int j = 1; j <= tmp; ++j){
				cin >> t;
				sum += t;
				vi[i].push_back(sum);
				q.push_back(sum);
			}
		}
		sort(q.begin(), q.end());
		q.erase(unique(q.begin(), q.end()) - 1, q.end());
		for (int i = 1; i <= N; ++i){
			int mmax = 0;
			usi.clear();
			for (int j = 0; j < vi[i].size(); ++j){
				usi.insert(vi[i][j]);
				mmax = max(mmax, vi[i][j]);
			}
			for (int k = 0; k < q.size(); ++k){
				if (!usi.count(q[k]) && q[k] < mmax ){
					num[k]++;
				}
			}
		}
		int ans = N;
		for (int i = 0; i < q.size(); ++i)
			ans = min(ans, num[i]);
		cout << ans << endl;

	}


	return 0;
}