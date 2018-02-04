#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int A[50010], B[50010], C[50010], T, N;
struct Node{
	int time, index, f;
	bool operator<(const Node& p)const{
		if (time != p.time)
			return time < p.time;
		else
			return f < p.f;		
	}
}data[100010];


int main(){
	ifstream in("C:\\input.txt");
	cin >> T;

	while (T--){
		long long sum = 0;
		long long ans = 0;
		//in >> N;
		scanf("%d", &N);
		int size = 0;
		for (int i = 0; i < N; ++i){
		//	in >> data[size].time;
			scanf("%d", &data[size].time);
			data[size].f = 1;
			data[size].index = i;
			size++;
		//	in >> data[size].time;
			scanf("%d", &data[size].time);
			data[size].f = 2;
			data[size].index = i;
			size++;
		//	in >> A[i] >> B[i] >> C[i];
			scanf("%d%d%d", &A[i], &B[i], &C[i]);
			sum += C[i];
		}

		ans = sum;

		sort(data, data + size);
		int pos = 0;
		int pre = 0;
		int pretime = -1;
		while (pos < size){
			int time = data[pos].time;
			sum += pre;
			if (ans < sum)
				ans = sum;
			pre = 0;
			while (pos < size && data[pos].time == time){
				int index = data[pos].index;
				if (data[pos].f == 1){
					sum += A[index] - C[index];
				}
				else{
					pre += B[index] - A[index];
				//	sum += B[index] - A[index];
				}
				pos++;
			}
			if (ans < sum)
				ans = sum;
		}
		cout << ans << endl;
	}


	return 0;
}