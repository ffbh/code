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

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	int x1, y1, x2, y2, x, y;
	in >> x1 >> y1 >> x2 >> y2 >> x >> y;
	int a = abs(x2 - x1);
	int b = abs(y2 - y1);
	if (a%x != 0 || b%y != 0){
		cout << "NO" << endl;
	}
	else{
		a /= x;
		b /= y;
		if (a % 2 == b % 2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
















	return 0;
}





