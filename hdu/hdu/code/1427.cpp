#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
vector<double> vd;

bool dfs(vector<double> v){
	vector<double> vv;
	int size = v.size();
	for (int i = 0; i < size-1;++i)
	for (int j = 0; j < 4; ++j){
		vv = v;
		if (j == 0)
			vv[i] = vv[i] + vv[i + 1];
		else if (j == 1)
			vv[i] = vv[i] - vv[i + 1];
		else if (j == 2)
			vv[i] = vv[i] * vv[i + 1];
		else
			vv[i] = vv[i] / vv[i + 1];
	
		if (size==2){
			if (vv[0]==24)return 1;
		}
		else{
			vector<double>::iterator it = vv.begin();
			for (int k = 0; k <= i; ++k)it++;
			vv.erase(it);
			if (dfs(vv))
				return 1;
		}
	}
	return 0;
}



int main(){
	ifstream in("C:\\temp.txt");
	map<char, int> mci;
	
	while (in >> a >> b >> c >> d){
		vd.clear();
		vd.push_back(mci[a]);
		vd.push_back(mci[b]);
		vd.push_back(mci[c]);
		vd.push_back(mci[d]);
		if (dfs(vd))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}




	return 0;
}