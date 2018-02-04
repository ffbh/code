#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
struct Node{
	int to, v;
	string name;
};
struct FF{
	string name;
	int age;
	int now;
	bool operator<(const FF& p)const{
		if (age != p.age)
			return age < p.age;
		return name>p.name;
	}
};
vector<Node> vn[210];



int main(){
	//ifstream in("C:\\temp.txt");
	map<string, int> msi;
	priority_queue<FF> pf;
	string s1, s2;
	int d;
	int T;
	cin >> T;
	int N;
	int size;
	int CASE = 1;
	while (T--){
		for (int i = 0; i < 210; ++i)
			vn[i].clear();
		while (!pf.empty())
			pf.pop();
		cin >> N;
		size = 1;
		msi.clear();
		while (N--){
			cin >> s1 >> s2 >> d;
			if (msi[s1] == 0)
				msi[s1] = size++;
			if (msi[s2] == 0)
				msi[s2] = size++;
			vn[msi[s1]].push_back(Node{ msi[s2], d ,s2});
		}
		int f = msi["Ted"];
		for (int i = 0; i < vn[f].size(); ++i){
			s2 = vn[f][i].name;
			int age = 100 - vn[f][i].v;
			int index = vn[f][i].to;
			pf.push(FF{ s2, age, index });
		}
		printf("DATASET %d\n", CASE++);
		while (!pf.empty()){
			FF temp = pf.top();
			pf.pop();
			printf("%s %d\n", temp.name.c_str(), temp.age);
			for (int i = 0; i < vn[temp.now].size(); ++i){
				s2 = vn[temp.now][i].name;
				int age = temp.age - vn[temp.now][i].v;
				int index = vn[temp.now][i].to;
				pf.push(FF{ s2, age, index });
			}
		}
	}
	return 0;
}