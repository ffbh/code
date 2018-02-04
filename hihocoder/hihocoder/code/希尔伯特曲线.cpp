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
long long n, x, y;
struct Node{
	long long lx, ly, rx, ry;
	bool inner(long long x,long long y){
		return x >= lx&&y >= ly&&x <= rx&&y <= ry;
	}
};


void input(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	in >> n >> x >> y;

}

int change[4][4] = { { 1, 0, 0, -1 }, { -1, 1, 0, 0 }, { 0, -1, 1, 0 }, { 0, 0, -1, 1 } };
int Move[4][4] = { { 0, 1, 2, 3 }, { 0, 3, 2, 1 }, { 2, 3, 0, 1 }, { 2, 1, 0, 3 } };



int main(){
	input();
	long long ans = 0;
	Node now, a[4];
	now.lx = now.ly = 1;
	now.rx = now.ry = pow(2, n);
	long long block_num = (long long)now.rx * now.ry;
	block_num /= 4;
	int cur = 0;
	while (n-->0){
		long long midx = (now.lx + now.rx) / 2;
		long long midy = (now.ly + now.ry) / 2;

		a[0].lx = now.lx;
		a[0].ly = now.ly;
		a[0].rx = midx;
		a[0].ry = midy;

		a[1].lx = now.lx;
		a[1].ly = midy + 1;
		a[1].rx = midx;
		a[1].ry = now.ry;

		a[2].lx = midx + 1;
		a[2].ly = midy + 1;
		a[2].rx = now.rx;
		a[2].ry = now.ry;

		a[3].lx = midx + 1;
		a[3].ly = now.ly;
		a[3].rx = now.rx;
		a[3].ry = midy;

		for (int i = 0; i < 4; ++i){
			if (a[Move[cur][i]].inner(x, y)){
				now = a[Move[cur][i]];
				cur = (cur + 4 + change[cur][Move[cur][i]]) % 4;
				break;
			}
			ans += block_num;
		}
		block_num /= 4;
	}

	cout << ans+1 << endl;

















	return 0;
}





