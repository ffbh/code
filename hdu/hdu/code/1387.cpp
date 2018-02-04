#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>
#include <deque>
using namespace std;
struct Node{
	int flag;
	queue<string> qi;
};
map<string, int> msi;
bool mark[1001];


int main(){
	//ifstream in("C:\\temp.txt");
	Node t;
	int N;
	string temp;
	int CASE = 1;
	while (cin >> N&&N){
		printf("Scenario #%d\n", CASE++);
		memset(mark, 0, sizeof(mark));
		deque<Node> qn;
		int M;
		for (int i = 1; i <= N; ++i){
			cin >> M;
			while (M--){
				cin >> temp;
				msi[temp] = i;
			}
		}
		while (cin >> temp&&temp[0] != 'S'){
			if (temp[0] == 'E'){
				string que;
				cin >> que;
				int flag = msi[que];
				if (!mark[flag]){
					mark[flag] = 1;
					t.flag = flag;
					qn.push_back(t);
					qn.back().qi.push(que);
				}
				else{
					for (int i = 0; i < qn.size(); ++i)
					if (qn[i].flag == flag)
						qn[i].qi.push(que);
				}
			}
			else{
				cout << qn[0].qi.front() << endl;
				qn[0].qi.pop();
				if (qn[0].qi.empty()){
					mark[qn[0].flag] = 0;
					qn.pop_front();
				}
			}
		}
		cout << endl;
	}
	return 0;
}