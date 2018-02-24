#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int num[60];
int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int aver;
	int sum;
	int ans;
	int CASE = 1;
	
	while (cin >> N&&N){
		
		ans=sum = 0;
		for (int i = 1; i <= N; ++i){
			scanf("%d", &num[i]);
			sum += num[i];
		}
		aver = sum / N;
		for (int i = 1; i <= N;++i)
		if (num[i] > aver)
			ans += num[i] - aver;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",CASE++, ans);
	
	}

	return 0;
}