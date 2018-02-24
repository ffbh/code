#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

class FountainOfLife {
public:
	double elixirOfDeath(int elixir, int poison, int pool) {
		if (elixir >= poison){
			return -1.0;
		}
		else{
			double p = poison - (elixir + poison) / 2.0;
			return pool / 2.0 / p;


		}



	}
};


int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;

















	return 0;
}





