#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
#define Exp (1e-10)
int N, M;
struct Star{
	double x, y, z;
	double M(){
		return sqrt(x*x + y*y + z*z);
	}
}star[510];
struct Telescopes{
	double x, y, z, ang;
	double M(){
		return sqrt(x*x + y*y + z*z);
	}
}tel[51];


bool judge(Star& s){
	for (int i = 1; i <= M; ++i){
		double ab = s.x*tel[i].x + s.y*tel[i].y + s.z*tel[i].z;
		double abm = s.M()*tel[i].M();
		double angle = acos(ab / abm);
		if (tel[i].ang - angle > -Exp)
			return 1;
	}
	return 0;
}


int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N&&N){
		for (int i = 1; i <= N; ++i)
			cin >> star[i].x >> star[i].y >> star[i].z;
		cin >> M;
		for (int i = 1; i <= M; ++i)
			cin >> tel[i].x >> tel[i].y >> tel[i].z >> tel[i].ang;

		int ans = 0;
		for (int i = 1; i <= N;++i)
		if (judge(star[i]))
			ans++;
		cout << ans << endl;


	}
















	return 0;
}