#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
struct Node{
	long long   x, y;
}P, A , B, C;

long long  getArea(Node& a, Node& b, Node& c){
	long long  x1 = a.x - c.x;
	long long  y1 = a.y - c.y;
	long long  x2 = b.x - c.x;
	long long  y2 = b.y - c.y;
	return abs((x1*y2) - (x2*y1));

}
int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> P.x >> P.y >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
		long long  trasum = getArea(P, A, B) + getArea(P, A, C) + getArea(P, B, C);
		long long  tra = getArea(A, B, C);
		if (trasum == tra){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}






	}




	return 0;
}