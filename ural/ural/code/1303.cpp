#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
	int a, b;
	bool operator<(const Node& p)const{
		return a < p.a;
	}
}data[1000010];
vector<int> V;

int main(){
	ifstream in("C:\\temp.txt");
	int M;
	cin >> M;
	int a, b;
	int size = 0;
	while (cin >> a >> b){
		if (a == 0 && b == 0)
			break;
		data[size].a = a;
		data[size].b = b;
		size++;
	}
	int now = 0;
	int i = 0;
	sort(data, data + size);
	while (i < size){
		int u = -1, max = now;
		while (data[i].a<=now&&i<size){
			if (data[i].b>max){
				u = i;
				max = data[i].b;
			}
			i++;
		}
		if (u == -1){
			now = -1;
			break;
		}
		now = max;
		V.push_back(u);
		if (now >= M)
			break;
	}
	if (now < M)
		printf("No solution\n");
	else{
		cout << V.size() << endl;
		for (int i = 0; i < V.size(); ++i)
			printf("%d %d\n", data[V[i]].a, data[V[i]].b);
	}
	return 0;
}