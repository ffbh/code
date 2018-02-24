#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int len[110], size;


int main(){
	ifstream in("C:\\input.txt");
	int N, M;
	cin >> N >> M;
	size = 0;
	string s;
	while (cin >> s){
		len[size++] = s.length()-1;
	}
	int ansx, ansy;
	ansx = ansy = 1;
	bool  f = 0;
	while (N--){
		for (int i = 0; i < size; ++i){
			if (f){
				if (ansy<M-1)
					ansy += 2;
				else if(ansy == M-1){
					ansx++;
					ansy = 1;
				}
				else{
					ansx++;
					ansy = 2;
				}
			}
			else{
				f = 1;
			}
			if (M - ansy < len[i]){
				ansx++;
				ansy = len[i]+1;
			}
			else if (M - ansy == len[i]){
				ansy = M;

			}
			else{
				ansy += len[i];
			}
		}
	}
	cout << ansx << " " << ansy << endl;
	return 0;
}