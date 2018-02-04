#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
int T, N;
int data[100010];

multimap<int,int> si;
multimap<int,int>::iterator it;
int group[100010], size, son[100010];
vector<int> vi[100010];
void Init(int n){
	si.clear();
	size = 0;
	for (int i = 0; i <= n; ++i){
		vi[i].clear();
		son[i] = 0;
	}
	
}





int main(){
	ifstream in("C:\\input.txt");
	cin >> T;
	while (T-- > 0){
		scanf("%d", &N);
	//	in >> N;
		Init(N);
		for (int i = 0; i < N; ++i){
		//	in >> data[i];
			scanf("%d", &data[i]);
		//	data[i].idx = i + 1;
		}
	//	sort(data, data + N);
		si.insert(multimap<int, int>::value_type(0, 0));
		for (int i = 0; i < N; ++i){
			int val = data[i];
			int idx = i + 1;
			it = si.lower_bound(val);
			if (it == si.end() || it->first != val)
				--it;
			int fidx = it->second;
			if (fidx == 0){
				group[idx] = size++;
				vi[group[idx]].push_back(idx);
			}
			else{
				group[idx] = group[fidx];
				vi[group[idx]].push_back(idx);
				if (++son[fidx] == 2){
					si.erase(it);
				}
			}
			si.insert(multimap<int, int>::value_type(data[i], i+1));
		
		}
		printf("%d\n", size);

		for (int i = 0; i < size; ++i){
		
			sort(vi[i].begin(), vi[i].end());
			printf("%d", vi[i].size());
			for (int j = 0; j < vi[i].size(); ++j)
				printf(" %d", vi[i][j]);
			printf("\n");
		}
	}

	return 0;
}