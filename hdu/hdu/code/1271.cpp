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
#define lson (root<<1)  
#define rson (root<<1|1)  


LL N;

string dig;

int D[20];
set<LL> all;
bool judge(LL k){
	return k * 2 > N;
}
void dfs(int pos, bool f, bool e, int pre){
	if (pos == dig.length()){
		if (f)
			return;
		LL ret = 0;
		for (int i = 0; i < pos; ++i){
			ret = ret * 10 + D[i];
		}
		if (judge(ret))
			all.insert(ret);
		return;
	}
	else{
		int aim = dig[pos] - '0';
		if (f)
			aim += 10;
		if (e == 0){
			for (int i = 0; i <= 9; ++i){
				D[pos] = i;
				if (i + pre == aim - 1){
					dfs(pos + 1, 1, 0, i);
					dfs(pos + 1, 1, 1, i);

				}
				else if (i + pre == aim){
					dfs(pos + 1, 0, 0, i);
					dfs(pos + 1, 0, 1, i);
				}
			}
		}
		else{
			if (aim % 2 == 0){
				D[pos] = aim / 2;
				dfs(pos + 1, 0, 1, -1);
			}
			else{
				D[pos] = aim / 2;
				dfs(pos + 1, 1, 1, -1);
			}
		}
	}

}


int main(){

	while (in >> N&&N){
		all.clear();
		dig = to_string(N);
		dfs(0, 0, 0, 0);
		if (all.empty()){
			printf("No solution.\n");
		}
		else{
			bool f = 1;
			for (LL s : all){
				if (f){
					f = 0;
					printf("%lld", s);
				}
				else{
					printf(" %lld", s);
				}
			}
			cout << endl;
		}
	}



	return 0;
}





