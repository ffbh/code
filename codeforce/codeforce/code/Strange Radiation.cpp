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
#define MMAX (int(1e6)+10)
#define EXP (1e-8)
int n;
double s;
vector<pair<int, double> > V[2];
int h[MMAX];
//int numL[MMAX], numR[MMAX];

bool ok(double time,int id){
	vector<pair<int, int> >all;
	for (pair<int, double> p : V[0]){
		double mint = double(p.first) / (p.second + s);
		double maxt = double(p.first) / p.second;
		if (mint - time > -EXP)
			continue;
		else if (time - maxt > -EXP){
			all.push_back(make_pair(0, int(1e6)));
			continue;
		}
		double delta = (time * (s*s-p.second*p.second)-s*p.first+p.second*p.first) / s;
		if (delta > 1e6)
			delta = 1e6;
		int d = (int)floor(delta);
		int l = p.first;
		int r = d + l;
		if (l < 0)
			l = 0;
		if (r>int(1e6))
			r = int(1e6);
		if (l <= r){
			all.push_back(make_pair(l, r));
		}
	}
	sort(all.begin(), all.end());
	int cur = 0;
	for (pair<int, int> p : all){
		if (cur < p.first)
			cur = p.first;
		while (cur <= p.second){
			h[cur] = id;
			cur++;
		}
	}

	all.clear();
	for (pair<int, double> p : V[1]){
		p.first = int(1e6) - p.first;
		double mint = double(p.first) / (p.second + s);
		double maxt = double(p.first) / p.second;
		if (mint - time > -EXP)
			continue;
		else if (time - maxt > -EXP){
			all.push_back(make_pair(0, int(1e6)));
			continue;
		}
		double delta = (time * s + time * p.second - p.first) *(s - p.second) / s;
		if (delta > 1e6)
			delta = 1e6;
		int d = (int)floor(delta);
		int l = p.first;
		int r = d + l;
		if (l < 0)
			l = 0;
		if (r>int(1e6))
			r = int(1e6);
		if (l <= r){
			l = (int)1e6 - l;
			r = (int)1e6 - r;
			swap(l, r);
			all.push_back(make_pair(l, r));
		}
	}

	sort(all.begin(), all.end());
	cur = 0;
	for (pair<int, int> p : all){
		if (cur < p.first)
			cur = p.first;
		while (cur <= p.second){
			if (h[cur] == id)
				return 1;
			cur++;
		}
	}
	return 0;
}
int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	in >> n >> s;
	for (int i = 0; i < n; ++i){
		int x, v, t;
		in >> x >> v >> t;
		V[t - 1].push_back(make_pair(x, v));
	}
	double Ltime = 1e18;
	double Rtime = 1e18;

	for (pair<int, double> p : V[0]){
	//	numL[p.first]++;
		Ltime = min(Ltime, double(p.first) / p.second);
	}
	for (pair<int, int> p : V[1]){
	//	numR[p.first]++;
		Rtime = min(Rtime, (1e6 - double(p.first)) / p.second);
	}
	/*for (int i = 1; i < MMAX; ++i)
		numL[i] += numL[i - 1];
	for (int i = MMAX - 2; i >= 0; --i)
		numR[i] += numR[i + 1];*/

	double L = 0;
	double R = max(Ltime, Rtime);
	int id = 1;
	while (R - L > EXP){
		double mid = (L + R) / 2.0;
		if (ok(mid, id++)){
			R = mid;
		}
		else{
			L = mid;
		}
	}
	
	printf("%.10f\n", L + EXP);

	return 0;
}





