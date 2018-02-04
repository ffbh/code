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


LL n, k;
string digit;
int high;
void input(){
	in >> n >> k;


}

void ch(){
	digit = "";
	while (n){
		digit += ('0' + n % 2);
		n /= 2;
	}
	reverse(digit.begin(), digit.end());
	high = digit.size() - 1;
	for (int i = 0; i < 100; ++i)
		digit += '0';
}


void EP(int h,int num){
	if (num == 1){
		printf("%d ",h);
	}
	else{
		while (num-- > 1){
			printf("%d ", --h);
		}
		printf("%d ", h);

	}
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		ch();
		int num = 0;
		for (char c : digit){
			if (c == '1'){
				num++;
			}
		}

		if (num > k){
			cout << "No" << endl;
			return 0;
		}

		cout << "Yes" << endl;

		LL sum = 0;
		int pos,  rest = num;
		for (pos = 0; pos < digit.size(); ++pos){
			sum = sum * 2 + digit[pos] - '0';
			if (digit[pos] == '1'){
				rest--;
			}
			if (sum + rest <= k){
				
			}
			else{
				if (digit[pos] == '1'){
					rest++;
				}
				pos--;
				high++;
				sum /= 2;

				break;
			}
			high--;
		}

		if (rest == 0){
			for (int i = 1; i < sum; ++i)
				printf("%d ", high);
			k -= (sum - 1);
			EP(high, k);
		}
		else{
			for (int i = 1; i <= sum; ++i)
				printf("%d ", high);
			k -= sum;
			pos++;
			high--;
			while (pos < digit.size()){
				if (digit[pos] == '1'){
					rest--;
					if (rest == 0){
						EP(high, k);
					}
					else{
						printf("%d ", high);
						k--;
					}
				}

				pos++;
				high--;
			}

		}



		cout << endl;



	}


	return 0;
}





