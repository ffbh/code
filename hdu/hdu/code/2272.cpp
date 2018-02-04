#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <cmath>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	string s;
	int N;
	int sum;
	priority_queue<int> qn;
	while (cin >> N){
		sum = 0;
		while (!qn.empty())
			qn.pop();
		for (int i = 1; i <= N; ++i){
			int t;
			cin >> s >> t;
			qn.push(t);
		}
		for (int i = N; i >= 1; --i){
			sum += abs(qn.top() - i);
			qn.pop();
		}
		cout << sum << endl;
	}
	return 0;
}