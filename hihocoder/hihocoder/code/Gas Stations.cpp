#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;
float dp[2][100010];
float dist[1010];
float ndp[100010];
int data[1010];
struct Node{
	Node(int a,int b){
		d = a;
		m = b;
		caleK();
	}
	void caleK(){
		k = (float)d / (m+1);
	}
	int d, m;
	float k;
	bool operator<(const Node& p)const{
		return k < p.k;
	}
};
priority_queue<Node> qn;

int main(){
	ifstream in("C:\\input.txt");
	int N, M, K;
	cin >> N >> M >> K;
	N--;
	for (int i = 0; i <= N; ++i)
		cin >> data[i];
	
	for (int i = 1; i <= N; ++i){
		if (data[i] != data[i - 1])
			qn.push(Node(data[i] - data[i - 1], 0));
	}
	while (K--){
		Node top = qn.top();
		qn.pop();
		top.m++;
		top.caleK();
		qn.push(top);
	}
	printf("%.1f\n", qn.top().k);
	return 0;
}