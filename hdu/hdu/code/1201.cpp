#include <iostream>
using namespace std;

bool Leap(int n){
	return  n % 4 == 0 && n % 100 != 0||n % 400 == 0 ;
}

int time[2][13] = { 
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31} 
};
int main(){
	int N;
	int y, m, d;
	cin >> N;
	int sum;
	while (N--){
		scanf("%d-%d-%d", &y, &m, &d);
		if (m == 2 && d == 29){
			cout << -1 << endl;
			continue;
		}
		sum = 18 * 365;
		if (Leap(y) && m <= 2)
			sum++;
		if (Leap(y + 18) && m > 2)
			sum++;
		for (int i = y + 1; i < y + 18;++i)
		if (Leap(i))
			sum++;
		cout << sum << endl;
		
	}
	return 0;
}