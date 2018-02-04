#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;
struct Node{
	map<string, Node*> msn;
	set<string> ss;
	void dfs(int dept){
		map<string, Node*>::iterator it = msn.begin();
		while (it != msn.end()){
			for (int i = 0; i < dept; ++i)
				printf("    ");
			printf("%s\n", it->first.c_str());
			it->second->dfs(dept + 1);
			it++;
		}
		set<string>::iterator it2= ss.begin();
		while (it2 != ss.end()){
			for (int i = 0; i < dept; ++i)
				printf("    ");
			printf("%s\n", (*it2).c_str());
			it2++;
		}
	}
};


int main(){
	ifstream in("C:\\input.txt");
	Node* root = new Node();
	string s;
	vector<string> vs;
	int CASE = 1;
	while (getline(in,s)){
		if (s == "0"){
			printf("Case %d:\n", CASE++);
			root->dfs(0);
			delete root;
			root = new Node();
		}
		else{
			vs.clear();
			int a = 0, b;
			while (a < s.length()){
				for (b = a; b < s.length(); ++b){
					if (s[b] == '/')
						break;
				}
				vs.push_back(s.substr(a, b - a));
			//	cout << s.substr(a, b - a) << endl;
				a = b + 1;
			}
			Node* now = root;
			for (int i = 0; i < vs.size() - 1; ++i){
				if (now->msn.count(vs[i])){
					now = now->msn[vs[i]];
				}
				else{
					Node* Q = new Node();
					now->msn[vs[i]] = Q;
					now = Q;
				}
			}
			now->ss.insert(vs.back());
		}
	}
















	return 0;
}