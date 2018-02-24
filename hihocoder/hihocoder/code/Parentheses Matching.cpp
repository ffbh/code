#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <stack>
using namespace std;
struct Node{
	int l, r;
	bool operator<(const Node& p)const{
		return l < p.l;
	}
}data[100010];
int size;
int main(){
	ifstream in("C:\\input.txt");
	string s;
	stack<int> si;
	cin >> s;
	size = 0;
	for (int i = 0; i < s.length(); ++i){
		if (s[i] == '(')
			si.push(i);
		else{
			data[size].l = si.top()+1;
			data[size].r = i + 1;
			size++;
			si.pop();
		}
	}
	sort(data, data + size);
	for (int i = 0; i < size; ++i){
		printf("%d %d\n", data[i].l, data[i].r);
	}

	return 0;
}