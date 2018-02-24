#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
using namespace std;



int main(){
	int m, n;
	while (cin >> m >> n&&m >= 0 && n >= 0){
		double sum = 0;
		int i = 0;
		int tj, tf;
		int* p1 = new int[n];
		int* p2 = new int[n];
		map<double, int, greater<double>> mdi;
		if (!p1 || !p2) exit(0);
		while (i<n){
			cin >> tj >> tf;
			p1[i] = tj;
			p2[i] = tf;
			if (tf == 0){
			//	mdi[0.0] = i;
				sum += tj;
				i++;
				continue;
			}
			mdi[double(tj) / double(tf)] = i;
			i++;
		}
	//	sort(mdi.begin(), mdi.end(), greater<double>());
		map<double, int>::iterator it=mdi.begin();
		
		while (m>0&&it!=mdi.end()){
			int index = it->second;
			if (m >= p2[index]){
				m -= p2[index];
				it++;
				sum += p1[index];
			}
			else{
				double per = double(m) / p2[index];
				sum += per*p1[index];
				break;
			}
		}
		printf("%.3f\n", sum);
	
	}




	return 0;
}