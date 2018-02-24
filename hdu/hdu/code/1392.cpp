#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct Node{
	int x, y;
}data[100010];
int N;
vector<int> V;
int dis(Node& p1, Node& p2){
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

bool cmp(Node& a, Node& b){
	int m = ((b.x - data[0].x)*(a.y - data[0].y)
		- (b.y - data[0].y)*(a.x - data[0].x));
	if (m > 0)
		return 1;
	else if (m<0){
		return 0;
	}
	else{
		int mminy = min(a.y, b.y);
		if (mminy <= data[0].y){
			return dis(data[0], a) > dis(data[0], b);
		}
		else{
			return dis(data[0], a) < dis(data[0], b);
		}
	
	}

}

bool OK(int a, int b, int c){
	return ((data[c].x - data[a].x)*(data[b].y - data[a].y)
		- (data[c].y - data[a].y)*(data[b].x - data[a].x)) >= 0;
}

void Slove(){
	for (int i = 0; i < N; ++i){
		while (V.size() >= 2 && !OK(V[V.size() - 2], V[V.size() - 1], i))
			V.pop_back();
		V.push_back(i);
	}
}

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	vector<Point> outerTrees(vector<Point>& points) {
		V.clear();
		int u = 0;
		for (int i = 0; i < points.size(); ++i){
			data[i].x = points[i].x;
			data[i].y = points[i].y;
			if (data[i].x < data[u].x || data[i].x == data[u].x&&data[i].y < data[u].y)
				u = i;
		}
		if (u)
			swap(data[0], data[u]);
		N = points.size();
		sort(data + 1, data + N, cmp);
		Slove();
		vector<Point> ans;
		for (int i = 0; i < V.size(); ++i){
			int idx = V[i];
			ans.push_back(Point(data[idx].x, data[idx].y));
		}
	
		return ans;

	}
};


int main(){
	ifstream in("C:\\input.txt");

	Solution so;

	//vector<Point> p = { {1, 1 }, { 2, 2 }, { 2, 0 }, { 2, 4 }, { 3, 3 }, { 4, 2 }};
	vector<Point> p = {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}, {3, 2}, {3, 1}, {3, 0}, {2, 0}};

	vector<Point> ans =  so.outerTrees(p);
	int k = 0;




	return 0;
}