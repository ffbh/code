#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int a[20], b[20], c[20],N,M;

int main(){
	ifstream in("C:\\input.txt");
	int T;
	in >> T;
	while (T--){
		in >> M>>N;
		int amass = 1;
		for (int i = 1; i <= N; ++i){
			in >> a[i];
			amass *= a[i];
		}
		for (int i = 1; i <= N; ++i)
			in >> b[i];
		
		







	}

















	return 0;
}