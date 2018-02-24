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

int n, p[100010];



void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> p[i];


}

bool vis[100010];

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		vector<LL> ans;
		for (int i = 1; i <= n; ++i){
			if (vis[i])
				continue;
			LL num = 0, u = i;
			while (!vis[u]){
				vis[u] = 1;
				num++;
				u = p[u];
			}
			ans.push_back(num);
		}

		sort(ans.begin(), ans.end());


		if (ans.size() == 1){
			cout << ans[0] * ans[0] << endl;
		}
		else{
			LL sum = 0;
			for (int i = 0; i < (int)ans.size() - 2; ++i){
				sum += ans[i] * ans[i];
			}
			LL t = ans.back() + ans[ans.size() - 2];
			sum += t*t;
			cout << sum << endl;

		}






	}


	return 0;
}





