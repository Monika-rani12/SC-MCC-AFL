#include<stdio.h>
#include <assert.h>
#include <math.h>
#define BOUND 2
int usymb1,usymb2,usymb3,usymb4;
int main()
{
int X, Y, Z; 
scanf("%d",&usymb1);
scanf("%d",&usymb2);
scanf("%d",&usymb3);
scanf("%d",&usymb4);

scanf("%d",&X);
scanf("%d",&Y);
scanf("%d",&Z); 
if(usymb1){assert((!(!(Z<90)&&!(X>50)&&Y==100)));};
if(usymb2){assert((!(!(Z<90)&&X>50&&!(Y==100))));};
if(usymb3){assert((!(!(Z<90)&&X>50&&Y==100)));};
if(usymb4){assert((!(Z<90&&!(X>50)&&Y==100)));};
if (((X > 50) && (Y == 100)) || (Z < 90)) {
printf("This is FIRST CONDITION\n");
}

if(usymb1){assert((!(!(Z<0)&&!(X>20)&&Y==70)));};
if(usymb2){assert((!(!(Z<0)&&X>20&&!(Y==70))));};
if(usymb3){assert((!(!(Z<0)&&X>20&&Y==70)));};
if(usymb4){assert((!(Z<0&&!(X>20)&&Y==70)));};
if (((X > 20) && (Y == 70)) || (Z < 0)) {
printf("This is SECOND CONDITION\n");
}
return 0;
}
