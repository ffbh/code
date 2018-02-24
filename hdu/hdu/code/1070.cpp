#include <iostream>
#include <string>
using namespace std;
int MIN(int a, int b){
	return a < b ? a : b;
}
int main(){
	
	string s;
	double m;
	int T,n;
	int MaxV;
	cin >> T;
	while (T--){
		cin >> n;
		m = 0;
		MaxV = 0;
		string temp;
		int P, V, tV;
		double c;
		while (n--){
			cin >> temp;
			scanf("%d%d", &P, &V);
			int k = V / 200;
			k = MIN(k, 5);
			tV = k * 200;
			c = double(tV) / P;
			if (c > m){
				m = c;
				s = temp;
				MaxV = V;
				
			}
			else if (c == m&&MaxV<V){
				m = c;
				s = temp;
				MaxV = V;
			}
		}
		cout << s << endl;
	}

}