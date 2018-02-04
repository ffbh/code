#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;

	int N;
	in >> N;
	double tp, fp, fn, tn;
	tp = fp = fn = tn = 0;
	for (int i = 1; i <= N; ++i){
		char a, b;
		in >> a >> b;
		if (b == '+'&&a == '+')
			tp += 1;
		else if (b == '+'&&a == '-'){
			fp += 1;
		}
		else if (b == '-'&&a == '+'){
			fn += 1;
		}
		else{
			tn += 1;
		}

	}
	

	//double re = double(tp) / (tp + fn);
//	double pr = double(tp) / (tp + fp);
///	printf("%.2f%%\n", 200 * re*pr / (re + pr));
	printf("%.2f%%\n", 200 * tp / (2 * tp + fp + fn));
	return 0;
}