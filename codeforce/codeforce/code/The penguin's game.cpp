#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;
int n, x, y;
//ifstream in("C:\\input.txt");
istream& in = cin;


bool query(vector<pair<int, int> >& q){
	fflush(stdout);
	int sum = 0;
	for (pair<int, int> p : q){
		sum += p.second - p.first + 1;
	}
	cout << "? " << sum << " ";
	for (pair<int, int> p : q){
		for (int i = p.first; i <= p.second; ++i)
			cout << i << " ";
	}
	cout << endl;
	fflush(stdout);
	int ans;
	in >> ans;
	if (sum % 2 == 0){
		return ans != 0;
	}
	else{
		return ans == y;
	}
}


bool query(int l, int r){
	fflush(stdout);
	int sum = r - l + 1;
	cout << "? " << sum << " ";

	for (int i = l; i <= r; ++i)
		cout << i << " ";

	cout << endl;
	fflush(stdout);
	int ans;
	in >> ans;
	if (sum % 2 == 0){
		return ans != 0;
	}
	else{
		return ans == y;
	}
}
vector<int> ANS;
void binary(int l,int r){
	if (l == r){
		ANS.push_back(l);
	}
	else{
		int mid = (l + r) / 2;
		if (query(l, mid)){
			binary(l, mid);
		}
		else{
			binary(mid + 1, r);
		}
	}
}


vector<pair<int, int> > ALL, LF;
void slove(){
	int l = 0, r = LF.size() - 1;
	while (l < r){
		int mid = (l + r) / 2;
		vector<pair<int, int> > tmp;
		for (int i = l; i <= mid; ++i){
			tmp.push_back(LF[i]);
		}
		if (query(tmp)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	pair<int, int> L = LF[l];
	pair<int, int> R = ALL[l * 2 + 1];
	if (L > R)
		swap(L, R);
	binary(L.first, L.second);
	binary(R.first, R.second);
	cout << "! ";
	for (int i = 0; i < 2; ++i)
		cout << ANS[i] << " ";
	cout << endl;
	fflush(stdout);
}


void dfs(vector<pair<int,int> >& fa){
	vector<pair<int, int> > all, lf;
	for (pair<int, int> p : fa){
		int mid = (p.first + p.second)/2;
		all.push_back(make_pair(p.first, mid));
		all.push_back(make_pair(mid + 1, p.second));
		lf.push_back(make_pair(p.first, mid));
	}
	if (query(lf)){
		ALL = all;
		LF = lf;
		slove();

	}
	else{
		dfs(all);
	}
}

int main(){
	
	
	in >> n >> x >> y;
	
	vector<pair<int, int> > P;
	P.push_back(make_pair(1, n));
	dfs(P);





	return 0;
}





