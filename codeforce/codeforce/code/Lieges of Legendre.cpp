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


int n,k;
int a[100010];

void input(){
	in>>n>>k;
	for(int i=1;i<=n;++i){
		in>>a[i];
	}


}

int cale(int n){
    int b = 0;
    while(n > 2 && n % 2 == 0){
        n/=2;
        b++;
    }
    return b;
}



int p[40];

bool win(){
    int A,B;
    A=B=0;
    for(int i=0;i<40;++i){
        if(p[i]==0)
            continue;
        if(i % 2 == 0){
            B++;
        }
        else{
            A++;
        }
    }
    A%=2;
    B%=2;
    if(A==0&&B==0){
        return 0;
    }
    else{
        return 1;
    }
}


bool fail(){
    int A,B;
    A=B=0;
    for(int i=0;i<40;++i){
        if(p[i]==0)
            continue;
        if(i % 2 == 0){
            B++;
        }
        else{
            A++;
        }
    }
    A%=2;
    B%=2;
    if(A&&B){
        return 1;
    }
    else if(A&&!B){
        return 0;
    }
    else if(!A&&B){
        return 1;
    }
    else{
        return 1;
    }


}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if(k % 2 == 0){
			int one = 0,even = 0;
			for(int i=1;i<=n;++i){
				if(a[i] % 2 == 0){
					even ++;
				}
				else if(a[i] == 1){
					one ++;
				}
			}
			even %= 2;
			one %= 2;
			if(even != one){
				cout<<"Kevin"<<endl;
			}
			else{
				cout<<"Nicky"<<endl;
			}
		}
		else{
            int one = 0,even = 0,odd=0,ee=0;
            for(int i=1;i<=n;++i){
                if(a[i] >  2 && a[i] % 2== 0){
                    p[cale(i)]^=1;
                }
                else if(a[i] == 1 || a[i] == 3){
                    one ++;
                }
                else if(a[i] % 2 == 1 && a[i] >3){
                    odd++;
                }
                else{
                    assert(a[i]==2);
                }
            }
            one %= 2;
            int w = win();
            if(w || !w && one ==1){
                cout<<"Kevin"<<endl;
            }
            else{
                cout<<"Nicky"<<endl;
            }




		}













	}


	return 0;
}





