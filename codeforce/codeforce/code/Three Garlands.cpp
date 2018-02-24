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


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back


int a[3];


void input(){
	for (int i = 0; i < 3; ++i)
		in >> a[i];


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		sort(a, a + 3);
		if (a[0] == 1){
			cout << "YES" << endl;
		}
		else if (a[0] == 2){
			if (a[1] == a[2] && a[1] == 4){
				cout << "YES" << endl;
				return 0;
			}
			if (a[1] == 2){
				cout << "YES" << endl;
			}
			else if (a[1] == 3){
				if (a[2] == 3){
					cout << "NO" << endl;
				}
				else{
					cout << "NO" << endl;
				}
			}
			else {
				cout << "NO" << endl;
			}


		}
		else if (a[0] == 3){
			if (a[1] == 3 && a[2] == 3){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
		else{
			cout << "NO" << endl;
		}











	}


	return 0;
}





