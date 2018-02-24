#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
ifstream in("C:\\temp.txt");
map<string, int> msi;
vector<int> vi[310];
vector<string> V;
struct Node{
	int id, num;
};
bool vis[310];
int mark[310];
int size = 1;
int getInput(){
	string s;
	cin >> s;
	if (msi[s] == 0){
		msi[s] = size++;
		V.push_back(s);
	}
	return msi[s];
}

void bfs(){
	queue<Node> qn;
	Node temp1, temp2;
	temp1.id = msi["Isenbaev"];
	temp1.num = 0;
	vis[temp1.id] = 1;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		mark[temp1.id] = temp1.num;
		temp1.num++;
		for (int i = 0; i < vi[temp1.id].size(); ++i){
			temp2 = temp1;
			temp2.id = vi[temp1.id][i];
			if (!vis[temp2.id]){
				vis[temp2.id] = 1;
				qn.push(temp2);
			}
		}
	}
}

int main(){
	int N;
	cin >> N;
	while (N--){
		int data[3];
		for (int i = 0; i < 3; ++i)
			data[i] = getInput();
		for (int i = 0; i < 3;++i)
		for (int j = 0; j < 3;++j)
		if (i != j)
			vi[data[i]].push_back(data[j]);
	}
	bfs();
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); ++i){
		int id = msi[V[i]];
		if (!vis[id])
			printf("%s undefined\n", V[i].c_str());
		else
			printf("%s %d\n", V[i].c_str(), mark[id]);
	}
	return 0;
}