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
	// in("C:\\input.txt");
	istream& in = cin;
	int s, v1, v2, t1, t2;
	in >> s >> v1 >> v2 >> t1 >> t2;
	int a = t1 + s*v1 + t1;
	int b = t2 + s*v2 + t2;
	if (a < b){
		cout << "First" << endl;
	}
	else if (a == b){
		cout << "Friendship" << endl;
	}
	else{
		cout << "Second" << endl;
	}
















	return 0;
}





