#include <stdio.h>
#include <assert.h>
#include <math.h>

double x,a,na,f1;
#include "ivps/que.h"
#ifndef x0
	#define x0 0
#endif
#ifndef a0
	#define a0 0
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
	x=x0;a=a0;na=f1=0;
	assert(x<xn &&"invalid input");
	printf("  x       \t|  approx  \t|  f1      \n");
	while(x<=xn){
		f1=f(a,x);
		na=a+dx*f1;
		printf("%10lf\t| %10lf\t| %10lf\n",x,a,f1);
		x+=dx;
		a=na;
	}
}
