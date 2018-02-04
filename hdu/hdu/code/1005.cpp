
#include <iostream>  
using namespace std;
int main()
{
	int a, b, n, f[55];
	while (cin >> a >> b >> n&&a&&b&&n)
	{
		f[1] = 1, f[2] = 1;
		int i;
		for (i = 3; i<50; ++i)
		{
			f[i] = ((a*f[i - 1]) % 7 + (b*f[i - 2]) % 7) % 7;
			//cout<<f[i]<<" "<<f[i-1]<<" "<<f[i-2]<<endl;  
			if (f[i] == f[i - 1] && f[i - 1] == 1)
			{
				break;
			}
		}
		i -= 2;
		n = n%i;
		//cout<<k<<endl;  
		if (n)
			cout << f[n] << endl;
		else
			cout << f[i] << endl;
	}
	return 0;
}