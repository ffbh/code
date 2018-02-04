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
#include <unordered_map>
using namespace std;
struct Node{
	unordered_map<string, int> usi;
	vector<int> vi, ans;
	bool multi[250];
	int num;

	void Insert(string& s){
		if (usi.count(s)){
			int k = usi[s];
			multi[k] = 1;
		}
		else{
			int k = usi.size();
			usi[s] = k;
		}
	}

	void clear(){
		for (int i = 0; i < vi.size(); ++i)
			vi[i] = -1;
	}
	bool isok(string& s, int idx){
		if (usi.count(s)){
			int real_idx = usi[s];
			for (int i = 0; i < vi.size(); ++i){
				if (real_idx == i && !multi[real_idx])
					continue;
				if (vi[i] != -1){
					int dis = idx - vi[i] - 1;
					if (dis <= num){
						return 1;
					}
				}
			}
			vi[real_idx] = idx;
		}
		return 0;
	}
}P[60];
stringstream ss;

void clear(string& p){
	string ret = "";
	for (int i = 0; i < p.length(); ++i){
		if (islower(p[i])){
			ret += p[i];
		}
		else if (isupper(p[i])){
			ret += char(p[i] + 32);
		}
	}
	p = ret;
}

bool ok(Node& p, vector<string>& vs){
	p.clear();
	for (int i = 0; i < vs.size(); ++i){
		if (p.isok(vs[i], i))
			return 1;

	}
	return 0;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	string s, tmp;
	int size = 1, tsize = 1;
	while (getline(in, s) && s != "#"){
		if (s[0] == 'P'){
			memset(P[size].multi, 0, sizeof(P[size].multi));
			s[0] = s[1] = ' ';
			ss.clear();
			ss.str(s);
			ss >> P[size].num;
			while (ss >> s){
				P[size].Insert(s);
			}
			P[size].vi.resize(P[size].usi.size());
			size++;
		}
		else{
			s[0] = s[1] = ' ';
			while (s.back() != '|'){
				getline(in, tmp);
				s += ' ';
				s += tmp;
			}
			ss.clear();
			ss.str(s);
			vector<string> vs;
			while (ss >> s){
				clear(s);
				if (s.length() > 0){
					vs.push_back(s);
				}
			}
			if (tsize == 3){
				int t = 0;
			}
			for (int k = 1; k < size; ++k){
				if (ok(P[k], vs)){
					P[k].ans.push_back(tsize);
				}
			}

			tsize++;
		}


	}

	for (int i = 1; i < size; ++i){
		printf("%d: ", i);
		if (!P[i].ans.empty()){
			for (int j = 0; j < P[i].ans.size() - 1; ++j)
				printf("%d,", P[i].ans[j]);
			cout << P[i].ans.back();
		}
		cout << endl;
	}
	return 0;
}