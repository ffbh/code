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

//ifstream in("C:\\input.txt");
istream& in = cin;


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;

struct Node{
	int next[2];
	bool full;
}data[1000010];

int root, size;
int N, M;
int MALLOC(){
	data[size].full = 0;
	data[size].next[0] = data[size].next[1] = -1;
	return size++;
}

void Init(){
	size = 0;
	root = MALLOC();
}

void Insert(int val){
	int p = root;
	for (int i = 20; i >= 0; --i){
		int k = (val &(1 << i)) ? 1 : 0;
		if (data[p].next[k] == -1){
			data[p].next[k] = MALLOC();
		}
		p = data[p].next[k];
	}
}


void input(){
	in >> N >> M;


}

void dfs(int pos){
	if (data[pos].next[0] == -1 && data[pos].next[1] == -1){
		data[pos].full = 1;
		return ;
	}
	if (data[pos].next[0] != -1){
		dfs(data[pos].next[0]);
	}

	if (data[pos].next[1] != -1){
		dfs(data[pos].next[1]);
	}
	
	if (data[pos].next[0] != -1 && data[data[pos].next[0]].full &&
		data[pos].next[1] != -1 && data[data[pos].next[1]].full){
		data[pos].full = 1;
	}
}


int getAns(int x){
	int ans = 0;
	int p = root;
	for (int i = 20; i >= 0; --i){
		if (p == -1)
			break;
		int k = (x &(1 << i)) ? 1 : 0;
		if (k == 0){
			
			if (data[p].next[0] == -1){
				break;
			}
			else if ( !data[data[p].next[0]].full){
				p = data[p].next[0];
			}
			else{
				p = data[p].next[1];
				ans += (1 << i);
			}
		}
		else{
			if (data[p].next[1] == -1){
				break;
			}
			else if (  !data[data[p].next[1]].full){
				p = data[p].next[1];
			}
			else{
				p = data[p].next[0];
				ans += (1 << i);
			}
		}
	}
	return ans;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		Init();
		input();

		for (int i = 1; i <= N; ++i){
			int val;
			in >> val;
			Insert(val);
		}

		dfs(0);

		int x = 0;
		for (int i = 1; i <= M; ++i){
			int tmp;
			in >> tmp;
			x ^= tmp;

			printf("%d\n", getAns(x));

		}

	}


	return 0;
}





