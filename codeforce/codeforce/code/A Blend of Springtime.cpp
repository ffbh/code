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



string s;


void input(){
	in>>s;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		if(s.length() < 3){
			cout<<"No"<<endl;
			return 0;
		}

		for(int i=1;i<s.length()-1;++i){
			vector<char> p;
			p.push_back(s[i-1]);
			p.push_back(s[i]);
			p.push_back(s[i+1]);
			sort(p.begin(),p.end());
			if(p[0]=='A'&&p[1]=='B'&&p[2]=='C'){
                cout<<"Yes"<<endl;
                return 0;
			}
		}

        cout<<"No"<<endl;
        return 0;












	}


	return 0;
}





