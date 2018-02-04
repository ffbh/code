#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
using namespace std;
const int num = 1000000;
void output_random_data(){
	ofstream out("C:\\input.txt");
	for (int i = 0; i < num; ++i)
		out << (unsigned int)(rand()) * (unsigned int)(rand()) << " " << (unsigned int)(rand()) * (unsigned int)(rand()) << endl;
}

struct Node{
	unsigned int s, e;
	bool operator<(const Node& p)const{
		//if (s != p.s)
			return s < p.s;
	//	else
		//	return e > p.e;
	}
//	bool operator==(const Node& p)const{
//		return s == p.s;
//	}
}data[num+10];

int main(){
	ifstream in("C:\\input.txt");
	output_random_data();
	long start, end;

	start = clock();
	srand(time(0));
	for (int i = 0; i < num; ++i){
		in >> data[i].s >> data[i].e;
		if (data[i].s > data[i].e)
			swap(data[i].s, data[i].e);
	}
	end = clock();
	cout << "input time:  " << end - start << endl;

	start = clock();
	//for (int i = 0; i < num; ++i){
	//	data[i].s = (unsigned int)(rand()) * (unsigned int)(rand());
	//	data[i].e = (unsigned int)(rand()) * (unsigned int)(rand());
	//	if (data[i].s > data[i].e)
	//		swap(data[i].s, data[i].e);
//	}

	//end = clock();
	//cout << end-start << endl;
//	start = clock();
//	sort(data, data + num);
//	end = clock();
//	cout << "sort end:"<<end-start << endl;
//	start = clock();
//	num = unique(data, data + 1000000) - data;
//	end = clock();
//	cout << end - start << endl;
//	cout << "num:" << num << endl;
//	start = clock();
	unsigned int  mmax = 0;
	for (int i = 0; i < num; ++i){
		if (i && data[i].e - data[i].s + 1 <= mmax)
			continue;
		for (int j = i + 1; j < num; ++j){
		//	if (data[j].s>data[i].e)
		//		break;
			if (data[i].s>data[j].e || data[j].s>data[i].e)
				continue;
			if (data[i].s >= data[j].s&&data[i].s <= data[j].e){
				if (data[i].e >= data[j].e){
					if (mmax < data[j].e - data[i].s + 1)
						mmax = data[j].e - data[i].s + 1;
				}
				else {
					if (mmax < data[i].e - data[i].s + 1)
						mmax = data[i].e - data[i].s + 1;
				}
			}
			else {
				if (data[j].e >= data[i].e){
					if (mmax < data[i].e - data[j].s + 1)
						mmax = data[i].e - data[j].s + 1;
				}
				else {
					if (mmax < data[j].e - data[j].s + 1)
						mmax = data[j].e - data[j].s + 1;
				}

			}
		}
	}
	cout << mmax << endl;
	end = clock();
	cout <<"time:  "<< end - start << endl;

	start = clock();
	sort(data, data + num);
	mmax = 0;
	for (int i = 0; i < num; ++i){
		if (i && data[i].e - data[i].s + 1 <= mmax)
			continue;
		for (int j = i + 1; j < num; ++j){
			if (data[j].s > data[i].e)
				break;
			int len = min(data[i].e, data[j].e) - data[j].s + 1;
			if (len > mmax)
				mmax = len;
		}
	}
	cout << mmax << endl;
	end = clock();
	cout << "time:  " << end - start << endl;




	return 0;
}




