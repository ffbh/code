#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
struct Node{
	int s, e;
	int mmin;
	Node(int _s, int _e){
		s = _s;
		e = _e;
	}
	Node(){}
}part, tmp;
vector<Node> vn;
int data[1010];
int GetPeak(){
	data[0] = data[N + 1] = 0;
	vn.clear();
	int s, e;
	int p = 1;
	while (p <= N){
		s = p;
		while (p<=N&&data[p] == data[s])
			p++;
		e = p - 1;
		if (data[s] > data[s - 1] && data[e] > data[e + 1])
			vn.push_back(Node(s, e));
	}
	return vn.size();
}

int GetNum(int index){
	int s = vn[index].s;
	int e = vn[index].e;
	int num = 0;
	int i;
	for (i = s - 1; i >= 1 && data[i] >= data[i - 1]; --i);
	if (i < 1)
		tmp.s = 1;
	else
		tmp.s = i;
	for (i = e + 1; i <= N&&data[i] >= data[i + 1]; ++i);
	if (i>N)
		tmp.e = N;
	else
		tmp.e = i;
	if (s == 1 || e == N){
		tmp.mmin = min(data[tmp.s], data[tmp.e]);
	}
	else{
		tmp.mmin = max(data[tmp.s], data[tmp.e]);
	}
	for (int i = tmp.s; i <= tmp.e; ++i)
	if (data[i] > tmp.mmin)
		num += data[i] - tmp.mmin;
	return num;



}

void clear(){
	for (int i = part.s; i <= part.e; ++i)
	if (data[i] > part.mmin)
		data[i] = part.mmin;
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> K;
	for (int i = 1; i <= N; ++i){
		cin >> data[i];
	}
	data[N + 1] = 0;
	int ans = 0;
	while (GetPeak()>K){
		int mmin = INT_MAX;
		for (int i = 0; i < vn.size(); ++i){
			int ret = GetNum(i);
			if (ret < mmin){
				mmin = ret;
				part = tmp;
			}
		}
		ans += mmin;
		clear();

	}
	cout << ans << endl;
	return 0;
}