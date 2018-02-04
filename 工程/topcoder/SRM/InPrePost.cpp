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
#define DEBUG (0)


class InPrePost {
public:
	vector<string> code;
	bool judge(vector<int> a, vector<int> b, vector<int> c){
		if (a.size() != b.size() || a.size() != c.size() || b.size() != c.size())
			return 0;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());
		for (int i = 0; i < a.size(); ++i){
			if (a[i] != b[i] || a[i] != c[i])
				return 0;
		}
		return 1;
	}

	int getIndex(string& s){
		if (s == "pre")
			return 0;
		else if (s == "in")
			return 1;
		else
			return 2;
	}

	bool dfs(vector<int> a, vector<int> b, vector<int> c){
		if (a.size() == 0 && b.size() == 0 && c.size() == 0)
			return 1;
		if (!judge(a, b, c))
			return 0;
		int root = a[0];
		if (c.back() != root)
			return 0;
		int len = -1;
		for (int i = 0; i < b.size(); ++i){
			if (b[i] == root){
				len = i;
				break;
			}
		}
		int L_len = len;;
		vector<int> L[3], R[3], tmpL, tmpR;
		int pos;
		


		tmpL.clear();
		tmpR.clear();
		pos = 0;
		while (pos < a.size()){
			if (pos == 0){
				pos++;
				continue;
			}
			if (tmpL.size() < L_len){
				tmpL.push_back(a[pos]);
			}
			else{
				tmpR.push_back(a[pos]);
			}
			pos++;
		}
		L[getIndex(code[0])] = tmpL;
		R[getIndex(code[1])] = tmpR;

		tmpL.clear();
		tmpR.clear();
		pos = 0;
		while (pos < b.size()){
			if (pos == len){
				pos++;
				continue;
			}
			if (tmpL.size() < L_len){
				tmpL.push_back(b[pos]);
			}
			else{
				tmpR.push_back(b[pos]);
			}
			pos++;
		}
		L[getIndex(code[2])] = tmpL;
		R[getIndex(code[3])] = tmpR;

		tmpL.clear();
		tmpR.clear();
		pos = 0;
		while (pos < c.size()){
			if (pos == c.size()-1){
				pos++;
				continue;
			}
			if (tmpL.size() < L_len){
				tmpL.push_back(c[pos]);
			}
			else{
				tmpR.push_back(c[pos]);
			}
			pos++;
		}
		L[getIndex(code[4])] = tmpL;
		R[getIndex(code[5])] = tmpR;

		return dfs(L[0], L[1], L[2]) && dfs(R[0], R[1], R[2]);

	}


	string isPossible(vector <string> s, vector <int> a1, vector <int> a2, vector <int> a3) {
		code = s;
		if (dfs(a1, a2, a3))
			return "Possible";
		else
			return "Impossible";

	}
};



#if 0
int main(){
	vector<string> p({ "post", "in", "pre", "post", "in", "pre" });
	vector<int> a({ 1, 2, 3, 4, 5 });
	vector<int> b({ 2, 1, 3, 5, 4 });
	vector<int> c({ 2, 4, 3, 5, 1 });

	InPrePost so;
	cout<<so.isPossible(p,a,b,c)<<endl;
















	return 0;
}
#endif

