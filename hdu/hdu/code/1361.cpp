#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;
int data[101];
stack<int> sc;
string pace;

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		while (!sc.empty()) sc.pop();
		int N;
		cin >> N;
		for (int i = 1; i <= N; ++i)
			cin >> data[i];
		int pre = 0;
		pace = "";
		for (int i = 1; i <= N; ++i){
			while (pre < data[i]){
				pace += '(';
				pre++;
			}
			pace += ')';
		}
		bool sign = 0;
		for (int i = 0; i < pace.length(); ++i){
			if (pace[i] == '(')
				sc.push(1);
			else{
				if (sign)
					putchar(' ');
				else
					sign = 1;
				int temp = sc.top();
				sc.pop();
				cout << temp;
				if (!sc.empty())
					sc.top() += temp;
			}
		}
		cout << endl;
	}
	return 0;
}