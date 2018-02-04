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

int n;



void input(){
	in >> n;


}

bool vis[266];
bool tmp[266];

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int ans = 0;
		int rest = 26;
		while (n-- > 0){
			char c;
			string str;
			in >> c >> str;
			
			if (c == '!'){
				if (rest == 1){
					ans++;
				}
				for (char p = 'a'; p <= 'z'; ++p){
					tmp[p] = 0;
				}
				for (char p : str){
					tmp[p] = 1;
				}
				for (char p = 'a'; p <= 'z'; ++p){
					if (tmp[p] == 0 && !vis[p]){
						rest--;
						vis[p] = 1;
					}
				}
			}
			else if (c == '.'){
				for (char p : str){
					if (!vis[p]){
						vis[p] = 1;
						rest--;
					}
				}
			}
			else{
				if (n>0&&rest == 1){
					
					ans++;
				}
				if (!vis[str[0]]){
						rest--;
						vis[str[0]] = 1;
					}

			}
	
		}
		cout << ans << endl;















	}


	return 0;
}





