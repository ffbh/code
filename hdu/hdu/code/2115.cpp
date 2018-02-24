#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	string name;
	int time;
	bool operator<(const Node& p)const{
		if (time != p.time)
			return time < p.time;
		return name < p.name;
	}
};

Node data[11];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int ok = 0;
	int CASE = 1;
	while (cin >> N&&N){
		if (ok)cout << endl;
		ok = 1;
		printf("Case #%d\n", CASE++);
		for (int i = 0; i < N; ++i){
			string time;
			cin >> data[i].name>>time;
			data[i].time = (time[0] * 10 + time[1]) * 60 + time[3] * 10 + time[4];
		}
		sort(data, data + N);
		int prerank = 1;
		for (int i = 0; i < N; ++i){
			int rank = i+1;
			if (data[i].time == data[i - 1].time)
				rank = prerank;
			printf("%s %d\n", data[i].name.c_str(), rank);
			prerank = rank;
		}
	}
	return 0;
}