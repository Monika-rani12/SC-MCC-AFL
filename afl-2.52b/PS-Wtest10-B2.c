#include <assert.h>
#include <math.h>
#include<stdio.h>
#ifdef LLBMC
#include <llbmc.h>
#else
//removed
#endif
#include <assert.h>
#define BOUND 2


// inputs
int a= 1;
int e= 5;
int d= 4;
int f= 6;
int c= 3;

// outputs
int u = 21;
int v = 22;
int w = 23;
int x = 24;
int y = 25;
int z = 26;


int a25 = 0;
int a11 = 0;
int a28 = 7;
int a19 = 1;
int a21 = 1;
int a17 = 8;
int kappa;
int calculate_output(int input) {
printf("POINT: 1\n");
if((((!(a11==1)&&((a19==1)&&((input==4)&&((!(a25==1)&&(a28==8))||((a25==1)&&(a28==9))))))&&(a21==1))&&(a17==8))){
printf("POINT: 2\n");
a28 = 9;
assert(0);
a11 = 1;
a25 = 1;
printf("%d",-1);//return -1;
} else{
printf("POINT: 3\n");
}
 if(((a17==8)&&((((!(a11==1)&&((a21==1)&&(input==6)))&&(a28==7))&&(a19==1))&&!(a25==1)))){
printf("POINT: 4\n");
a28 = 10;
assert(0);
printf("%d", 22);//return 22;
} else{
printf("POINT: 5\n");
}
assert(0);
 
printf("%d",-2);//return -2;
}


int input, output;

int main()
{
kappa = 0;
// default output
int output = -1;

// main i/o-loop

for (int FLAG=0;FLAG<BOUND;FLAG++) {
printf("POINT: 294\n");
int symb; scanf("%d",&symb);

// operate eca engine
output = calculate_output(symb);
        printf("%d",symb);

}
return 0;

}

