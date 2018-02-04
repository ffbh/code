#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
//	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int one, two;
		one = two = 0;
		int M;
		cin >> M;
		while (M--){
			string s1, s2;
			cin >> s1 >> s2;
			if (s1 == s2)
				continue;
			if (s1 == "R"){
				if (s2 == "S")
					one++;
				else
					two++;
			}
			else if (s1 == "S"){
				if (s2 == "P")
					one++;
				else
					two++;
			}
			else{
				if (s2 == "R")
					one++;
				else
					two++;
			}
		}
		if (one < two)
			cout << "Player 2" << endl;
		else if (one == two)
			cout << "TIE" << endl;
		else
			cout << "Player 1" << endl;

	}





	return 0;
}