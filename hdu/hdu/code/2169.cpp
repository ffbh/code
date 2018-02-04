#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	string s;
	string data;
	int N;
	cin >> T;
	while (T--){
		cin >> s;
		if (s == "b"){
			cin >> data;
			int ans = 0;
			int base = 1;
			for (int i = data.length() - 1; i >= 0; --i){
				ans += base*(data[i] - '0');
				base *= -2;
			}
			printf("From binary: %s is %d\n", data.c_str(), ans);
		}
		else{
			cin >> N;
			int temp = N;
			string ans = "";
			while (N){
				int mod = N % 2;
				N /= 2;
				if (mod < 0){
					mod += 2;
					N--;
				}
				N = -N;
				ans = char('0' + mod) + ans;
			}
			if (ans.length() == 0)
				printf("From decimal: 0 is 0\n");
			else
				printf("From decimal: %d is %s\n", temp, ans.c_str());
		}

	}
	return 0;
}