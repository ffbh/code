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

int N, R;
int X[1010];
double Y[1010];



void input(){
	in >> N >> R;
	for (int i = 1; i <= N; ++i)
		in >> X[i];


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i <= N; ++i){
			double y = R;
			for (int j = 1; j < i; ++j){
				if (X[i] == X[j]){
					y = max(y, Y[j] + 2 * R);
				}
				else if (abs(X[i] - X[j]) < 2 * R){
					double pp = sqrt(4 * R * R - (X[i] - X[j])*(X[i] - X[j]));
					y = max(y, Y[j] + pp);

				}
				else if (abs(X[i] - X[j]) == 2 * R){
					y = max(y, Y[j]);
				}
			}
			Y[i] = y;
		}

		for (int i = 1; i <= N; ++i)
			printf("%.8f ", Y[i]);
		cout << endl;

	}


	return 0;
}





