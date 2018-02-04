#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	priority_queue<int> pp;
	while (cin >> N >>  M){
		int t;
		while (!pp.empty())pp.pop();
		for (int i = 0; i < N; ++i){
			scanf("%d", &t);
			pp.push(t);
		}
		for (int i = 0; i < M - 1; ++i){
			printf("%d ", pp.top());
			pp.pop();
		}
		printf("%d\n", pp.top());
	
	}

	return 0;
}