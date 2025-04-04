#include <stdio.h>
#include <assert.h>
#include <math.h>

double x,p,pp,fp,fpp;
#include "problem.h"
#ifndef x0
	#define x0 0
#endif
#ifndef x1
	#define x1 1
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

int main(){
	x=0;p=x1;pp=x0;fp=f(p);fpp=f(pp);
	for(int i=0;i<iter;i++){
		printf("iteration:%d\n"
		 		"x:%.10lf\tf(x):%lf\n"
			,i,p,fp);
		x=p-fp*(p-pp)/(fp-fpp);
		if((x-p<=precision && x-p>=-1.0*precision)||f(x)==0) break;
		pp=p;
		p=x;
		fpp=fp;
		fp=f(p);
	}
	printf("solution=%.10lf\n",x);
}
