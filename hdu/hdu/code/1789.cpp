#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
	int date;
	int se;
	bool operator<(const Node& p)const{
		return date > p.date;
	}
};
Node num[1010];

int main(){
	//ifstream in("C:\\temp.txt");
	int T,N;
	cin >> T;
	while (T--){
		priority_queue<int> pi;
		cin >> N;
		int sum = 0;
		for (int i = 0; i < N; ++i)
			//in >> num[i].date;
			scanf("%d", &num[i].date);

		for (int i = 0; i < N; ++i){
			//in >> num[i].se;
			scanf("%d", &num[i].se);
			sum += num[i].se;
		}

		sort(num, num + N);
		int day = num[0].date;
		int k = 0;
		int res = 0;
		while (day>0){
			while (num[k].date >= day&&k < N)
				pi.push(num[k++].se);
			if (!pi.empty()){
				res += pi.top();
				pi.pop();
			}
			day--;
		}
		cout << sum - res << endl;


	}
	return 0;
}