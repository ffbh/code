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

class SymbolFrequency{
public :
	double cale(string& s1,string& s2){
		double p[30] = { 0 };
		for (int i = 0; i < s1.length(); i += 3){
			int id = s1[i] - 'a';
			p[id] = 0.01*((s1[i + 1] - '0') * 10 + (s1[i + 2] - '0'));
		}
		int len = 0;
		int num[30] = { 0 };
		for (int i = 0; i < s2.length(); ++i){
			if (islower(s2[i])){
				len++;
				num[s2[i] - 'a']++;
			}
		}

		for (int i = 0; i < 30; ++i){
			p[i] *= len;
		}

		double sum = 0;
		for (int i = 0; i < 30; ++i){
			sum += pow((p[i] - num[i]), 2);
		}
		return sum;
	}


	double language(vector <string> frequencies, vector <string> text){
		double ans = 1e100;
		string t = "";
		for (int j = 0; j < text.size(); ++j){
			t += text[j];
		}
		for (int i = 0; i < frequencies.size(); ++i){
			double tmp = cale(frequencies[i], t);
			
			ans = min(ans, tmp);
		}
		return ans;


	}


};


int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;


	vector<string> a({ "a09b01c03d05e20g01h01i08l06n08o06r07s09t08u07x01"
		, "a14b02c05d06e15g01h01i07l05n07o10r08s09t05u04x01" }
	);
	vector<string> b({ "this text is in english"
		, "the letter counts should be close to"
		, "that in the table" }
	);

	
	SymbolFrequency sp;
	cout << sp.language(a, b) << endl;










	return 0;
}