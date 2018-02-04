#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
string word[110];
bool W[110][30];
bool team[3][30];//0 wu ,1 + ,2 -
int size;

void  handlestring(string& s){
	memset(team, 0, sizeof(team));
	int f = 0;
	for (int i = 0; i < s.length(); ++i){
		if (s[i] == '+')
			f = 1;
		else if (s[i] == '-')
			f = 2;
		if (s[i] >= 'a'&&s[i] <= 'z'){
			team[f][s[i] - 'a'] = 1;
			f = 0;
		}
	}
}

void show(){
	for (int i = 0; i < 30;++i)
	if (team[0][i])
		cout << char('a' + i);
	cout << endl;
	for (int i = 0; i < 30; ++i)
	if (team[1][i])
		cout << char('a' + i);
	cout << endl;
	for (int i = 0; i < 30; ++i)
	if (team[2][i])
		cout << char('a' + i);
	cout << endl;


}

void showW(){
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < 30; ++j)
		if (W[i][j])
			cout << char('a' + j);
		cout << endl;
	}


}
int  judge(string& s){
	handlestring(s);
	for (int i = 0; i < size; ++i){
		bool f = 0;
		for (int j = 0; j < 30;++j)
		if (team[0][j] && W[i][j]){
			f = 1;
			break;
		}
		if (f == 0)
			continue;
		f = 0;
		for (int j = 0; j < 30;++j)
		if (team[1][j] && !W[i][j]){
			f = 1;
			break;
		}
		if (f == 1)
			continue;
		f = 0;
		for (int j = 0; j < 30;++j)
		if (team[2][j] && W[i][j]){
			f = 1;
			break;
		}
		if (f == 1)
			continue;
		return i;
	}
	return 99999;
}

int main(){
	//ifstream in("C:\\temp.txt");
    stringstream ss;
	while (1){
		memset(W, 0, sizeof(W));
		getline(cin, word[0]);
		if (word[0] == "#")
			break;
		
		for (size = 0; word[size] != "*";){
			size++;
			getline(cin, word[size]);
		}
		sort(word, word + size);
		for (int i = 0; i < size; ++i)
		for (int j = 0; j < word[i].size(); ++j)
			W[i][word[i][j] - 'a'] = 1;
		string match;
		while (getline(cin, match)&&match != "**"){
			vector<string> vs;
			for (int i = 0; i < match.length(); ++i){
				if (match[i] == '|')
					match[i] = ' ';

			}
			ss.clear();
			ss.str(match);
			string tmp;
			while (ss >> tmp)
				vs.push_back(tmp);
			int ans = 99999;
			for (int i = 0; i < vs.size(); ++i){
				int ret = judge(vs[i]);
				if (ret < ans)
					ans = ret;
			}
			if (ans == 99999)
				cout << "NONE" << endl;
			else
				cout << word[ans] << endl;
		}
		cout << "$" << endl;
	}

	return 0;
}