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
int a[210];
void input(){
	///ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n;
	m = n * 2;
	for (int i = 0; i < m; ++i)
		in >> a[i];
}


int main(){
	input();
	sort(a, a + m);
	if (a[n] != a[n-1]){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
















	return 0;
}





