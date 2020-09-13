/************************************************
Filename: Ass3S20CST8233.c
Version: 1.0
Student Name: Yanni Li
Student Number: 040914267
Course Name: Numerical Computing
Course Code: CST8233
Lab Section Number: 303
Assignment Name: ansient-Response Analysis of 1st Order Systems 
Due Date: 2020/08/07
Submission Date:2020/08/01
Professor's Name: Abdullah Kadri
Purpose: Find the solution of 1st order Ordinary Differential Equations (ODE) using well known methods; 
		 namely, Euler’s and Runge-Kutta 4th Order Methods. 
**********************************/
#include<stdio.h>
#include<conio.h>
#include<math.h>

void ode(double);
void rkRule(double);
/***********************************************
Function name: ode
Purpose: use Euler's method to find the discrete values of y(t) at each step h
In parameters: double h
Out Parameters: nothing
Version: 1.0
Author: Yanni Li
************************************************/
void ode(double h) {
	int i;
	double t = 2.0;
	double x[50];
	double y[50];
	double actualVal[50];
	double error[50];
	x[0] = 0;
	y[0] = 3;

	for (i = 0; i <= t / h; i++) {
		y[i + 1] = y[i] + (cos(4 * x[i]) - 2 * y[i])*h;
		x[i + 1] = x[i] + h;

		actualVal[i] = 0.1 * cos(4.0 * x[i]) + 0.2 * sin(4.0 * x[i]) + 2.9 * exp(-2 * x[i]);
		error[i] = 100 * ((actualVal[i] - y[i]) / actualVal[i]);
		printf("%12.2f\t%12.3f\t%16.3f\t%16.2f\n", x[i], actualVal[i], y[i], fabs(error[i]));
	}

}
/***********************************************
Function name: rkRule
Purpose: use Runge-Kutta 4th order method to find the discrete values of y(t) at each step h
In parameters: double h
Out Parameters: nothing
Version: 1.0
Author: Yanni Li
************************************************/
void rkRule(double h) {
	int i;
	double t = 2.0;
	double k1, k2, k3, k4;
	double x[50], y[50];
	double actualVal[50];
	double error[50];
	x[0] = 0;
	y[0] = 3;
	/* n= (b-a)/h  */
	for (i = 0; i <= t / h; i++)
	{
		k1 = cos(4.0 * x[i]) - 2 * y[i];
		k2 = cos(4.0 * (x[i] + 1 / 2.0 * h)) - 2 * (y[i] + 1 / 2.0 * k1 * h);
		k3 = cos(4.0 * (x[i] + 1 / 2.0 * h)) - 2 * (y[i] + 1 / 2.0 * k2 * h);
		k4 = cos(4.0 * (x[i] + h)) - 2 * (y[i] + k3 * h);

		x[i + 1] = x[i] + h; // x changes 0.1 when i++
		y[i + 1] = y[i] + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6.0; // calculate equation

		actualVal[i] = 0.1 * cos(4.0 * x[i]) + 0.2 * sin(4.0 * x[i]) + 2.9 * exp(-2 * x[i]);
		error[i] = 100 * ((actualVal[i] - y[i]) / actualVal[i]);
		printf("%12.2f\t%12.3f\t%16.3f\t%16.2f\n", x[i+1], actualVal[i], y[i+1], fabs(error[i]));
	}
}

/***********************************************
Function name: main
Purpose: main function
In parameters: None
Out Parameters: 0
Version: 1.0
Author: Yanni Li
************************************************/
int main()
{
	char choice = ' ';
	//char n;
	double h;

	do {
		printf("Choose the method for solving the ODE: \n");
		printf("1. Euler's method \n");
		printf("2. Runge-Kutta 4th Order Method. \n");

		scanf_s("%c",&choice);
		// flushes the standard input 
		// (clears the input buffer) 
		while ((getchar()) != '\n');
		if (choice == '1' || choice == '2')
		{
			printf("Choose step size h (0.8, 0.2, 0.05 )\n");
			scanf_s("%lf", &h);
		}
		// flushes the standard input 
		// (clears the input buffer) 
		while ((getchar()) != '\n');
		switch (choice)
		{
		case '1':
			printf("Time(second)\t ExactTemp(c)\t EstimatedTemp(c)\t PercentangeError\t \n");
			ode(h);
			break;
		case '2':
			printf("Time(second)\t ExactTemp(c)\t EstimatedTemp(c)\t PercentangeError\t \n");
			rkRule(h);
			break;
		case '3':
			printf("Exiting...");
			break;
		default:
			printf("Invalid!");
			break;
		}
	} while (choice != '3');

	return 0;
}


