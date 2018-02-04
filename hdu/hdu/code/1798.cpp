#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
double x1, Y1, r1, x2, y2, r2;
const double PI = acos(-1.0);
double getDist(double x1,double Y1,double x2,double y2){
	return sqrt((x1 - x2)*(x1 - x2) + (Y1 - y2)*(Y1 - y2));
}

/*double chaji(double rx,double ry,double ax,double ay,double bx,double by){
	double _x1 = ax - rx;
	double _x2 = bx - rx;
	double _y1 = ay - ry;
	double _y2 = by - ry;
	return fabs(_x1*_y2 - _x2*_y1) / 2.0;
}*/

double chaji(double rx, double ry, double ax, double ay, double bx, double by){
	double _x1 = ax - rx;
	double _x2 = bx - rx;
	double _y1 = ay - ry;
	double _y2 = by - ry;
	return (_x1*_y2 - _x2*_y1) / 2.0;
}

double getAngle(double vx1,double vy1,double vx2,double vy2){
	return acos((vx1*vx2 + vy1*vy2) / (sqrt(vx1*vx1 + vy1*vy1)*sqrt(vx2*vx2 + vy2*vy2)));
}

double getArea(){
	double L = getDist(x1, Y1, x2, y2);

	if (L - r1 - r2 >= 0){
		return 0;
	}
	else if (max(r1, r2) - (L + min(r1, r2)) >= 0){
		return PI * pow(min(r1, r2), 2.0);
	}
	double x = (r1*r1 - r2*r2 + L*L) / (2 * L);
	double y = sqrt(r1*r1 - x*x);
	double k = x / L;

	
	double centerX = x1 + (x2-x1) * k;
	double centerY = Y1 + (y2-Y1) * k;
	double jx1, jy1, jx2, jy2;
	if (fabs(x2 - x1) < 1e-8){
		jx1 = centerX + y;
		jx2 = centerX - y;
		jy1 = jy2 = centerY;
	}
	else{
	//	printf("%.4f %.4f\n", sin(ang), cos(ang));
		double ang = atan((y2 - Y1)/ (x2 - x1));
		jx1 = centerX + y * sin(ang);
		jy1 = centerY - y * cos(ang);

		jx2 = centerX - y * sin(ang);
		jy2 = centerY + y * cos(ang);

	}
	
	double c1 = chaji(x1, Y1, jx1, jy1, jx2, jy2);
	double c2 = chaji(x2, y2, jx2, jy2, jx1, jy1);
	//printf("%.4f %.4f\n", c1, c2);

	double ang1 = getAngle(jx1 - x1, jy1 - Y1, jx2 - x1, jy2 - Y1);
	double ang2 = getAngle(jx2 - x2, jy2 - y2, jx1 - x2, jy1 - y2);
	//printf("%.4f %.4f\n", 180.0 / PI*ang1, 180.0 / PI*ang2);
	double ans = 0;
	if (c1 > 0){
		ans += 0.5*r1*r1*(ang1 - sin(ang1));
	}
	else{
		ans += PI *r1*r1 - 0.5*r1*r1*(ang1-sin(ang1));
	}

	if (c2 > 0){
		ans += 0.5*r2*r2*(ang2 - sin(ang2));
	}
	else{
		ans += PI *r2*r2 - 0.5*r2*r2*(ang2-sin(ang2));
	}
	return ans;
}

int main(){
	ifstream in("C:\\input.txt");
	
	/*printf("%.4f\n", 180.0/PI*getAngle(1, 0, -0.5,-0.5));

	printf("%.4f\n", getAngle(1, 0, -0.5, -0.5));

	printf("%.4f\n", 180.0 / PI*getAngle(1, 0, -0.5, 0.5));

	printf("%.4f\n", getAngle(1, 0, -0.5, 0.5));*/
	while (cin >> x1 >> Y1 >> r1 >> x2 >> y2 >> r2){
		if (r1 < r2){
			swap(x1, x2);
			swap(Y1, y2);
			swap(r1, r2);
		}
		x2 -= x1;
		y2 -= Y1;
		x1 = Y1 = 0;
		x2 = fabs(x2);
		y2 = fabs(y2);
		printf("%.3lf\n",getArea());


	}


	return 0;
}