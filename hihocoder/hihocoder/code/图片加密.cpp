#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int image[110][110],aim_image[110][110],temp[110][110],T, N;

/*void show(int p[110][110]){
	for (int i = 1; i < 6; ++i){
		for (int j = 1; j < 6; ++j)
			cout << p[i][j] << " ";
		cout << endl;
	}
	cout << endl;

}*/

/*void closerorate(int** tmp,int n){
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
		temp[i][j] = tmp[i][j];
	for (int i = 1; i <= n;++i)
	for (int j = 1; j <= n; ++j)
		tmp[i][j] = temp[j][n - i + 1];
}
*/
/*void show(int** t, int n){
	for (int i = 1; i <=n ; ++i){
		for (int j = 1; j <=n ; ++j)
			cout << t[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}*/
void closerorate(int (*tmp)[110], int sx,int ex,int sy,int ey){
	int n = ex - sx + 1;
//	int ttemp[110][110];


/*	for (int i = 1; i <= n;++i)
	for (int j = 1; j <= n; ++j)
		temp[i][j] = tmp[sx + i - 1][sy + j - 1];*////////1


/*	for (int i = 1; i <= n;++i)
	for (int j = 1; j <= n; ++j)
		ttemp[i][j] = temp[j][n + 1 - i];
	for (int i = sx; i <= ex;++i)
	for (int j = sy; j <= ey; ++j)
		tmp[i][j] = ttemp[i - sx + 1][j - sy + 1];*/


	/*for (int i = sx; i <= ex;++i)
	for (int j = sy; j <= ey; ++j)
		tmp[i][j] = temp[j - sy + 1][n + 1 - (i - sx + 1)];*//////2

	for (int i = sx; i <= (sx + ex) / 2; ++i)
	for (int j = sy; j <= (sy + ey - 1) / 2; ++j){

		int t = tmp[i][j];
		tmp[i][j] = tmp[j + sx - sy][n - i + sx + sy - 1];
		tmp[j + sx - sy][n - i + sx + sy - 1] = tmp[n - i + 2 * sx - 1][n - j + 2 * sy - 1];
		tmp[n - i + 2 * sx - 1][n - j + 2 * sy - 1] = tmp[n - j + sx + sy - 1][i - sx + sy];
		tmp[n - j + sx + sy - 1][i - sx + sy] = t;
	}



}
/*void uncloserorate(int** tmp,  int sx, int ex, int sy, int ey){
	for (int i = sx; i <= ex; ++i)
	for (int j = sy; j <= ey; ++j)
		temp[i][j] = tmp[i][j];
	for (int i = sx; i <= ex; ++i)
	for (int j = sy; j <= ey; ++j)
		tmp[i][j] = temp[j][ey + 2 - i];
}*/

bool judge(int (*tmp)[110], int sx, int ex, int sy, int ey){

	for (int i = sx; i <= ex; ++i)
	for (int j = sy; j <= ey; ++j)
	if (aim_image[i][j] != tmp[i][j])
		return 0;
	return 1;
}

bool dfs(int (*img)[110],int sx, int ex, int sy, int ey){
	int n = ex - sx + 1;
	int tmp[110][110];
	for (int i = sx; i <= ex; ++i)
	for (int j = sy; j <= ey; ++j)
		tmp[i][j] = img[i][j];
	
	if (n % 2 == 0){
		/*	sum += dfs(tmp, 1, n / 2, 1, n / 2);
		sum += dfs(tmp, 1, n / 2, n / 2 + 1, n);
		sum += dfs(tmp, n / 2 + 1, n, 1, n / 2);
		sum += dfs(tmp, n / 2 + 1, n, n / 2 + 1, n);*/
		bool ok = 1;
		if (ok)
			ok = dfs(tmp, sx, sx + n / 2 - 1, sy, sy + n / 2 - 1);
		if (ok)
			ok = dfs(tmp, sx + n / 2, ex, sy + n / 2, ey);
		if (ok)
			ok = dfs(tmp, sx, sx + n / 2 - 1, sy + n / 2, ey);
		if (ok)
			ok = dfs(tmp, sx + n / 2, ex, sy, sy + n / 2 - 1);
		if (ok)
			return 1;

		
		closerorate(tmp,sx,ex,sy,ey);
	/*	if (sx == 1 && ex == 4 && sy == 1 && ey == 4){
			show(tmp, n);
		}*/
		ok = 1;
		if (ok)
			ok = dfs(tmp, sx, sx + n / 2 - 1, sy, sy + n / 2 - 1);
		if (ok)
			ok = dfs(tmp, sx + n / 2, ex, sy + n / 2, ey);
		if (ok)
			ok = dfs(tmp, sx, sx + n / 2 - 1, sy + n / 2, ey);
		if (ok)
			ok = dfs(tmp, sx + n / 2, ex, sy, sy + n / 2 - 1);
		if (ok)
			return 1;

		closerorate(tmp, sx, ex, sy, ey);

		ok = 1;
		if (ok)
			ok = dfs(tmp, sx, sx + n / 2 - 1, sy, sy + n / 2 - 1);
		if (ok)
			ok = dfs(tmp, sx + n / 2, ex, sy + n / 2, ey);
		if (ok)
			ok = dfs(tmp, sx, sx + n / 2 - 1, sy + n / 2, ey);
		if (ok)
			ok = dfs(tmp, sx + n / 2, ex, sy, sy + n / 2 - 1);
		if (ok)
			return 1;

		closerorate(tmp, sx, ex, sy, ey);
//		show(tmp, n);
		ok = 1;
		if (ok)
			ok = dfs(tmp, sx, sx + n / 2 - 1, sy, sy + n / 2 - 1);
		if (ok)
			ok = dfs(tmp, sx + n / 2, ex, sy + n / 2, ey);
		if (ok)
			ok = dfs(tmp, sx, sx + n / 2 - 1, sy + n / 2, ey);
		if (ok)
			ok = dfs(tmp, sx + n / 2, ex, sy, sy + n / 2 - 1);
		if (ok)
			return 1;
	}
	else{
		if (judge(tmp, sx, ex, sy, ey))
			return 1;
		closerorate(tmp, sx, ex, sy, ey);
		if (judge(tmp, sx, ex, sy, ey))
			return 1;
		closerorate(tmp, sx, ex, sy, ey);
		if (judge(tmp, sx, ex, sy, ey))
			return 1;	
		closerorate(tmp, sx, ex, sy, ey);
		if (judge(tmp, sx, ex, sy, ey))
			return 1;
	}
	return 0;
}

int main(){
	ifstream in("C:\\input.txt");
/*	for (int i = 1; i < 6;++i)
	for (int j = 1; j < 6; ++j)
		image[i][j] = (i - 1) * 5 + j;
	show(image);

	closerorate(image,2,3,1,2);

	show(image);*/

	in >> T;
	while (T--){
		in >> N;
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j)
			in >> image[i][j];
	//	show(image, N);
		for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			in >> aim_image[i][j];

		if (dfs(image, 1, N, 1, N))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
	

	return 0;
}