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
	for (int FLAG=0;FLAG<BOUND;FLAG++) {
        int symb; scanf("%d",&symb); 
        int symb1; scanf("%d",&symb1);  
        int symb2; scanf("%d",&symb2); 
        int symb3; scanf("%d",&symb3); 
        if((symb1 != 10) && (symb1 != 6) && (symb2 != 1) && (symb2 != 8) && (symb3 != 2) || (symb3 != 5) && (symb1 != 7) && (symb2 != 9) && (symb3 != 4) && (symb != 3)){
        printf("%d",symb);
    	}
    }
 	return 0;

}


