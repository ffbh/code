#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;
string err[5] = { "",
"Division By Zero", "Type Mismatch", "Unbound Identifier"
};
int e[210];
string s;
int T;
#define EDBZ (1)
#define ETM (2)
#define EUI (3);
struct Node{
	unsigned int l, r;
	Node(unsigned int a=0, int b=0){
		l = a;
		r = b;
	}
};
struct S{
	int val;
	bool b;
	int error;
	S(){
		val = 0;
		b = 0;
		error = 0;
	}
};
map<string, S> varible[50];
Node nextNode(int& pos){
	Node ret;
	while (s[pos] == ' ')pos++;
	ret.l = pos;
	if (s[pos] == '('){
		ret.r = e[pos];
		pos = ret.r + 1;
	}
	else{
		while (s[pos] != ' ') pos++;
		ret.r = pos - 1;
	}
	return ret;
}




void InitE(){
	memset(e, -1, sizeof(e));
	stack<int> si;
	for (unsigned int i = 0; i < s.length(); ++i){
		if (s[i] == '(')
			si.push(i);
		else if(s[i]==')'){
			e[si.top()] = i;
			si.pop();
		}
	}
}
S  CaleS(Node& region, int dept);
int BoundVarible(Node& region, int dept){
	int pos = region.l;
	while (s[pos] == ' ')pos++;
	if (s[pos] != '('){
		cout << "errot" << endl;///////////
	}
	pos++;
	Node tname = nextNode(pos);
	string name = s.substr(tname.l, tname.r - tname.l + 1);
	Node A = nextNode(pos);
	S p = CaleS(A, dept + 1);
	if (p.error)
		return p.error;
	varible[dept][name] = p;
	return 0;
}


void UnBoundVarible(int dept){
	varible[dept].clear();
}

S  CaleS(Node& region,int dept){
	int pos = region.l;
	while (s[pos] == ' ')pos++;
	if (s[pos] == '('){//处理()
		S ret;
		pos++;
		while (s[pos] == ' ') pos++;
		if (s[pos] == '+' || s[pos] == '-' || s[pos] == '*' || s[pos] == '/'){
			char op = s[pos];
			pos++;
			Node A = nextNode(pos);

			Node B = nextNode(pos);


			S p1 = CaleS(A,dept+1);////////////
			if (p1.error){
				return p1;
			}
			S p2 = CaleS(B,dept+1);/////////////
			if (p2.error){
				return p2;
			}
			if (p1.b || p2.b){
				ret.error = ETM;
				return ret;
			}
			else{
				ret.b = 0;
				switch (op){
				case '+': 
					ret.val = p1.val + p2.val;
					break;
				case '-': 
					ret.val = p1.val - p2.val;
					break;
				case '*': 
					ret.val = p1.val * p2.val;
					break;
				case '/':
					if (p2.val == 0){
						ret.error = EDBZ;
						return ret;
					}
					ret.val = p1.val / p2.val;
					break;
				}
				return ret;
			}
		}
		else if (s[pos] == '<' || s[pos] == '>' || s[pos] == '='){
			char op = s[pos];
			pos++;
			Node A = nextNode(pos);

			Node B = nextNode(pos);

			S p1 = CaleS(A,dept+1);//////////
			if (p1.error){
				return p1;
			}
			S p2 = CaleS(B,dept+1);//////////
			if (p2.error){
				return p2;
			}
			if (p1.b || p2.b){
				ret.error = ETM;
				return ret;
			}
			else{
				ret.b = 1;
				switch (op){
				case '>':
					ret.val = p1.val > p2.val;
					break;
				case '<':
					ret.val = p1.val < p2.val;
					break;
				case '=':
					ret.val = p1.val == p2.val;
					break;
				}
				return ret;
			}
		}
		else{//other mission
			Node reserve = nextNode(pos);
			string name = s.substr(reserve.l, reserve.r - reserve.l + 1);
			if (name == "if"){///////if
				Node A = nextNode(pos);
				S p1 = CaleS(A,dept+1);///////////
				if (p1.error){
					return p1;
				}
				if (!p1.b){
					ret.error = ETM;
					return ret;
				}
				else{
					Node B = nextNode(pos);
					Node C = nextNode(pos);
					if (p1.val){
						ret = CaleS(B,dept+1);
					}
					else
						ret = CaleS(C,dept+1);
					return ret;
				}
			}
			else{///////let
				Node XA = nextNode(pos);
				ret.error = BoundVarible(XA, dept);
				if (ret.error){
					return ret;
				}
				Node B = nextNode(pos);
				ret = CaleS(B, dept + 1);
				UnBoundVarible(dept);
				return ret;
			}
		}
	}
	else{//处理atom
		S ret;
		if (s[pos] >= '0'&&s[pos] <= '9'){
			ret.b = 0;
			while (s[pos] >= '0'&&s[pos] <= '9'){
				ret.val = ret.val * 10 + s[pos] - '0';
				pos++;
			}
			return ret;
		}
		else {
			int End = pos;
			while (s[End]>='a' && s[End]<='z') End++;
			string name = s.substr(pos, End - pos);
			if (name == "true" || name == "false"){
				ret.b = 1;
				ret.val = name == "true";
				return ret;
			}
			else{//bound   map 
				for (int k = dept - 1; k >= 0; --k){
					if (varible[k].count(name))
						return varible[k][name];
				}
				ret.error = EUI;
				return ret;

			}
		}
	}
}


int main(){
	ifstream in("C:\\input.txt");
	cin >> T;
	cin.get();
	
	while (T--){
		getline(cin, s);
		for (int i = 0; i < 50; ++i)
			varible[i].clear();
		InitE();
		Node t;
		t.l = 0;
		t.r = s.length() - 1;
		S ans = CaleS(t,1);
		if (ans.error){
			cout << err[ans.error] << endl;
		}
		else{
			if (ans.b){
				if (ans.val)
					cout << "true" << endl;
				else
					cout << "false" << endl;
			}
			else
				cout << ans.val << endl;
		}

	}






	return 0;
}