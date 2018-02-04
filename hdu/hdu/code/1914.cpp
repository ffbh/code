#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
//ifstream in("C:\\temp.txt");
map<char, int> mc1, mc2;
map<char, char> res;
int data1[30][30], data2[30][30];
char m1[30], m2[30];
int value[30][30];
int link[30];
int C[30];
void Init(int n){
	char c;
	int id = 1;
	for (int i = 0; i < n; ++i){
		cin >> c;
		m1[id] = c;
		mc1[c] = id++;
	}
	id = 1;
	for (int i = 0; i < n; ++i){
		cin >> c;
		m2[id] = c;
		mc2[c] = id++;
	}
}



int main(){
	int T;
	cin >> T;
	int N;
	int ok = 0;
	while (T--){
		if (ok)cout << endl;
		ok = 1;
		cin >> N;
		for (int i = 0; i < 30; ++i){
			C[i] = 1;
			link[i] = 30;
			value[i][30] = 30;
		}
		mc1.clear();
		mc2.clear();
		res.clear();
		Init(N);
		for (int i = 1; i <= N; ++i){
			string s;
			cin >> s;
			int index = mc1[s[0]];
			for (int j = 2; j < s.length(); ++j)
				data1[index][j - 1] = mc2[s[j]];
		}
		for (int i = 1; i <= N; ++i){
			string s;
			cin >> s;
			int index = mc2[s[0]];
			for (int j = 2; j < s.length(); ++j)
				data2[index][j - 1] = mc1[s[j]];
		}
		for (int i = 1; i <= N; ++i){
			int v = 1;
			for (int j = 1; j <= N; ++j)
				value[i][data2[i][j]] = v++;
		}
		stack<int> si;
		for (int i = 1; i <= N; ++i)
			si.push(i);
		while (!si.empty()){
			int top = si.top();
			si.pop();
			while(C[top]<=N){
				int girl = data1[top][C[top]];
				if (link[girl] == top)
					break;
				else if (value[girl][top] < value[girl][link[girl]]){
					if (link[girl] < 28)
						si.push(link[girl]);
					link[girl] = top;
					break;
				}
				else
					C[top]++;
			}
		}
		for (int i = 1; i <= N; ++i)
			res[m1[link[i]]] = m2[i];
		map<char, char>::iterator it = res.begin();
		while (it != res.end()){
			printf("%c %c\n", it->first, it->second);
			it++;
		}
	}
	return 0;
}