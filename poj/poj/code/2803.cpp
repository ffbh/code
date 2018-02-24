#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
string s;
int p, sf;
string pre[] = { "anti", "post", "pre", "re", "un" };
string suf[] = { "er", "ing", "ize", "s", "tion" };
void getPF(){
	p = sf = -1;
	for (int i = 0; i < 5; ++i){
		bool f = 1;
		int j;
		for (j = 0; j<s.length()&&j < pre[i].size(); ++j)
		if (s[j] != pre[i][j]){
			f = 0;
			break;
		}
		if (j < pre[i].length())
			f = 0;
		if (f){
			p = i;
			s = s.substr(pre[i].length());
			break;
		}
	}

	for (int i = 0; i < 5; ++i){
		bool f = 1;
		int j, k = suf[i].length() - 1;
		for (j = s.length() - 1; j >= 0 && k >= 0; --j,k--)
		if (s[j] != suf[i][k]){
			f = 0;
			break;
		}
		if (k >= 0){
			f = 0;
		}
		if (f){
			sf = i;
			s = s.substr(0, s.length() - suf[i].length());
			break;
		}
	}
}


int main(){
	ifstream in("C:\\input.txt");
	int T;
	in >> T;
	string start, end;
	while (T--){
		bool k = 0;
		start = end = "";
		in >> s;
		getPF();
		switch (p){
		case 0:
			start += "against ";
			break;
		case 1:
			start += "after ";
			break;
		case 2:
			start += "before ";
			break;
		case 3:
			end += " again";
			k = 1;
			break;
		case 4:
			start += "not ";
			break;
		}
		switch (sf){
		case 0:
			start += "one who ";
			if (k)
				end = "s" + end;
			else
				end += "s";
			break;
		case 1:
			start += "to actively ";
			break;
		case 2:
			start += "change into ";
			break;
		case 3:
			start += "multiple instances of ";
			break;
		case 4:
			start += "the process of ";
			if (k)
				end = "ing" + end;
			else
				end += "ing";
			break;
		}
		cout << start << s << end << endl;
	}
	return 0;
}