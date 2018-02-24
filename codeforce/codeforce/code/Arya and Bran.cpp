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


void input(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;



}

int a[110];
int main(){
	input();
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	int n, k;
	in >> n >> k;
	for (int i = 1; i <= n; ++i)
		in >> a[i];
	int sum = 0;
	int ans = -1;
	for (int i = 1; i <= n; ++i){
		sum += a[i];
		if (sum > 8){
			sum -= 8;
			k -= 8;
		}
		else{
			k -= sum;
			sum = 0;
		}
		if (k <= 0){
			ans = i;
			break;
		}
	}
	cout << ans << endl;











	return 0;
}





