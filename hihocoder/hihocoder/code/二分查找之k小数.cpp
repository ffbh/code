#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
unsigned int data[10000010], N, K, data2[10000010];

int cale(int l, int r, int k){
	if (r - l<3){
		sort(data + l, data + r + 1);
		return data[l+k-1];
	}
	int tmp = data[l];
	int ll = l, rr = r;
	while (ll < rr){
		while (rr > ll&&data[rr] >= tmp)
			rr--;
		data[ll] = data[rr];
		while (ll < rr&&data[ll] <= tmp)
			ll++;
		data[rr] = data[ll];
	}
	data[ll] = tmp;
	int lfnum = ll - l + 1;
	if (k <= lfnum){
		return cale(l, ll, k);
	}
	else{
		return cale(ll + 1, r, k - lfnum);
	}
}

void randomInput(int n){
	ofstream out("C:\\input.txt");
	srand(time(0));
	out << n << "  " << rand() % n / 2 + 1 << endl;;
	for (int i = 0; i < n; ++i)
		out << rand() % 2000000000 << " ";
	out << endl;

}
int main(){
	ifstream in("C:\\input.txt");
	/*randomInput(8000000);
	cout << "end" << endl;
	return 0;*/
	long s = clock();
	cout << "input start" << endl;
	in >> N >> K;
	for (int i = 1; i <= N; ++i){
		in >> data[i];
		data2[i] = data[i];
	}
	cout << "input time:" << clock() - s << endl;
	cout << "input end" << endl << endl;;
	cout << "start cale£º" << endl;
	if (K > N)
		cout << -1 << endl;
	else{
		s = clock();
		cout << cale(1, N, K) << endl;
		cout << "time:" << clock() - s << endl << endl;
		
		s = clock();
		sort(data2 + 1, data2 + N + 1);
		cout << data[K] << endl;
		cout << "time:" << clock() - s << endl << endl;
	}

	return 0;
}