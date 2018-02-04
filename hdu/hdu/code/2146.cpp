#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define MMAX (400000)
_int64 data[MMAX];



int main(){
	ifstream in("C:\\temp.txt");
	int N, M, K;
//	while (in >> N >> M >> K){
	while (~scanf("%d%d%d",&N,&M,&K)){
		int ans = 0;
		int size = 0;
		_int64 base = (_int64)((1 << (K-1)) -1);
		for (int i = 0; i < N; ++i){
			char buf[70];
			scanf("%s", buf);
		//	in >> buf;
			_int64 temp = 0;
			for (int k = 0; k < K;++k)
				temp = (temp << 1) + buf[k] - '0';
			data[size++] = temp;
			for(int k=K;k<M;++k){
				temp = ((temp&base)<<1) + buf[k] - '0';
				data[size++] = temp;			
			}
		}
		sort(data, data + size);
		int sum;
		sum = 1;
		for (int i = 1; i < size; ++i){
			if (data[i] != data[i-1]){
				if (sum>ans)
					ans = sum;
				sum = 1;
			}
			else sum++;
		}
		//cout << ans << endl;
		printf("%d\n", max(ans,sum));
	}
	return 0;
}