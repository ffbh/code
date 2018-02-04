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
using namespace std;
struct Node{
	int next[2];
	int num;
}data[30 * 100000 + 10];
int size, root;
int MALLOC(){
	data[size].next[0] = data[size].next[1] = -1;
	data[size].num = 0;
	return size++;
}
vector<int> digit, L;

void change(int x,vector<int>& tar){
	for (int i = 0; i < 30; ++i){
		tar[29 - i] = x % 2;
		x /= 2;
	}
}

void insert(int x,int val){
	change(x, digit);
	int p = root;
	for (int i = 0; i < 30; ++i){
		int k = digit[i];
		if (data[p].next[k] == -1){
			data[p].next[k] = MALLOC();
		}
		p = data[p].next[k];
		data[p].num += val;
	}
}


int get(int x){
	if (x == -1)
		return 0;
	else{
		return  data[x].num;
	}
}

int query(int x,int l){
	change(x, digit);
	change(l, L);

	int ans = 0;
	int p = root;

	for (int i = 0; i < 30 && p != -1; ++i){
		int k = digit[i];
		if (L[i] == 1){
			ans += get(data[p].next[k]);
			p = data[p].next[1 - k];
		}
		else{
			p = data[p].next[k];
		}
	}
	return ans;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	digit.resize(30);
	L.resize(30);

	int N;
	in >> N;
	size = 1;
	root = MALLOC();
	for (int i = 1; i <= N; ++i){
		int type, a, b;
		in >> type;
		if (type == 1){
			in >> a;
			insert(a, 1);
			
		}
		else if (type == 2){
			in >> a;
			insert(a, -1);


		}
		else{
			in >> a >> b;
			printf("%d\n", query(a, b));
		}

	}




	return 0;
}





