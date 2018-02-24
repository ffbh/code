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

class SpeedRadar{
public :
	double averageSpeed(int minLimit, int maxLimit, vector <int> readings){
		double sum = 0;
		int num = 0;
		for (int i = 0; i < readings.size(); ++i){
			if (readings[i] >= minLimit && readings[i] <= maxLimit){
				sum += readings[i];
				num++;
			}
		}
		if (((double)num) / readings.size() < 0.9||num==0){
			return 0.0;
		}
		else{
			return sum / num;
		}
	}



};


int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;

















	return 0;
}