#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Point{
	int x, y;
}data[710];
#define OK(a,b,c)( (data[b].x - data[a].x)*(data[c].y - data[a].y)== (data[b].y - data[a].y)*(data[c].x - data[a].x))


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		for (int i = 0; i < N; ++i)
			//in >> data[i].x >> data[i].y;
			scanf("%d%d", &data[i].x, &data[i].y);
		int ans = 0;
		for (int i = 0; i < N;++i)
		for (int j = i + 1; j < N; ++j){
			int num = 2;
			for (int k = j + 1; k < N; ++k)
			if (OK(i, j, k))
				num++;
			if (ans < num)
				ans = num;
		}
		cout << ans << endl;
	}
	return 0;
}