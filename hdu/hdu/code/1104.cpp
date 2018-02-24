#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct Node{
	int now;
	string pace;
};
bool vis[1001];
int S, E;
int N, K, M;

int MOD(int a, int m){
	int c = a%m;
	if (c < 0)
		c = (c + m);
	return c;
}

void Cale(int i, int& a){
	switch (i){
	case 0:



	default:break;
	}

}
bool bfs(){
	queue<Node> qn;
	Node temp1, temp2;
	temp1.now = S;
	temp1.pace = "";
	qn.push(temp1);
	for (int i = 0; i < 5;++i)




}


int main(){
	ifstream in("C:\\temp.txt");
	while (in >> N >> K >> M&&N + M + K){
		S = MOD(N, K);
		E = MOD(N + 1, K);


	}





	return 0;
}