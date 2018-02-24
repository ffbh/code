#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int IN[210];
vector<int> V[210];
struct Node{
	int id, u;
	Node(int a, int b){
		id = a;
		u = b;
	}
	bool operator<(const Node& p)const{
		if (u != p.u)
			return u > p.u;
		return id > p.id;
	}
};

void Test(){
	priority_queue<Node> qp;
	qp.push(Node(1, 0));
	qp.push(Node(1, 1));
	qp.push(Node(2, 0));
	qp.push(Node(2, 2));
	while (!qp.empty()){
		cout << qp.top().id << " " << qp.top().u << endl;
		qp.pop();
	}
	cout << endl;


}

int main(){
	ifstream in("C:\\temp.txt");
	int N, M, K;
	in >> K;
	priority_queue<int,vector<int>,greater<int> > qp;
	while (K--){
		while (!qp.empty())
			qp.pop();
		memset(IN, 0, sizeof(IN));
		for (int i = 0; i < 210; ++i)
			V[i].clear();
		in >> N >> M;
		while (M--){
			int a, b;
			in >> a >> b;
			IN[b]++;
			V[a].push_back(b);
		}
		for (int i = 1; i <= N;++i)
		if (IN[i] == 0){
			qp.push(i);
		}
		int w = 1;
		int d[210];
		int num = 0;
		while (!qp.empty()){
			int top = qp.top();
			qp.pop();
			d[top] = w++;
			num++;
			for (int i = 0; i < V[top].size(); ++i){
				int v = V[top][i];
				IN[v]--;
				if (IN[v] == 0)
					qp.push(v);
			}
		}
		if (num != N)
			cout << -1 << endl;
		else{
			for (int i = 1; i < N; ++i)
				cout << d[i] << " ";
			cout << d[N] << endl;
		}









	}





	return 0;
}