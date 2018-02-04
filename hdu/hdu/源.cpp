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
#include <cassert>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;





void input(){



}


int main(){
	LL p;
	while (in >> p){
		if (p == 0){
			cout << "NO!" << endl;
			continue;
		}

		p++;
		while (p % 2 == 0)
			p /= 2;
		while (p % 3 == 0)
			p /= 3;
		if (p == 1){
			cout << "YES!" << endl;
		}
		else{
			cout << "NO!" << endl;
		}
	}


	return 0;
}





