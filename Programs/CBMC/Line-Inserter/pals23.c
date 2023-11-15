//This program is pals_lcr-var-start-time.3_true-unreach-call.ufo.UNBOUNDED.pals.c






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
  if (mode1) {
    if (r1 == 255) {
      r1 = 2;
    }
    r1 = r1 + 1;
    m1 = p3_old;
    p3_old = nomsg;
    if ((int )m1 != (int )nomsg) {
      if (alive1) {
        if ((int )m1 > (int )id1) {
          send1 = m1;
        } else
        if ((int )m1 == (int )id1) {
          st1 = (char)1;
        }
      } else {
        send1 = m1;
      }
    }
    mode1 = (bool)0;
  } else {
    if (alive1) {
      
    if ((send1 != nomsg) && (p1_new == nomsg)){
    p1_new = send1;
    }
    else{
    p1_new = p1_new;
    }
      
      
    } else
    {
    if ((int )send1 != (int )id1) {
      
    if ((send1 != nomsg) && (p1_new == nomsg)){
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
  if (mode2) {
    m2 = p1_old;
    p1_old = nomsg;
    if ((int )m2 != (int )nomsg) {
      if (alive2) {
        if ((int )m2 > (int )id2) {
          send2 = m2;
        } else if ((int )m2 == (int )id2) {
          st2 = (char)1;
        }
      } else {
        send2 = m2;
      }
    }
    mode2 = (bool)0;
  } else {
    if (alive2) {
   
   if ((send2 != nomsg) && (p2_new == nomsg)){
    p2_new = send2;
    }
    else{
    p2_new = p2_new;
    }   
    } else{
    if ((int )send2 != (int )id2) {
    
    if ((send2 != nomsg) && (p2_new == nomsg)){
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
  if (mode3) {
    m3 = p2_old;
    p2_old = nomsg;
    if ((int )m3 != (int )nomsg) {
      if (alive3) {
        if ((int )m3 > (int )id3) {
          send3 = m3;
        } else
        if ((int )m3 == (int )id3) {
          st3 = (char)1;
        }
      } else {
        send3 = m3;
      }
    }
    mode3 = (bool)0;
  } else {
    if (alive3) {
          
    if ((send3 != nomsg) && (p3_new == nomsg)){
    p3_new = send3;
    }
    else{
    p3_new = p3_new;
    }
      
      
    } else{
    if ((int )send3 != (int )id3) {
    
    if ((send3 != nomsg) && (p3_new == nomsg)){
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
  if ((int )r1 == 0) {
    if (((int )alive1 + (int )alive2) + (int )alive3 >= 1) {
      if ((int )id1 >= 0) {
        if ((int )st1 == 0) {
          if ((int )send1 == (int )id1) {
            if ((int )mode1 == 0) {
              if ((int )id2 >= 0) {
                if ((int )st2 == 0) {
                  if ((int )send2 == (int )id2) {
                    if ((int )mode2 == 0) {
                      if ((int )id3 >= 0) {
                        if ((int )st3 == 0) {
                          if ((int )send3 == (int )id3) {
                            if ((int )mode3 == 0) {
                              if ((int )id1 != (int )id2) {
                                if ((int )id1 != (int )id3) {
                                  if ((int )id2 != (int )id3) {
                                    tmp = 1;
                                  } else {
                                    tmp = 0;
                                  }
                                } else {
                                  tmp = 0;
                                }
                              } else {
                                tmp = 0;
                              }
                            } else {
                              tmp = 0;
                            }
                          } else {
                            tmp = 0;
                          }
                        } else {
                          tmp = 0;
                        }
                      } else {
                        tmp = 0;
                      }
                    } else {
                      tmp = 0;
                    }
                  } else {
                    tmp = 0;
                  }
                } else {
                  tmp = 0;
                }
              } else {
                tmp = 0;
              }
            } else {
              tmp = 0;
            }
          } else {
            tmp = 0;
          }
        } else {
          tmp = 0;
        }
      } else {
        tmp = 0;
      }
    } else {
      tmp = 0;
    }
  } else {
    tmp = 0;
  }
  return (tmp);
}
}
int check(void) 
{ 
  int tmp ;

  {
  if (((int )st1 + (int )st2) + (int )st3 <= 1) {
    if ((int )r1 < 3) {
      tmp = 1;
    } else if (((int )st1 + (int )st2) + (int )st3 == 1) {
      tmp = 1;
    } else {
      tmp = 0;
    }
  } else {
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
  scanf("%c", &r1);
  
  
  scanf("%c", &id1);
  scanf("%c", &st1);
  scanf("%c", &send1);
  scanf("%", &mode1);
  scanf("%", &alive1);

  scanf("%c", &id2);
  scanf("%c", &st2);
  scanf("%c", &send2);
  scanf("%", &mode2);
  scanf("%", &alive2);
  
  scanf("%c", &id3);
  scanf("%c", &st3);
  scanf("%c", &send3);
  scanf("%", &mode3);
  scanf("%", &alive3);
    i2 = init();
  

  p1_old = nomsg;
  p1_new = nomsg;
  p2_old = nomsg;
  p2_new = nomsg;
  p3_old = nomsg;
  p3_new = nomsg;
  i2 = 0;
  while (i2 < 2) {
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
