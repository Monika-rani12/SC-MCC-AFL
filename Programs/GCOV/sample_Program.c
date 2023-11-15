#include<stdio.h>
#ifdef LLBMC
#include <llbmc.h>
#else
//removed
#endif

#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define BOUND 2
int kappa;
	 
int main()
{
kappa = 0;
    // main i/o-loop
      
printf("POINT: 481\n");

    for (int FLAG=0;FLAG<BOUND;FLAG++) {
printf("POINT: 482\n");
        int symb; scanf("%d",&symb);  
        if((symb != 10) && (symb != 6) && (symb != 1) && (symb != 8) && (symb != 2) || (symb != 5) && (symb != 7) && (symb != 9) && (symb != 4) && (symb != 3)){
        printf("%d",symb);
    }
    }
 return 0;

}


