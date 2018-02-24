#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	map<string, int> msi;
	msi["Kamen"] = 1;
	msi["Rock"] = 1;
	msi["Pierre"] = 1;
	msi["Stein"] = 1;
	msi["Ko"] = 1;
	msi["Koe"] = 1;
	msi["Sasso"] = 1;
	msi["Roccia"] = 1;
	msi["Guu"] = 1;
	msi["Kamien"] = 1;
	msi["Piedra"] = 1;
	msi["Nuzky"] = 2;
	msi["Scissors"] = 2;
	msi["Ciseaux"] = 2;
	msi["Schere"] = 2;
	msi["Ollo"] = 2;
	msi["Olloo"] = 2;
	msi["Forbice"] = 2;
	msi["Choki"] = 2;
	msi["Nozyce"] = 2;
	msi["Tijera"] = 2;
	bool flag = 1;
	int CASE = 1;
	while (flag){
		string s1, s2;
		cin >> s1 >> s1;
		cin >> s2 >> s2;
		int num1, num2;
		num1 = num2 = 0;
		string temp1, temp2;
		while (cin >> temp1){
			if (temp1 == "-")
				break;
			if (temp1 == "."){
				flag = 0;
				break;
			}
			cin >> temp2;
			int a, b;
			a = msi[temp1];
			b = msi[temp2];
			if (a == b)
				continue;
			if (b == (a + 1) % 3)
				num1++;
			else
				num2++;
		}
		printf("Game #%d:\n", CASE++);
		printf("%s: %d point", s1.c_str(), num1);
		if (num1 != 1)
			putchar('s');
		putchar('\n');
		printf("%s: %d point", s2.c_str(), num2);
		if (num2 != 1)
			putchar('s');
		putchar('\n');
		if (num1 == num2)
			cout << "TIED GAME" << endl;
		else if (num1 > num2)
			printf("WINNER: %s\n", s1.c_str());
		else
			printf("WINNER: %s\n", s2.c_str());
		cout << endl;
	}
	return 0;
}