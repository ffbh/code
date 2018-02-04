#include <iostream>
#include <map>
using namespace std;
int main(){
	map<int, int> m;
	int n,temp,maxlen,max;
	while (scanf("%d", &n) != EOF){
		int i = 0;
		maxlen =max= 0;
		while (i++ < n){
			scanf("%d", &temp);
			m[temp]++;
			if (maxlen < m[temp]){
				max = temp;
				maxlen = m[temp];
			}
		}
		printf("%d\n", max);
		m.clear();
	
	
	}



	return 0;
}
