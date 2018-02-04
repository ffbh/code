#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
int N;
struct Data{
	int pre;
	char v;
}data[2000010];
int size;
struct Node{
	int mod;
	int now;
};
bool vis[1000010];
int bfs(){
	queue<Node> qn;
	Node temp1, temp2;
	temp1.mod = 1;
	data[size].pre = -1;
	data[size].v = '1';
	temp1.now = size++;
	qn.push(temp1);
	vis[1] = 1;
	temp1.mod = 2;
	data[size].pre = -1;
	data[size].v = '2';
	temp1.now = size++;
	qn.push(temp1);
	vis[2] = 1;
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		if (temp1.mod == 0)
			return temp1.now;
		temp2 = temp1;
		temp2.mod = (temp2.mod*10 + 1) % N;
		if (!vis[temp2.mod]){
			vis[temp2.mod] = 1;
			data[size].pre = temp2.now;
			data[size].v = '1';
			temp2.now = size++;
			qn.push(temp2);
		}
		temp2 = temp1;
		temp2.mod = (temp2.mod*10 + 2) % N;
		if (!vis[temp2.mod]){
			vis[temp2.mod] = 1;
			data[size].pre = temp2.now;
			data[size].v = '2';
			temp2.now = size++;
			qn.push(temp2);
		}
	}
	return -1;
}

void Print(int now){
	if (data[now].pre != -1)
		Print(data[now].pre);
	putchar(data[now].v);
}


int main(){
	ifstream in("C:\\temp.txt");
	cin >> N;
	size = 0;
	if (N == 1 || N == 2)
		cout << N << endl;
	else{
		int ans = bfs();
		if (ans == -1)
			cout << "Impossible" << endl;
		else{
			Print(ans);
			cout << endl;
		}
	}
	return 0;
}