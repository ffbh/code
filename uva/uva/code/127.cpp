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
	char a, b;
	Node(char _a,char _b){
		a = _a;
		b = _b;
	}
	Node(string& s){
		a = s[0];
		b = s[1];
	}
	bool ok(Node& p){
		return a == p.a || b == p.b;
	}
};
vector<Node> vi[60];
int size;

bool judge(){
	int idx = -1;
	for (int i = 1; i <= size; ++i){
		int pre = i - 3;
		if (pre >= 1 && vi[pre].back().ok(vi[i].back())){
			vi[pre].push_back(vi[i].back());
			vi[i].pop_back();
			idx = i;
			break;
		}
		pre = i - 1;
		if (pre >= 1 && vi[pre].back().ok(vi[i].back())){
			vi[pre].push_back(vi[i].back());
			vi[i].pop_back();
			idx = i;
			break;
		}
	}
	if (idx == -1)
		return 0;
	else{
		if (vi[idx].empty()){
			for (int i = idx + 1; i <= size; ++i)
				vi[i - 1] = vi[i];
			size--;
		}
		return 1;
	}

}
int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	string s;
	while (in >> s && s!= "#"){
		for (int i = 1; i < 60; ++i)
			vi[i].clear();
		size = 52;
		vi[1].push_back(Node(s));
		for (int i = 2; i <= 52; ++i){
			in >> s;
			vi[i].push_back(Node(s));
		}

		while (judge());

		if (size == 1){
			cout << "1 pile remaining: 52" << endl;
		}
		else{
			printf("%d piles remaining:", size);
			for (int i = 1; i <= size; ++i)
				printf(" %d", vi[i].size());
			putchar('\n');
		}

	}















	return 0;
}