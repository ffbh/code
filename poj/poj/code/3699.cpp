#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
#include <sstream>
#include <vector>
using namespace std;
map<string, int> msi;
struct Data{
	string data[11];
}data[10010];
struct Type{
	string name;
	string type;
}type[11];
struct Node{
	string d1;
	int d2;
	int index,id;
	bool operator<(const Node& p)const{
		if (type[id].type == "INT")
			return d2 < p.d2;
		else
			return d1 < p.d1;
	}
	bool operator==(const Node& p)const{
		if (type[id].type == "INT")
			return d2 == p.d2;
		else
			return d1 == p.d1;
	}
}Index[11][10010], tmp;
int N, M, K, vis[11];
void coutstring(string& s,int id){
	int chazhi = vis[id] - s.length();
	if (chazhi % 2){
		for (int i = 0; i < chazhi / 2; ++i)
			putchar(' ');
		printf("%s", s.c_str());
		for (int i = 0; i < chazhi / 2 + 1; ++i)
			putchar(' ');

	}
	else{
		for (int i = 0; i < chazhi / 2; ++i)
			putchar(' ');
		printf("%s", s.c_str());
		for (int i = 0; i < chazhi / 2; ++i)
			putchar(' ');
	}
}

int main(){
	//ifstream in("C:\\input.txt");
	stringstream ss;
	msi.clear();
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i){
		cin >> type[i].name >> type[i].type;
		msi[type[i].name] = i;
	}
	for (int i = 0; i < M; ++i)
	for (int j = 0; j < N; ++j){
		cin >> data[i].data[j];
		if (type[j].type == "STR"){
			Index[j][i].d1 = data[i].data[j];
		}
		else{
			Index[j][i].d2 = atoi(data[i].data[j].c_str());
		}
		Index[j][i].id = j;
		Index[j][i].index = i;
	}
	for (int i = 0; i < N;++i)
		sort(Index[i], Index[i] + M);
	string s, name;
	while (K--){
		vector<int> col, ans;
		memset(vis, -1, sizeof(vis));
		cin >> s >> s;
		for (int i = 0; i < s.length();++i)
		if (s[i] == ',')
			s[i] = ' ';
		ss.clear();
		ss.str(s);
		while (ss >> s){
			col.push_back(msi[s]);
		}

		cin >> s >> s;
		int c;
		for (int i = 0; i < s.length(); ++i){
			if (s[i] == '=' || s[i] == '<' || s[i] == '>'){
				if (s[i] == '=')
					c = 0;
				else if (s[i] == '<')
					c = 1;
				else
					c = 2;
				s[i] = ' ';
			}
			else if (s[i] == '"')
				s[i] = ' ';
		}
		ss.clear();
		ss.str(s);
		ss >> name;
		tmp.id = msi[name];
		if (type[tmp.id].type == "INT")
			ss >> tmp.d2;
		else
			ss >> tmp.d1;
		if (c == 0){
			int p = lower_bound(Index[tmp.id], Index[tmp.id] + M,tmp) - Index[tmp.id];
			while (p < M){
				if (Index[tmp.id][p] == tmp)
					ans.push_back(Index[tmp.id][p].index);
				else
					break;
				p++;
			}
		}
		else if (c == 1){
			int p = lower_bound(Index[tmp.id], Index[tmp.id] + M, tmp) - Index[tmp.id];
			while (p >= 0){
				if (Index[tmp.id][p] < tmp)
					ans.push_back(Index[tmp.id][p].index);
				p--;
			}
		}
		else{
			int p = lower_bound(Index[tmp.id], Index[tmp.id] + M, tmp) - Index[tmp.id];
			while (p < M){
				if (tmp < Index[tmp.id][p] )
					ans.push_back(Index[tmp.id][p].index);
				p++;
			}
		}
		sort(ans.begin(), ans.end());
		int outputlen = 1;
		memset(vis, -1, sizeof(vis));
		for (int i = 0; i < col.size(); ++i){
			int id = col[i];
			if (vis[id] == -1){
				vis[id] = type[id].name.length();
				for (int j = 0; j < ans.size(); ++j)
				if (vis[id] < data[j].data[id].length())
					vis[id] = data[j].data[id].length();
				vis[id] += 2;
			}
			outputlen += vis[id] + 1;
		}
		string se = '+' + string(outputlen-2, '-') + '+';
		cout << se << endl;
		putchar('|');
		for (int i = 0; i < col.size(); ++i){
			string name = type[col[i]].name;
			coutstring(name,col[i]);
			putchar('|');
		}
		cout << endl;

		putchar('|');
		for (int i = 0; i < col.size(); ++i){
			for (int k = 0; k < vis[col[i]]; ++k)
				putchar('-');
			putchar('|');
		}
		cout << endl;

		for (int i = 0; i < ans.size(); ++i){
			putchar('|');
			for (int j = 0; j < col.size(); ++j){
				string name = data[ans[i]].data[col[j]];
				coutstring(name, col[j]);
				putchar('|');
			}
			cout << endl;
		}
		cout << se << endl;
		cout << endl;
	}
	return 0;
}