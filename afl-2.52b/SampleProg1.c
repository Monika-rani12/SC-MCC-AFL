#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
//#include <assume.h>
//#define assert(ignore)((void) 0)
/////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
int k=0;
int main(){
        int x;
scanf("%d", &x);
        if(x == 5)
{
	 assert(0);
         printf("hey");
} 
       else{
	  assert(0);
          printf("BYE");
}
 if(k < 5)
{
	 assert(0);
} 
assert(0); 
assert(k > 2);    // Count of assertion statically present in the program     
}
