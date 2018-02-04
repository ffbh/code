#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
struct node{
	int index;
	int step;
};
int data[220];
bool vis[220][2];

int N, A, B;
bool IN(const node& p){
	return p.index >= 1 && p.index <= N;
}
int dirs[2] = { 1, -1 };

int bfs(){
	if (A == B) return 0;
	queue<node> qn;
	node temp1, temp2;
	temp1.step = 0;
	temp1.index = A;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		temp1.step++;
		for (int i = 0; i < 2; ++i){
			temp2 = temp1;
			temp2.index += dirs[i] * data[temp1.index];
			if (temp2.index == B)return temp2.step;
			if (IN(temp2) && !vis[temp1.index][i]){
				vis[temp1.index][i] = 1;
				qn.push(temp2);
			}
		}
	}
	return -1;
}


int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> A >> B&&N){
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= N; ++i)
			//	in >> data[i];
			scanf("%d", &data[i]);
		cout << bfs() << endl;
	
	
	
	}







	return 0;
}