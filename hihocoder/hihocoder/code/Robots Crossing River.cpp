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

bool END(){
	for (int i = 0; i < 3;++i)
	if (a[i] != 0)
		return 0;
	return 1;
}

void input(){
	for (int i = 0; i < 3; ++i)
		in >> a[i];


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if (END()){
			cout << 0 << endl;
		}
		else{
			LL ans = 0;
			sort(a, a + 3, greater<int>());
			if ((a[1] + a[2]) >= a[0]){
				LL sum = 0;
				for (int i = 0; i < 3; ++i)
					sum += a[i];
				ans = sum / 20 + (sum % 20 == 0 ? 0 : 1);
			}
			else{
				LL large = a[0];
				LL small = a[1] + a[2];
				ans = small / 10;
				large -= ans * 10;
				small %= 10;
				if (small != 0){
					ans++;
					if (small + small < 15){
						large -= 15 - small;
					}
					else{
						large -= small;
					}
				}

				ans += large / 15 + (large % 15 == 0 ? 0 : 1);
			}

			
			cout << ans * 6 << endl;
		}


	}


	return 0;
}





