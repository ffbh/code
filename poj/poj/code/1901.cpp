#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
struct Node{
	int a, b;
	double k;
	bool operator<(const Node& p)const{
		return k < p.k;
	}
}data[500010];
int size;

struct Plant{
	int x, y, z;
	int p;
	double getDist(Plant& p){
		double sum = (x - p.x)*(x - p.x) + (y - p.y)*(y - p.y) + (z - p.z)*(z - p.z);
		return sqrt(sum);
	}
}plant[1010];

int val[1010];

void Init(){
	size = 0;
	for (int i = 0; i < 1010; ++i)
		val[i] = 1;
}



int main(){
	ifstream in("C:\\input.txt");
	Init();
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> plant[i].x >> plant[i].y >> plant[i].z >> plant[i].p;
	}

	for (int i = 0; i < N;++i)
	for (int j = i + 1; j < N; ++j){
		data[size].a = i;
		data[size].b = j;
		data[size].k = plant[i].getDist(plant[j]);
		size++;
	}
	sort(data, data + size);

	double ansR = 0, tmpR = 0;;
	ansR = 0;
	int maxP = 0, tmpP = 0;
	int pos = 0;
	while (pos < size){
		tmpR = data[pos].k;
		while (pos < size && fabs(data[pos].k - tmpR) < 1e-5){
			int a = data[pos].a;
			int b = data[pos].b;
			if (plant[a].p == plant[b].p){
				val[a]++;
				if (val[a] == 0){
					tmpP--;
				}

				val[b]++;

				if (val[b] == 0){
					tmpP--;
				}
			}
			else{
				val[a]--;
				if (val[a] == -1){
					tmpP++;
				}

				val[b]--;
				if (val[b] == -1){
					tmpP++;
				}
			}

			pos++;
		}

		if (tmpP > maxP || tmpP == maxP && tmpR < ansR){
			maxP = tmpP;
			ansR = tmpR;
		}
	}

	printf("%d\n%.4f\n", maxP, ansR);

	return 0;
}