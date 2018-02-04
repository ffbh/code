#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	int s, t;
	bool operator<(const Node& p)const{
		return t < p.t;
	}
}data[100010];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> data[i].s >> data[i].t;
	sort(data, data + N);
	int ans = 0;
	int now = 0;
	int k = 0;
	while(k < N){
		int end = INT_MAX;
		bool ok = 0;
		while (k<N){
			if (data[k].s>now){
				ok = 1;
				end = data[k].t;
				break;
			}
			k++;
		}
		if (ok)
			ans++;
		now = end;
	}
	cout << ans << endl;
	return 0;
}