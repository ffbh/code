#include <iostream>
using namespace std;

bool isLeap(int n){
	return n % 400 == 0 || n % 4 == 0 && n % 100 != 0;
}
int main(){
	int N;
	cin >> N;
	int start, time;
	while (N--){
		cin >> start >> time;
		if (isLeap(start)){
			time--;
			while (time>=1){
				start += 4;
				if (isLeap(start))
					time--;
			}
			cout << start << endl;
		}
			
		else
		{
			while (!isLeap(start))start++;
			time --;
			while (time>=1){
				start += 4;
				if (isLeap(start))
					time--;
			}
			cout << start << endl;
		}

	}






	return 0;
}