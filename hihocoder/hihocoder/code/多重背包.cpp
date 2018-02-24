#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int N, M;
long long A[10010], P[10010], S[10010];
struct Node{
	long long v, num;
	bool operator<(const Node& p)const{
		return v>p.v;
	}
}data[20010];


int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	for (int i = 1; i <= M; ++i)
		cin >> A[i];
	for (int i = 1; i <= M; ++i)
		cin >> P[i];
	for (int i = 1; i <= M; ++i)
		cin >> S[i];
	int size = 0;
	for (int i = 1; i <= M; ++i){
		if (A[i] / S[i]){
			data[size].num = A[i] / S[i];
			data[size].v = P[i] * S[i];
			size++;
		}
		if (A[i] % S[i]){
			data[size].num = 1;
			data[size].v = (A[i] % S[i])*P[i];
			size++;
		}
	}
	sort(data, data + size);
	long long ans = 0;
	for (int i = 0; i < size; ++i){
		if (N == 0)
			break;
		if (N >= data[i].num){
			ans += data[i].num*data[i].v;
			N -= data[i].num;
		}
		else{
			ans += N*data[i].v;
			N = 0;
		}
	}
	cout << ans << endl;
	return 0;
}