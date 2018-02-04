#include <iostream>
using namespace std;

int max(int a, int b){
	return a > b ? a : b;
}
int min(int a, int b){
	return a < b ? a : b;
}
int main(){
	int s, m;
	int t1,t2,t;
	bool flag = false;
	cout << right;
	while(cin >> s >> m){
		printf("%10d%10d    ", s, m);
		t1 = max(s, m);
		t2 = min(s, m);
		if (t1!=t2)
			while (1){
				if (t=t1%t2){
					t1 = t2;
					t2 = t;
				}
				else break;

			}
		else flag = false;
		if (t2 == 1) flag = 1;//最大公约数是否为1

		if (flag) cout << "Good Choice" << endl << endl;
		else cout << "Bad Choice" << endl<<endl;
		flag = 0;
	
	
	}
	return 0;
}
