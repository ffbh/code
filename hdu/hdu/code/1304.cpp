#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	string name, ntemp;
	int time, ttemp;
	int point, ptemp;
	while (cin >> N){
		time = -1;
		while (N--){
			ttemp = 0;
		    ptemp = 0;
			cin >> ntemp;
			int M = 4;
			while (M--){
				int a,b;
				cin >> a >> b;
				if (b){
					ttemp++;
					ptemp += (a - 1) * 20 + b;
				}
			}
			if (ttemp > time || ttemp == time&&point > ptemp){
				name = ntemp;
				time = ttemp;
				point = ptemp;
			}
		}
		printf("%s %d %d\n", name.c_str(), time, point);
	}
	return 0;
}