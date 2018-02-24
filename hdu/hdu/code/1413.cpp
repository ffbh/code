#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <list>
using namespace std;
struct Node{
	int a, b, c;
};
struct Dire{
	string name;
	list<Node*> direson;
	set<string> filename;
};

int main(){
	ifstream in("C:\\temp.txt");
	list<Node*>::iterator it;
	Dire* root = new Dire();
	Dire* now = root;
	string cmd, name;
	while (cin >> cmd >> name){
		if (cmd == "CD"){
			it = now->direson.begin();


		}



	}





	return 0;
}