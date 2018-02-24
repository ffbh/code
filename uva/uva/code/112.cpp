#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
string str;
int N;
int e[100010];
struct Node{
	int val, l, r;
}data[100010];
int size;

int build(int l,int r){
	l++;
	r--;
	if (r < l){
		return -1;
	}
	int pos = l;
	bool nega = 0;
	int val = 0;
	if (str[pos] == '-'){
		nega = 1;
		pos++;
	}
	while (isdigit(str[pos])){
		val = val * 10 + str[pos] - '0';
		pos++;
	}
	if (nega)
		val = -val;
	int now = size++;
	data[now].val = val;
	data[now].l = build(pos, e[pos]);
	pos = e[pos] + 1;
	data[now].r = build(pos, e[pos]);
	return now;
}

bool dfs(int p,int sum){
	sum += data[p].val;
	if (data[p].l == -1 && data[p].r == -1){
		return sum == N;
	}
	if (data[p].l != -1&& dfs(data[p].l, sum) || data[p].r != -1 && dfs(data[p].r,sum))
		return 1;
	return 0;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	while (in >> N){
		str = "";
		int lf = 0;
		char c;
		while ((c = in.get())){
			if (c == ' ' || c=='\n'||c=='\t')
				continue;
			str += c;
			if (c == '('){
				lf++;
			}
			else if(c == ')'){
				lf--;
				if (lf == 0)
					break;
			}

		}
		stack<int> si;
		for (int i = 0; i < str.length(); ++i){
			if (str[i] == '('){
				si.push(i);
			}
			else if (str[i] == ')'){
				e[si.top()] = i;
				si.pop();
			}

		}
		if (str.length() == 2){
			cout << "no" << endl;
		}
		else{
			size = 1;
			build(0, e[0]);
			if (dfs(1,0)){
				cout << "yes" << endl;
			}
			else{
				cout << "no" << endl;
			}

		}


	}
















	return 0;
}