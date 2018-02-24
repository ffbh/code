#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string ff[] = {
	"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
	"ten","eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

string ff2[] = {
	"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int ok;
	while (cin >> N){
		if (N == 0){
			cout << ff[N] << endl;
			continue;
		}
		int t = N / 1000;
		ok = 0;
		if (t){
			N %= 1000;
			printf("%s thousand", ff[t].c_str());
			ok = 1;
		}
		t = N / 100;
		if (t){
			N %= 100;
			if (ok)
				printf(" and ");
			
			printf("%s hundred", ff[t].c_str());
			ok = 1;
		}
		if (N == 0){
			cout << endl;
			continue;
		}
		if (ok)
			printf(" and ");
		ok = 0;
		if (N < 20 && N != 0){
			printf("%s\n", ff[N].c_str());
			continue;
		}
		else if (N>=20){
		
			t = N / 10;
			N %= 10;
			printf("%s", ff2[t - 1].c_str());
			ok = 1;
		}
		if (N){
			if (ok)
				printf("-");
			printf("%s", ff[N].c_str());
		}
		cout << endl;
	}

	return 0;
}