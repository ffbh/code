#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M;
struct Node{
	int a, b;
	bool operator<(const Node& p)const{
		return a<p.a;
	}
};
Node data[1001];
int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		for (int i = 0; i < M; ++i)
			cin >> data[i].a >> data[i].b;
		sort(data, data + M);
		double ans = 0;
		for (int i = 0; i < M; ++i){
			if (N>data[i].a*data[i].b){
				N -= data[i].a*data[i].b;
				ans += data[i].b;
			}
			else{
				ans += double(N) / data[i].a;
				break;
			}
		}
		printf("%.2f\n", ans);
	}
	return 0;
}