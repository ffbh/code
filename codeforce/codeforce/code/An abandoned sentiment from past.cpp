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
int n, m, pos, a[110], b[110];

void input(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n >> m;
	pos = -1;
	for (int i = 1; i <= n; ++i){
		in >> a[i];
		if (a[i] == 0)
			pos = i;
	}
	for (int i = 1; i <= m; ++i)
		in >> b[i];
}


int main(){
	input();

	if (m >= 2){
		cout << "Yes" << endl;
	}
	else{
		a[pos] = b[1];
		bool flag = 0;
		for (int i = 1; i < n; ++i){
			if (a[i]>a[i + 1]){
				flag = 1;
				break;
			}
		}

		if (flag){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}


	}















	return 0;
}





