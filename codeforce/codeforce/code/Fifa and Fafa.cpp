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

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


double R, x1, yy1, x2, y2;

void input(){
	in >> R >> x1 >> yy1 >> x2 >> y2;


}

pdd get(){
	double x = x2 - x1;
	double y = y2 - yy1;
	double lll = sqrt(x*x + y*y);
	if (fabs(lll) > 1e-9){
		double X = -x * R / lll;
		double Y = -y*R / lll;
		return mp(X + x1, Y + yy1);
	}
	else{
		return mp(x1 + R, yy1);
	}

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		double d = pow((x2 - x1), 2) + pow(y2 - yy1, 2);
		if ((d - R*R) > 0 || fabs(d - R*R) < 1e-9){
			printf("%.8f %.8f %.8f\n", x1, yy1, R);
		}
		else{
			double len = R + sqrt(d);
			double r = len / 2.0;
			pdd p = get();
			printf("%.8f %.8f %.8f\n", (p.first + x2) / 2.0, (p.second + y2) / 2.0, r);

		}














	}


	return 0;
}





