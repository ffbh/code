#include<iostream>
#include <string>
using namespace std;



void show(const string& s, int start, int end){
	while (start <= end)
		printf("%c", s[end--]);

}
int main(){
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	while (n--){
		getline(cin, s);
		int start = 0;
		int end = 0;
		int len = s.length();
		while (1){
			int i;
			for (i = start; i < len;++i)
			if (s[i] == ' ')
				break;
				end = i-1;
				show(s, start, end);
				if (i == len)
					break;
				cout << " ";
				start = end+2;
				
		}
		cout << endl;
		
	}



	
}