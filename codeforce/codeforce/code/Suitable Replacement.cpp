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
string s, t;
int a[30], b[30];
queue<int> qi;
bool ok(){
	for (int i = 0; i < 30; ++i)
	if (a[i] < b[i])
		return 0;
	return 1;
}

void del(){
	for (int i = 0; i < 30; ++i)
		a[i] -= b[i];
}

void work(int p){

	while (1){
		if (ok()){
			del();
		}
		else{
			for (int i = 0; i < 30; ++i){
				if (a[i] < b[i]){
					int need = b[i] - a[i];
					if (p >= need){
						p -= (b[i] - a[i]);
						a[i] = b[i];
						for (int k = 0; k < need; ++k){
							s[qi.front()] = 'a' + i;
							qi.pop();
						}
					}
					else{
						for (int k = 0; k < p; ++k){
							s[qi.front()] = 'a';
							qi.pop();
						}
						return;
					}
				}
			}
		}
	}
}
int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> s >> t;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	while (!qi.empty())
		qi.pop();
	int p = 0;
	for (int i = 0; i < s.length(); ++i){
		if (s[i] == '?'){
			p++;
			qi.push(i);
		}
		else{
			a[s[i] - 'a']++;
		}


	}
	for (char c : t)
		b[c - 'a']++;

	work(p);


	cout << s << endl;









	return 0;
}

