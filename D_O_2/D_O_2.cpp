#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

double res_1(double y, double x, double p1) {
	return  y + p1 * sin(x);
}

double res_2 (double x, double y_n) {	
	return x + y_n;
}

int main()
{
	fstream tx_res;
	double y, x, y_n, x_n, y_0, p1, p1_max;

	p1 = -2.0;
	p1_max = 2.0;


	int t = 0;
	int tmp;
	tx_res.open("result.txt");
	while (p1 < p1_max) {
		y = 1;
		x = 1;
		while (t < 1000) {
			y_n = res_1(y, x, p1);
			x_n = res_2(x, y_n);
			tx_res << p1 << " " << x_n << " " << y_n << endl;
			x_n = x_n * 100;
			tmp = (int)x_n % 628;
			x_n = (double)tmp / 100;
			x = x_n;
			y = y_n;
			cout << p1 << " " << x << " " << y << endl;
			t++;
		}
		t = 0;
		p1 += 0.1;
	}
	
	tx_res.close();
}

