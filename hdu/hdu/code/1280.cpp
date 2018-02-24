#include <iostream>
//#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
int num[3010];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	//ifstream in("C:\\temp.txt");
	int N, M;

	priority_queue<int> pp;
	while (cin >> N >> M){
	
		memset(num, -1, sizeof(num));
		while (!pp.empty())pp.pop();
		for (int i = 0; i < N; ++i)
			//in >> num[i];
			scanf("%d", &num[i]);
		sort(num, num + N, cmp);
		for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j)
			pp.push(num[i] + num[j]);
		for (int i = 0; i < M - 1; ++i){
			printf("%d ", pp.top());
			pp.pop();
		}
		cout << pp.top() << endl;
	}
	

	return 0;
}