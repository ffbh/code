#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
int data[21000];
int T, N, M;


int main(){
	ifstream in("C:\\input.txt");
	
	in >> T;
	while (T-- > 0){
		in >> N >> M;
		for (int i = 1; i <= N; ++i)
			in >> data[i];
		while (M-- > 0){
			int l, r;
			in >> l >> r;
			if (l > r){
				swap(l, r);
			}
	
		}


	}



	return 0;
}