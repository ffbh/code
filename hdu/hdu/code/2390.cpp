#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	int a, b, c;
}data[50010];
bool cmp(Node& a, Node& b){
	if (a.a != b.a)
		return a.a < b.a;
	return a.c < b.c;
}
int main(){
	ifstream in("C:\\temp.txt");
	int size;
	int T, N;
	cin >> T;
	int CASE = 1;
	while (T--){
		cin >> N;
		size = 1;
		for (int i = 0; i < N; ++i)
			//in >> data[i].a >> data[i].b >> data[i].c;
			scanf("%d%d%d", &data[i].a, &data[i].b, &data[i].c);
		sort(data, data + N,cmp);
		int ans = 1;
		int day = data[0].a;
		int time = data[0].c;
		for (int i = 1; i < N; ++i){
			if (data[i].a>day){
				ans++;
				day = data[i].a;
				time = data[i].c;
			}
			else if (data[i].b >= time){
				time = data[i].c;
				ans++;
			}
		}
		printf("Scenario #%d:\n", CASE++);
		cout << ans << endl << endl;

	}



	return 0;
}