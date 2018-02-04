#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;


int main(){
	map<char, int> mci;
	mci['A'] = 5;
	mci['B'] = 4;
	mci['C'] = 3;
	mci['D'] = 2;
	mci['F'] = 1;
	ifstream in("C:\\temp.txt");
	stringstream ss;
	string s;
	while (getline(cin, s)){
		ss.clear();
		ss.str(s);
		char c;
		double sum = 0;
		int num = 0;
		bool flag = 1;
		while (ss >> c){
			if (!mci[c])
				flag = 0;
			sum += mci[c] - 1;
			num++;
		}
		if (flag)
			printf("%.2f\n", sum / num);
		else
			printf("Unknown letter grade in input\n");


	}



	return 0;
}