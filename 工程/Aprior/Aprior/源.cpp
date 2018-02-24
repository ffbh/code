#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct Node{
	string str;
	int num;
	Node(string s,int n){
		str = s;
		num = n;
	}

	bool can_union(Node& p){
		for (int i = 0; i < str.length() - 1;++i)
		if (str[i] != p.str[i]){
			return 0;
		}
		return 1;
	}

	Node Union(Node& p){
		string tmp = str;
		tmp.push_back(p.str.back());
		return Node(tmp, -1);
	}
};

vector<Node> initC(vector<string>& data){
	int h[30];
	memset(h, 0, sizeof(h));
	for (int i = 0; i < data.size(); ++i){
		for (int j = 0; j < data[i].size(); ++j){
			h[data[i][j] - 'A']++;
		}
	}
	vector<Node> ans;
	for (int i = 0; i < 30; ++i){
		string tmp = "";
		if (h[i]){
			tmp += char(i + 'A');
			ans.push_back(Node(tmp, h[i]));
		}
	}
	return ans;
}
vector<Node> C[30], F[30];


vector<Node> candidate_gen(vector<Node>& f){
	vector<Node> ans;
	unordered_set<string> usi;
	for (int i = 0; i < f.size(); ++i){
		usi.insert(f[i].str);
	}
	for (int i = 0; i < f.size();++i)
	for (int j = i + 1; j < f.size(); ++j){
		if (f[i].can_union(f[j])){
			ans.push_back(f[i].Union(f[j]));
		}
	}
	vector<bool> vis;
	vis.resize(ans.size());
	for (int i = 0; i < vis.size(); ++i)
		vis[i] = 1;

	for (int i = 0; i < ans.size(); ++i){
		for (int j = 0; j < ans[i].str.size(); ++j){
			string& s = ans[i].str;
			string tmp = s.substr(0, j) + s.substr(j + 1);
			if (!usi.count(tmp)){
				vis[i] = 0;
				break;
			}
		}
	}

	vector<Node> ret;
	for (int i = 0; i < ans.size(); ++i){
		if (vis[i]){
			ret.push_back(ans[i]);
		}
	}


	return ret;
}

bool judge(string& s,string& t){
	int pos = 0;
	for (int i = 0; i < t.length(); ++i){
		while (pos < s.length() && s[pos] != t[i]){
			pos++;
		}
		if (pos == s.length()){
			return 0;
		}
		pos++;
	}
	return 1;
}

int Count(vector<string>& data, string& s){
	int num = 0;
	for (int i = 0; i < data.size(); ++i){
		if (judge(data[i], s)){
			num++;
		}
	}
	return num;
}

void Aprior(vector<string>& data,double minsup,double minconf){
	vector<Node> ans;

	C[1] = initC(data);
	for (int i = 0; i < C[1].size(); ++i){
		if ((double)C[1][i].num / data.size() >= minsup){
			F[1].push_back(C[1][i]);
		}
	}

	int pos = 2;
	while (F[pos - 1].size()>1){
		C[pos] = candidate_gen(F[pos - 1]);
		for (int i = 0; i < C[pos].size(); ++i){
			C[pos][i].num = Count(data, C[pos][i].str);
			if ((double)C[pos][i].num / data.size() >= minsup){
				F[pos].push_back(C[pos][i]);
			}
		}
		pos++;
	}



	for (int i = 1; i < pos; ++i){
		cout << "C" << i << "集合: ";
		for (int j = 0; j < C[i].size(); ++j)
			cout << C[i][j].str << " ";
		cout << endl << endl;

		cout << "F" << i << "集合: ";
		for (int j = 0; j < F[i].size(); ++j)
			cout << F[i][j].str << " ";
		cout << endl << endl;
	}

}


void Get_Rule(vector<Node>& f){
	unordered_map<string, int> mmp;


	for (int i = 0; i < f.size(); ++i){
		string& s = f[i].str;
		for (int j = 0; j < s.length(); ++j){







		}


	}

}









int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;

	vector<string> vs;
	string t;
	while (in >> t){
		vs.push_back(t);
	}

	Aprior(vs, 0.3,0.3);

	int p = 0;
	p++;













	return 0;
}