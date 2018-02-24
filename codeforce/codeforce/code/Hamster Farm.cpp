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


LL N, K;
LL a[100010];

void input(){
	in >> N >> K;
	for (int i = 1; i <= K; ++i)
		in >> a[i];


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL ans = N;
		int type = 1;
		for (int i = 1; i <= K; ++i){
			if (ans > N % a[i]){
				ans = N%a[i];
				type = i;
			}
		}

		cout << type << " " << N/a[type] << endl;












	}


	return 0;
}





