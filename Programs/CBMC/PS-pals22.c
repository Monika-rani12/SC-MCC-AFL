//This program is pals_lcr-var-start-time.3_false-unreach-call.1.ufo.UNBOUNDED.pals.c







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
bool alive1  ;
port_t p2  ;
char p2_old ;
char p2_new ;
char id2  ;
char st2  ;
msg_t send2  ;
bool mode2  ;
bool alive2  ;
port_t p3  ;
char p3_old ;
char p3_new ;
char id3  ;
char st3  ;
msg_t send3  ;
bool mode3  ;
bool alive3  ;
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

      if (alive1) {
printf("POINT: 8\n");
printf("POINT: 9\n");

        if ((int )m1 > (int )id1) {
printf("POINT: 10\n");
          send1 = m1;
printf("POINT: 11\n");

        } else if ((int )m1 == (int )id1) {
printf("POINT: 12\n");
          st1 = (char)1;
        } else {
printf("POINT: 14\n");
          send1 = m1;
        }
      } else {
printf("POINT: 16\n");
        send1 = m1;
      }
    }
    mode1 = (bool)0;
  } else {
printf("POINT: 18\n");
printf("POINT: 19\n");

    if (alive1) {
printf("POINT: 20\n");
      
printf("POINT: 21\n");

      if ((send1 != nomsg) && (p1_new == nomsg)){
printf("POINT: 22\n");
    p1_new = send1;
    }
    else{
    p1_new = p1_new;
    }
      
      
    } else{
printf("POINT: 23\n");

    if ((int )send1 != (int )id1) {
printf("POINT: 24\n");
      
printf("POINT: 25\n");

      if ((send1 != nomsg) && (p1_new == nomsg)){
printf("POINT: 26\n");
    p1_new = send1;
    }
    else{
    p1_new = p1_new;
    }
    } 
      
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
printf("POINT: 27\n");

  if (mode2) {
printf("POINT: 28\n");
    m2 = p1_old;
    p1_old = nomsg;
printf("POINT: 29\n");

    if ((int )m2 != (int )nomsg) {
printf("POINT: 30\n");
printf("POINT: 31\n");

      if (alive2) {
printf("POINT: 32\n");
printf("POINT: 33\n");

        if ((int )m2 > (int )id2) {
printf("POINT: 34\n");
          send2 = m2;
printf("POINT: 35\n");

        } else if ((int )m2 == (int )id2) {
printf("POINT: 36\n");
          st2 = (char)1;
        }
      } else {
printf("POINT: 38\n");
        send2 = m2;
      }
    }
    mode2 = (bool)0;
  } else {
printf("POINT: 40\n");
printf("POINT: 41\n");

    if (alive2) {
printf("POINT: 42\n");
      
printf("POINT: 43\n");

    if ((send2 != nomsg) && (p2_new == nomsg)){
printf("POINT: 44\n");
    p2_new = send2;
    }
    else{
    p2_new = p2_new;
    }
      
      
    } else{
printf("POINT: 45\n");

    if ((int )send2 != (int )id2) {
printf("POINT: 46\n");
      
printf("POINT: 47\n");

    if ((send2 != nomsg) && (p2_new == nomsg)){
printf("POINT: 48\n");
    p2_new = send2;
    }
    else{
    p2_new = p2_new;
    }
    } 
      
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
printf("POINT: 49\n");

  if (mode3) {
printf("POINT: 50\n");
    m3 = p2_old;
    p2_old = nomsg;
printf("POINT: 51\n");

    if ((int )m3 != (int )nomsg) {
printf("POINT: 52\n");
printf("POINT: 53\n");

      if (alive3) {
printf("POINT: 54\n");
printf("POINT: 55\n");

        if ((int )m3 > (int )id3) {
printf("POINT: 56\n");
          send3 = m3;
printf("POINT: 57\n");

        } else if ((int )m3 == (int )id3) {
printf("POINT: 58\n");
          st3 = (char)1;
        }
      } else {
printf("POINT: 60\n");
        send3 = m3;
      }
    }
    mode3 = (bool)0;
  } else {
printf("POINT: 62\n");
printf("POINT: 63\n");

    if (alive3) {
printf("POINT: 64\n");
    
printf("POINT: 65\n");

    if ((send3 != nomsg) && (p3_new == nomsg)){
printf("POINT: 66\n");
    p3_new = send3;
    }
    else{
    p3_new = p3_new;
    }
    
    } else{
printf("POINT: 67\n");

    if ((int )send3 != (int )id3) {
printf("POINT: 68\n");
    
printf("POINT: 69\n");

    if ((send3 != nomsg) && (p3_new == nomsg)){
printf("POINT: 70\n");
    p3_new = send3;
    }
    else{
    p3_new = p3_new;
    }
    
    }
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
printf("POINT: 71\n");

  if ((int )r1 == 0) {
printf("POINT: 72\n");
printf("POINT: 73\n");

    if (((int )alive1 + (int )alive2) + (int )alive3 >= 1) {
printf("POINT: 74\n");
printf("POINT: 75\n");

      if ((int )id1 >= 0) {
printf("POINT: 76\n");
printf("POINT: 77\n");

        if ((int )st1 == 0) {
printf("POINT: 78\n");
printf("POINT: 79\n");

          if ((int )send1 == (int )id1) {
printf("POINT: 80\n");
printf("POINT: 81\n");

            if ((int )mode1 == 0) {
printf("POINT: 82\n");
printf("POINT: 83\n");

              if ((int )id2 >= 0) {
printf("POINT: 84\n");
printf("POINT: 85\n");

                if ((int )st2 == 0) {
printf("POINT: 86\n");
printf("POINT: 87\n");

                  if ((int )send2 == (int )id2) {
printf("POINT: 88\n");
printf("POINT: 89\n");

                    if ((int )mode2 == 0) {
printf("POINT: 90\n");
printf("POINT: 91\n");

                      if ((int )id3 >= 0) {
printf("POINT: 92\n");
printf("POINT: 93\n");

                        if ((int )st3 == 0) {
printf("POINT: 94\n");
printf("POINT: 95\n");

                          if ((int )send3 == (int )id3) {
printf("POINT: 96\n");
printf("POINT: 97\n");

                            if ((int )mode3 == 0) {
printf("POINT: 98\n");
printf("POINT: 99\n");

                              if ((int )id1 != (int )id2) {
printf("POINT: 100\n");
printf("POINT: 101\n");

                                if ((int )id1 != (int )id3) {
printf("POINT: 102\n");
printf("POINT: 103\n");

                                  if ((int )id2 != (int )id3) {
printf("POINT: 104\n");
                                    tmp = 1;
                                  } else {
printf("POINT: 106\n");
                                    tmp = 0;
                                  }
                                } else {
printf("POINT: 108\n");
                                  tmp = 0;
                                }
                              } else {
printf("POINT: 110\n");
                                tmp = 0;
                              }
                            } else {
printf("POINT: 112\n");
                              tmp = 0;
                            }
                          } else {
printf("POINT: 114\n");
                            tmp = 0;
                          }
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
                  } else {
printf("POINT: 122\n");
                    tmp = 0;
                  }
                } else {
printf("POINT: 124\n");
                  tmp = 0;
                }
              } else {
printf("POINT: 126\n");
                tmp = 0;
              }
            } else {
printf("POINT: 128\n");
              tmp = 0;
            }
          } else {
printf("POINT: 130\n");
            tmp = 0;
          }
        } else {
printf("POINT: 132\n");
          tmp = 0;
        }
      } else {
printf("POINT: 134\n");
        tmp = 0;
      }
    } else {
printf("POINT: 136\n");
      tmp = 0;
    }
  } else {
printf("POINT: 138\n");
    tmp = 0;
  }
  return (tmp);
}
}
int check(void) 
{ 
  int tmp ;

  {
printf("POINT: 139\n");

  if (((int )st1 + (int )st2) + (int )st3 <= 1) {
printf("POINT: 140\n");
printf("POINT: 141\n");

    if ((int )r1 < 3) {
printf("POINT: 142\n");
      tmp = 1;
printf("POINT: 143\n");

    } else if (((int )st1 + (int )st2) + (int )st3 == 1) {
printf("POINT: 144\n");
      tmp = 1;
    } else {
printf("POINT: 146\n");
      tmp = 0;
    }
  } else {
printf("POINT: 148\n");
    tmp = 0;
  }
  return (tmp);
}
}
int main(void) 
{ 
  int c1 ;
  int i2 ;
  kappa = 0;
  {
  c1 = 0;
  r1 = nondet_char(); __CPROVER_input("r1",r1);
  
  
  id1 = nondet_char(); __CPROVER_input("id1",id1);
  st1 = nondet_char(); __CPROVER_input("st1",st1);
  send1 = nondet_char(); __CPROVER_input("send1",send1);
  mode1 = nondet_bool(); __CPROVER_input("mode1",mode1);
  alive1 = nondet_bool(); __CPROVER_input("alive1",alive1);

  id2 = nondet_char(); __CPROVER_input("id2",id2);
  st2 = nondet_char(); __CPROVER_input("st2",st2);
  send2 = nondet_char(); __CPROVER_input("send2",send2);
  mode2 = nondet_bool(); __CPROVER_input("mode2",mode2);
  alive2 = nondet_bool(); __CPROVER_input("alive2",alive2);
  
  id3 = nondet_char(); __CPROVER_input("id3",id3);
  st3 = nondet_char(); __CPROVER_input("st3",st3);
  send3 = nondet_char(); __CPROVER_input("send3",send3);
  mode3 = nondet_bool(); __CPROVER_input("mode3",mode3);
  alive3 = nondet_bool(); __CPROVER_input("alive3",alive3);
  
  
  
  i2 = init();
  
  p1_old = nomsg;
  p1_new = nomsg;
  p2_old = nomsg;
  p2_new = nomsg;
  p3_old = nomsg;
  p3_new = nomsg;
  i2 = 0;
printf("POINT: 149\n");

  while (i2 < 2) {
printf("POINT: 150\n");
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
