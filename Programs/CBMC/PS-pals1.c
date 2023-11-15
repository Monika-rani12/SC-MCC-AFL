//This program is pals_lcr.3_false-unreach-call.1.ufo.UNBOUNDED.pals.c








/**********************************************************************

Copyright (c) 2013 Carnegie Mellon University. All Rights Reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following acknowledgments and
disclaimers.

2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

3. The names "Carnegie Mellon University," "SEI" and/or "Software
Engineering Institute" shall not be used to endorse or promote
products derived from this software without prior written
permission. For written permission, please contact
permission@sei.cmu.edu.

4. Products derived from this software may not be called "SEI" nor may
"SEI" appear in their names without prior written permission of
permission@sei.cmu.edu.

5. Redistributions of any form whatsoever must retain the following
acknowledgment:

This material is based upon work funded and supported by the
Department of Defense under Contract No. FA8721-05-C-0003 with
Carnegie Mellon University for the operation of the Software
Engineering Institute, a federally funded research and development
center.

Any opinions, findings and conclusions or recommendations expressed in
this material are those of the author(s) and do not necessarily
reflect the views of the United States Department of Defense.

NO WARRANTY. THIS CARNEGIE MELLON UNIVERSITY AND SOFTWARE ENGINEERING
INSTITUTE MATERIAL IS FURNISHEDON AN "AS-IS" BASIS. CARNEGIE MELLON
UNIVERSITY MAKES NO WARRANTIES OF ANY KIND, EITHER EXPRESSED OR
IMPLIED, AS TO ANY MATTER INCLUDING, BUT NOT LIMITED TO, WARRANTY OF
FITNESS FOR PURPOSE OR MERCHANTABILITY, EXCLUSIVITY, OR RESULTS
OBTAINED FROM USE OF THE MATERIAL. CARNEGIE MELLON UNIVERSITY DOES NOT
MAKE ANY WARRANTY OF ANY KIND WITH RESPECT TO FREEDOM FROM PATENT,
TRADEMARK, OR COPYRIGHT INFRINGEMENT.

This material has been approved for public release and unlimited
distribution.

DM-0000575

**********************************************************************/

