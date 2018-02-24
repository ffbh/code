#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
string S;
int t;
double Exp = 1e-10;
int pos;
bool ZERO(double d){
	return fabs(d) < Exp;
}
double getDouble(){
	while (pos<S.length() && S[pos] == ' ')pos++;
	double ans = 0;
	double flag = 0;
	double f = 1;
	while (S[pos] >= '0'&&S[pos] <= '9' || S[pos] == '.' ||S[pos]=='-'){
		if (S[pos] == '-')
			f = -1;
		else if (S[pos] == '.'){
			flag = 0.1;
		}
		else if (!ZERO(flag)){
			ans += flag*(S[pos] - '0');
			flag *= 0.1;
		}
		else{
			ans = ans * 10 + S[pos] - '0';
		}
		pos++;
	}
	return f*ans;
}

double CaleS(){
	while (S[pos] == ' ')pos++;
	if (S[pos] == '('){
		pos++;
		while (S[pos] == ' ')pos++;
		double x, y;
		double p = getDouble();
		while (S[pos] == ' ')pos++;
		x = CaleS();
		y = CaleS();
		while (S[pos] != ')')pos++;
		pos++;
		return  p*(x + y) + (1 - p)*(x - y);
	}
	else
		return getDouble();
}


int main(){
	ifstream in("C:\\input.txt");
	while (getline(cin, S) && S != "()"){
		pos = 0;
		printf("%.2f\n", CaleS());
	}
	return 0;
}