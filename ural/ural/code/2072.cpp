#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node{
	long long d, v;
	bool operator<(const Node& p)const{
		if (v != p.v)
			return v < p.v;
		return d < p.d;
	}
}data[100010];



int main(){
	ifstream in("C:\\temp.txt");
	long long N;
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> data[i].v;
		data[i].d = i;
	}
	sort(data, data + N);
	long long Lans, Rans, L, R, k, nowv, preL, preR;
	Lans = Rans = k = preL = preR = 0;
	while (k < N){
		nowv = data[k].v;
		L = INT_MAX;
		R = INT_MIN;
		while (k < N&&data[k].v == nowv){
			if (L > data[k].d)
				L = data[k].d;
			if (R < data[k].d)
				R = data[k].d;
			k++;
		}
		long long TL, TR;
		TL = Lans;
		TR = Rans;
		Lans = R - L + min(TL + abs(preL - R), TR + abs(preR - R));
		Rans = R - L + min(TL + abs(preL - L), TR + abs(preR - L));
		preL = L;
		preR = R;
	}
	cout << min(Lans, Rans) + N << endl;
	return 0;
}



