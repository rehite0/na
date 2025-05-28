#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

double x,a,ad,na,fp,fc;
#include "../extras/ivps/que.h"
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
#ifndef prec
	#define prec 0.0001
#endif

int main(){
	x=x0;a=a0;ad=na=fp=fc=0;
	assert(x<xn &&"invalid input");
	printf("  x       \t|  approx  \t|\n");
	while(x<=xn){
		printf("%10lf\t| %10lf\t",x,a);
		fp=f(a,x);
		ad=a+dx*fp;
		do{
			printf("| %10lf\t",ad);
			fc=f(ad,(x+dx));
			na=a+dx*(f(a,x)+fc)/2.0;
		}while(fabs(na-ad) >=prec && (ad=na));
		x+=dx;
		a=na;
		printf("\n");
	}
}
