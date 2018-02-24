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
long long Ta, Tb, X, N, M;
struct Node{
	long long Ta, Tac, D;
}A[10010], B[20010];

struct Seg{
	long long l, r, d;
	bool operator<(const Seg& p)const{
		if (l != p.l)
			return l < p.l;
		else
			return r < p.r;
	}
}data[20010];
map<int, int> mii;

void getInput(int k){
	ofstream out("C:\\input.txt");
	srand(time(0));
	while (k--){
		const int mod = 1e8;
		int N = 10000;
		int M = 10000;
		
		out << abs(rand()) % mod << " " << abs(rand()) % mod << endl;
		out << abs(rand()) % mod << endl;
		out << N << " " << N << endl;
		for (int i = 1; i <= N; ++i){
			out << abs(rand()) % mod << " " << abs(rand()) % mod + 1 << " " <<
				abs(rand()) % mod << endl;
		}

		for (int i = 1; i <= N; ++i){
			out << abs(rand()) % mod << " " << abs(rand()) % mod + 1 << " " <<
				abs(rand()) % mod << endl;
		}
	}
}

int main(){

	//getInput(5);


	ifstream in("C:\\input.txt");

	while (cin >> Ta >> Tb){
		mii.clear();
		cin >> X >> N >> M;
		for (int i = 0; i < N; ++i)
			cin >> A[i].Ta >> A[i].Tac >> A[i].D;
		for (int i = 0; i < M; ++i)
			cin >> B[i].Ta >> B[i].Tac >> B[i].D;

	
		int size = M;
		long long Bl = X, Br = Tb + X;
		for (int i = 0; i < N; ++i){
			long long time = A[i].Ta + A[i].Tac;
			if (time >= Bl && time <= Br){
				B[size].Ta = time;
				B[size].Tac = A[i].Tac;
				B[size].D = A[i].D;
				size++;
			}
		}
		long long sum = 0;
		for (int i = 0; i < size; ++i){
			sum += B[i].D;
			data[i].d = B[i].D;
			data[i].l = B[i].Ta + B[i].Tac;
			long long cycle = 2 * B[i].Tac;
			long long firsttime = B[i].Ta + cycle;
			if (Bl <= firsttime && Br >= firsttime){
				long long count = (Br - firsttime) / cycle + 1;
				data[i].r = data[i].l + cycle * count;
			}
			else{
				data[i].r = data[i].l;
			}
		}
		for (int i = 0; i < size; ++i){
			if (data[i].r - data[i].l <= Ta){
				mii[data[i].l + 1] += data[i].d;
				mii[data[i].r - Ta] += -data[i].d;
			}
		}
		long long ans = sum;
		map<int, int>::iterator it = mii.begin();
		while (it != mii.end()){
			sum += it->second;
			ans = min(ans, sum);
			it++;
		}
		cout << ans << endl;
	}

	return 0;
}