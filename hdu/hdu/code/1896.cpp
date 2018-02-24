#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct Stone{//xunhuan pop
	int dist;
	int power;
	bool operator<(const Stone& s)const{
		if (dist != s.dist)
			return dist>s.dist;
		return power > s.power;
	}
};


int main(){
	//ifstream in("C:\\temp.txt");
	priority_queue<Stone> pi;
	int T, M;
	cin >> T;
	Stone temp;
	while (T--){
		while (!pi.empty())
			pi.pop();
		cin >> M;
		while (M--){
		//	cin >> temp.dist >> temp.power;
			scanf("%d%d", &temp.dist, &temp.power);
			pi.push(temp);
		}
		int flag = 1;
		while (pi.size()!=1){
			temp = pi.top();
			pi.pop();
			if (flag++ % 2){	
				temp.dist += temp.power;
				pi.push(temp);
			}
		}
		if (flag)
			cout << pi.top().power + pi.top().dist << endl;
		else
			cout << pi.top().dist << endl;
	}
	return 0;
}