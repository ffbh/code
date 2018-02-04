#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	cin >> N;
	char op;
	int a, b;
	while (N--){
		cin >> op >> a >> b;
		if (op == '+')
			cout << a + b << endl;
		else if (op == '-')
			cout << a - b << endl;
		else if (op == '*')
			cout << a*b << endl;
		else{
			if (a > b&&a%b == 0)
				cout <<  a / b << endl;
			else
				printf("%.2f\n", double(a) / b);
		}
	}


	return 0;
}