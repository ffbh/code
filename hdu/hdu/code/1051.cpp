#include <iostream>
#include <algorithm>
//#include <fstream>
using namespace std;
struct Point{
	int x, y;
	bool visited;
	bool operator<(const Point& p)const{
		if (x != p.x)
			return x<=p.x;
		return y < p.y;
	}
};
int n;
Point array[5010];
int allVisited(){
	int i;
	for (i = 0; i < n;++i)
	if (!array[i].visited) break;
	return i;
}
int main(){
	int T;
//	ifstream in("C:\\temp.txt");
	cin >> T;
	while (T--){
		cin >> n;
		memset(array, 0, 5010 * sizeof(Point));
		for (int i = 0; i < n; ++i){
			scanf("%d%d", &array[i].x, &array[i].y);
			//in >> array[i].x >> array[i].y;
			array[i].visited = 0;
		}
		sort(array, array + n);
		int index;
		int time=0;
		while ((index=allVisited())!=n){
			time++;
			array[index].visited = 1;
			for (int i = index+1; i < n;++i)
				if (!array[i].visited&&array[index].x <= array[i].x&&array[index].y <= array[i].y){
					index = i;
					array[index].visited = 1;
				}
		}
		cout << time << endl;
	}
	
}

