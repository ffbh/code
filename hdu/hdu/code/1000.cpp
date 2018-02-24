#include <iostream>
using namespace std;
int num[] = {
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10
};

int main()
{
	int low = 0;
	int high = 9;
	int mid;
	int checkaim = 3;//要查找的数据
	cout << "要查找的数据为:" << checkaim << endl;
	while (low <= high){
		mid = (low + high) / 2;
		if (num[mid] == checkaim)
			break;
		else if (num[mid] < checkaim)
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout << "数据下标是:" << mid << endl;

	
	return 0;
}