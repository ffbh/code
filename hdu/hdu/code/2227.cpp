#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int size;	
struct Node{
	int v, index;
	bool operator<(const Node& p)const{
		return v < p.v;
	}
};
Node data[100010];
int num[100010];
int N;
int C[100010];
int lowbit(int x){
	return x&(-x);
}

void update(int x,int num){
	for (int i = x; i<=size; i += lowbit(i))
		C[i] = (C[i] + num) % 1000000007;
}

int getsum(int x){
	int sum = 0;
	for (int i = x; i>0; i -= lowbit(i))
		sum = (sum + C[i]) % 1000000007;
	return sum;
}

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (in >> N){
		size = 0;
		for (int i = 0; i < N; ++i){
			in >> data[i].v;
			data[i].index = i;
		}
		sort(data, data + N);
		num[data[0].index] = ++size;
		for (int i = 1; i < N; ++i){
			if (data[i].v == data[i - 1].v)
				num[data[i].index] = size;
			else
				num[data[i].index] = ++size;
		}
		for (int i = 1; i <= size; ++i)
			C[i] = 0;
		int ans = 0;
		for (int i = 0; i < N; ++i){
			int u = getsum(num[i]) + 1;
			ans = (ans + u) % 1000000007;
			update(num[i], u);
		}
		cout << ans << endl;

	}
	
	return 0;
}