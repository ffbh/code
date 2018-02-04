#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int a, b;
	while (cin >> a >> b){
		if (a == 0 && b == 0)
			break; 
		int max_x, max_y, min_x, min_y;
		max_x = min_x = a;
		max_y = min_y = b;
		while (cin >> a >> b){
			if (a == 0 && b == 0)
				break;
			if (max_x < a)
				max_x = a;
			if (min_x>a)
				min_x = a;
			if (max_y < b)
				max_y = b;
			if (min_y>b)
				min_y = b;
		}
		printf("%d %d %d %d\n", min_x, min_y, max_x, max_y);
	}
	return 0;
}