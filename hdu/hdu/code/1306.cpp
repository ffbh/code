#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int gcd(int n, int m){
	if (m == 0)
		return n;
	else
		return gcd(m, n%m);
}

int main(){
	ifstream in("C:\\temp.txt");
	string s1, s2;
	while (cin >> s1&&s1 != "-1"){
		cin >> s2;
		int ans = 0;
		string temp1, temp2;
		for (int i = 0; i < s1.length(); ++i){
			temp1 = s1.substr(i);
			for (int j = 0; j < s2.length(); ++j){
				int temp = 0;
				temp2 = s2.substr(j);
				int max = min(temp1.length(), temp2.length());
				for (int k = 0; k < max; ++k)
				if (temp1[k] == temp2[k])
					temp += 2;
				if (temp>ans)
					ans = temp;
			}
		}
		int fenmu = s1.length() + s2.length();
		int fenzi = ans;
		if (fenmu!=fenzi&&fenzi){
			ans = gcd(fenzi, fenmu);
			fenmu /= ans;
			fenzi /= ans;
			printf("appx(%s,%s) = %d/%d\n", s1.c_str(), s2.c_str(), fenzi, fenmu);
		}
		else if (fenzi==0)
			printf("appx(%s,%s) = 0\n", s1.c_str(), s2.c_str());
		else
			printf("appx(%s,%s) = 1\n", s1.c_str(), s2.c_str());
	}
	return 0;
}