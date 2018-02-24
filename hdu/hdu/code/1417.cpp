#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	int x1, y1, z1, x2, y2, z2;
	int ok;
}S, T;
void get(){
	if (S.ok){
		if (T.x2 < S.x1||T.y2 < S.y1||T.z2 < S.z1||T.x1>S.x2||T.y1>S.y2||T.z1>S.z2)
			S.ok = 0;
		else{
			if (S.x1 < T.x1) S.x1 = T.x1;
			if (S.y1 < T.y1) S.y1 = T.y1;
			if (S.z1 < T.z1) S.z1 = T.z1;
			if (S.x2 > T.x2) S.x2 = T.x2;
			if (S.y2 > T.y2) S.y2 = T.y2;
			if (S.z2 > T.z2) S.z2 = T.z2;
		}
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		cin >> S.x1 >> S.y1 >> S.z1;
		int d;
		cin >> d;
		S.x2 = S.x1 + d;
		S.y2 = S.y1 + d;
		S.z2 = S.z1 + d;
		S.ok = 1;
		while (--N){
			cin >> T.x1 >> T.y1 >> T.z1;
			cin >> d;
			T.x2 = T.x1 + d;
			T.y2 = T.y1 + d;
			T.z2 = T.z1 + d;
			get();
		}
		if (S.ok){
			cout << (S.x2 - S.x1)*(S.y2 - S.y1)*(S.z2 - S.z1) << endl;
		}
		else
			cout << 0 << endl;
	}
	return 0;
}