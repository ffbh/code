#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
using namespace std;



/*vector<bitset<32> > vi;
int bit(int p){
	int num = 0;
	for (int i = 0; i < 31; ++i){
		int b = (1 << i);
		if (p&i)
			num++;

	}
	return num;
}
int ans[9000];
bool vis[9000];

bool judge(int p){
	for (int i = 0; i < p; ++i){
		bitset<32> tmp(ans[i] & ans[p]);
		if (tmp.count() >= 2){
			return 0;
		}

	}
	return 1;
}

bool cmp(int a, int b){
	int p = a^b;
	p = (p)&(-p);
	if (a&p)
		return 1;
	else
		return 0;
}

bool dfs(int dept,int limit){
	if (dept == limit){
		sort(ans, ans + dept, cmp);
		for (int i = 0; i < dept; ++i){
			for (int j = 0; j < limit; ++j){
				cout << bool(ans[i] & (1 << j));
			}
			cout << endl;
		}
		cout << endl;
		return 1;
	}
	for (int i = 0; i < vi.size(); ++i){
		if (vis[i])
			continue;
		ans[dept] = (int)vi[i].to_ulong();
		if (judge(dept)){
			vis[i] = 1;
			if (dfs(dept + 1,limit))
				return 1;
			vis[i] = 0;
		}
	}
	return 0;
}

void Init(int k){
	vi.clear();
	int n = k*k - k + 1;
	for (int i = 0; i < (1 << n); ++i){
		bitset<32> b(i);
		if (b.count() == k){
			vi.push_back(b);
		}
	}
	if (!dfs(0, n))cout << "No";
	



}*/



int ans[1220][1220];
int tmp[1220];
int k;
void rorate(int a,int b){
	int t = tmp[a];
	for (int i = a; i < b; ++i)
		tmp[i] = tmp[i + 1];
	tmp[b] = t;
}
int main(){
	ifstream in("C:\\input.txt");
//	istream& in = cin;
//	Init(6);
	bool ok = 0;
	while (in >> k){
		if (ok)
			cout << endl;
		ok = 1;

		int n = k*k - k + 1;
		for (int i = 0; i <= n;++i)
		for (int j = 0; j <= n; ++j)
			ans[i][j] = 0;

		for (int i = 1; i <= k; ++i){
			ans[i][1] = 1;
			int a = (i-1)*(k-1)+2;
			int b = i*(k-1)+1;
			for (int j = a; j <= b; ++j)
				ans[i][j] = 1;

		}
		for (int i = k + 1; i <= n; ++i){
			ans[i][(i - k-1) / (k-1)+2] = 1;
			ans[i][(i - k - 1) % (k - 1) + 2+k-1] = 1;
		}

		for (int i = 0; i < (k - 1)*(k - 1); ++i)
			tmp[i] =(k-1-( (i) / (k - 1) + i)%(k-1));
		int base = 2 + 2 * (k - 1)-1;
		for (int p = 1; p < k - 1; ++p){
			for (int i = 0; i < (k - 1)*(k - 1); ++i){
				ans[k+i+1][base + tmp[i]] = 1;
			}
			for (int i = 0; i < k; ++i){
				int low = i*(k - 1);
				int high = (i + 1)*(k - 1) - 1;
				rorate(low, high);
			}
			int d = 0;
			d++;
			
			base += k - 1;

		}


		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j)
				cout << ans[i][j];
			cout << endl;
		}
		
		vector<int> v[1220];
		set<pair<int,int> > usi;
		for (int i = 1; i <= n; ++i){
			int num = 0;
			for (int j = 1; j <= n; ++j){
				if (ans[i][j] == 1){
					num++;
					cout << j;
					v[i].push_back(j);
					if (num != k)
						cout << " ";
				}
			}
			cout << endl;
		}

		for (int i = 1; i <= n; ++i){
			for (int j = 0; j < v[i].size();++j)
			for (int k = j + 1; k < v[i].size(); ++k){
				pair<int, int> tmp;
				tmp.first = v[i][j];
				tmp.second = v[i][k];
				if (usi.count(tmp)){
					cout << "WAAAA:  " << i << "  " << j << " " << k << endl;
				}
				usi.insert(tmp);
			}

		}





	}



	return 0;
}