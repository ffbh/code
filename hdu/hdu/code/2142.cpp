#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;





int main(){
	//ifstream in("C:\\temp.txt");
	map<string, double> msi;
	map<string, double>::iterator it;
	string temp[101];
	string s;
	double score;
	while (cin >> s&&s[0] != 'Q'){
		if (s[0] == 'N'){
			cin >> s >> score;
			if (msi.count(s)){
				msi[s] = score;
				printf("update succeed\n");
			}
			else{
				msi[s] = score;
				printf("A new record\n");
			}
		}
		else if (s[0] == 'M'){
			it = msi.begin();
			double mmax = -1;
			int p = 0;
			while (it != msi.end()){
				if (it->second == mmax){
					temp[p++] = it->first;
				}
				else if (mmax < it->second){
					mmax = it->second;
					p = 0;
					temp[p++] = it->first;
				}
				it++;
			}
			if (!p)
				printf("0 0\n");
			else{
				printf("%d %d\n", int(mmax), p);
				sort(temp, temp + p);
				for (int i = 0; i < p; ++i)
					cout << temp[i] << endl;
			}
		}
		else if (s[0] == 'A'){
			double all = 0;
			it = msi.begin();
			while (it != msi.end()){
				all += it->second;
				it++;
			}
			if (msi.empty())
				printf("0.00\n");
			else
				printf("%.2f\n", all / msi.size());
		}
		else{
			cin >> s;
			it = msi.find(s);
			if (it==msi.end())
				printf("no such record\n");
			else{
				msi.erase(it);
				printf("delete succeed\n");
			}
		}
	}
	return 0;
}