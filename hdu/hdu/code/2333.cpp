#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
ifstream in("C:\\temp.txt");
struct Node{
	int v, q;
	bool operator<(const Node& p)const{
		return q < p.q;
	}
};
vector<Node> vn[1010];
map<string,int>msi;
int M,  size;
_int64 K;


int GetInput(){
	string s, t;
	cin >> s >> t;
	if (!msi[s])
		msi[s] = size++;
	return msi[s];
}

bool OK(int m){
	_int64 sum = 0;
	for (int i = 1; i < size; ++i){
		int mmin = INT_MAX;
		for (int j = vn[i].size() - 1; j>=0&&vn[i][j].q >= m;--j)
		if (vn[i][j].v<mmin)
			mmin = vn[i][j].v;
		sum += mmin;
		if (sum>K)
			return 0;
	}
	return 1;
}

int main(){
	int T;
	cin >> T;
	while (T--){
		for (int i = 1; i < 1010; ++i)
			vn[i].clear();
		size = 1;
		msi.clear();
		cin >> M >> K;
		int mmin, mmax;
		mmin = INT_MAX;
		mmax = INT_MIN;
		while (M--){
			Node temp;
			int num;
			num = GetInput();
			cin >> temp.v >> temp.q;
			if (temp.q < mmin)
				mmin = temp.q;
			if (temp.q > mmax)
				mmax = temp.q;
			vn[num].push_back(temp);
		}
		for (int i = 1; i < size; ++i)
			sort(vn[i].begin(), vn[i].end());
		int ans;
		while (mmin <= mmax){
			int m = (mmin + mmax) / 2;
			if (OK(m)){
				ans = m;
				mmin = m +1;
			}
			else
				mmax = m - 1;
		}
		cout << ans << endl;
	}
	return 0;
}