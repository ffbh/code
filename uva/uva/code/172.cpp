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
int var[266];
int nowvar[266];
int e[110];
struct Node{
	int val;
	char op, var;
	int type;//1 val   2 op    3 var    4 null   5  (
};

Node getNext(int& pos,int r){
	Node ret;
	while (pos <= r && str[pos] == ' ')
		pos++;
	if (pos > r){
		ret.type = 4;
	}
	else{
		if (isupper(str[pos])){
			ret.type = 3;
			ret.var = str[pos];
			pos++;
		}
		else if (str[pos] == '+' || str[pos] == '-' || str[pos] == '*' || str[pos] == '/' || str[pos] == '='){
			ret.op = str[pos];
			ret.type = 2;
			pos++;
		}
		else if (str[pos] == '('){
			ret.type = 5;
		}
		else{
			ret.type = 1;
			int nega = 1;
			if (str[pos] == '_'){
				nega = -1;
				pos++;
				while (pos <= r && str[pos] == ' ')
					pos++;
			}
			ret.val = 0;
			while (pos <= r && isdigit(str[pos])){
				ret.val = ret.val * 10 + str[pos] - '0';
				pos++;
			}
			ret.val = ret.val*nega;
		}
	}
	return ret;
}

int GETVAL(Node& p){
	if (p.type == 1){
		return  p.val;
	}
	else{
		return  nowvar[p.var];
	}
}

Node cale(int l,int r){
	Node ans;
	ans.type = 1;
	ans.val = 0;
	int pos = l;
	stack<Node> ss;
	while (pos <= r){
		Node ret = getNext(pos,r);
		if (ret.type == 5){
			ret = cale(pos + 1, e[pos] - 1);
			pos = e[pos] + 1;
		}
		ss.push(ret);
	}
	if (ss.empty()){
		return ans;
	}
	Node a, op, b;
	b = ss.top();
	ss.pop();
	while (!ss.empty()){
		op = ss.top();
		ss.pop();
		a = ss.top();
		ss.pop();
		int aval = GETVAL(a);
		int bval = GETVAL(b);
		switch (op.op){
		case '=':
			nowvar[a.var] = bval;
			break;
		case '+':
			bval = aval + bval;
			break;
		case '-':
			bval = aval - bval;
			break;
		case '*':
			bval = aval * bval;
			break;
		case '/':
			bval = aval / bval;
			break;
		}
		b.type = 1;
		b.val = bval;

	}
	ans.val = b.val;
	return ans;
}



int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	while (getline(in, str) && str!="#"){
		stack<int> ss;
		for (int i = 0; i < str.length(); ++i){
			if (str[i] == '('){
				ss.push(i);
			}
			else if (str[i] == ')'){
				e[ss.top()] = i;
				ss.pop();
			}
		}
		cale(0, str.length() - 1);
		bool change = 0;
		for (char c = 'A'; c <= 'Z'; ++c){
			if (nowvar[c] != var[c]){
				var[c] = nowvar[c];
				if (change){
					printf(", %c = %d", c, var[c]);
				}
				else{
					change = 1;
					printf("%c = %d", c, var[c]);
				}
			}
		}
		if (!change){
			cout << "No Change";
		}
		cout << endl;



	}
















	return 0;
}