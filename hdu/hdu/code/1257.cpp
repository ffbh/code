#include <iostream>
//#include <fstream>
#include <algorithm>
using namespace std;
int dp[30010];
int main(){
//	ifstream in("C:\\temp.txt");
	int N;
	int count;
	int t;
	while (cin >> N){
		count = 0;
		memset(dp, 0, sizeof(dp));
		cin >> dp[0];
		for (int i = 0; i < N-1; ++i){
			scanf("%d", &t);
		//	in >> t;
			if (t>dp[count])
				dp[++count] = t;
			else{
				/*int low = 0;
				int high = count;
				int mid;
				while (low <= high){
					mid = (low + high) / 2;
					if (dp[mid] < t)
						low = mid + 1;
					else if(dp[mid]==t)
						break;
					else
						high = mid - 1;
				}
				if (dp[mid] < t)mid++;
				dp[mid] = t;*/
				int *p = lower_bound(dp, dp + count, t);
				*p = t;
			}
			
		
		}
		printf("%d\n", count+1);
	
	}

	return 0;
}


/*int main(){
	int kk[10] = {0,1,3,4,5,6,7,9,10,13};
	int low = 0;
	int high = 9;
	int mid;
	const int aim = 2;
	while (low <= high){
		mid = (low + high) / 2;
		if (kk[mid] < aim)
			low = mid + 1;
		else if (kk[mid] == aim)
			break;
		else
			high = mid - 1;
	}
	if (kk[mid] < aim)mid++;
	cout << mid <<  endl;


	return 0;
}*/