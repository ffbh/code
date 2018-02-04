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
using namespace std;
#define MMAX (int(1e6)+10)
int num[MMAX];
int S[27], E[27];
int n, k;
string s;
int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n >> k;
	in >> s;
	for (int i = 0; i < 26; ++i){
		E[i] = -1;
	}
	for (int i = 0; i < s.length(); ++i)
		E[s[i]-'A'] = i;
	for (int i = s.length() - 1; i >= 0; --i){
		S[s[i] - 'A'] = i;
	}

	for (int i = 0; i < 26; ++i){
		for (int j = S[i]; j <= E[i]; ++j)
			num[j]++;
	}

	bool ok = 0;
	for (int i = 0; i < s.length(); ++i){
		if (num[i]>k){
			ok = 1;
			break;
		}
	}

	if (ok){
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;











	return 0;
}





