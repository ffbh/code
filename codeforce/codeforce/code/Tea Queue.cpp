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



pii p[1010];
int n;
void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> p[i].first >> p[i].second;


}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int pos = 1;
		for (int time = 1; time <= 7000 && pos <= n; ++time){
			while (pos <= n && p[pos].second < time){
				printf("%d ", 0);
				pos++;
			}

			if (p[pos].first <= time && p[pos].second >= time){
				printf("%d ", time);
				pos++;
			}
		}


		cout << endl;










	}


	return 0;
}





