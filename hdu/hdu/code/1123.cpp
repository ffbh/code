#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <stack>
using namespace std;
struct Node{
	bool add, sub, mul, div, remove;
	Node(){
		add = sub = mul = div = remove = 0;
	}
};
char s[300];
int e[300];

bool Ljudge(Node& node,char op){
	bool f = 0;
	switch (op){
	case '+':
	case '(':
		f = 1;
		break;
	case '-':
		f = (node.sub == 0 && node.add == 0);
		break;
	case '*':
		f = (node.add == 0 && node.sub == 0);
		break;
	case '/':
		f = (node.add == 0 && node.sub == 0 && node.div == 0 && node.mul == 0);
		break;
	}
	return f;
}

bool Rjudge(Node& node, char op){
	bool f = 0;
	switch (op){
	case '+':
	case ')':
	case '-':
		f = 1;
		break;
	case '*':
	case '/':
		f = (node.add == 0 && node.sub == 0);
		break;
	}
	return f;


}

Node DFS(int l,int r){
	Node node;
	for (int i = l + 1; i <= r - 1; ++i){
		switch (s[i]){
		case '+':
			node.add = 1;
			break;
		case '-':
			node.sub = 1;
			break;
		case '*':
			node.mul = 1;
			break;
		case '/':
			node.div = 1;
			break;
		case '(':
			Node son = DFS(i, e[i]);
			i = e[i];
			if (son.remove){
				if (son.add)
					node.add = 1;
				if (son.sub)
					node.sub = 1;
				if (son.mul)
					node.mul = 1;
				if (son.div)
					node.div = 1;
			}
			break;
		}
	}
	char lop, rop;
	if (l - 1 < 0 || s[l - 1] == '(')
		lop = '+';
	else
		lop = s[l - 1];

	if (s[r + 1] == 0  || s[r + 1] == ')')
		rop = '+';
	else
		rop = s[r + 1];

	if (Ljudge(node, lop) && Rjudge(node, rop)){
		node.remove = 1;
		s[l] = s[r] = ' ';
	}
	return node;
}

void Init(){

	memset(e, -1, sizeof(e));
	stack<int> si;
	for (int i = 0; s[i]; ++i){
		if (s[i] == '('){
			si.push(i);
		}
		else if (s[i] == ')'){
			e[si.top()] = i;
			si.pop();
		}
	}
}


int main(){
	ifstream in("C:\\input.txt");
	int T;
//	cin >> T;
	scanf("%d", &T);
	getchar();
	while (T--){
	//	cin >> s;
		gets(s);
		Init();
		for (int i = 0;s[i]; ++i){
			if (s[i] == '(')
				DFS(i, e[i]);
		}
		for (int i = 0; s[i]; ++i){
			if (s[i] != ' ')
			putchar(s[i]);
		}
		cout << endl;
	}
	return 0;
}