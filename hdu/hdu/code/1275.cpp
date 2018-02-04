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


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define EXP (1e-9)
typedef long long LL;


double s, a, b;
int t;

void input(){
	in >> s >> a >> b >> t;
}

struct Node{
	double now;
	double speed;
	int dir;
	Node go(double time)const {
		double d;
		if (dir == 1){
			d = s - now;
		}
		else{
			d = now;
		}
		Node ret;
		ret.dir = dir;
		ret.speed = speed;
		if (d - time * speed  > EXP){
			ret.now = now + dir * time*speed;
		}
		else{
			if (ret.dir == 1){
				ret.now = s - speed * (time - d / speed);
			}
			else{
				ret.now = speed * (time - d / speed);
			}
			ret.dir = -1 * ret.dir;
		}
		return ret;
	}
	Node(double a,double b,int c){
		now = a;
		speed = b;
		dir = c;
	}
	Node(){}
	
};

bool ok(Node& p1,Node& p2,Node& n1,Node& n2){
	double p = p1.now - p2.now;
	double n = n1.now - n2.now;
	return p*n < EXP;
}

int main(){
	

	int CASE;
	in >> CASE;
	while (CASE--){
		input();
		vector<double> SPEED;
		double sa = s / a;
		double sb = s / b;
		for (int i = 1; i <  2 * t; ++i){
			SPEED.push_back(i*sa);
			SPEED.push_back(i*sb);
		}
		sort(SPEED.begin(), SPEED.end());
		Node A(0, a, 1);
		Node B(s, b, -1);
		double pre = 0;
		int pos = 0;
		double anstime, ansdist;
		while (1){
			double delta = fabs(SPEED[pos] - pre);
			if (delta < EXP){
				pos++;
				continue;
			}
			Node na = A.go(delta);
			Node nb = B.go(delta);
		//	printf("A %.5f   B %.5f\n", na.now, nb.now);
			if (ok(A, B, na, nb)){
				t--;
			}
			if (t == 0){
				double L = 0;
				double R = delta;
				while (R - L > EXP){
					double mid = (L + R) / 2.0;
					Node ta = A.go(mid);
					Node tb = B.go(mid);
					if (fabs(ta.now - tb.now) < EXP){
						L = mid;
						break;
					}
					else if (ok(A,B,ta,tb)){
						R = mid;

					}
					else{
						L = mid;
					}
				}
				anstime = L + pre;
				double dd = A.go(L).now;
				ansdist = min(s-dd, dd);
				break;
			}
			A = na;
			B = nb;
			pre = SPEED[pos];
			pos++;
		}


		printf("Time=%.3f Dist=%.3f\n", anstime, ansdist);


	}


	return 0;
}





