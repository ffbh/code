#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{
	int l, r;
	bool operator<(const Node& p){
		return l < p.l;
	}
}data[100010];


int main(){
	ifstream in("C:\\input.txt");
	int M, size = 0;
	cin >> M;
	while (cin >> data[size].l >> data[size].r){
		if (data[size].l == 0 && data[size].r == 0)
			break;
		
		size++;
	}
	sort(data, data + size);
	vector<int> ans;
	int pos = 0, Index;
	int L = 0;
	bool flag = 0;
	while (pos < size){
		int maxR = L;
		Index = -1;
		while (pos < size && data[pos].l <= L){
			if (data[pos].r > maxR){
				maxR = data[pos].r;
				Index = pos;
			}
			pos++;
		}
		if (Index != -1)
			ans.push_back(Index);
		else{
			break;
		}
		L = maxR;
		if (L >= M){
			flag = 1;
			break;
		}
	}

	if (flag){
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); ++i)
			printf("%d %d\n", data[ans[i]].l, data[ans[i]].r);
	}
	else{
		cout << "No solution" << endl;
	}














	return 0;
}