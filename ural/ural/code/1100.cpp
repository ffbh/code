#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	int a, b, i;
	bool operator<(const Node& p)const{
		if (b != p.b)
			return b > p.b;
		return i < p.i;
	}
}data[150010];
int N;


int main(){
	ifstream in("C:\\temp.txt");
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> data[i].a >> data[i].b;
		data[i].i = i;
	}
	sort(data, data + N);
	for (int i = 0; i < N; ++i)
		printf("%d %d\n", data[i].a, data[i].b);
	return 0;
}