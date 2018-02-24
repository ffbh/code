#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <sstream>
#include <vector>
using namespace std;
string s1, s2;
char tmp, a, b;
stringstream ss;
vector<char> vc;
vector<int> vi[30];
int In[30];

void Init(){
	vc.clear();
	for (int i = 0; i < 30; ++i){
		vi[i].clear();
		In[i] = 0;
	}
}

char ans[30];
void dfs(int dept,string V,int c){
	if (dept == vc.size()){
		for (int i = 0; i < dept; ++i)
			putchar(ans[i]);
		putchar('\n');
		return;
	}
	if (dept != 0){
		for (int i = 0; i < vi[c].size(); ++i){
			if (--In[vi[c][i]] == 0){
				int id = vi[c][i];
				V += char(id + 'a');
			}
		}
		sort(V.begin(), V.end());
	}

	for (int i = 0; i < V.length(); ++i){
		ans[dept] = V[i];
		dfs(dept + 1, V.substr(0, i) + V.substr(i + 1), V[i] - 'a');
	}
	if (dept != 0){
		for (int i = 0; i < vi[c].size(); ++i){
			++In[vi[c][i]];
		}
	}
}

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	bool ok = 0;
	while (getline(in,s1)){
		getline(in, s2);
		if (ok)
			cout << endl;
		ok = 1;

		Init();
		ss.clear();
		ss.str(s1);
		while (ss >> tmp){
			vc.push_back(tmp);
		}
		sort(vc.begin(), vc.end());
		ss.clear();
		ss.str(s2);
		while (ss >> a >> b){
			vi[a - 'a'].push_back(b - 'a');
			In[b - 'a']++;
		}
		string  start = "";
		for (int i = 0; i < vc.size(); ++i){
			char id = vc[i];
			if (In[id-'a'] == 0)
				start += id;
		}
		dfs(0, start,-1);
	}

















	return 0;
}