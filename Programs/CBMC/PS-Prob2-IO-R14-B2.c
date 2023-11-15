#include<stdio.h>
#ifdef LLBMC
#include <llbmc.h>
#else
//removed
#endif

#include <stdio.h> 
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define BOUND 2 //BOUND 15
int kappa;
	int inputs[] = {1,6,3,5,4,2};

	 int a11 = 11;
	 int a279 = 1;
	 int a398 = 1;
	 int a252 = 4;
	 int a107 = 34;
	 int a290 = 6;
	 int a329 = 9;
	 int a236 = 6;
	 int a114 = 279;
	 int a90 = 2;
	 int a125 = -15;
	 int a178 = -201;
	 int a134 = 7;
	 int a97 = 213;
	 int a171 = 7;
	 int a187 = 237;
	 int a103 = -161;
	 int a79 = -65;
	 int a124 = 227;
	 int a280 = 6;
	 int a147 = 11;
	 int a109 = 34;
	 int a158 = 6;
	 int a388 = 3;
	 int a182 = 495;
	 int a56 = 10;
	 int a189 = 45;
	 int a117 = 166;
	 int a24 = 10;
	 int a66 = -37;
	 int a337 = 11;
	 int a173 = 115;
	 int a88 = -19;
	 int a136 = 9;
	 int a116 = 163;
	 int a119 = 55;
	 int a75 = 232;
	 int a45 = 56;
	 int a108 = 279;
	 int a302 = 13;
	 int a260 = 10;
	 int a23 = 11;
	 int a184 = 10;
	 int a180 = 10;
	 int a0 = 375;
	 int a39 = 12;
	 int a83 = -104;
	 int a185 = 199;
	 int a19 = 140;
	 int a70 = 4;
	 int a358 = 4;
	 int a212 = 9;
	 int a229 = 4;
	 int a138 = 266;
	 int a105 = -95;
	 int a111 = 387;
	 int a127 = 10;
	 int a155 = 506;
	 int a21 = 8;
	 int a317 = 4;
	 int a168 = -24;
	 int cf = 1;
	 int a99 = 226;
	 int a327 = 9;
	 int a61 = 2;
	 int a383 = 8;
	 int a144 = 4;
	 int a284 = 8;
	 int a82 = 65;
	 int a299 = 9;
	 int a85 = 199;
	 int a78 = 101;
	 int a80 = 488;
	 int a251 = 6;
	 int a32 = -47;
	 int a148 = 9;
	 int a28 = 77;
	 int a141 = 4;
	 int a321 = 6;
	 int a110 = 452;
	 int a132 = 47;
	 int a121 = 4;
	 int a159 = -48;
	 int a360 = 5;
	 int a38 = 11;
	 int a67 = 3;
	 int a152 = 9;
	 int a113 = 65;
	 int a151 = -20;
	 int a344 = 9;
	 int a49 = 248;
	 int a210 = 6;
	 int a196 = 4;
	 int a58 = 148;
	 int a193 = 147;
	 int a130 = 6;
	 int a126 = 7;
	 int a129 = 4;
	 int a169 = 11;
	 int a258 = 5;
	 int a156 = -176;
	 int a120 = 80;
	 int a91 = 288;
	 int a142 = -38;
	 int a309 = 8;
	 int a52 = 161;
	 int a60 = 94;
	 int a13 = 35;
	 int a92 = 6;
	 int a73 = 470;
	 int a41 = 55;
	 int a74 = 40;
	 int a93 = 405;
	 int a46 = 4;
	 int a98 = 121;
	 int a289 = 12;
	 int a379 = 6;
	 int a378 = 3;
	 int a200 = 399;
	 int a177 = -79;
	 int a276 = 3;
	 int a160 = 49;

 void calculate_output(int input) {
    if((( 224 < a119  || (( 491 < a155  &&  a193 <=  167 ) || !(a344==9))) && ((((cf==1) && (input == 1)) &&  -120 < a19 ) || !(a329==9)))){
printf("POINT: 192\n");
    	 cf = (0);
    	a321 = (6);
    	a178 = ((((((((  a178) * a119)% 14999) % 75)- 108) + 2) / 5) + -61);
    	a196 = (4);
    	a74 = (((((((  a74) * a116)% 14999) - 6596) * 1) % 62)+ -38);
    	a134 = (11);
    	a260 = (10);
    	a58 = ((((((((  a58) * a80)% 14999) % 49)- -107) + 3) / 5) - -135);
    	a344 = (9);
    	a210 = (6);
    	   
    } 
}

int input,output;
int main()
{
kappa = 0;
    // main i/o-loop

/*   int symb;*/
printf("POINT: 405\n");

   for (int FLAG=0;FLAG<BOUND;FLAG++){
printf("POINT: 406\n");
    int symb = nondet_int(); __CPROVER_input("symb",symb);
        // operate eca engine
        calculate_output(symb);
        printf("%d",symb);
    }
}
