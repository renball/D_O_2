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

double lap_pok(double x, double k) {
	return 1+k*cos(x)-k*cos(x);
}

double lappok(double x,double k) {
	double nu3, nu4, D2;
	D2 = k*cos(x) * k* cos(x) + 4 * k* cos(x);
	if (D2 < 0) {
		D2 = abs(D2);
		D2 = sqrt(D2);
		D2 = D2 / 2;
		nu3 = sqrt(((2 + k*cos(x)) / 2) * ((2 + k* cos(x)) / 2) + D2 * D2);
		nu4 = sqrt(((2 + k * cos(x)) / 2) * ((2 + k * cos(x)) / 2) + D2 * D2);

	}
	else {
		nu3 = ((2 + k * cos(x)) + sqrt(D2)) / 2;
		nu4 = ((2 + k * cos(x)) - sqrt(D2)) / 2;
	}
	return max(abs(nu3), abs(nu4));
}
double lp1(double k) {
	double nu3, nu4, D2;
	D2 = k * k + 4 * k;
	if (D2 < 0) {
		D2 = abs(D2);
		D2 = sqrt(D2);
		D2 = D2 / 2;
		nu3 = sqrt(((2 + k) / 2) * ((2 + k) / 2) + D2*D2);
		nu4 = sqrt(((2 + k) / 2) * ((2 + k) / 2) + D2*D2);

	}
	else {
		nu3 = ((2 + k) + sqrt(D2)) / 2;
		nu4 = ((2 + k) - sqrt(D2)) / 2;
	}
	return max(abs(nu3), abs(nu4));
}
double lp2(double k) {
	double nu3, nu4, D2;
	D2 = k * k - 4 * k;
	if (D2 < 0) {
		D2 = abs(D2);
		D2 = sqrt(D2);
		D2 = D2 / 2;
		nu3 = sqrt(((2 - k)/2) * ((2 - k)/2) + D2*D2);
		nu4 = sqrt(((2 - k) / 2) * ((2 - k) / 2) + D2*D2);

	}
	else {
		nu3 = ((2 - k) + sqrt(D2)) / 2;
		nu4 = ((2 - k) - sqrt(D2)) / 2;
	}
	return max(abs(nu3), abs(nu4));
}

int main()
{
	fstream tx_res,tx_lap;
	double y, x, y_n, x_n, y_0, p1, p1_max;

	double X[60000]; X[0] = 0.001;
	double Y[60000]; Y[0] = 0.001;

	p1 = -1.1;
	p1_max = -1.1;

	int t = 0;
	int tmp;
	tx_res.open("result.txt");

	int i = 0;

	y = 0;
	x = 1;
	
	while (p1 <= p1_max) {
		X[0] = 0.001;
		Y[0] = 0.001;
		for (int i = 1; i < 60000; i++) {
			Y[i] = res_1(Y[i - 1], X[i - 1], p1);
			X[i] = res_2(X[i - 1], Y[i]);
			if (X[i] > 1 || X[i] < -1) {
				x = (X[i] * 100);

				tmp = (int)x % 628;

				X[i] = (double)tmp / 100;

			}

		}
		for (int i = 0; i < 60000; i++) {
			tx_res << p1 << " " << X[60000 - 1 - i] << " " << Y[60000 - 1 - i] << "\n";
		}
		p1 += 0.01;
	}
	tx_res.close();
	
	int n ;
	p1 = -5;
	p1_max = 5;
	double A1,A2,A3;
	tx_lap.open("lap.txt");

	while (p1 <= p1_max) {
		double A1, A2, A3, A4;
		A1 = log(abs(lp1(p1)));
		A2 = log(abs(lp2(p1)));
		A3 = (log(abs(lp1(p1)))+log(abs(lp2(p1))))/2;

		A4 = 0.0;
		X[0] = 0.001;
		Y[0] = 0.001;
		n = 0;
		for (int i = 1; i < 10000; i++) {
			Y[i] = res_1(Y[i - 1], X[i - 1], p1);
			X[i] = res_2(X[i - 1], Y[i]);

			if (X[i] > 1 || X[i] < -1) {
				x = (X[i] * 100);
				tmp = (int)x % 628;

				X[i] = (double)tmp / 100;
			}

			A4 += log(abs(lappok(X[i],p1)));
		}
		A4 = A4 / 10000;
		if (A4 < 0 && A4 > -0.00001) {
			A4 = -0.0001;
		}

		if (A1 < 0 && A1 > -0.00001) {
			A1 = -0.0001;
		}
		if (A2 < 0 && A2 > -0.00001) {
			A2 = -0.0001;
		}
		if (A3 < 0 && A3 > -0.00001) {
			A3 = -0.0001;
		}

		tx_lap << p1 << " " << A1 << " " << A2 << " " << A3 << " " << A4 << endl;
		p1 += 0.01;
	}

	tx_lap.close();
}

