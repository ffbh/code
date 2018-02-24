#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[32];
int getNum(string& s){
	int num = 0;
	for (int i = 0; i < 8; ++i)
		num = num * 2 + s[i] - '0';
	return num;
}

int main(){
	ifstream in("C:\\temp.txt");
	string s;
	int pc ;
	int accu;
	while (cin >> s){
		data[0] = getNum(s);
		for (int i = 1; i < 32; ++i){
			cin >> s;
			data[i] = getNum(s);
		}
		pc = accu = 0;
		bool flag = 1;
		while (flag){
			int type = data[pc] / 32;
			int value = data[pc] % 32;
			switch (type){
			case 0:
				data[value] = accu;
				pc++;
				pc %= 32;
				break;
			case 1:
				accu = data[value];
				pc++;
				pc %= 32;
				break;
			case 2:
				if (accu == 0)
					pc = value;
				else{
					pc++;
					pc %= 32;
				}
				break;
			case 3:
				pc++;
				pc %= 32;
				break;
			case 4:
				accu += 255;
				accu %= 256;
				pc++;
				pc %= 32;
				break;
			case 5:
				++accu;
				accu %= 256;
				pc++;
				pc %= 32;
				break;
			case 6:
				pc = value;
				break;
			case 7:
				flag = 0;
				break;
			}
		}
		string ans = "";
		for (int i = 0; i < 8; ++i){
			ans = char(accu % 2 + '0') + ans;
			accu /= 2;
		}
		cout << ans << endl;
	}
	
	return 0;
}