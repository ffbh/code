#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
struct Node{
	int id;
	char c;
	bool operator<(const Node& p)const{
		if (c != p.c)
			return c < p.c;
		return id < p.id;
	}
};
priority_queue<Node> qn;
string map[510];
int h[510], w[510];
int N;
vector<Node> ans;
bool fun(){
	while (!qn.empty()){
		Node temp = qn.top();
		qn.pop();
		ans.push_back(temp);
		if (temp.c == 'R'){
			for (int i = 0; i < N; ++i)
				if (map[temp.id][i] == 'X'){
					w[i]--;
					if (w[i] == 0)
						qn.push(Node{ i, 'C' });
				}
		}
		else{
			for (int i = 0; i < N;++i)
			if (map[i][temp.id] == 'O'){
				h[i]--;
				if (h[i] == 0)
					qn.push(Node{ i, 'R' });
			}
		}
	}
	for (int i = 0; i < N;++i)
	if (h[i]>0 || w[i]>0)
		return 0;
	return 1;
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		while (!qn.empty())qn.pop();
		ans.clear();
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> map[i];
		for (int i = 0; i < N; ++i){
			h[i] = 0;
			for (int j = 0; j < N; ++j)
			if (map[i][j] == 'O')
				h[i]++;
			if (h[i] == 0)
				qn.push(Node{ i, 'R' });
			else if (h[i] == N){
				h[i] = -1;
			}
		}
		for (int i = 0; i < N; ++i){
			w[i] = 0;
			for (int j = 0; j < N; ++j)
			if (map[j][i] == 'X')
				w[i]++;
			if (w[i] == 0)
				qn.push(Node{ i, 'C' });
			else if (w[i] == N){
				w[i] = -1;
			}
		}
		if (qn.size() == 0||!fun())
			cout << "No solution" << endl;
		else{
			for (int i = ans.size() - 1; i>0; --i)
				printf("%c%d ", ans[i].c, ans[i].id + 1);
			printf("%c%d\n", ans[0].c, ans[0].id + 1);
		}
	}
	return 0;
}