
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

			  using namespace std;
struct Node{
	int data[5];
}data[130];
int d[130][5], size;

void InitAllp(){
	Node s;
	size = 0;
	for (int i = 0; i<5; ++i)
		s.data[i] = i;
	for (int i = 0; i<5; ++i)
		d[size][s.data[i]] = i;
	while (next_permutation(s.data, s.data + 5)){
		size++;
		for (int i = 0; i<5; ++i)
			d[size][s.data[i]] = i;

	}
}

int N, ans;

int cale(int k1, int k2){
	int sum = 0;
	for (int i = 0; i<5; ++i)
	for (int j = i + 1; j<5; ++j){
		if ((d[k1][i] - d[k1][j])*(data[k2].data[i] - data[k2].data[j]) < 0)
			sum++;
	}
	return sum;

}
int main(){
	//ifstream in("C:\\input.txt");
	InitAllp();
	while (cin >> N && N){
		for (int i = 0; i<N; ++i){
			string ss;
			cin >> ss;
			for (int j = 0; j<5; ++j){
				data[i].data[ss[j] - 'A'] = j;
			}
		}
		int minValue = 99999999;
		for (int i = 0; i <= size; ++i){
			int val = 0;
			for (int j = 0; j<N; ++j){
				val += cale(i, j);
			}
			if (val < minValue){
				ans = i;
				minValue = val;
			}
		}
		string aaa(5, ' ');
		for (int i = 0; i<5; ++i)
			aaa[d[ans][i]] = 'A' + i;
		cout << aaa;
		printf(" is the median ranking with value %d.\n", minValue);

	}









	return 0;
}
