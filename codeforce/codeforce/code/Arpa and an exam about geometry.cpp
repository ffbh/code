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


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;

LL ax, ay, bx, by, cx, cy;



void input(){
	in >> ax >> ay >> bx >> by >> cx >> cy;


}

bool judge(){
	if ((bx - ax)*(cy - by) == (by - ay)*(cx - bx))
		return 0;

	LL ab = (ax - bx)*(ax - bx) + (ay - by)*(ay - by);
	LL bc = (bx - cx)*(bx - cx) + (by - cy)*(by - cy);

	return ab == bc;

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if (judge()){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
		













	}


	return 0;
}





