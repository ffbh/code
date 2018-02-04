#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream in("C:\\temp.txt");
	int N,T;
	int a, b;
	int now;
	in >> N;
	while (N--){
		in >> T;
		now = 2;
		for (int i = 0; i < T; ++i){
			in >> a >> b;
			//scanf("%d%d", &a, &b);
			if (a == now)
				now = b;
			else if (b == now)
				now = a;
		}
		cout << now << endl;
	
	
	}

	return 0;
}