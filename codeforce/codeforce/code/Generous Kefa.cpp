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
int n, k;
string s;
int h[266];
void input(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n >> k;
	in >> s;

}

bool judge(){
	for (char c = 'a'; c <= 'z';++c)
	if (h[c] > k)
		return 0;
	return 1;


}

int main(){
	input();

	for (char c : s){
		h[c]++;
	}

	if (judge())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;















	return 0;
}





