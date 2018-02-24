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
int n;
bool odd;
void input(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n;
	odd = 0;
	for (int i = 1; i <= n; ++i){
		int t;
	//	in >> t;
		scanf("%d", &t);
		if (t % 2 == 1){
			odd = 1;
		}
	}



}


int main(){
	input();

	if (odd)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
















	return 0;
}