/* Generated by CIL v. 1.6.0 */
/* print_CIL_Input is true */
#include <stdlib.h>
#include <stdio.h> 
#include <assert.h>
int kappa;
typedef int bool;
#define true 1
#define false 0
typedef char msg_t;
typedef int port_t;
extern void read(port_t p , msg_t m ) ;
extern void write(port_t p , msg_t m ) ;
msg_t nomsg  =    (msg_t )-1;
char r1  ;
port_t p1  ;
char p1_old ;
char p1_new ;
char id1  ;
char st1  ;
msg_t send1  ;
bool mode1  ;
port_t p2  ;
char p2_old ;
char p2_new ;
char id2  ;
char st2  ;
msg_t send2  ;
bool mode2  ;
port_t p3  ;
char p3_old ;
char p3_new ;
char id3  ;
char st3  ;
msg_t send3  ;
bool mode3  ;
void node1(void) 
{ 
  msg_t m1 ;

  {
  m1 = nomsg;
printf("POINT: 1\n");

  if (mode1) {
printf("POINT: 2\n");
printf("POINT: 3\n");

    if (r1 == 255) {
printf("POINT: 4\n");
      r1 = 2;
    }
    r1 = r1 + 1;
    m1 = p3_old;
    p3_old = nomsg;
printf("POINT: 5\n");

    if ((int )m1 != (int )nomsg) {
printf("POINT: 6\n");
printf("POINT: 7\n");

      if ((int )m1 > (int )id1) {
printf("POINT: 8\n");
        send1 = m1;
      } else
printf("POINT: 9\n");

      if ((int )m1 == (int )id1) {
printf("POINT: 10\n");
        st1 = (char)1;
      } else {
printf("POINT: 12\n");
        send1 = m1;
      }
    }
    mode1 = (bool)0;
  } else {
printf("POINT: 14\n");
  
printf("POINT: 15\n");

   if ((send1 != nomsg) && (p1_new == nomsg)){
printf("POINT: 16\n");
    p1_new = send1;
    }
    else{
    p1_new = p1_new;
    }
    mode1 = (bool)1;
  }
  return;
}
}
void node2(void) 
{ 
  msg_t m2 ;

  {
  m2 = nomsg;
printf("POINT: 17\n");

  if (mode2) {
printf("POINT: 18\n");
    m2 = p1_old;
    p1_old = nomsg;
printf("POINT: 19\n");

    if ((int )m2 != (int )nomsg) {
printf("POINT: 20\n");
printf("POINT: 21\n");

      if ((int )m2 > (int )id2) {
printf("POINT: 22\n");
        send2 = m2;
printf("POINT: 23\n");

      } else if ((int )m2 == (int )id2) {
printf("POINT: 24\n");
        st2 = (char)1;
      }
    }
    mode2 = (bool)0;
  } else {
printf("POINT: 26\n");
    
    
printf("POINT: 27\n");

    if ((send2 != nomsg) && (p2_new == nomsg)){
printf("POINT: 28\n");
    p2_new = send2;
    }
    else{
    p2_new = p2_new;
    }
    
    mode2 = (bool)1;
  }
  return;
}
}
void node3(void) 
{ 
  msg_t m3 ;

  {
  m3 = nomsg;
printf("POINT: 29\n");

  if (mode3) {
printf("POINT: 30\n");
    m3 = p2_old;
    p2_old = nomsg;
printf("POINT: 31\n");

    if ((int )m3 != (int )nomsg) {
printf("POINT: 32\n");
printf("POINT: 33\n");

      if ((int )m3 > (int )id3) {
printf("POINT: 34\n");
        send3 = m3;
printf("POINT: 35\n");

      } else if ((int )m3 == (int )id3) {
printf("POINT: 36\n");
        st3 = (char)1;
      }
    }
    mode3 = (bool)0;
  } else {
printf("POINT: 38\n");
    
printf("POINT: 39\n");

    if ((send3 != nomsg) && (p3_new == nomsg)){
printf("POINT: 40\n");
    p3_new = send3;
    }
    else{
    p3_new = p3_new;
    }
    
    
    mode3 = (bool)1;
  }
  return;
}
}
void (*nodes[3])(void)  = {      & node1,      & node2,      & node3};
int init(void) 
{ 
  int tmp ;

  {
printf("POINT: 41\n");

  if ((int )r1 == 0) {
printf("POINT: 42\n");
printf("POINT: 43\n");

    if ((int )id1 >= 0) {
printf("POINT: 44\n");
printf("POINT: 45\n");

      if ((int )st1 == 0) {
printf("POINT: 46\n");
printf("POINT: 47\n");

        if ((int )send1 == (int )id1) {
printf("POINT: 48\n");
printf("POINT: 49\n");

          if ((int )mode1 == 0) {
printf("POINT: 50\n");
printf("POINT: 51\n");

            if ((int )id2 >= 0) {
printf("POINT: 52\n");
printf("POINT: 53\n");

              if ((int )st2 == 0) {
printf("POINT: 54\n");
printf("POINT: 55\n");

                if ((int )send2 == (int )id2) {
printf("POINT: 56\n");
printf("POINT: 57\n");

                  if ((int )mode2 == 0) {
printf("POINT: 58\n");
printf("POINT: 59\n");

                    if ((int )id3 >= 0) {
printf("POINT: 60\n");
printf("POINT: 61\n");

                      if ((int )st3 == 0) {
printf("POINT: 62\n");
printf("POINT: 63\n");

                        if ((int )send3 == (int )id3) {
printf("POINT: 64\n");
printf("POINT: 65\n");

                          if ((int )mode3 == 0) {
printf("POINT: 66\n");
printf("POINT: 67\n");

                            if ((int )id1 != (int )id2) {
printf("POINT: 68\n");
printf("POINT: 69\n");

                              if ((int )id1 != (int )id3) {
printf("POINT: 70\n");
printf("POINT: 71\n");

                                if ((int )id2 != (int )id3) {
printf("POINT: 72\n");
                                  tmp = 1;
                                } else {
printf("POINT: 74\n");
                                  tmp = 0;
                                }
                              } else {
printf("POINT: 76\n");
                                tmp = 0;
                              }
                            } else {
printf("POINT: 78\n");
                              tmp = 0;
                            }
                          } else {
printf("POINT: 80\n");
                            tmp = 0;
                          }
                        } else {
printf("POINT: 82\n");
                          tmp = 0;
                        }
                      } else {
printf("POINT: 84\n");
                        tmp = 0;
                      }
                    } else {
printf("POINT: 86\n");
                      tmp = 0;
                    }
                  } else {
printf("POINT: 88\n");
                    tmp = 0;
                  }
                } else {
printf("POINT: 90\n");
                  tmp = 0;
                }
              } else {
printf("POINT: 92\n");
                tmp = 0;
              }
            } else {
printf("POINT: 94\n");
              tmp = 0;
            }
          } else {
printf("POINT: 96\n");
            tmp = 0;
          }
        } else {
printf("POINT: 98\n");
          tmp = 0;
        }
      } else {
printf("POINT: 100\n");
        tmp = 0;
      }
    } else {
printf("POINT: 102\n");
      tmp = 0;
    }
  } else {
printf("POINT: 104\n");
    tmp = 0;
  }
  return (tmp);
}
}
int check(void) 
{ 
  int tmp ;

  {
printf("POINT: 105\n");

  if (((int )st1 + (int )st2) + (int )st3 <= 1) {
printf("POINT: 106\n");
printf("POINT: 107\n");

    if ((int )r1 >= 3) {
printf("POINT: 108\n");
      goto _L;
    } else
printf("POINT: 109\n");

    if (((int )st1 + (int )st2) + (int )st3 == 0) {
printf("POINT: 110\n");
      _L: /* CIL Label */ 
printf("POINT: 111\n");

      if ((int )r1 < 3) {
printf("POINT: 112\n");
        tmp = 1;
printf("POINT: 113\n");

      } else if (((int )st1 + (int )st2) + (int )st3 == 1) {
printf("POINT: 114\n");
        tmp = 1;
      } else {
printf("POINT: 116\n");
        tmp = 0;
      }
    } else {
printf("POINT: 118\n");
      tmp = 0;
    }
  } else {
printf("POINT: 120\n");
    tmp = 0;
  }
  return (tmp);
}
}


