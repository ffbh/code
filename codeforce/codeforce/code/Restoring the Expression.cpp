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


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back

string str;



void input(){
	in >> str;


}


bool judeg(int al,int ar,int bl,int br,int cl,int cr){
	assert(al <= ar&&ar < bl&&bl <= br&&br < cl&&cl <= cr);

	if (str[al] == '0' || str[bl] == '0' || str[cl] == '0'){
		return 0;
	}
	int flag = 0;
	while (cr >= cl){
		int a = 0, b = 0;
		if (ar >= al){
			a = str[ar] - '0';
		}
		if (br >= bl){
			b = str[br] - '0';
		}
		int val = (a + b + flag) % 10;
		flag = (a + b + flag) / 10;
		if (val + '0' != str[cr]){
			return 0;
		}
		ar--;
		br--;
		cr--;
	}
	return flag == 0;
}


int main(){
	

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		if (str[0] == '0'){
			putchar('0');
			putchar('+');
			int len = (str.length() - 1) / 2;
			
			for (int i = 1; i < str.length(); ++i){
				putchar(str[i]);
				len--;
				if (len == 0){
					putchar('=');
				}

			}
			cout << endl;

		}
		else{
			if (str.length() % 2 == 1 && str[str.length() / 2] == '0'){
				bool ok = 1;
				for (int i = 0; i < str.length() / 2; ++i){
					if (str[i] != str[i + str.length() / 2 + 1]){
						ok = 0;
						break;
					}
				}
				if (ok == 1){
					for (int i = 0; i < str.length(); ++i){
						if (i == str.length() / 2){
							putchar('+');
							putchar('0');
							putchar('=');
						}
						else{
							putchar(str[i]);
						}

					}
					cout << endl;
					return 0;
				}
			}
			int len = str.length() / 2;
			for (int i = 0; i < len; ++i){
				if (i == 2){
					int t = 0;
				}

				int lena = i + 1;
				int restlen = str.length() - lena;
				int lenc = max(lena,restlen / 2 + restlen % 2);
				int al, ar, bl, br, cl, cr;
				al = 0;
				ar = i;
				bl = i + 1;
				cr = str.length() - 1;
				cl = cr - lenc + 1;
				br = cl - 1;
		
				if (judeg(al, ar, bl, br, cl, cr)){
					for (int i = 0; i < str.length(); ++i){
						if (i == bl){
						
							putchar('+');
						}
						if (i == cl){
					
							putchar('=');
						}
				
						putchar(str[i]);


					}
			
					cout << endl;
					return 0;
				}
				lenc++;
				al = 0;
				ar = i;
				bl = i + 1;
				cr = str.length() - 1;
				cl = cr - lenc + 1;
				br = cl - 1;
				if (judeg(al, ar, bl, br, cl, cr)){
					for (int i = 0; i < str.length(); ++i){
						if (i == bl){
							putchar('+');
						}
						if (i == cl){
							putchar('=');
						}
						putchar(str[i]);


					}

					cout << endl;
					return 0;
				}

			}

		}




	}


	return 0;
}





