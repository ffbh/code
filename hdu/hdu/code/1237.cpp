#include <iostream>
#include <string>
//#include <fstream>
#include <stack>
#include <map>
using namespace std;
int main(){
	//ifstream in("C:\\temp.txt");
	map<char, int> mci;
	mci['+'] = 1;
	mci['-'] = 1;
	mci['*'] = 2;
	mci['/'] = 2;

	while (1){
		char eee;
		stack<double> sd;
		stack<char> sc;
		double d;
		char c;
		bool flag = 1;
		do{
			if (flag == 1){
				scanf("%lf", &d);
				sd.push(d);
				flag = 0;
			}
			else{
				scanf("%c", &c);
				while (!sc.empty() && mci[sc.top()] >= mci[c]){
					char cc = sc.top();
					sc.pop();
					if (cc == '*'){
						double a = sd.top();
						sd.pop();
						double b = sd.top();
						sd.pop();
						a *= b;
						sd.push(a);
					}
					else if (cc == '-'){
						double a = sd.top();
						sd.pop();
						double b = sd.top();
						sd.pop();
						b -= a;
						sd.push(b);
					}
					else if (cc == '+'){
						double a = sd.top();
						sd.pop();
						double b = sd.top();
						sd.pop();
						b += a;
						sd.push(b);
					}
					else{
						double a = sd.top();
						sd.pop();
						double b = sd.top();
						sd.pop();
						b /= a;
						sd.push(b);
					}
				}
				sc.push(c);
				flag = 1;
			}
		} while (scanf("%c",&eee)!=EOF&&eee!='\n');
		if (sd.size() == 1)break;
		while (!sc.empty()){
			char cc = sc.top();
			sc.pop();
			double a = sd.top();
			sd.pop();
			double b = sd.top();
			sd.pop();
			if (cc == '+'){
				b += a;
				sd.push(b);
			}
			else if (cc == '-'){
				b -= a;
				sd.push(b);
			}
			else if (cc == '*'){
				b *= a;
				sd.push(b);
			}
			else{
				b /= a;
				sd.push(b);
			}
		}
		double ans = sd.top();
		sd.pop();
		printf("%.2f\n", ans);
	}
	return 0;
}