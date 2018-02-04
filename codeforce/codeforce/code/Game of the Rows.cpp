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
int a[10010];
int numa, numb, numo;
void input(){
	//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n >> k;
	for (int i = 1; i <= k; ++i)
		in >> a[i];



}


bool judge(){
	numa = n * 2;
	numb = n;
	numo = 0;
	sort(a + 1, a + k + 1);
	reverse(a + 1, a + k + 1);
	for (int i = 1; i <= k; ++i){
		if (a[i] >= 4){
			int p = a[i] / 4;
			if (numb >= p){
				numb -= p;
				a[i] %= 4;
			}
			else{
				a[i] -= numb * 4;
				numb = 0;
			}
		}
	}
	sort(a + 1, a + k + 1);
	reverse(a + 1, a + k + 1);
	for (int i = 1; i <= k && numb != 0; ++i){
		if (a[i] == 3){
			a[i] = 0;
			numb--;
		}
		else if (a[i] == 2){
			a[i] = 0;
			numo++;
			numb--;
		}
		else if (a[i] == 1){
			a[i] = 0;
			numa++;
			numb--;
		}
	}

	sort(a + 1, a + k + 1);
	reverse(a + 1, a + k + 1);
	for (int i = 1; i <= k; ++i){
		if (a[i] >= 2){
			int p = a[i] / 2;
			if (numa >= p){
				numa -= p;
				a[i] %= 2;
			}
			else{
				a[i] -= numa * 2;
				numa = 0;
			}
		}

	}

	sort(a + 1, a + k + 1);
	reverse(a + 1, a + k + 1);
	for (int i = 1; i <= k && numa != 0; ++i){
		if (a[i] == 1){
			numa--;
			a[i] = 0;
		}
	}
	int sum = 0;
	for (int i = 1; i <= k; ++i)
		sum += a[i];

	return sum <= numo;
}

int main(){
	input();


	if (judge()){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}















	return 0;
}

