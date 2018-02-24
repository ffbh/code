#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	int id;
	int v;
};
Node data[100010];
bool cmp(int a,int b){
	if (data[a].v != data[b].v)
		return data[a].v < data[b].v;
	return data[a].id < data[b].id;
}


int f1[100010];
int f2[100010];
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 1; i <= N; ++i){
			data[i].id = i;
			//in >> data[i].v;
			scanf("%d", &data[i].v);
		}
		for (int i = 1; i <= N; ++i)
			f1[i] = i;
		sort(f1 + 1, f1 + 1 + N, cmp);
		for (int i = 1; i <= N; ++i)
			f2[f1[i]] = i;
		for (int i = 1; i < N; ++i){
			int k = f1[i];
			printf("%d ", k);
			int low = i;
			int high = k;
			while (low < high){
				swap(f1[f2[low]], f1[f2[high]]);
				swap(f2[low], f2[high]);
				++low;
				--high;
			}	
		}
		printf("%d\n", N);
	}





	return 0;
}