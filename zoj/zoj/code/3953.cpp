#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

struct Node{
	int l, r, index;
	bool operator<(const Node& p)const{
		if (r != p.r)
			return r < p.r;
		else{
			return l < p.l;
		}
	}
}data[50010];

bool mark[50010];
vector<int> ans;

int main(){
	ifstream in("C:\\input.txt");
	int T, N;
	cin >> T;


	while (T-->0){
		ans.clear();
		memset(mark, 0, sizeof(mark));
		cin >> N;	
		
		for (int i = 0; i < N; ++i){
			cin >> data[i].l >> data[i].r;
			data[i].index = i + 1;
		}
		sort(data, data + N);
	
		
		int cofR, maxR;
		cofR = maxR = -1;
		int num = 0;
		int pos = 0;
		while (pos < N){
			if (data[pos].l <= maxR)
				cofR = maxR;
			maxR = data[pos].r;
			pos++;
			while (pos < N &&data[pos].l <= cofR){
				num++;
				mark[pos] = 1;
				pos++;
			}
		}
		cout << num << endl;
		bool f = 0;
		for (int i = 0; i < N; ++i){
			if (mark[i]){
				ans.push_back(data[i].index);
			}
		}
		sort(ans.begin(), ans.end());
		if (!ans.empty()){
			cout << ans[0];
			for (int i = 1; i < ans.size(); ++i)
				cout << " " << ans[i];
		}
		cout << endl;
	}
	return 0;
}