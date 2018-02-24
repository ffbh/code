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
using namespace std;
char data[10];
bool mark[10];
vector<int> vi[30];
stringstream ss;
bool vis[30];
vector<char> tmp;
void Init(){
	for (int i = 0; i < 10; ++i){
	
		
		mark[i] = 0;
	}
	for (int i = 0; i < 30; ++i){
		vi[i].clear();
		vis[i] = 0;
	}
	tmp.clear();
}

string s;
int h[266], size, idx[30];

string ansS;


void Get(string& p){
	p  = "";
	for (int i = 0; i < size; ++i){
		p += tmp[i];
		p += ' ';
	}
}

bool dfs(int dept,int limit){
	if (dept == size){
		Get(ansS);
		return 1;
	}

	for (int i = 0; i < size; ++i){
		if (mark[i])
			continue;
		int id = data[i] - 'A';
		bool ok = 1;
		for (int k = 0; k < vi[id].size(); ++k){
			int id2 = vi[id][k];
			if (!mark[h[id2]])
				continue;
			if (abs(idx[id2] - dept)>limit){
				ok = 0;
				break;
			}
		}

		if (ok){
			mark[i] = 1;
			tmp.push_back(data[i]);
			idx[id] = dept;
			if (dfs(dept + 1,limit))
				return 1;
			tmp.pop_back();
			mark[i] = 0;


		}
	}


	return 0;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	
	while (getline(in, s) && s!= "#"){
		Init();
		string tmp = "";
		for (int i = 0; i < s.length(); ++i){
			if (s[i] != ' ')
				tmp += s[i];
		}
		for (int i = 0; i < tmp.length(); ++i){
			if (tmp[i] == ';')
				tmp[i] = ' ';
		}

		ss.clear();
		ss.str(tmp);
		while (ss >> s){
			int p = s[0] - 'A';
			vis[p] = 1;
			for (int i = 2; i < s.length(); ++i){
				int p2 = s[i] - 'A';
				vis[p2] = 1;
				vi[p].push_back(p2);
				vi[p2].push_back(p);

			}
		}

		size = 0;
		for (int i = 0; i < 30; ++i){
			if (vis[i]){
				h[i] = size;
				data[size++] = 'A' + i;

			}
		}
		
		for (int i = 1;i<size; ++i){
		
			if (dfs(0, i)){
				cout << ansS << "-> " << i << endl;
				break;
			}
		}
	}
	return 0;
}