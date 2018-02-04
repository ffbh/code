#include <iostream>
#include <string>
#include <fstream>
using namespace std;
_int64 num[20];

_int64 gcd(_int64 a, _int64 b){
	if (a < b)
		swap(a, b);
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);

}

int main(){
	ifstream in("C:\\temp.txt");
	_int64 N, A;
	while (cin >> N >> A&&N + A){
		for (int i = 0; i < N; ++i)
			cin >> num[i];
		_int64 ans = gcd(num[0], num[1]);
		ans = num[0] / ans * num[1];
		for (_int64 i = 2; i < N; ++i){
			_int64 temp = ans;
			ans = gcd(ans, num[i]);
			ans = temp / ans*num[i];
		}
		cout << ans - A << endl;
	}
	return 0;
}