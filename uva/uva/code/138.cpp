#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
#define MMAX (int(9e7+10))
//long long sum[MMAX];
int ans[][2] = { 6, 8,
35, 49,
204, 288,
1189, 1681,
6930, 9800,
40391, 57121,
235416, 332928,
1372105, 1940449,
7997214, 11309768,
46611179, 65918161
};
int main(){
	ifstream in("C:\\input.txt");
	ofstream out("C:\\input.txt");
	//istream& in = cin;
/*	for (int i = 1; i < MMAX; ++i){
		sum[i] = sum[i - 1] + i;
	}
	int num = 0;
	
	for (int i = 5; i < MMAX; ++i){
		int l = 1;
		int r = i;
		while (l <= r){
			int mid = (l + r) / 2;
			long long lf = sum[mid - 1];
			long long rg = sum[i] - sum[mid];
			if (lf == rg){
				num++;
				out <<   mid << "," << i << endl;
				break;
			}
			else if (lf < rg){
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}

	}
	cout << num << endl;*/


	for (int i = 0; i < 10; ++i){
		printf("%10d%10d\n", ans[i][0], ans[i][1]);
	}











	return 0;
}