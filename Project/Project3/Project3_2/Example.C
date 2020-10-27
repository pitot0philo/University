#include <stdio.h>
#include <math.h>

double dotproduct(double x[], double y[]);
double size_of_vector(double x[]);

int main(void)
{
	double slope, ybias, xpoint, ypoint;
	double strt[2];
	double drcstrt[2];
	double bet_strt_n_pnt[2];

	printf("enter the slope and bias of equation of straight line : ");
	scanf("%lf %lf", &slope, &ybias);

	printf("\nenter the two point of x,y field : ");
	scanf("%lf %lf", &xpoint, &ypoint);

	if ((slope > 0 && ybias > 0) || (slope < 0 && ybias > 0))
	{
		printf("\n\nentered equation of straight line is y=%.4lfx+%.4lf", slope, ybias);
		printf("\n\nentered x,y field point is (%.4lf, %.4lf)\n", xpoint, ypoint);
	}
	else if ((slope > 0 && ybias < 0)|| (slope < 0 && ybias < 0))
	{
		printf("\n\nentered equation of straight line is y=%.4lfx%.4lf", slope, ybias);
		printf("\n\nentered x,y field point is (%.4lf, %.4lf)\n", xpoint, ypoint);
	}

	//slope = ybias-0/0-xbias. so=> 0-xbias=ybias/slope. xbias = - ybias/slope
	double xbias = 0;

	xbias = -(ybias / slope);

	printf("\n\nx, y bias of equation of straight line is (%.4lf , 0), (0, %.4lf)", xbias, ybias);

	strt[0] = 0 - xbias;
	strt[1] = ybias - 0;
	//strt[0] and strt[1] are vector of straight line

	if (strt[1] > 0)
	{
		printf("\n\nvector of straight line is %.4lfi+%.4lfj", strt[0], strt[1]);
	}
	else if (strt[1] < 0)
	{
		printf("\n\nvector of straight line is %.4lfi%.4lfj", strt[0], strt[1]);
	}

	//size of vector

	drcstrt[0] = strt[0] / size_of_vector(strt);
	drcstrt[1] = strt[1] / size_of_vector(strt);
	//drcstrt[0] and drcstrt[1] are direction vector of straight line

	if (drcstrt[1] > 0)
	{
		printf("\n\ndirection vector of straight line is %.4lfi+%.4lfj", drcstrt[0], drcstrt[1]);
	}
	else if (drcstrt[1] < 0)
	{
		printf("\n\ndirection vector of straight line is %.4lfi%.4lfj", drcstrt[0], drcstrt[1]);
	}

	//ul vector:drcstrt[0], drcstrt[1]//a vector=xpoint-0 i + ypoint-ybias j

	bet_strt_n_pnt[0] = xpoint - 0;
	bet_strt_n_pnt[1] = ypoint - ybias;
	//bet_strt_n_pnt[0] and bet_strt_n_pnt[1] is Element of vector between straight line and point

	if (bet_strt_n_pnt[1] > 0)
	{
		printf("\n\nnew vector between point of x,y field and straight line is %.4lfi+%.4lfj", bet_strt_n_pnt[0], bet_strt_n_pnt[1]);
	}
	else if (bet_strt_n_pnt[1] < 0)
	{
		printf("\n\nnew vector between point of x,y field and straight line is  %.4lfi%.4lfj", bet_strt_n_pnt[0], bet_strt_n_pnt[1]);
	}

	//shortest vector : vec(bet_strt_n_pnt)-(vec(bet_strt_n_pnt) dotproduct vec(drcstrt))*vec(drcstrt)
	//distance between straight line and point : sqrt(shortest vector)

	
	double dot = 0;
	dot = dotproduct(bet_strt_n_pnt, drcstrt);

	printf("\n\ndotproduct of vector between straight line and point is %.4lf", dot);

	double shrtvec[2];
	shrtvec[0] = bet_strt_n_pnt[0] - dot * drcstrt[0];
	shrtvec[1] = bet_strt_n_pnt[1] - dot * drcstrt[1];

	double dist = 0;
	dist = size_of_vector(shrtvec);

	if ((slope > 0 && ybias > 0) || (slope < 0 && ybias > 0))
	{
		printf("\n\ndistance between straight line y=%.4lfx+%.4lf and point of x, y field (%.4lf, %.4lf) is %.4lf\n\n", slope, ybias, xpoint, ypoint, dist);
	}
	else if ((slope > 0 && ybias < 0) || (slope < 0 && ybias < 0))
	{
		printf("\n\ndistance between straight line y=%.4lfx%.4lf and point of x, y field (%.4lf, %.4lf) is %.4lf\n\n", slope, ybias, xpoint, ypoint, dist);
	}

	return 0;
}

double dotproduct(double x[], double y[])
{
	int i;
	double result;

	result = 0.0;
	for (i = 0; i < 2; i++)
		result += x[i] * y[i];

	return result;
}

double size_of_vector(double x[])
{
	double result;
	
	result = sqrt(pow(x[0], 2) + pow(x[1], 2));

	return result;
}
