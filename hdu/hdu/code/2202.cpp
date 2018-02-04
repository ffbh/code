#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> V;
struct Node{
	int x, y;
}data[50010];

int chaji(Node& a, Node& b,Node& c){
	return (c.x - a.x)*(b.y - a.y) -
		(c.y - a.y)*(b.x - a.x);
}
bool cmp(Node& a, Node& b){
	return chaji(data[0], a, b) >= 0;
}

void getTuBao(){
	for (int i = 0; i < N; ++i){
		while (V.size() > 2 && chaji(data[i], data[V[V.size() - 1]], data[V[V.size() - 2]]) >= 0)
			V.pop_back();
		V.push_back(i);
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N){
		int u = 0;
		V.clear();
		for (int i = 0; i < N; ++i){
			cin >> data[i].x >> data[i].y;
			if (data[u].x < data[i].x || data[u].x == data[i].x&&data[u].y < data[i].y)
				u = i;
		}
		if (u)
			swap(data[u], data[0]);
		sort(data + 1, data + N, cmp);
		getTuBao();
		double mmax = 0;
		for (int i = 0; i < V.size();++i)
		for (int j = i + 1; j < V.size();++j)
		for (int k = j + 1; k < V.size(); ++k){
			double ret = chaji(data[V[i]], data[V[j]], data[V[k]])/2.0;
			if (ret>mmax)
				mmax = ret;
		}
		printf("%.2f\n", mmax);

	}





	return 0;
}