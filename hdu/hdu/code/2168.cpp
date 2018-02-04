/*#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;
map<char, int> mci;
char* temp[4][3];
void change(){
	char t[3];
	for (int i = 0; i < 3; ++i)
		t[i] = *(temp[3][i]);
	for (int i = 3; i > 0;--i)
	for (int j = 0; j < 3; ++j)
		*temp[i][j] = *temp[i - 1][j];
	for (int i = 0; i < 3; ++i)
		*temp[0][i] = t[i];
}



struct Node{
	char color[3][3];

	void show(){
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j)
				putchar(color[i][j]);
			putchar('\n');
		}
	}

	void putptr(int u,int f){
		if (f <= 2){
			for (int i = 0; i < 3; ++i)
				temp[u][i] = &color[2-i][f];
		}
		else if(f<=5){
			f -= 3;
			for (int i = 0; i < 3; ++i)
				temp[u][i] = &color[f][2-i];
		}
		else if (f <= 8){
			f -= 6;
			for (int i = 0; i < 3; ++i)
				temp[u][i] = &color[i][f];

		}
		else{
			f -= 9;
			for (int i = 0; i < 3; ++i)
				temp[u][i] = &color[f][i];
		}
	}
}data[6];
string s;
struct Table{
	int u, f;
}table[6][4] = {
	{ { 1, 6 }, { 2, 6 }, { 3, 6 }, { 4, 6 } },
	{ { 0, 8 }, { 4, 5 }, { 5, 5 }, { 2, 9 } },
	{ { 0, 5 }, { 1, 5 }, { 5, 8 }, { 3, 9 } },
	{ { 0, 6 }, { 2, 5 }, { 5, 9 }, { 4, 9 } },
	{ { 0, 9 }, { 3, 5 }, { 5, 0 }, { 1, 9 } },
	{ { 4, 8 }, { 3, 8 }, { 2, 8 }, { 1, 8 } }
};





void rorate(int k){
	char color[3][3];
	memcpy(color, data[k].color, sizeof(color));
	
	//data[k].show();

	for (int i = 0; i < 3;++i)
	for (int j = 0; j < 3; ++j)
		data[k].color[i][j] = color[2-j][i];
	//data[k].show();
}



int main(){
	ifstream in("C:\\input.txt");
	int T;
	in >> T;
	while (T--){
		mci.clear();
		for (int i = 0; i < 3;++i)
		for (int j = 0; j < 6;++j)
		for (int k = 0; k < 3; ++k)
			in >> data[j].color[i][k];
		in >> s;
		for (int i = 0; i < 6; ++i)
			mci[data[i].color[1][1]] = i;

		int yellow = mci['Y'];
		rorate(yellow);

		for (int i = 0; i < s.length(); ++i){
			int k = mci[s[i]];
			for (int j = 0; j < 4; ++j){
				data[table[k][j].u].putptr(j, table[k][j].f);
			}
			change();
		}
		for (int i = 0; i < 3; ++i){
			bool sign = 1;
			for (int j = 0; j < 6; ++j)
			for (int k = 0; k < 3; ++k){
				if (sign){
					sign = 0;
					printf("%c", data[j].color[i][k]);
				}
				else
					printf(" %c", data[j].color[i][k]);
			}

			putchar('\n');
			
		}
		cout << "===================================" << endl;
	}
	return 0;
}*/