#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
bool map[1010][1010];
void getK(string& s){
	for (int i = 0; i < s.length(); ++i)
	if (s[i] > '9' || s[i] < '0')
		s[i] = ' ';
	

}



int main(){
	ifstream in("C:\\temp.txt");
	string s;
	stringstream ss;
	while (getline(cin, s)){
		memset(map, 0, sizeof(map));
		getK(s);
		ss.clear();
		ss.str(s);
		int x1, y1, x2, y2;
		int area = 0;
		while (ss >> x1 >> y1 >> x2 >> y2){
			if (x1 > x2)
				swap(x1, x2);
			if (y1 > y2)
				swap(y1, y2);
			y2--;
			x2--;
			for (int i = x1; i <= x2;++i)
			for (int j = y1; j <= y2;++j)
			if (map[i][j] == 0){
				map[i][j] = 1;
				area++;
			}
		}
		cout << area << endl;
	}
	return 0;
}