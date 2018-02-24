#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	int x1, y1, x2, y2;
};
Node data[31][101];

bool ok(Node& a, Node& b){
	_int64 k1 = _int64(a.x2 - a.x1)*(b.y1 - a.y1)
		- (b.x1 - a.x1)*(a.y2 - a.y1);
	_int64 k2 = _int64(a.x2 - a.x1)*(b.y2 - a.y1)
		- (b.x2 - a.x1)*(a.y2 - a.y1);
	return k1*k2 <= 0;
}
int num[31];
int N;
bool slove(){
	for (int i = 0; i < N;++i)
		for (int j = i + 1; j < N;++j)
		for (int k1 = 0; k1 < num[i];++k1)
		for (int k2 = 0; k2 < num[j];++k2)
		if (ok(data[i][k1], data[j][k2]) && ok(data[j][k2], data[i][k1]))
			return 1;
		return 0;

}

int main(){
	ifstream in("C:\\temp.txt");

	while (cin >> N){
		for (int i = 0; i < N; ++i){
			cin >> num[i];
			num[i]--;
			cin >> data[i][0].x1 >> data[i][0].y1;
			for (int j = 0; j < num[i]; ++j)
				cin >> data[i][j].x2 >> data[i][j].y2;
			for (int j = 1; j < num[i]; ++j){
				data[i][j].x1 = data[i][j - 1].x2;
				data[i][j].y1 = data[i][j - 1].y2;
			}
		}
		if (slove())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;	
	}
	return 0;
}