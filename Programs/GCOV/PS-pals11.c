//This program is pals_STARTPALS_ActiveStandby_true-unreach-call.ufo.UNBOUNDED.pals.c







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

typedef signed char int8_t;
typedef int8_t msg_t;
typedef int port_t;
extern void read(port_t p , msg_t m ) ;
extern void write(port_t p , msg_t m ) ;
msg_t nomsg  =    (msg_t )-1;
port_t cs1  ;
int8_t cs1_old ;
int8_t cs1_new ;
port_t cs2  ;
int8_t cs2_old ;
int8_t cs2_new ;
port_t s1s2  ;
int8_t s1s2_old ;
int8_t s1s2_new ;
port_t s1s1  ;
int8_t s1s1_old ;
int8_t s1s1_new ;
port_t s2s1  ;
int8_t s2s1_old ;
int8_t s2s1_new ;
port_t s2s2  ;
int8_t s2s2_old ;
int8_t s2s2_new ;
port_t s1p  ;
int8_t s1p_old ;
int8_t s1p_new ;
port_t s2p  ;
int8_t s2p_old ;
int8_t s2p_new ;

bool side1Failed  ;
bool side2Failed  ;
msg_t side1_written  ;
msg_t side2_written  ;


static bool side1Failed_History_0  ;
static bool side1Failed_History_1  ;
static bool side1Failed_History_2  ;
static bool side2Failed_History_0  ;
static bool side2Failed_History_1  ;
static bool side2Failed_History_2  ;
static int8_t active_side_History_0  ;
static int8_t active_side_History_1  ;
static int8_t active_side_History_2  ;
static msg_t manual_selection_History_0  ;
static msg_t manual_selection_History_1  ;
static msg_t manual_selection_History_2  ;
void write_side1_failed_history(bool val ) 
{ 


  {
  side1Failed_History_2 = side1Failed_History_1;
  side1Failed_History_1 = side1Failed_History_0;
  side1Failed_History_0 = val;
  return;
}
}
bool read_side1_failed_history(unsigned char index ) 
{ 


  {
printf("POINT: 1\n");

  if ((int )index == 0) {
printf("POINT: 2\n");
    return (side1Failed_History_0);
printf("POINT: 3\n");

  } else if ((int )index == 1) {
printf("POINT: 4\n");
    return (side1Failed_History_1);
printf("POINT: 5\n");

  } else if ((int )index == 2) {
printf("POINT: 6\n");
    return (side1Failed_History_2);
  } else {
printf("POINT: 8\n");
    return ((bool)0);
  }
}
}
void write_side2_failed_history(bool val ) 
{ 


  {
  side2Failed_History_2 = side2Failed_History_1;
  side2Failed_History_1 = side2Failed_History_0;
  side2Failed_History_0 = val;
  return;
}
}
bool read_side2_failed_history(unsigned char index ) 
{ 


  {
printf("POINT: 9\n");

  if ((int )index == 0) {
printf("POINT: 10\n");
    return (side2Failed_History_0);
printf("POINT: 11\n");

  } else if ((int )index == 1) {
printf("POINT: 12\n");
    return (side2Failed_History_1);
printf("POINT: 13\n");

  } else if ((int )index == 2) {
printf("POINT: 14\n");
    return (side2Failed_History_2);
  } else {
printf("POINT: 16\n");
    return ((bool)0);
  }
}
}
void write_active_side_history(int8_t val ) 
{ 


  {
  active_side_History_2 = active_side_History_1;
  active_side_History_1 = active_side_History_0;
  active_side_History_0 = val;
  return;
}
}
int8_t read_active_side_history(unsigned char index ) 
{ 


  {
printf("POINT: 17\n");

  if ((int )index == 0) {
printf("POINT: 18\n");
    return (active_side_History_0);
printf("POINT: 19\n");

  } else if ((int )index == 1) {
printf("POINT: 20\n");
    return (active_side_History_1);
printf("POINT: 21\n");

  } else if ((int )index == 2) {
printf("POINT: 22\n");
    return (active_side_History_2);
  } else {
printf("POINT: 24\n");
    return ((int8_t )-2);
  }
}
}
void write_manual_selection_history(msg_t val ) 
{ 


  {
  manual_selection_History_2 = manual_selection_History_1;
  manual_selection_History_1 = manual_selection_History_0;
  manual_selection_History_0 = val;
  return;
}
}
msg_t read_manual_selection_history(unsigned char index ) 
{ 


  {
printf("POINT: 25\n");

  if ((int )index == 0) {
printf("POINT: 26\n");
    return (manual_selection_History_0);
printf("POINT: 27\n");

  } else if ((int )index == 1) {
printf("POINT: 28\n");
    return (manual_selection_History_1);
printf("POINT: 29\n");

  } else if ((int )index == 2) {
printf("POINT: 30\n");
    return (manual_selection_History_2);
  } else {
printf("POINT: 32\n");
    return ((msg_t )0);
  }
}
}
int init(void) 
{ 


  {
printf("POINT: 33\n");

  if ((int )side1Failed_History_0 != 0) {
printf("POINT: 34\n");
    return (0);
  }
printf("POINT: 35\n");

  if ((int )side2Failed_History_0 != 0) {
printf("POINT: 36\n");
    return (0);
  }
printf("POINT: 37\n");

  if ((int )active_side_History_0 != -2) {
printf("POINT: 38\n");
    return (0);
  }
printf("POINT: 39\n");

  if ((int )manual_selection_History_0 != 0) {
printf("POINT: 40\n");
    return (0);
  }
printf("POINT: 41\n");

  if ((int )side1Failed_History_1 != 0) {
printf("POINT: 42\n");
    return (0);
  }
printf("POINT: 43\n");

  if ((int )side2Failed_History_1 != 0) {
printf("POINT: 44\n");
    return (0);
  }
printf("POINT: 45\n");

  if ((int )active_side_History_1 != -2) {
printf("POINT: 46\n");
    return (0);
  }
printf("POINT: 47\n");

  if ((int )manual_selection_History_1 != 0) {
printf("POINT: 48\n");
    return (0);
  }
printf("POINT: 49\n");

  if ((int )side1Failed_History_2 != 0) {
printf("POINT: 50\n");
    return (0);
  }
printf("POINT: 51\n");

  if ((int )side2Failed_History_2 != 0) {
printf("POINT: 52\n");
    return (0);
  }
printf("POINT: 53\n");

  if ((int )active_side_History_2 != -2) {
printf("POINT: 54\n");
    return (0);
  }
printf("POINT: 55\n");

  if ((int )manual_selection_History_2 != 0) {
printf("POINT: 56\n");
    return (0);
  }
  return (1);
}
}
int8_t flip_the_side(int8_t side ) 
{ 
  int tmp ;

  {
printf("POINT: 57\n");

  if ((int )side == 1) {
printf("POINT: 58\n");
    tmp = 0;
  } else {
printf("POINT: 60\n");
    tmp = 1;
  }
  return ((int8_t )tmp);
}
}
void Console_task_each_pals_period(void) 
{ 
  msg_t manual_selection ;
  char tmpc ;

  {
  scanf("%c", &tmpc);
  manual_selection = tmpc;
  write_manual_selection_history(manual_selection);
printf("POINT: 61\n");

  if ((manual_selection != nomsg) && (cs1_new == nomsg)){
printf("POINT: 62\n");
    cs1_new = manual_selection;
    }
    else{
    cs1_new = cs1_new;
    }
printf("POINT: 63\n");

  if ((manual_selection != nomsg) && (cs2_new == nomsg)){
printf("POINT: 64\n");
    cs2_new = manual_selection;
    }
    else{
    cs2_new = cs2_new;
    }
  
  
  manual_selection = (msg_t )0;
  return;
}
}
void Side1_activestandby_task_each_pals_period(void) 
{ 
  int8_t side1 ;
  int8_t side2 ;
  msg_t manual_selection ;
  int8_t next_state ;

  {
  side1 = nomsg;
  side2 = nomsg;
  manual_selection = (msg_t )0;
  scanf("%", &side1Failed);
  write_side1_failed_history(side1Failed);
printf("POINT: 65\n");

  if (side1Failed) {
printf("POINT: 66\n");
    
    
printf("POINT: 67\n");

    if ((nomsg != nomsg) && (s1s1_new == nomsg)){
printf("POINT: 68\n");
    s1s1_new = nomsg;
    }
    else{
    s1s1_new = s1s1_new;
    }
    
printf("POINT: 69\n");

    if ((nomsg != nomsg) && (s1s2_new == nomsg)){
printf("POINT: 70\n");
    s1s2_new = nomsg;
    }
    else{
    s1s2_new = s1s2_new;
    }
    
printf("POINT: 71\n");

    if ((nomsg != nomsg) && (s1p_new == nomsg)){
printf("POINT: 72\n");
    s1p_new = nomsg;
    }
    else{
    s1p_new = s1p_new;
    }
    
    
    
    
    
    
    
    
    
    
    side1_written = nomsg;
    return;
  }
  side1 = s1s1_old;
  s1s1_old = nomsg;
  side2 = s2s1_old;
  s2s1_old = nomsg;
  manual_selection = cs1_old;
  cs1_old = nomsg;
printf("POINT: 73\n");

  if ((int )side1 == (int )side2) {
printf("POINT: 74\n");
    next_state = (int8_t )1;
printf("POINT: 75\n");

  } else if ((int )side1 == (int )nomsg) {
printf("POINT: 76\n");
printf("POINT: 77\n");

    if ((int )side2 != (int )nomsg) {
printf("POINT: 78\n");
      next_state = (int8_t )0;
    } else {
printf("POINT: 80\n");
      goto _L___0;
    }
  } else
  _L___0: /* CIL Label */ 
printf("POINT: 81\n");

  if ((int )side1 != (int )nomsg) {
printf("POINT: 82\n");
printf("POINT: 83\n");

    if ((int )side2 == (int )nomsg) {
printf("POINT: 84\n");
      next_state = (int8_t )1;
    } else {
printf("POINT: 86\n");
      goto _L;
    }
  } else
  _L: /* CIL Label */ 
printf("POINT: 87\n");

  if ((int )manual_selection == 1) {
printf("POINT: 88\n");
    next_state = flip_the_side(side1);
  } else {
printf("POINT: 90\n");
    next_state = side1;
  }
printf("POINT: 91\n");

 if ((next_state != nomsg) && (s1s1_new == nomsg)){
printf("POINT: 92\n");
    s1s1_new = next_state;
    }
    else{
    s1s1_new = s1s1_new;
    }
    
printf("POINT: 93\n");

    if ((next_state != nomsg) && (s1s2_new == nomsg)){
printf("POINT: 94\n");
    s1s2_new = next_state;
    }
    else{
    s1s2_new = s1s2_new;
    }
    
printf("POINT: 95\n");

    if ((next_state != nomsg) && (s1p_new == nomsg)){
printf("POINT: 96\n");
    s1p_new = next_state;
    }
    else{
    s1p_new = s1p_new;
    }
  
  
  side1_written = next_state;
  return;
}
}
void Side2_activestandby_task_each_pals_period(void) 
{ 
  int8_t side1 ;
  int8_t side2 ;
  msg_t manual_selection ;
  int8_t next_state ;

  {
  side1 = nomsg;
  side2 = nomsg;
  manual_selection = (msg_t )0;
  scanf("%", &side2Failed);
  write_side2_failed_history(side2Failed);
printf("POINT: 97\n");

  if (side2Failed) {
printf("POINT: 98\n");
    
printf("POINT: 99\n");

    if ((nomsg != nomsg) && (s2s1_new == nomsg)){
printf("POINT: 100\n");
    s2s1_new = nomsg;
    }
    else{
    s2s1_new = s2s1_new;
    }
    
printf("POINT: 101\n");

    if ((nomsg != nomsg) && (s2s2_new == nomsg)){
printf("POINT: 102\n");
    s2s2_new = nomsg;
    }
    else{
    s2s2_new = s2s2_new;
    }
    
printf("POINT: 103\n");

    if ((nomsg != nomsg) && (s2p_new == nomsg)){
printf("POINT: 104\n");
    s2p_new = nomsg;
    }
    else{
    s2p_new = s2p_new;
    }
    
    side2_written = nomsg;
    return;
  }
  side1 = s1s2_old;
  s1s2_old = nomsg;
  side2 = s2s2_old;
  s2s2_old = nomsg;
  manual_selection = cs2_old;
  cs2_old = nomsg;
printf("POINT: 105\n");

  if ((int )side1 == (int )side2) {
printf("POINT: 106\n");
    next_state = (int8_t )0;
printf("POINT: 107\n");

  } else if ((int )side2 == (int )nomsg) {
printf("POINT: 108\n");
printf("POINT: 109\n");

    if ((int )side1 != (int )nomsg) {
printf("POINT: 110\n");
      next_state = (int8_t )0;
    } else {
printf("POINT: 112\n");
      goto _L___0;
    }
  } else
  _L___0: /* CIL Label */ 
printf("POINT: 113\n");

  if ((int )side2 != (int )nomsg) {
printf("POINT: 114\n");
printf("POINT: 115\n");

    if ((int )side1 == (int )nomsg) {
printf("POINT: 116\n");
      next_state = (int8_t )1;
    } else {
printf("POINT: 118\n");
      goto _L;
    }
  } else
  _L: /* CIL Label */ 
printf("POINT: 119\n");

  if ((int )manual_selection == 1) {
printf("POINT: 120\n");
    next_state = flip_the_side(side2);
  } else {
printf("POINT: 122\n");
    next_state = side2;
  }
printf("POINT: 123\n");

  if ((next_state != nomsg) && (s2s1_new == nomsg)){
printf("POINT: 124\n");
    s2s1_new = next_state;
    }
    else{
    s2s1_new = s2s1_new;
    }
    
printf("POINT: 125\n");

    if ((next_state != nomsg) && (s2s2_new == nomsg)){
printf("POINT: 126\n");
    s2s2_new = next_state;
    }
    else{
    s2s2_new = s2s2_new;
    }
    
printf("POINT: 127\n");

    if ((next_state != nomsg) && (s2p_new == nomsg)){
printf("POINT: 128\n");
    s2p_new = next_state;
    }
    else{
    s2p_new = s2p_new;
    }
  
  
  side2_written = next_state;
  return;
}
}
void Pendulum_prism_task_each_pals_period(void) 
{ 
  int8_t active_side ;
  int8_t tmp ;
  int8_t side1 ;
  int8_t side2 ;

  {
  tmp = read_active_side_history((unsigned char)0);
  active_side = tmp;
  side1 = nomsg;
  side2 = nomsg;
  side1 = s1p_old;
  s1p_old = nomsg;
  side2 = s2p_old;
  s2p_old = nomsg;
printf("POINT: 129\n");

  if ((int )side1 == 1) {
printf("POINT: 130\n");
    active_side = (int8_t )1;
printf("POINT: 131\n");

  } else if ((int )side2 == 1) {
printf("POINT: 132\n");
    active_side = (int8_t )2;
printf("POINT: 133\n");

  } else if ((int )side1 == 0) {
printf("POINT: 134\n");
printf("POINT: 135\n");

    if ((int )side2 == (int )nomsg) {
printf("POINT: 136\n");
      active_side = (int8_t )1;
    } else {
printf("POINT: 138\n");
      goto _L;
    }
  } else
  _L: /* CIL Label */ 
printf("POINT: 139\n");

  if ((int )side1 == (int )nomsg) {
printf("POINT: 140\n");
printf("POINT: 141\n");

    if ((int )side2 == 0) {
printf("POINT: 142\n");
      active_side = (int8_t )2;
    } else {
printf("POINT: 144\n");
      active_side = (int8_t )0;
    }
  } else {
printf("POINT: 146\n");
    active_side = (int8_t )0;
  }
  write_active_side_history(active_side);
  return;
}
}
void (*nodes[4])(void)  = {      & Console_task_each_pals_period,      & Side1_activestandby_task_each_pals_period,      & Side2_activestandby_task_each_pals_period,      & Pendulum_prism_task_each_pals_period};
int check(void) 
{ 
  int tmp ;
  msg_t tmp___0 ;
  bool tmp___1 ;
  bool tmp___2 ;
  bool tmp___3 ;
  bool tmp___4 ;
  int8_t tmp___5 ;
  bool tmp___6 ;
  bool tmp___7 ;
  bool tmp___8 ;
  int8_t tmp___9 ;
  bool tmp___10 ;
  bool tmp___11 ;
  bool tmp___12 ;
  msg_t tmp___13 ;
  bool tmp___14 ;
  bool tmp___15 ;
  bool tmp___16 ;
  bool tmp___17 ;
  int8_t tmp___18 ;
  int8_t tmp___19 ;
  int8_t tmp___20 ;

  {
printf("POINT: 147\n");

  if (! side1Failed) {
printf("POINT: 148\n");
    tmp = 1;
  } else
printf("POINT: 149\n");

  if (! side2Failed) {
printf("POINT: 150\n");
    tmp = 1;
  } else {
printf("POINT: 152\n");
    tmp = 0;
  }

  tmp___0 = read_manual_selection_history((unsigned char)1);
printf("POINT: 153\n");

  if (! tmp___0) {
printf("POINT: 154\n");
    tmp___1 = read_side1_failed_history((unsigned char)1);
printf("POINT: 155\n");

    if (! tmp___1) {
printf("POINT: 156\n");
      tmp___2 = read_side1_failed_history((unsigned char)0);
printf("POINT: 157\n");

      if (! tmp___2) {
printf("POINT: 158\n");
        tmp___3 = read_side2_failed_history((unsigned char)1);
printf("POINT: 159\n");

        if (! tmp___3) {
printf("POINT: 160\n");
          tmp___4 = read_side2_failed_history((unsigned char)0);
printf("POINT: 161\n");

          if (! tmp___4) {
printf("POINT: 162\n");
printf("POINT: 163\n");

            if (! ((int )side1_written == 1)) {
printf("POINT: 164\n");
printf("POINT: 165\n");

              if (! ((int )side1_written == 0)) {
printf("POINT: 166\n");
                return (0);
              }
            }
printf("POINT: 167\n");

            if (! (! ((int )side1_written == 0))) {
printf("POINT: 168\n");
printf("POINT: 169\n");

              if (! ((int )side2_written == 1)) {
printf("POINT: 170\n");
                return (0);
              }
            }
printf("POINT: 171\n");

            if (! (! ((int )side1_written == 1))) {
printf("POINT: 172\n");
printf("POINT: 173\n");

              if (! ((int )side2_written == 0)) {
printf("POINT: 174\n");
                return (0);
              }
            }
          }
        }
      }
    }
  }
  tmp___7 = read_side1_failed_history((unsigned char)1);
printf("POINT: 175\n");

  if (tmp___7) {
printf("POINT: 176\n");
    tmp___8 = read_side2_failed_history((unsigned char)1);
printf("POINT: 177\n");

    if (! tmp___8) {
printf("POINT: 178\n");
      tmp___5 = read_active_side_history((unsigned char)0);
printf("POINT: 179\n");

      if (! ((int )tmp___5 == 2)) {
printf("POINT: 180\n");
        return (0);
      }
      tmp___6 = read_side2_failed_history((unsigned char)0);
printf("POINT: 181\n");

      if (! tmp___6) {
printf("POINT: 182\n");
printf("POINT: 183\n");

        if (! ((int )side2_written == 1)) {
printf("POINT: 184\n");
          return (0);
        }
      }
    }
  }
  tmp___11 = read_side1_failed_history((unsigned char)1);
printf("POINT: 185\n");

  if (! tmp___11) {
printf("POINT: 186\n");
    tmp___12 = read_side2_failed_history((unsigned char)1);
printf("POINT: 187\n");

    if (tmp___12) {
printf("POINT: 188\n");
      tmp___9 = read_active_side_history((unsigned char)0);
printf("POINT: 189\n");

      if (! ((int )tmp___9 == 1)) {
printf("POINT: 190\n");
        return (0);
      }
      tmp___10 = read_side1_failed_history((unsigned char)0);
printf("POINT: 191\n");

      if (! tmp___10) {
printf("POINT: 192\n");
printf("POINT: 193\n");

        if (! ((int )side1_written == 1)) {
printf("POINT: 194\n");
          return (0);
        }
      }
    }
  }
  tmp___20 = read_active_side_history((unsigned char)2);
printf("POINT: 195\n");

  if ((int )tmp___20 > -2) {
printf("POINT: 196\n");
    tmp___13 = read_manual_selection_history((unsigned char)2);
printf("POINT: 197\n");

    if (! tmp___13) {
printf("POINT: 198\n");
      tmp___14 = read_side1_failed_history((unsigned char)2);
      tmp___15 = read_side1_failed_history((unsigned char)1);
printf("POINT: 199\n");

      if ((int )tmp___14 == (int )tmp___15) {
printf("POINT: 200\n");
        tmp___16 = read_side2_failed_history((unsigned char)2);
        tmp___17 = read_side2_failed_history((unsigned char)1);
printf("POINT: 201\n");

        if ((int )tmp___16 == (int )tmp___17) {
printf("POINT: 202\n");
          tmp___18 = read_active_side_history((unsigned char)1);
          tmp___19 = read_active_side_history((unsigned char)0);
printf("POINT: 203\n");

          if (! ((int )tmp___18 == (int )tmp___19)) {
printf("POINT: 204\n");
            return (0);
          }
        }
      }
    }
  }
  return (1);
}
}


