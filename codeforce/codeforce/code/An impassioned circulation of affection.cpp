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
//ifstream in("C:\\input.txt");
istream& in = cin;
int n, m;
string s;
int h[1510][30];
void input(){
	in >> n >> s;


}

int cale(int num, char c){
	int & ref = h[num][c - 'a'];
	if (ref != 0)
		return ref;
	int now = 0;
	int rest = num;
	int L = -1;
	for (int i = 0; i < n; ++i){
		if (s[i] == c){
			now++;
		}
		else {
			while (rest == 0){
				if (s[L + 1] != c)
					rest++;
				L++;
			}
			rest--;
		}
		ref = max(ref, i - L);
	}
	return ref;
}

int main(){
	input();

	in >> m;
	while (m-- > 0){
		int num;
		char c;
		in >> num >> c;
		printf("%d\n", cale(num, c));


	}
















	return 0;
}





