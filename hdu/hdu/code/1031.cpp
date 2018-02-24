#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
struct house{
	float sum;
	int index;
};

bool cmp(house a, house b){
	if (a.sum != b.sum) return a.sum > b.sum;
	return a.index < b.index;
}
int main(){
	int n, m, k;
	ifstream in("C:\\temp.txt");
	while (scanf("%d", &n) != EOF){
		scanf("%d%d", &m, &k);
		float** p = new float*[n];
		house* hp = new house[m];
		int* result = new int[k];
		for (int i = 0; i < n; ++i)
			p[i] = new float[m + 1];
		for (int i = 0; i < n;++i)
		for (int j = 1; j <= m; ++j)
			scanf("%f", &p[i][j]);
			
		for (int j = 1; j <= m; ++j){
			hp[j-1].index = j;
			hp[j - 1].sum = 0;
			for (int i = 0; i < n; ++i){
				hp[j - 1].sum += p[i][j];
			}
		}
		sort(hp, hp + m, cmp);
		for (int i = 0; i < k; ++i)
			result[i] = hp[i].index;
		sort(result, result + k);
		for (int i = k - 1; i >= 0; --i){
			printf("%d", result[i]);
			if (i) printf(" ");
		}
		cout << endl;
		for (int i = 0; i < n; ++i)
			delete[] p[i];
		delete[] p;
		delete[] hp;
		delete result;


	
	}


	return 0;
}