#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;
#define VAL(k) (((long long)1<<k))
//unordered_map<long long, int> mmp;
vector<string> all;
int N;
void cale(string& s,string& p,int pian){
	if (pian + p.length() > s.length())
		return;
	string key = "";
	for (int i = 0; i < pian; ++i)
		key += '0';
	for (int i = 0; i < p.length(); ++i){

		switch (p[i]){
		case '0':
			key += '1';
			break;
		case '1':
			if (s[i + pian] == 'b'){
				key += '2';
			}
			else{
				key += '1';
			}
			break;
		case '2':
			if (s[i + pian] == 'a'){
				key += '2';
			}
			else{
				key += '1';
			}

			break;
		case '3':
			key += '2';
			break;
		}
	}

	for (int i = p.length() + pian; i < s.length(); ++i)
		key += '0';
	all.push_back(key);
}
struct Node{
	string p;
	int num, idx;
};




int bfs(){
	queue<Node> qn;
	Node st;
	st.p = string(N, '0');
	st.num = 0;
	st.idx = 0;
	qn.push(st);
	int ans = 0;
	while (!qn.empty()){
		if (qn.size() > 10000){
			int t = 0;
		}
		Node u = qn.front();
		qn.pop();
		if (u.idx == all.size()){
			ans = max(ans, u.num);
			continue;
		}
		string& p = all[u.idx];
		int f1 = 0, f2 = 1;
		for (int i = 0; i < N; ++i){
			if ((u.p[i] == '0' && p[i] != '0') || (u.p[i] != '0' && p[i] == '0')){
				f1 = 1;
			}
			if ((u.p[i] == '1'&&p[i] == '2') || (u.p[i] == '2'&&p[i] == '1')){
				f2 = 0;
				break;
			}
		}

		if (f2 == 0){
			u.idx++;
			qn.push(u);
		}
		else{
			if (f1 == 0){
				u.num++;
				u.idx++;
				qn.push(u);
			}
			else{
				u.idx++;
				qn.push(u);
				for (int i = 0; i < N; ++i){
					if (p[i] != '0'){
						u.p[i] = p[i];
					}
				}
				u.num++;
				qn.push(u);
			}
		}
	}

	return ans;

}



class Softmatch {
public:
	int count(string S, vector <string> patterns) {
		N = S.length();

		for (int i = 0; i < patterns.size(); ++i){
			for (int j = 0; j < S.length(); ++j){
				cale(S, patterns[i], j);
			}
		}
	
		return bfs();
		
		

	}
};



#if 1
int main(){
	




	vector<string> p({ "3" });
	Softmatch so;
	cout<<so.count("aaaababbbbabbaabaababbabab",p)<<endl;


	return 0;
}
#endif




