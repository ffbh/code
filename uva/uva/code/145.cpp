#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
double price[5][3] = { 0.1, 0.06, 0.02, 0.25, 0.15, 0.05, 0.53, 0.33, 0.13, 0.87, 0.47, 0.17, 1.44, 0.8, 0.3 };

struct Node{
	int A, B, C;
	Node(){
		A = B = C = 0;
	}
	void sub(const Node& p){
		A -= p.A;
		B -= p.B;
		C -= p.C;
	}

	void add(const Node& p){
		A += p.A;
		B += p.B;
		C += p.C;
	}
};
int dr, er, nr;

Node cale(int p){
	Node ans;
	if (p <= dr){
		ans.C = p;
	}
	else if (p <= er){
		ans.C = dr;
		ans.A = p - dr;
	}
	else if (p <= nr){
		ans.C = dr;
		ans.A = er - dr;
		ans.B = p - er;
	}
	else{
		ans.C = dr + p - nr;
		ans.A = er - dr;
		ans.B = nr - er;
	}
	return ans;
}

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;

	char number;
	string tel;
	int sh, sm, eh, em;
	dr = 8 * 60;
	er = 18 * 60;
	nr = 22 * 60;
	double ansP;
	while (in >> number && number != '#'){
		in >> tel >> sh >> sm >> eh >> em;
		int st = sh * 60 + sm;
		int en = eh * 60 + em;
		Node ans;
		if (st == en){
			ans.A = er - dr;
			ans.B = nr - er;
			ans.C = dr + 24 * 60 - nr;
			
		}
		else if (st < en){

			Node a = cale(st);
			
			ans = cale(en);
			ans.sub(a);
		}
		else{
			ans = cale(24 * 60);
			Node b = cale(st);
			ans.sub(b);
			Node c = cale(en);
			ans.add(c);
		}
		while (tel.length() < 10)
			tel = " " + tel;
		cout << tel;
		printf("%6d%6d%6d  %c", ans.A, ans.B, ans.C,number);
		printf("%8.2f\n", ans.A*price[number - 'A'][0]+ ans.B*price[number - 'A'][1]+ ans.C*price[number - 'A'][2]);
	}




	return 0;
}