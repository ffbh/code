#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{
	bool leaf;
	bool val;//0 and , 1 or
}data[210];
bool src[210];
bool change[210];
vector<int> vi[210];
const int MMAX = (1 << 28);
int DFS(int p){
	if (data[p].leaf){
		src[p] = data[p].val;
		change[p] = 0;
		return -1;
	}
	int l = vi[p][0];
	int r = vi[p][1];
	int L = DFS(l);
	int R = DFS(r);
	if (data[p].val){//or
		src[p] = src[l] | src[r];
		if (src[l] && src[r]){//11

			int mmin = MMAX;
			if (change[l] && mmin > L)
				mmin = L;
			if (change[r] && mmin > R)
				mmin = R;
			if (mmin != MMAX){
				change[p] = 1;
				return mmin + 1;
			}
		}
		else if (src[l] && !src[r]){//10

			change[p] = 1;
			return 1;
		}
		else if (!src[l] && src[r]){//01

			change[p] = 1;
			return 1;
		}
		else{//00

			int mmin = MMAX;
			if (change[l] && mmin > L)
				mmin = L;
			if (change[r] && mmin > R)
				mmin = R;
			if (mmin != MMAX){
				change[p] = 1;
				return mmin;
			}
		}
	}
	else{
		src[p] = src[l] & src[r];
		if (src[l] && src[r]){

			int mmin = MMAX;
			if (change[l] && mmin > L)
				mmin = L;
			if (change[r] && mmin > R)
				mmin = R;
			if (mmin != MMAX){
				change[p] = 1;
				return mmin;
			}
		}
		else if (src[l] && !src[r]){

			change[p] = 1;
			return 1;
		}
		else if (!src[l] && src[r]){

			change[p] = 1;
			return 1;
		}
		else{

			int mmin = MMAX;
			if (change[l] && mmin > L)
				mmin = L;
			if (change[r] && mmin > R)
				mmin = R;
			if (mmin != MMAX){
				change[p] = 1;
				return mmin + 1;
			}
		}
	}
	change[p] = 0;
	return -1;

}


int main(){
	ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	int root;
	for (int i = 1; i <= N; ++i){
		int f;
		string s;
		cin >> f >> s;
		if (f)
			vi[f].push_back(i);
		else
			root = i;
		if (s == "TRUE"){
			data[i].leaf = 1;
			data[i].val = 1;
		}
		else if (s == "FALSE"){
			data[i].leaf = 1;
			data[i].val = 0;
		}
		else if (s == "AND"){
			data[i].leaf = 0;
			data[i].val = 0;
		}
		else{
			data[i].leaf = 0;
			data[i].val = 1;
		}
	}
	cout << DFS(root) << endl;

	return 0;
}