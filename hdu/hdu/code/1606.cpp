#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;
struct Node{
	string s;
	int v;
	int index;
	bool operator<(const Node& p)const{
		if (v == p.v)
			return index < p.index;
		return v>p.v;
	}
};
Node num[50];

void fun(string& s){
	int len = s.length();
	for (int i = 0; i < len;++i)
	if (s[i] >= 'A'&&s[i] <= 'Z')
		s[i] += 32;
	else if (s[i]<'a' || s[i]>'z')
		s[i] = ' ';
}


int main(){
//	ifstream in("C:\\temp.txt");
	int N, M;
	stringstream ss;
	string s;
	int CASE = 1;
	while (cin >> N >> M){
		getchar();
	//	getline(in, s);
		
		set<string> si;
		while (N--){
			getline(cin, s);
			si.insert(s);
		}
		for (int i = 0; i < M; ++i){
			getline(cin, s);
			int v = 0;
			num[i].s = s;
			num[i].index = i;
			fun(s);
			ss.clear();
			ss.str(s);
			
			while (ss >> s)
			if (si.count(s))
				v++;
			num[i].v = v;
		}
		sort(num, num + M);
		int mmax = num[0].v;
		printf("Excuse Set #%d\n", CASE++);
		for (int i = 0;; ++i)
		if (num[i].v == mmax)
			cout << num[i].s << endl;
		else break;
		cout << endl;
	}

	return 0;
}