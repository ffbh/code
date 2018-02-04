#include <iostream>
//#include <fstream>
#include <map>
#include <stack>
#include <string>
using namespace std;
struct node{
	int left, right;
};
stack<string> sc;
map<string, node> mcn;
int N;
int ans;

bool fun(const string& c){
	string tc = sc.top();
	node n1 = mcn[tc];
	node n2 = mcn[c];
	if (n1.right != n2.left)
		return false;
	else
		ans += n1.left*n1.right*n2.right;
	node n3;
	n3.left = n1.left;
	n3.right = n2.right;
	string s = tc + c;
	mcn[s] = n3;
	sc.pop();
	sc.push(s);
	return true;
}
int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	cin >> N;
	string c;
	node nn;
	for (int i = 0; i < N; ++i){
		cin >> c >> nn.left >> nn.right;
		mcn[c] = nn;
	}
	while (cin >> s){
		ans = 0;
		int len = s.length();
		bool flag = 1;
		for (int i = 0; i < len; ++i){
			if (s[i] == '(' )
				sc.push(s.substr(i,1));
			else if (s[i] == ')'){
				if (sc.top() == "(")
					sc.pop();
				else{
					string t = sc.top();
					sc.pop();
					sc.pop();
					if (!sc.empty()&&sc.top() != "("){
						flag = fun(t);
						if (!flag)
							break;
					}
					else
						sc.push(t);
				}
			}
			else{
				if (sc.empty()||sc.top() == "(")
					sc.push(s.substr(i, 1));
				else{
					flag = fun(s.substr(i, 1)); 
					if (!flag)
						break;
				}
			}
				
			
			}
		if (flag)
			cout << ans << endl;
		else
			cout << "error" << endl;
		while (!sc.empty())sc.pop();
		}
		mcn.clear();
	


	return 0;
}