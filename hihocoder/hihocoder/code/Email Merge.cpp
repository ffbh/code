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

int f[100010];

void input(){
	in >> n;


}

unordered_map<string, int> usi;
string name[10010];
int P[10010];
int getId(string& str){
	if (usi.count(str)){
		return usi[str];
	}
	else{
		int id = usi.size() + 1;
		return usi[str] = id;
	}
}

int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}
vector<string> ans[10010];
int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 0; i < 100010; ++i)
			f[i] = i;


		for (int i = 1; i <= n; ++i){
			int num, pid = -1;
			in >> name[i] >> num;
			for (int j = 1; j <= num; ++j){
				string addr;
				in >> addr;
				int id = getId(addr);

				if (pid == -1){
					pid = id;
				}
				else{
					int fa = find(pid);
					int fb = find(id);
					f[fb] = fa;
					pid = fa;
				}
			}
			P[i] = pid;
		}

		unordered_map<int, int> mmp;
		for (int i = 1; i <= n; ++i){
			int ff = find(P[i]);
			if (mmp.count(ff)){
				ans[mmp[ff]].push_back(name[i]);
			}
			else{
				int id = mmp.size() + 1;
				mmp[ff] = id;
				ans[id].push_back(name[i]);
			}
		}

		int size = mmp.size();
		for (int i = 1; i <= size; ++i){
			for (string& s : ans[i]){
				printf("%s ", s.c_str());
			}
			putchar('\n');
		}


	}


	return 0;
}





