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
int n, m;
char mmp[110][110];
int h[266];

bool ok(int lx,int rx,int ly,int ry,char c){
	for (int i = lx; i <= rx;++i)
	for (int j = ly; j <= ry; ++j){
		if (mmp[i][j] != c)
			return 0;
	}
	return 1;
}




bool judgeR(){
	if (n % 3 != 0)
		return 0;
	int delta = n / 3;
	bool used[3] = { 0 };
	for (int i = 0; i < 3; ++i){
		used[h[mmp[i*delta][0]]] = 1;
//		cout << i*delta << endl;
//		cout << mmp[i*delta][1] << endl;
	}

	for (int i = 0; i < 3; ++i)
	if (!used[i])
		return 0;
	for (int i = 0; i < 3; ++i){
		if (!ok( i*delta, (i + 1)*delta - 1,0,m-1, mmp[i*delta][0]))
			return 0;
	}
	return 1;




}


bool judgeC(){
	if (m % 3 != 0){
		return 0;
	}
	int delta = m / 3;

	bool used[3] = { 0 };
	for (int i = 0; i < 3; ++i){
		used[h[mmp[0][i*delta]]] = 1;
		//cout << mmp[0][i*delta] << endl;

	}

	for (int i = 0; i < 3;++i)
	if (!used[i])
		return 0;
	for (int i = 0; i < 3; ++i){
		if (!ok(0, n-1, i*delta, (i + 1)*delta - 1, mmp[0][i*delta]))
			return 0;
	}
	return 1;
}


int main(){
	//ifstream in("C:\\input.txt");
istream& in = cin;
	h['R'] = 0;
	h['G'] = 1;
	h['B'] = 2;
	in >> n >> m;
	for (int i = 0; i < n; ++i)
		in >> (mmp[i]);
	int used[3] = { 0 };
	for (int i = 0; i < m; ++i){
		used[h[mmp[0][i]]] = 1;
	}

	bool f = 1;
	for (int i = 0; i < 3; ++i){
		if (!used[i]){
			f = 0;
			break;
		}
	}
	bool ans;
	if (f){
		ans = judgeC();
	}
	else{
		ans = judgeR();
	}


	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;









	return 0;
}





