#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
int N, M;
struct Node{
	int time;
	string s1, s2;
}data[110];
struct Map{
	bool map[22];
	int code;
	int sumtime;
	bool operator<(const Map& p)const{
		return sumtime>p.sumtime;
	}
};
bool vis[1 << 22];
int dist[1 << 22];

bool putok(int u,Map& p){
	for (int i = 0; i < N; ++i)
	if (data[u].s1[i] != '0'){
		bool b = (data[u].s1[i] == '+');
		if (!b&&p.map[i]||b&&!p.map[i])
			return 0;
	}
	return 1;
}

int HashCode(Map& p){
	int code = 0;
	for (int i = 0; i < N; ++i)
		code = code * 2 + p.map[i];
	return code;
}
void putbuding(int u,Map& p){
	for (int i = 0; i < N; ++i)
	if (data[u].s2[i] != '0')
		p.map[i]= (data[u].s2[i] == '+');
	p.sumtime += data[u].time;
}

int Astar(){
	memset(vis, 0, sizeof(vis));
	priority_queue<Map> qn;
	Map temp1, temp2;
	temp1.sumtime = 0;
	memset(temp1.map, 1, sizeof(temp1.map));
	temp1.code = HashCode(temp1);
	vis[temp1.code] = 1;
	dist[temp1.code] = 0;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.top();
		qn.pop();
		if (temp1.code==0)
			return temp1.sumtime;
		for (int i = 0; i < M; ++i){
			if (putok(i, temp1)){
				temp2 = temp1;
				putbuding(i, temp2);
				temp2.code = HashCode(temp2);
				if (!vis[temp2.code]){
					vis[temp2.code] = 1;
					dist[temp2.code] = temp2.sumtime;
					qn.push(temp2);
				}
				else if (temp2.sumtime < dist[temp2.code]){
					dist[temp2.code] = temp2.sumtime;
					qn.push(temp2);
				}
			}
		}
	}
	return -1;
}




int main(){
	ifstream in("C:\\temp.txt");
	int CASE = 1;
	while (cin >> N >> M&&N + M){
		printf("Product %d\n", CASE++);
		for (int i = 0; i < M; ++i)
			cin >> data[i].time >> data[i].s1 >> data[i].s2;
		int ans = Astar();
		if (ans < 0)
			cout << "Bugs cannot be fixed." << endl;
		else
			printf("Fastest sequence takes %d seconds.\n", ans);
		cout << endl;
	}
	return 0;
}