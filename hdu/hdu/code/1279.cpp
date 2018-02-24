#include <iostream>

using namespace std;
int main(){
	int N;
	cin >> N;
	int m;
	int pre;
	bool yy;
	while (N--){
		cin >> m;
		yy = 1;
		pre = 0;
		while (m != 1){
			if (m % 2 == 1){
				if (pre)
					printf("%d ", pre);
				pre = m;
				m = m * 3 + 1;
				yy = 0;
			}
			else
				m /= 2;
		
		}
		if (yy)printf("No number can be output !\n");
		else cout << pre << endl;
	}


	return 0;
}