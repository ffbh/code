#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
string str = "abcdefghij";
vector<string> ans[10];
vector<char> vc;
string tmp;

void dfs(int dept,int n){
	if (dept == n){
		string p = "";
		for (int i = 0; i < vc.size() - 1; ++i){
			p += vc[i];
			p += ',';
		}
		p += vc.back();
		ans[n].push_back("writeln(" + p + ")");
		return;
	}
	char now = str[dept];
	vc.push_back(now);
	string state = "";
	state += "if ";
	state += vc[vc.size() - 2];
	state += " < ";
	state += vc.back();
	state += " then";
	ans[n].push_back(state);
	dfs(dept + 1, n);

	int idx = vc.size() - 1;
	while (idx > 1){
		state = "";
		swap(vc[idx], vc[idx - 1]);
		idx--;
		state += "else if ";
		state += vc[idx - 1];
		state += " < ";
		state += vc[idx];
		state += " then";
		ans[n].push_back(state);
		dfs(dept + 1, n);
	}

	state = "";
	ans[n].push_back("else");
	swap(vc[0], vc[1]);
	dfs(dept + 1, n);

	for (int i = 0; i < vc.size() - 1; ++i){
		swap(vc[i], vc[i + 1]);
	}
	vc.pop_back();

}

void cale(int n){
	if (n == 3){
		int t = 0;
	}
	ans[n].push_back("program sort(input, output);");
	ans[n].push_back("var");
	tmp = "";
	for (char c = 'a'; c < 'a' + n - 1; ++c){
		tmp += c ;
		tmp += ",";
	}
	tmp += char('a' + n - 1);
	ans[n].push_back(tmp + "  : integer;");
	ans[n].push_back("begin");
	ans[n].push_back("readln(" + tmp + ");");
	vc.clear();
	vc.push_back('a');
	dfs(1, n);
	ans[n].push_back("end.");
}

void Init(){
	for (int i = 1; i <= 8; ++i){
		
		cale(i);
	}
}


int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	Init();

	int T;
	cin >> T;
	while (T-- > 0){
		int N;
		cin >> N;
		for (int i = 0; i < ans[N].size(); ++i){
			printf("%s\n", ans[N][i].c_str());
		}
		if (T)
			putchar('\n');

	}

	return 0;
}