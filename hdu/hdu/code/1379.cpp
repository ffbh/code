#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct node{
	string s;
	int r;
};
node data[110];


int GetR(string& s){
	int len = s.length();
	int ans = 0;
	for (int i = 0; i < len;++i)
	for (int j = i + 1; j < len;++j)
	if (s[i]>s[j])ans++;
	return ans;
}
bool cmp(const node& p1, const node& p2){
	if (p1.r!=p2.r)
		return p1.r < p2.r;
	return p1.s < p2.s;
}
int main(){
//	ifstream in("C:\\temp.txt");
	int T,N,M;
	string s;
	cin >> T;
	while (T--){
		cin >> M >> N;
		for (int i = 0; i < N; ++i){
			cin>>data[i].s;
			data[i].r = GetR(data[i].s);
		}
		sort(data, data + N, cmp);
		for (int i = 0; i < N; ++i)
			cout << data[i].s << endl;
	}

	return 0;
}