#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
struct Node{
	int x, y;
	Node(){
		x = y = 0;
	}
	bool operator<(const Node& p)const{
		if (x != p.x)
			return x>p.x;
		else
			return y < p.y;
	}
	bool operator==(const Node& p)const{
		return x == p.x&&y == p.y;
	}
};

struct Express{
	int x, y, c;
};
vector<Express> A, B;

bool eend(char c){
	return c == '+' || c == '-';
}

void cale(string& s, vector<Express>& data ){
	int pos = 0;
	while (pos < s.length()){
		int sign = 1;
		if (s[pos] == '-'){
			sign = -1;
			pos++;
		}
		if (s[pos] == '+')
			pos++;
		Express tmp;
		int  biaoji;

			tmp.x = tmp.y = tmp.c = 0;
			while (pos < s.length() && isdigit(s[pos])){
				tmp.c = tmp.c * 10 + s[pos] - '0';
				pos++;
			}
			if (tmp.c == 0){
				tmp.c = 1;
			}
			tmp.c = tmp.c*sign;
			if (s[pos] == 'x'){
				biaoji = 1;
				pos++;
			}
			else if(s[pos]=='y'){
				biaoji = 2;
				pos++;
			}
			else{
				biaoji = 3;
			}

			if (biaoji == 1){
				while (pos < s.length() && isdigit(s[pos])){
					tmp.x = tmp.x * 10 + s[pos] - '0';
					pos++;
				}
				if (tmp.x == 0)
					tmp.x = 1;
				if (pos < s.length() && s[pos] == 'y'){
					pos++;
					while (pos < s.length() && isdigit(s[pos])){
						tmp.y = tmp.y * 10 + s[pos] - '0';
						pos++;
					}
					if (tmp.y == 0)
						tmp.y = 1;
				}
			}
			else if (biaoji == 2){
				while (pos < s.length() && isdigit(s[pos])){
					tmp.y = tmp.y * 10 + s[pos] - '0';
					pos++;
				}
				if (tmp.y == 0)
					tmp.y = 1;

				if (pos < s.length() && s[pos] == 'x'){
					pos++;
					while (pos < s.length() && isdigit(s[pos])){
						tmp.x = tmp.x * 10 + s[pos] - '0';
						pos++;
					}
					if (tmp.x == 0)
						tmp.x = 1;
				}
			}

			data.push_back(tmp);
		
	}
}

string s1, s2;
map<Node, int> ans;

string build;
string Get(int c){
	string b = "";
	while (c){
		b += char(c%10 + '0');
		c /= 10;
	}
	reverse(b.begin(), b.end());
	return b;
}

string change(Node p,int c){
	c = abs(c);
	if (p.x == 0 && p.y == 0){
		return Get(c);
	}

	string ret = "";
	string b = Get(c);
	if (c != 1){
		ret += b;
	}
	if (p.x){
		ret += 'x';
		if (p.x != 1){
			ret += Get(p.x);
		}
	}
	if (p.y){
		ret += 'y';
		if (p.y != 1){
			ret += Get(p.y);
		}
	}
	return ret;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	while (getline(in, s1) && s1 != "#"){
		getline(in, s2);
		A.clear();
		B.clear();
		ans.clear();

		cale(s1, A);
		cale(s2, B);
		for (int i = 0; i < A.size();++i)
		for (int j = 0; j < B.size(); ++j){
			Node tmp;
			tmp.x = A[i].x + B[j].x;
			tmp.y = A[i].y + B[j].y;
			int c = A[i].c*B[j].c;
			ans[tmp] += c;
		}
		
	

		build = "";
		map<Node, int>::iterator it = ans.begin();
		while (it != ans.end()){
			if (it->second != 0){
				if (it == ans.begin()){
					if (it->second < 0)
						build += '-';
					build += change(it->first, it->second);
				}
				else{
					if (it->second > 0){
						build += " + ";
					}
					else{
						build += " - ";
					}

					build += change(it->first, it->second);
				}


			}
			it++;
		}

		
		string coef(build.size(), ' ');
		int pos = 0;
		while (pos < build.size()){
			while (pos < build.size() && build[pos] != 'x' && build[pos] != 'y')
				pos++;
			if (pos < build.size()){
				pos++;
				while (pos < build.size() && isdigit(build[pos])){
					swap(build[pos], coef[pos]);
					pos++;
				}

			}


		}
		cout << coef << endl;
		cout << build << endl;

	}

	














	return 0;
}