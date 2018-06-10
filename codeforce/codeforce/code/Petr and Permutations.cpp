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

int n;
int a[1000010];
int aim[1000010];
void input(){
	in>>n;
	for(int i=1;i<=n;++i){
		in>>aim[i];
		a[i] = i;
	}
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for(int i=1;i<=3*n;++i){
            srand(time(0));
			int p1 = abs(rand())%n+1;
			int p2 = abs(rand())%n+1;
			swap(a[p1],a[p2]);
		}

		int num1 = 0;
		for(int i=1;i<=n;++i){
			if(a[i] == aim[i]){
				num1++;
			}
		}

        for(int i=1;i<=4*n+1;++i){
            int p1 = abs(rand())%n+1;
            int p2 = abs(rand())%n+1;
            swap(a[p1],a[p2]);
        }

        int num2 = 0;
        for(int i=1;i<=n;++i){
            if(a[i] == aim[i]){
                num2++;
            }
        }
        if(n < 1000){
            cout<<"Petr"<<endl;
            return 0;
        }

		if(num1 > num2){
			cout<<"Petr"<<endl;
		}
		else{
			cout<<"Um_nik"<<endl;
		}










	}


	return 0;
}





