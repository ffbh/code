#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Point{
	int x, y;
}data[10];
#define exp (1e-8)
int chaji(int a, int b, int c){
	return (data[c].x - data[a].x)*(data[b].y - data[a].y)
		- (data[c].y - data[a].y)*(data[b].x - data[a].x);
}



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	cin >> N;
	printf("INTERSECTING LINES OUTPUT\n");
	while (N--){
		for (int i = 0; i < 4;++i)
			cin >> data[i].x >> data[i].y;
		int k1 = chaji(0, 1, 2);
		int k2 = chaji(0, 1, 3);
		if (k1 == 0 && k2 == 0)
			printf("LINE\n");
		else if (k1 == k2)
			printf("NONE\n");
		else{
			double s1 = double(k1);
			double s2 = double(k2);
			printf("POINT %.2f %.2f\n", (s1*data[3].x - s2*data[2].x) / (s1 - s2),
				(s1*data[3].y - s2*data[2].y) / (s1 - s2));
		}
	}
	printf("END OF OUTPUT\n");





	return 0;
}