int main(void) 
{ 
kappa=0;
  int c1 ;
  int i2 ;

  {
  c1 = 0;
  
  r1 = nondet_char(); __CPROVER_input("r1",r1);
  id1 = nondet_char(); __CPROVER_input("id1",id1);
  st1 = nondet_char(); __CPROVER_input("st1",st1);
  send1 = nondet_char(); __CPROVER_input("send1",send1);
  mode1 = nondet_bool(); __CPROVER_input("mode1",mode1);

  id2 = nondet_char(); __CPROVER_input("id2",id2);
  st2 = nondet_char(); __CPROVER_input("st2",st2);
  send2 = nondet_char(); __CPROVER_input("send2",send2);
  mode2 = nondet_bool(); __CPROVER_input("mode2",mode2);
  
  id3 = nondet_char(); __CPROVER_input("id3",id3);
  st3 = nondet_char(); __CPROVER_input("st3",st3);
  send3 = nondet_char(); __CPROVER_input("send3",send3);
  mode3 = nondet_bool(); __CPROVER_input("mode3",mode3);
  
   i2 = init();

  p1_old = nomsg;
  p1_new = nomsg;
  p2_old = nomsg;
  p2_new = nomsg;
  p3_old = nomsg;
  p3_new = nomsg;
  i2 = 0;
printf("POINT: 121\n");

  while (i2 < 2) {
printf("POINT: 122\n");
    {
    node1();
    node2();
    node3();
    p1_old = p1_new;
    p1_new = nomsg;
    p2_old = p2_new;
    p2_new = nomsg;
    p3_old = p3_new;
    p3_new = nomsg;
    c1 = check();
    i2++;
    }
  }
}

 return 0;
 }
