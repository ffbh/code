#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> msi;
string data[13] = {
	"A", "2", "3", "4", "5", "6", "7",
	"8", "9", "10", "J", "Q", "K"
};



void Init(){
	for (int i = 0; i < 13; ++i)
		msi[data[i]] = i;
}

struct Node{
	int key;
	char c;
	bool operator<(const Node& p)const{
		if (key != p.key)
			return key < p.key;
		return c < p.c;
	}
}ans[5];

bool OK(){
	if (ans[0].c != ans[1].c)
		return 0;
	Node min = ans[2];
	int minindex = 2;
	int pow1, pow2 = 0;
	for (int i = 3; i < 5;++i)
	if (ans[i] < min){
		min = ans[i];
		minindex = i;
	}
	pow1 = minindex - 1;
	if (minindex == 2){
		if (ans[4] < ans[3])
			pow2 = 3;
	}
	else if (minindex == 3){
		if (ans[4] < ans[2])
			pow2 = 3;

	}
	else{
		if (ans[3] < ans[2])
			pow2 = 3;
	}
	int k = (ans[1].key + pow1 + pow2) % 13;
	return k == ans[0].key;
}


int main(){
	ifstream in("C:\\input.txt");
	Init();
	int T;
	cin >> T;
	int CASE = 1;

	while (T--){
		for (int i = 0; i < 5; ++i){
			string s;
			cin >> s;
			ans[i].c = s[s.length() - 1];
			ans[i].key = msi[s.substr(0, s.length() - 1)];
		}
		sort(ans, ans + 5);
		while (!OK())
			next_permutation(ans, ans + 5);
		printf("Problem %d:", CASE++);
		for (int i = 0; i < 5; ++i){
			putchar(' ');
			cout << data[ans[i].key];
			cout << ans[i].c;
		}
		cout << endl;
	}
	return 0;
}