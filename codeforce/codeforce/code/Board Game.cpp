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
ifstream in("/home/fbh/CLionProjects/acm/InOutput/input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


int px,py,vx,vy;

void input(){
	in>>px>>py>>vx>>vy;


}
int x,y;
bool cale(){
	if(x > 0){
		px-=x;
		vx-=x;
	}
	if(y > 0){
		py-=y;
		vy-=y;
	}
	int dp,dv;
	if(px==py){
		dp = 0;
		dv = vx - px;

	}
	else if(px > py){
		dp = px-py;
		dv = vy - py;
	}
	else{
		dp = py - px;
		dv = vx- px;

	}

	return dp <= dv;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if(px+py <= max(vx,vy)){
			cout<<"Polycarp"<<endl;
		}
		else if(px+py > vx+vy){
			cout<<"Vasiliy"<<endl;
		}
		else{
			if(vx >= vy){
				x = vx - vy;
				y = 0;
			}
			else{
				x = 0;
				y = vy - vx;
			}

			if(cale()){
				cout<<"Polycarp"<<endl;
			} else{
				cout<<"Vasiliy"<<endl;
			}


		}












	}


	return 0;
}





