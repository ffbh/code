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
ifstream in("/home/ffbh/CLionProjects/acm/InOutput/input.txt");
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
pii p1[4],p2[4];
pii pa1,pa2;
pii pb1,pb2;
bool in1(int x,int y){
    return x>=pa1.first&&x<=pa2.first&&y>=pa1.second&&y<=pa2.second;
}


bool in2(int x,int y){
    int x1 = p2[0].first;
    int x2 = p2[1].first;
    int x3 = p2[3].first;
    int D = pb1.second;
    int U = pb2.second;
    if(x>=pb1.first&&x<=pb2.first&&y>=pb1.second&&y<=pb2.second){
    //    int yyy = y - p2[1].second;
        int yyy = y;
        int py = abs(x2 - x);
        int dd = D + py;
        int uu = U - py;
        if(x == x2){
            return 1;
        }
        else if(x<x2){
            return yyy>=dd&&yyy<=uu;
        }
        else{
            return yyy>=dd&&yyy<=uu;
        }
        assert(0);
    }
    return 0;


}

void input(){
    for(int i=0;i<4;++i){
        in>>p1[i].first>>p1[i].second;
    }
    for(int i=0;i<4;++i){
        in>>p2[i].first>>p2[i].second;
    }


}


bool ok(){
    for(int i=0;i<4;++i){
        if(in2(p1[i].first,p1[i].second)){
            return 1;
        }

    }
    for(int i=0;i<4;++i){
        if(in1(p2[i].first,p2[i].second)){
            return 1;
        }

    }

    if(in2((pa1.first+pa2.first)/2,(pa1.second+pa2.second)/2)){
        return 1;
    }
    if(in1((pb1.first+pb2.first)/2,(pb1.second+pb2.second)/2)){
        return 1;
    }
    return 0;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

        pa1.first = pa1.second = 500;
        pa2.first = pa2.second = -500;

        for(int i=0;i<4;++i){
            pa1.first = min(pa1.first,p1[i].first);
            pa1.second = min(pa1.second,p1[i].second);
            pa2.first = max(pa2.first,p1[i].first);
            pa2.second = max(pa2.second,p1[i].second);
        }



        sort(p2,p2+4);
        pb1.first = pb1.second = 500;
        pb2.first = pb2.second = -500;


        for(int i=0;i<4;++i){
            pb1.first = min(pb1.first,p2[i].first);
            pb1.second = min(pb1.second,p2[i].second);
            pb2.first = max(pb2.first,p2[i].first);
            pb2.second = max(pb2.second,p2[i].second);
        }


        if(ok()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }




	}


	return 0;
}





