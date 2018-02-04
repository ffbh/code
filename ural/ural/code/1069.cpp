#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
vector<int> vi[8000];
int data[8000];
int eage[8000];

int main(){
	//ifstream in("C:\\input.txt");
	int size = 1;
	priority_queue<int, vector<int>,greater<int> > pq;
	while (cin >> data[size]){
		eage[data[size]]++;
		size++;
	}
	size--;
	for (int i = 1; i <= size;++i)
	if (eage[i] == 0)
		pq.push(i);
	for (int i = 1; i <= size; ++i){
		int top = pq.top();
		pq.pop();
		vi[data[i]].push_back(top);
		vi[top].push_back(data[i]);
		if (--eage[data[i]] == 0){
			pq.push(data[i]);
		}
	}
	for (int i = 1; i <= size+1; ++i){
		sort(vi[i].begin(), vi[i].end());
		printf("%d:", i);
		for (int j = 0; j < vi[i].size(); ++j)
			printf(" %d", vi[i][j]);
		putchar('\n');
	}

	return 0;
}