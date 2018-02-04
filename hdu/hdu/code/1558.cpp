#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	double x1, y1, x2, y2;
};
Node data[1010];
int f[1010];
int num[1010];
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}
bool _cross(int a, int b){
	double k1 = (data[b].x1 - data[a].x1)*(data[a].y2 - data[a].y1)
		- (data[b].y1 - data[a].y1)*(data[a].x2 - data[a].x1);
	double k2 = (data[b].x2 - data[a].x1)*(data[a].y2 - data[a].y1)
		- (data[b].y2 - data[a].y1)*(data[a].x2 - data[a].x1);
	return k1*k2 <= 0;
}

bool cross(int a, int b){
	return _cross(a, b) && _cross(b, a);
}
int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	char c;
	int size;
	int ok = 0;
	while (T--){
		if (ok)cout << endl;
		ok = 1;
		int M;
		cin >> M;
		size = 1;
		for (int i = 0; i <= M; ++i){
			f[i] = i;
			num[i] = 1;
		}
		while (M--){
			cin >> c;
			if (c == 'P'){
				cin >> data[size].x1 >> data[size].y1 >> data[size].x2 >> data[size].y2;
				size++;
				for (int i = 1; i < size-1;++i)
				if ((cross(i, size - 1))){
					int fi = find(i);
					if (fi != size - 1){
						f[fi] = size - 1;
						num[size - 1] += num[fi];
					}
				}
			}
			else{
				int Id;
				cin >> Id;
				cout << num[find(Id)] << endl;
			}
		}
	}
	return 0;
}