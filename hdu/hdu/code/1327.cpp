#include <iostream>
#include <fstream>
#include <set>
using namespace std;
bool Init[30];
int main(){
	ifstream in("C:\\temp.txt");
	int N;
	char x, y;
	set<char> sc;
	int CASE = 1;
	while (cin >> N&&N){	
		printf("Program #%d\n", CASE++);
		sc.clear();
		memset(Init, 0, sizeof(Init));
		Init[0] = 1;
		for (int i = 0; i < N; ++i){
		//	scanf("%c = %c", &x, &y);
			cin >> x >> y>>y;
			Init[x-'a'] = Init[y-'a'];
		}
		for (int i = 0; i < 27;++i)
		if (Init[i])
			sc.insert(char(i + 'a'));
		if (sc.empty())printf("none\n");
		else{
			int size = sc.size();
			set<char>::iterator it = sc.begin();
			for (int i = 0; i < size ; ++i)
				cout << *it++ << " ";
			cout  << endl;
		
		}
		cout << endl;
	
	}

	return 0;
}