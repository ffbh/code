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
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
#include <cassert>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


int N;
string str;

struct Node{
	int next[30];
	int num;
}data[7000010];

int root, size;

int MALLOC(){
	memset(data[size].next, -1, sizeof(data[size].next));
	data[size].num = 0;
	return size++;
}



void Insert(string str){
	int p = root;
	for (char c : str){
		int k = c - 'A';
		if (data[p].next[k] == -1){
			data[p].next[k] = MALLOC();
		}
		p = data[p].next[k];
		data[p].num++;
	}
}

void input(){
	in >> N;
	root = MALLOC();
	for (int i = 1; i <= N; ++i){
		in >> str;
		reverse(str.begin(), str.end());
		Insert(str);
	}
	
}

int dfs(int p){
	if (p == -1){
		return 0;
	}

	if (data[p].num <= 1){
		return 0;
	}
	int ans = 0;
	for (int k = 0; k < 30; ++k){
		int r = dfs(data[p].next[k]);
		ans += r;
		data[p].num -= r;
	}
	if (data[p].num >= 2){
		data[p].num -= 2;

		ans += 2;
	}
	return ans;
}

int main(){
	int CPP = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		

		int sum = 0;
		for (int i = 0; i < 30; ++i){
			if (data[root].next[i] != -1){
				sum += dfs(data[root].next[i]);
			}
		}
		printf("Case #%d: %d\n", CPP++, sum);





	}


	return 0;
}





