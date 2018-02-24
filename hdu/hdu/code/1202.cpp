#include <iostream>
#include <string>
using namespace std;

int getNum(double score){
	if (score <= 100 && score >= 90)return 4;
	else if (score >= 80)return 3;
	else if (score >= 70)return 2;
	else if (score >= 60)return 1;
	else return 0;
}

int main(){
	int N;
	double num, score;
	int kk;
	while (cin >> N){
		double point = 0.0;
		double sumScore = 0.0;
		for (int i = 0; i < N; ++i){
			scanf("%lf%lf", &num, &score);
			if (score == -1) 
				continue;
			
			point += num;
			kk = getNum(score);
			sumScore += num*kk;
		}
		if (sumScore==0)
			cout << -1 << endl;
		else printf("%.2f\n", sumScore / point);
	}
	return 0;
}