#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	int M1, M2;
	int R1, R2, R3;
	while (cin >> M1 >> M2){
		cin >> s;
		R1 = R2 = R3 = 0;
		int len = s.length();
		for (int i = 0; i < len; ++i)
			switch (s[i]){
			case 'A':
				R1 = M1;
				break;
			case 'B':
				R2 = M2;
				break;
			case 'C':
				M1 = R3;
				break;
			case 'D':
				M2 = R3;
				break;
			case 'E':
				R3 = R1 + R2;
				break;
			case 'F':
				R3 = R1 - R2;
				break;
			default: break;
		}
		printf("%d,%d\n", M1, M2);
		
		
		
		
		
	
	
	}

	return 0;
}