//This program in Problem1-RERS2012.c
#include <assert.h>
#include <math.h>
#include<stdio.h>
#ifdef LLBMC
#include <llbmc.h>
#else
//removed
#endif

int usymb1,usymb2,usymb3;

int kappa;


int main()
{
kappa = 0;
// default output
int output = -1;

// main i/o-loop


printf("POINT: 256\n");
int symb; scanf("%d",&symb);
scanf("%d",&usymb1);
scanf("%d",&usymb2);
scanf("%d",&usymb3);

// operate eca engine
if(usymb1){assert(0);};
if(usymb2){assert(0);};
if(usymb3){assert(0);};
        printf("%d",symb);

return 0;
}
