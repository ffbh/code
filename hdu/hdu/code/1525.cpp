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




bool dfs(LL a, LL b){
	if (a % b == 0){
		return 1;
	}
	LL k = a / b;
	LL m = a%b;
	if (k > 1){
		return 1;
	}
	return !dfs(b, m);
}

int main(){
	LL a, b;
	while (in >> a >> b){
		if (a + b == 0)
			break;
		if (a < b){
			swap(a, b);
		}
		if (dfs(a, b)){
			printf("Stan wins\n");
		}
		else{
			printf("Ollie wins\n");
		}

	}

	return 0;
}





