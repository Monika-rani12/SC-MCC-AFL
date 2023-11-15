#include<stdio.h>
#include <assert.h>
#include <math.h>
#define BOUND 2
int usymb1,usymb2,usymb3,usymb4,usymb5;
int main()
{
int X, Y, Z; 
scanf("%d",&usymb1);
scanf("%d",&usymb2);
scanf("%d",&usymb3);
scanf("%d",&usymb4);
scanf("%d",&usymb5);

scanf("%d",&X);
scanf("%d",&Y);
scanf("%d",&Z); 

if(usymb1){assert(!(!(X>50)&&Y==100&&!(Z<90)));}
if(usymb2){assert(!(!(X>50)&&Y==100&&Z<90));}
if(usymb3){assert(!(X>50&&!(Y==100)&&!(Z<90)));}
if(usymb4){assert(!(X>50&&!(Y==100)&&Z<90));}
if(usymb5){assert(!(X>50&&Y==100&&Z<90));}

if (((X > 50) && (Y == 100)) || (Z < 90)) {
printf("This is FIRST CONDITION\n");
}


if(usymb1){assert(!(!(X>20)&&Y==70&&!(Z<0)));}
if(usymb2){assert(!(!(X>20)&&Y==70&&Z<0));}
if(usymb3){assert(!(X>20&&!(Y==70)&&!(Z<0)));}
if(usymb4){assert(!(X>20&&!(Y==70)&&Z<0));}
if(usymb5){assert(!(X>20&&Y==70&&Z<0));}

if (((X > 20) && (Y == 70)) || (Z < 0)) {
printf("This is SECOND CONDITION\n");
}
return 0;
}
