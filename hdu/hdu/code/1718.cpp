#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;

int main(){
	//ifstream in("C:\\temp.txt");
	int ID;
	int t;
	int score;
	int k;
	while (cin >> ID){
		score = -1;
		priority_queue<int> qp;
		while (scanf("%d%d", &t, &k)&&t+k){
	//	while (in>>t>>k&&t+k){
			if (t == ID)
				score = k;
			else if (k > score)
				qp.push(k);
		}
		int ans = 1;
		while (!qp.empty() && qp.top() > score){
			qp.pop();
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}