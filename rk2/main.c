#include <stdio.h>
#include <assert.h>
#include <math.h>

double x,a,na,f1,f2;
#include "problem.h"
#ifndef x0
	#define x0 0
#endif
#ifndef xn
	#define xn 1
#endif
#ifndef dx
	#define dx 0.1
#endif

#ifndef f
	#error
#endif

int main(){
	x=x0;a=na=f1=f2=0;
	assert(x<xn &&"invalid input");
	printf("  x       \t|  approx  \t|  f1      \t|  f2      \n");
	while(x<=xn){
		f1=f(a,x);
		f2=f(a+dx*f1/2.0,x+dx/2.0);
		na=a+dx*f2;
		printf("%10lf\t|%10lf\t|%10lf\t|%10lf\n",x,a,f1,f2);
		x+=dx;
		a=na;
	}
}