int main(void) 
{ 
  int c1 ;
  int i2 ;
  kappa = 0;
  {
  c1 = 0;

  
  scanf("%", &side1Failed);
  scanf("%", &side2Failed);
    
  scanf("%c", &side1_written);
  scanf("%c", &side2_written);
  
  scanf("%", &side1Failed_History_0);
  scanf("%", &side1Failed_History_1);
  scanf("%", &side1Failed_History_2);
  
  scanf("%", &side2Failed_History_0);
  scanf("%", &side2Failed_History_1);
  scanf("%", &side2Failed_History_2);
  
  
  scanf("%c", &active_side_History_0);
  scanf("%c", &active_side_History_1);
  scanf("%c", &active_side_History_2);
  
  scanf("%c", &manual_selection_History_0);
  scanf("%c", &manual_selection_History_1);
  scanf("%c", &manual_selection_History_2);
  
  
  i2 = init();

  cs1_old = nomsg;
  cs1_new = nomsg;
  cs2_old = nomsg;
  cs2_new = nomsg;
  s1s2_old = nomsg;
  s1s2_new = nomsg;
  s1s1_old = nomsg;
  s1s1_new = nomsg;
  s2s1_old = nomsg;
  s2s1_new = nomsg;
  s2s2_old = nomsg;
  s2s2_new = nomsg;
  s1p_old = nomsg;
  s1p_new = nomsg;
  s2p_old = nomsg;
  s2p_new = nomsg;
  i2 = 0;
printf("POINT: 205\n");

  while (i2 < 3) {
printf("POINT: 206\n");
    {
    Console_task_each_pals_period();
    Side1_activestandby_task_each_pals_period();
    Side2_activestandby_task_each_pals_period();
    Pendulum_prism_task_each_pals_period();
    cs1_old = cs1_new;
    cs1_new = nomsg;
    cs2_old = cs2_new;
    cs2_new = nomsg;
    s1s2_old = s1s2_new;
    s1s2_new = nomsg;
    s1s1_old = s1s1_new;
    s1s1_new = nomsg;
    s2s1_old = s2s1_new;
    s2s1_new = nomsg;
    s2s2_old = s2s2_new;
    s2s2_new = nomsg;
    s1p_old = s1p_new;
    s1p_new = nomsg;
    s2p_old = s2p_new;
    s2p_new = nomsg;
    c1 = check();
    i2++;
    }
  }
}

return 0;
}
