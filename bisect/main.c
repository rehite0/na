#include <stdio.h>
#include <assert.h>
#include <math.h>

double u=0,v=0,b=0,bp=0;
#include "problem.h"
#ifndef start
	#define start 0
#endif
#ifndef stop
	#define stop 1
#endif
#ifndef iter
	#define iter 50
#endif
#ifndef precision
	#define precision 0
#endif
int main(){
	u=start;v=stop;
	for(int i=0;i<iter;i++){
		printf("iteration:%d\na:\t%lf\tb:\t%lf\n\tm:\t%lf\n",i,u,v,b);
		if(f(u)*f(v)>0)
			assert(0);
		b=(u+v)/2.0;
		if(f(b)==0) break;
		else if(f(u)*f(b)<0) v=b;
		else if(f(b)*f(v)<0) u=b;

		if(bp-b<=precision && bp-b>=-1.0*precision) break;
		bp=b;

	}
	printf("solution=%lf\n",b);
}
