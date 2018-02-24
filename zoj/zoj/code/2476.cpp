#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int data[10];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	stringstream ss;
	long long tmp;
	long long sum;
	int temp;
	while (cin >> N&&N){
		sum = 0;
		while (N--){
			string s;
			cin >> s;
			int num = -1;
			for (int i = 0; i < s.length();++i)
			if (s[i]<'0' || s[i]>'9'){
				s[i] = ' ';
				num++;
			}
			tmp = 0;
			ss.clear();
			ss.str(s);
			while (num--){
				ss >> temp;
				tmp = tmp * 1000 + temp;
			}
			ss >> temp;
			tmp = tmp * 100 + temp;
			sum += tmp;
		}
		data[4] = sum % 100;
		sum /= 100;
		for (int i = 3; i >= 1; --i){
			data[i] = sum % 1000;
			sum /= 1000;
		}
		bool f = 0;
		putchar('$');
		if (data[1]){
			printf("%d,", data[1]);
			f = 1;
		}
		if (f)
			printf("%03d,", data[2]);
		else if (data[2]){
			printf("%d,", data[2]);
			f = 1;
		}
		if (f)
			printf("%03d", data[3]);
		else 
			printf("%d", data[3]);
		printf(".%02d\n", data[4]);
	}
	return 0;
}