#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, M, K, P;
struct Node{
	unsigned int id;///////////////////%u!!!!!!!!!!!!!!!!!!!!!	
	int index;

	int now;
	int sumtime;

	bool operator<(const Node& p)const{
		if (sumtime != p.sumtime)
			return sumtime > p.sumtime;
		else
			return id > p.id;
	}
};
struct Message{
	Message(int p,int t){
		port = p;
		time = t;
	}
	int port;
	int time;
};
vector<Message> V[10010];
int ans[10010];
int endtime[110];
priority_queue<Node> qn;

int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i){
		Node stu;
		cin >> stu.id;
		cin >> stu.sumtime;
		stu.index = i;
		stu.now = -1;
		qn.push(stu);
		cin >> P;
		while (P--){
			int o, w;
			cin >> o >> w;
			V[i].push_back(Message(o, w));
		}
	}
	while (!qn.empty()){
		Node top = qn.top();
		qn.pop();
		if (top.now != -1){
			if(top.sumtime < endtime[V[top.index][top.now].port])
				top.sumtime = endtime[V[top.index][top.now].port];
			top.sumtime += V[top.index][top.now].time ;
			endtime[V[top.index][top.now].port] = top.sumtime;
		}
		top.now++;
		top.sumtime += K;
		if (top.now < V[top.index].size())
			qn.push(top);
		else
			ans[top.index] = top.sumtime - K;
	}

	for (int i = 1; i <= N; ++i)
		printf("%d\n", ans[i]);
	return 0;
}