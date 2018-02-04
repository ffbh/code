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
struct Node{
	int conds, conde;
	int thens, thene;
	int elses, elsee;
};


Node dfs(vector<string>& p, int pos){
	Node ret;
	ret.conds = pos;
	for (int i = pos; i < p.size(); ++i){
		if (p[i] == "IF"){
			Node tmp = dfs(p, i + 1);
			i = tmp.elsee;
		}
		else if (p[i] == "THEN"){
			ret.conde = i - 1;
			ret.thens = i + 1;
		}
		else if (p[i] == "ELSE"){
			ret.thene = i - 1;
			ret.elses = i + 1;
			i++;
			if (p[i] == "IF"){
				Node tmp = dfs(p, i + 1);
				ret.elsee = tmp.elsee;
			}
			else{
				ret.elsee = i;
			}
			break;
		}

	}
	return ret;
}

vector<vector<string> > vs;
int final_score[20];
string GJZ[14] = { "IF", "THEN", "ELSE", "AND", "OR", "=", "#", "NULL", "MY", "YOUR", "LAST1", "LAST2", "TRADE", "CHEAT" };

bool judge(string& p, string& m, int pos){
	int a = pos;
	int b = 0;
	if (m.length() + pos > p.length())
		return 0;
	while (b < m.length()){
		if (p[a] != m[b])
			return 0;
		a++;
		b++;
	}
	return 1;

}

vector<string> clearStr(string& s){
	string ret = "";
	for (int i = 0; i < s.length(); ++i){
		if (s[i] == ' ' || s[i] == '.'){
			continue;
		}
		ret += s[i];
	}
	vector<string> ss;
	int pos = 0;
	while (pos < ret.length()){
		for (int i = 0; i < 14; ++i){
			if (judge(ret, GJZ[i], pos)){
				ss.push_back(GJZ[i]);
				pos += GJZ[i].length();
				break;
			}
		}
	}
	return ss;
}

int GetCommand(string comm){
	if (comm == "NULL")
		return -1;
	else if (comm == "TRADE")
		return 0;
	else
		return 1;

}


bool cale_LJ(vector<int>& LJ){
	int ret = LJ[0];
	for (int i = 1; i < LJ.size(); i += 2){
		if (LJ[i] == '&'){
			ret &= LJ[i + 1];
		}
		else{
			if (ret == 1){
				return 1;
			}
			else{
				ret = LJ[i + 1];
			}
		}
	}
	return ret;
}
vector<int> LJ;
bool judgeCondition(int mylast1, int mylast2, int yourlast1, int yourlast2, int l, int r, vector<string>& p){
	LJ.clear();
	int pos = l;
	while (pos <= r){
		if (p[pos] == "AND"){
			LJ.push_back('&');
			pos++;
		}
		if (p[pos] == "OR"){
			LJ.push_back('|');
			pos++;
		}
		int now, comm;
		if (p[pos] == "MY"){
			pos++;
			if (p[pos].back() == '1'){
				now = mylast1;
			}
			else{
				now = mylast2;
			}
		}
		else{
			pos++;
			if (p[pos].back() == '1'){
				now = yourlast1;
			}
			else{
				now = yourlast2;
			}
		}
		pos++;
		if (p[pos] == "="){
			pos++;
			comm = GetCommand(p[pos]);
			pos++;
			LJ.push_back(now == comm);
		}
		else{
			pos++;
			comm = GetCommand(p[pos]);
			pos++;
			LJ.push_back(now != comm);
		}
	}

	return cale_LJ(LJ);


}


//-1 null      0 trade      1 cheat
string play(int mylast1, int mylast2, int yourlast1, int yourlast2, vector<string>& program, int pos){
	if (program[pos] == "IF"){
		Node tmp = dfs(program, pos + 1);
		bool ok = judgeCondition(mylast1, mylast2, yourlast1, yourlast2, tmp.conds, tmp.conde, program);
		if (ok){
			return play(mylast1, mylast2, yourlast1, yourlast2, program, tmp.thens);
		}
		else{
			return play(mylast1, mylast2, yourlast1, yourlast2, program, tmp.elses);
		}
	}
	else{
		return program[pos];
	}
}

void compete(int ap, int bp, int& as, int& bs){
	if (ap == 0){
		if (bp == 0){
			as++;
			bs++;
		}
		else{
			as -= 2;
			bs += 2;
		}

	}
	else{
		if (bp == 0){
			as += 2;
			bs -= 2;
		}
		else{
			as--;
			bs--;
		}
	}
}

void run(int a, int b){

	int A_score, B_score;
	A_score = B_score = 0;
	int Alist1, Alist2, Blist1, Blist2;
	Alist1 = Alist2 = Blist1 = Blist2 = -1;
	for (int k = 0; k < 10; ++k){
		if (a == 0 && b == 2 && k == 2){
			int t = 0;
		}
		int a_play = GetCommand(play(Alist1, Alist2, Blist1, Blist2, vs[a], 0));
		int b_play = GetCommand(play(Blist1, Blist2, Alist1, Alist2, vs[b], 0));
		compete(a_play, b_play, A_score, B_score);
		Alist2 = Alist1;
		Alist1 = a_play;
		Blist2 = Blist1;
		Blist1 = b_play;
	}

	final_score[a] += A_score;
	final_score[b] += B_score;
}




int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	string s, tmp;
	while (getline(in, s) && s != "#"){
		while (s.back() != '.'){
			getline(in, tmp);
			s += tmp;
		}
		vs.push_back(clearStr(s));
	}
	for (int i = 0; i < vs.size(); ++i)
	for (int j = i + 1; j < vs.size(); ++j){
		run(i, j);
	}

	for (int i = 0; i < vs.size(); ++i)
		printf("%3d\n", final_score[i]);



	return 0;
}