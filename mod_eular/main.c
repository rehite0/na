#include <stdio.h>
#include <assert.h>
#include <math.h>

double x,a,ad,na,fp,fc;
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
	x=x0;a=ad=na=fp=fc=0;
	assert(x<xn &&"invalid input");
	printf("  x       \t|  approx  \t|  apx.dash\t|  fp      \t|  fc      \n");
	while(x<=xn){
		fp=f(a,x);
		ad=a+dx*fp;
		fc=f(ad,x+dx);
		na=a+(dx/2.0)*(fp+fc);
		printf("%10lf\t|%10lf\t|%10lf\t|%10lf\t|%10lf\n",x,a,ad,fp,fc);
		x+=dx;
		a=na;
	}
}
