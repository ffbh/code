#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int getTime(int h, int m, int s){
	return 3600 * h + m * 60 + s;
}
int main(){
	//ifstream in("C:\\temp.txt");
	int N,M;
	cin >> N;
	string ss, se;
	string s;
	int mmax, mmin;
	int a, b, c;
	while (N--){
		cin >> M;
		mmax = INT_MIN;
		mmin = INT_MAX;
		for (int i = 0; i < M; ++i){
			cin >> s;
			//in >> a >> b >> c;
			scanf("%d:%d:%d", &a, &b, &c);
			int stime = getTime(a, b, c);
			if (stime < mmin){
				ss = s;
				mmin = stime;
			}
			//in >> a >> b >> c;
			scanf("%d:%d:%d", &a, &b, &c);
			int etime = getTime(a, b, c);
			if (etime>mmax){
				se = s;
				mmax = etime;
			}
		}
		cout << ss << " " << se << endl;
	
	
	
	}



	return 0;
}