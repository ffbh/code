#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct Point{
	int x, y;
};

struct Node{
	vector<Point> vp;
	int life;
	void add(vector<Point>& v){
		for (int i = 0; i < v.size(); ++i)
			vp.push_back(v[i]);
	}
};

class GO{
	int N;
	int map[40][40];
	int f[410];
	Node data[410];
	GO(int n){
		N = n;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < 410; ++i)
			f[i] = i;
	}
	void set(int x, int y, int flag){
		map[x][y] = flag;




	}




};





int main(){
	ifstream in("C:\\input.txt");




	return 0;
}