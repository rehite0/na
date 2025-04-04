#include <stdio.h>
#include <assert.h>
#include <math.h>

double xn,xm;
#include "problem.h"
#ifndef x0
	#define x0 0
#endif
#ifndef iter
	#define iter 10
#endif
#ifndef precision
	#define precision 0
#endif
#ifndef f
	#error
#endif
#ifndef df
	#error
#endif


int main(){
	xm=0;xn=x0;
	for(int i=0;i<iter;i++){
		printf("iteration:%d\nx:%.10lf\tf(x):%lf\n",i,xn,f(xn));
		xm=xn-(f(xn)/df(xn));
		if((xm-xn<=precision && xm-xn>=-1.0*precision)||f(xm)==0) break;
		xn=xm;

	}
	printf("solution=%.10lf\n",xm);
}
