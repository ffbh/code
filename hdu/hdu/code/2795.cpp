#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M, K;
int MMAX, ID;
int data[800010];
int len;


int Update(int root,int l,int r){
	if (data[root]+len > M)
		return -1;
	if (l==r){
		data[root] += len;
		return l;
	}
	int ans;
	int mid = (l + r) / 2;
	if (data[root * 2]+len<=M)
		ans = Update(root * 2, l,mid);
	else
		ans = Update(root * 2 + 1,mid+1,r);
	data[root] = min(data[root * 2], data[root * 2 + 1]);
	return ans;
}




int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M >> K){
		memset(data, 0, sizeof(data));
		MMAX = min(N, K);
		while (K--){
			//in >> len;
			scanf("%d", &len);
			printf("%d\n", Update(1,1,MMAX));
		}
	}
	return 0;
}