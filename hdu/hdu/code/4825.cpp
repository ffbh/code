#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
vector<unsigned int> data[40];
void init(){
	for (int i = 0; i < 40; ++i)
		data[i].resize(100010);
}
void clear(){
	for (int i = 0; i < 40; ++i)
		data[i].clear();
}
int getMaxZeroIndex(unsigned int k){
	for (int i = 31; i >= 0; --i)
	if (!(k & ((unsigned int)1 << i))){
		return i + 1;
	}
	return -1;
}

void add(unsigned int k){
	if (k == 0)
		data[0].push_back(0);
	else{
		for (int i = 31; i >= 0; --i)
		if (k & ((unsigned int)1 << i)){
			data[i + 1].push_back(k);
			break;
		}
	}

}



int main(){
	//ifstream in("C:\\input.txt");
	init();
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		printf("Case #%d:\n", CASE++);
		clear();
		int N, M;
		cin >> N >> M;
		while (N--){
			unsigned int k;
	//		in >> k;
			scanf("%u", &k);
			add(k);
		}
		while (M--){
			unsigned int k;
		//	in >> k;
			scanf("%u", &k);
			bool f = 0;
			for (int i = 31; i >= 0;--i)
			if (!(k & ((unsigned int)1 << i)) && !data[i + 1].empty()){
				f = 1;
				unsigned int mmax = 0;
				unsigned int ans = data[i + 1][0];
				for (int j = 0; j < data[i+1].size();++j)
				if ((mmax) < (k^data[i + 1][j])){
					mmax = (k^data[i + 1][j]);
					ans = data[i + 1][j];
				}
				printf("%u\n", ans);
				break;
			}
			if (!f){
				for (int i = 0; i <= 31;++i)
				if (!data[i].empty()){
					unsigned int mmax = 0;
					unsigned int ans = data[i][0];
					for (int j = 0; j < data[i].size(); ++j)
					if ((mmax) < (k^data[i][j])){
						mmax = (k^data[i][j]);
						ans = data[i][j];
					}
					printf("%u\n", ans);
					break;
				}
			}
		}
	}

	return 0;
}