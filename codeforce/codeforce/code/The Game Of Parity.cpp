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
int even,odd;


void input(){
	in>>n>>k;
	for(int i=1;i<=n;++i){
		int t;
		in>>t;
		if(t % 2 == 0){
			even++;
		}
		else{
			odd++;
		}
	}


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int S,D;
		D = (n-k)/2;
		S = n-k-D;


		if(D >= odd){
			cout<<"Daenerys"<<endl;
		}
		else{
			if(S > D){
                if(D < even){
                    cout<<"Stannis"<<endl;
                }
                else{
                    if(k % 2 == 0){
                        cout<<"Daenerys"<<endl;
                    }
                    else{
                        cout<<"Stannis"<<endl;
                    }
                }
			}
			else{
				if(S < even) {
                    if(S > 0) {
                        cout << "Daenerys" << endl;
                    }
                    else{
                        if(odd % 2 == 0){
                            cout << "Daenerys" << endl;
                        }
                        else{
                            cout<<"Stannis"<<endl;
                        }
                    }
				}
				else{

					if(k % 2 == 0){
						cout << "Daenerys" << endl;
					}
					else{
						cout<<"Stannis"<<endl;
					}
				}
			}


		}













	}


	return 0;
}





