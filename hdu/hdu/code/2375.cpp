#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N;
struct Data{
	double p, a;
	double coupon[16];
}data[16];
double mmin;
struct Dp{
	double suma, sump;
	double coupon[16];
}dp[1 << 16];
void DP(){
	double price, area;
	for (int k = 1; k < (1 << N); ++k){
		double lowest = DBL_MAX;
		for (int i = 0; i < N; ++i){
			int pre;
			int yiwei = (1 << i);
			if (k&yiwei){
				pre = k - yiwei;
				area = dp[pre].suma + data[i].a;
				price = dp[pre].sump + dp[pre].coupon[i] * data[i].p;
				if (price / area < lowest){
					lowest = price / area;
					dp[k].suma = area;
					dp[k].sump = price;
					memcpy(dp[k].coupon, dp[pre].coupon, sizeof(dp[k].coupon));
					for (int j = 0; j < N; ++j)
						dp[k].coupon[j] *= data[i].coupon[j];
				}
			}
		}
		if (lowest < mmin)
			mmin = lowest;
	}
}



int main(){
	ifstream in("C:\\temp.txt");
	dp[0].suma = 0;
	dp[0].sump = 0;
	for (int i = 0; i < 16; ++i)
		dp[0].coupon[i] = 1;
	while (cin >> N&&N){
		mmin = DBL_MAX;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < 16; ++j)
				data[i].coupon[j] = 1;
			int num;
		//	in >> data[i].p >> data[i].a >> num;
			scanf("%lf%lf%d", &data[i].p, &data[i].a, &num);
			while (num--){
				int k1, k2;
				//in >> k1 >> k2;
				scanf("%d%d", &k1, &k2);
				data[i].coupon[k1 - 1] = 1.0 - double(k2) / 100;//////////
			}
		}
		DP();
		printf("%.4f\n", mmin);
	}
	return 0;
}