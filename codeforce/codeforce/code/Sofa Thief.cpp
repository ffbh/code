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
#define MMAX ((int)1e5+10)
int D, N, M;
struct Node{
	int x1, y1, x2, y2;
}data[MMAX];
int L[MMAX], R[MMAX], T[MMAX], B[MMAX];
int cl, cr, ct, cb;


int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> D >> N >> M;
	for (int i = 1; i <= D; ++i){
		in >> data[i].x1 >> data[i].y1 >> data[i].x2 >> data[i].y2;
		if (data[i].x1 > data[i].x2)
			swap(data[i].x1, data[i].x2);
		if (data[i].y1 > data[i].y2)
			swap(data[i].y1, data[i].y2);
	}
	in >> cl >> cr >> ct >> cb;

	memset(L, 0, sizeof(L));
	memset(R, 0, sizeof(R));
	memset(T, 0, sizeof(T));
	memset(B, 0, sizeof(B));

	for (int i = 1; i <= D; ++i){
		L[data[i].x1]++;
		R[data[i].x2]++;
		T[data[i].y1]++;
		B[data[i].y2]++;
	}

	for (int i = 1; i < MMAX; ++i){
		L[i] += L[i - 1];
		R[i] += R[i - 1];
		T[i] += T[i - 1];
		B[i] += B[i - 1];
	}

	int ans = -1;
	for (int i = 1; i <= D; ++i){
		int a, b, c, d;
		a = L[data[i].x2 - 1];
		b = D - R[data[i].x1];
		if (data[i].x1 != data[i].x2){
			a--;
			b--;
		}
		c = T[data[i].y2 - 1];
		
		d = D - B[data[i].y1];
		if (data[i].y1 != data[i].y2){
			c--;
			d--;
		}
		if (a == cl&&b == cr&&c == ct&&d == cb){
			ans = i;
			break;
		}
	}

	cout << ans << endl;









	return 0;
}





