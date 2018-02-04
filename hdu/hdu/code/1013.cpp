#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool sg(string n){
	return n.size() == 1;
}
string fun(string n){
	vector<char> v(n.begin(),n.end());
	vector<char>::iterator it = v.begin();
	vector<char> old;
	long sum=0;
	while (it != v.end()){
		long t = *it++ - '0';
		sum += t;
	}
	while (sum){
		int t = sum % 10;
		old.push_back(t + '0');
		sum /= 10;
	}
	return string(old.rbegin(), old.rend());
}
int main(){
	string n;
	
	while (cin >> n){
		if (n.size() == 1 && n[0] == '0') break;
		while (!sg(n)) n = fun(n);
		cout << n << endl;



	}




	return 0;
}