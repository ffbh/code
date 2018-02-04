#include <iostream>
#include <string>
#include <iomanip>
//#include <fstream>
using namespace std;
double len;
int num;
int time(string s){
	if (s == "-:--:--") return 0;
	int hour = atoi(s.substr(0,1).c_str());
	int minute = atoi(s.substr(2,2).c_str());
	int second = atoi(s.substr(5).c_str());
	return hour * 3600 + minute * 60 + second;
}

void fun(int sum){
	int ave = double(sum) / len + 0.5;
	int m = ave / 60;
	int s = ave % 60;
	printf("%3d: %d:%02d min/km\n", num, m, s);
		
		
}
int main(){
	int n;
	string s;
	int result;
	int sum;
	bool flag;
	//ifstream in("C:\\temp.txt");
	cin >> n >> len;
	while (cin>>num){
		int i = 0;
		sum = 0;
		flag = 1;
		while (i < n) {
			cin >> s;
			result = time(s);
			if (result == 0) flag = false;
			sum += result;
			i++;
		}
		if (!flag) {
			cout << setw(3) << right << num << ": -" << endl;
			continue;
		}
		fun(sum);
	
	}
	return 0;
}