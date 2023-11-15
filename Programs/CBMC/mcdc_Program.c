#include<stdio.h>
#include <assert.h>
#include <math.h>
#define BOUND 2
int main()
{
int X = nondet_int(); __CPROVER_input("X",X); 
int Y = nondet_int(); __CPROVER_input("Y",Y); 
int Z = nondet_int(); __CPROVER_input("Z",Z);
if (((X > 50) && (Y == 100)) || (Z < 90)) {
printf("This is FIRST CONDITION\n");
}
if (((X > 20) && (Y == 70)) || (Z < 0)) {
printf("This is SECOND CONDITION\n");
}
return 0;
}
