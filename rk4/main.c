#include <stdio.h>
#include <assert.h>
#include <math.h>

double x,a,na,f1,f2,f3,f4;
#include "../extras/ivps/que.h"
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
	x=x0;a=a0;na=f1=f2=f3=f4=0;
	assert(x<xn &&"invalid input");
	printf("  x       \t|  approx  \t|  f1      \t|  f2      \t|  f3      \t|  f4      \n");
	while(x<=xn){
		f1=f( a , x );
		f2=f( (a+dx*f1/2.0) , (x+dx/2.0) );
		f3=f( (a+dx*f2/2.0) , (x+dx/2.0) );
		f4=f( (a+dx*f3) , (x+dx) );
		na=a+(dx/6)*(f1+2*f2+2*f3+f4);
		printf("%10lf\t| %10lf\t| %10lf\t| %10lf\t| %10lf\t| %10lf\n",x,a,f1,f2,f3,f4);
		x+=dx;
		a=na;
	}
}
