#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;
#define MAXSIZE (26)
struct Node{
	int next[MAXSIZE];
	int count;
	int pre;
	char c;
}data[500010];
int size, root;
string map[10] = {
	"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};
int MALLOC(){
	for (int i = 0; i < MAXSIZE; ++i)
		data[size].next[i] = -1;
	data[size].count = 0;
	data[size].pre = -1;
	return size++;
}

void Insert(string& s, int v){
	int p = root;
	for (int i = 0; i < s.length(); ++i){
		if (data[p].next[s[i] - 'a'] == -1){
			data[p].next[s[i] - 'a'] = MALLOC();
			data[data[p].next[s[i] - 'a']].pre = p;
			data[data[p].next[s[i] - 'a']].c = s[i];
		}
		p = data[p].next[s[i] - 'a'];
		data[p].count += v;
	}
}
string ss;
int Max, index;
void search(int pos, int p){
	if (p == -1)
		return;
	if (pos == ss.length()){
		if (data[p].count > Max){
			Max = data[p].count;
			index = p;
		}
	}
	int u = ss[pos] - '0';
	for (int j = 0; j < map[u].length(); ++j){
		int tmp = data[p].next[map[u][j] - 'a'];
		search(pos + 1, tmp);
	}
}



int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		size = 0;
		root = MALLOC();
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i){
			string s;
			int v;
			cin >> s >> v;
			Insert(s, v);
		}
		int M;
		cin >> M;
		printf("Scenario #%d:\n", CASE++);
		while (M--){
			string temp;
			cin >> temp;
			for (int i = 0; temp[i] != '1'; ++i){////////
				Max = index = -1;
				ss = temp.substr(0, i + 1);
				search(0, root);
				if (Max == -1)
					printf("MANUALLY\n");
				else{
					stack<char> qn;
					while (index > 0){
						qn.push(data[index].c);
						index = data[index].pre;
					}
					while (!qn.empty()){
						putchar(qn.top());
						qn.pop();
					}
					cout << endl;
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}