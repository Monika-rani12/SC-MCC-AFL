//This program is pals_STARTPALS_Triplicated_false-unreach-call.2.ufo.UNBOUNDED.pals.c







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
port_t g1v  ;
int8_t g1v_old ;
int8_t g1v_new ;
port_t g2v  ;
int8_t g2v_old ;
int8_t g2v_new ;
port_t g3v  ;
int8_t g3v_old ;
int8_t g3v_new ;

bool gate1Failed  ;
bool gate2Failed  ;
bool gate3Failed  ;
msg_t VALUE1  ;
msg_t VALUE2  ;
msg_t VALUE3  ;

bool gate1Failed_History_0  ;
bool gate1Failed_History_1  ;
bool gate1Failed_History_2  ;
bool gate2Failed_History_0  ;
bool gate2Failed_History_1  ;
bool gate2Failed_History_2  ;
bool gate3Failed_History_0  ;
bool gate3Failed_History_1  ;
bool gate3Failed_History_2  ;
int8_t votedValue_History_0  ;
int8_t votedValue_History_1  ;
int8_t votedValue_History_2  ;
bool read_historybool(int history_id , int historyIndex ) ;
int8_t read_history_int8(int history_id , int historyIndex ) ;
int add_history_type(int history_id ) 
{ 
  bool inibool ;
  int8_t ini_int ;
  int var ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;

  {
  inibool = (bool)0;
  ini_int = (int8_t )-2;
  var = 0;
printf("POINT: 1\n");

  while (var < 3) {
printf("POINT: 2\n");
printf("POINT: 3\n");

    if (history_id == 0) {
printf("POINT: 4\n");
      tmp = (int )read_historybool(0, 0);
printf("POINT: 5\n");

      if (! (tmp == (int )inibool)) {
printf("POINT: 6\n");
        return (0);
      }
printf("POINT: 7\n");

    } else if (history_id == 1) {
printf("POINT: 8\n");
      tmp___0 = (int )read_historybool(1, 0);
printf("POINT: 9\n");

      if (! (tmp___0 == (int )inibool)) {
printf("POINT: 10\n");
        return (0);
      }
printf("POINT: 11\n");

    } else if (history_id == 2) {
printf("POINT: 12\n");
      tmp___1 = (int )read_historybool(2, 0);
printf("POINT: 13\n");

      if (! (tmp___1 == (int )inibool)) {
printf("POINT: 14\n");
        return (0);
      }
printf("POINT: 15\n");

    } else if (history_id == 3) {
printf("POINT: 16\n");
      tmp___2 = (int )read_history_int8(3, 0);
printf("POINT: 17\n");

      if (! (tmp___2 == (int )ini_int)) {
printf("POINT: 18\n");
        return (0);
      }
    }
    var ++;
  }
  return (1);
}
}
int8_t read_history_int8(int history_id , int historyIndex ) 
{ 


  {
printf("POINT: 19\n");

  if (history_id == 3) {
printf("POINT: 20\n");
printf("POINT: 21\n");

    if (historyIndex == 0) {
printf("POINT: 22\n");
      return (votedValue_History_0);
printf("POINT: 23\n");

    } else if (historyIndex == 1) {
printf("POINT: 24\n");
      return (votedValue_History_1);
    } else {
printf("POINT: 26\n");
      return (votedValue_History_2);
    }
  } else {
printf("POINT: 28\n");
  }
  return ((int8_t )-2);
}
}
bool read_historybool(int history_id , int historyIndex ) 
{ 


  {
printf("POINT: 29\n");

  if (history_id == 0) {
printf("POINT: 30\n");
printf("POINT: 31\n");

    if (historyIndex == 0) {
printf("POINT: 32\n");
      return (gate1Failed_History_0);
printf("POINT: 33\n");

    } else if (historyIndex == 1) {
printf("POINT: 34\n");
      return (gate1Failed_History_1);
    } else {
printf("POINT: 36\n");
      return (gate1Failed_History_2);
    }
  } else
printf("POINT: 37\n");

  if (history_id == 1) {
printf("POINT: 38\n");
printf("POINT: 39\n");

    if (historyIndex == 0) {
printf("POINT: 40\n");
      return (gate2Failed_History_0);
printf("POINT: 41\n");

    } else if (historyIndex == 1) {
printf("POINT: 42\n");
      return (gate2Failed_History_1);
    } else {
printf("POINT: 44\n");
      return (gate2Failed_History_2);
    }
  } else
printf("POINT: 45\n");

  if (history_id == 2) {
printf("POINT: 46\n");
printf("POINT: 47\n");

    if (historyIndex == 0) {
printf("POINT: 48\n");
      return (gate3Failed_History_0);
printf("POINT: 49\n");

    } else if (historyIndex == 1) {
printf("POINT: 50\n");
      return (gate3Failed_History_1);
    } else {
printf("POINT: 52\n");
      return (gate3Failed_History_2);
    }
  } else {
printf("POINT: 54\n");
  }
  return ((bool)0);
}
}
void write_history_int8(int history_id , int8_t buf ) 
{ 


  {
printf("POINT: 55\n");

  if (history_id == 3) {
printf("POINT: 56\n");
    votedValue_History_2 = votedValue_History_1;
    votedValue_History_1 = votedValue_History_0;
    votedValue_History_0 = buf;
  } else {
printf("POINT: 58\n");
  }
  return;
}
}
void write_historybool(int history_id , bool buf ) 
{ 


  {
printf("POINT: 59\n");

  if (history_id == 0) {
printf("POINT: 60\n");
    gate1Failed_History_2 = gate1Failed_History_1;
    gate1Failed_History_1 = gate1Failed_History_0;
    gate1Failed_History_0 = buf;
printf("POINT: 61\n");

  } else if (history_id == 1) {
printf("POINT: 62\n");
    gate2Failed_History_2 = gate2Failed_History_1;
    gate2Failed_History_1 = gate2Failed_History_0;
    gate2Failed_History_0 = buf;
printf("POINT: 63\n");

  } else if (history_id == 2) {
printf("POINT: 64\n");
    gate3Failed_History_2 = gate3Failed_History_1;
    gate3Failed_History_1 = gate3Failed_History_0;
    gate3Failed_History_0 = buf;
  } else {
printf("POINT: 66\n");
  }
  return;
}
}
int init(void) 
{ 
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;

  {
  tmp = add_history_type(0);
printf("POINT: 67\n");

  if (! tmp) {
printf("POINT: 68\n");
    return (0);
  }
  tmp___0 = add_history_type(1);
printf("POINT: 69\n");

  if (! tmp___0) {
printf("POINT: 70\n");
    return (0);
  }
  tmp___1 = add_history_type(2);
printf("POINT: 71\n");

  if (! tmp___1) {
printf("POINT: 72\n");
    return (0);
  }
  tmp___2 = add_history_type(3);
printf("POINT: 73\n");

  if (! tmp___2) {
printf("POINT: 74\n");
    return (0);
  }
  return (1);
}
}
int check(void) 
{ 
  int tmp ;
  int temp_count ;
  int8_t tmp___0 ;
  int8_t tmp___1 ;
  int8_t tmp___2 ;
  bool tmp___3 ;
  bool tmp___4 ;
  bool tmp___5 ;
  int8_t tmp___6 ;
  bool tmp___7 ;
  bool tmp___8 ;
  bool tmp___9 ;
  int8_t tmp___10 ;
  int8_t tmp___11 ;
  int8_t tmp___12 ;
  int8_t tmp___13 ;
  int8_t tmp___14 ;

  {
printf("POINT: 75\n");

  if (! gate1Failed) {
printf("POINT: 76\n");
    tmp = 1;
printf("POINT: 77\n");

  } else if (! gate2Failed) {
printf("POINT: 78\n");
    tmp = 1;
printf("POINT: 79\n");

  } else if (! gate3Failed) {
printf("POINT: 80\n");
    tmp = 1;
  } else {
printf("POINT: 82\n");
    tmp = 0;
  }

  tmp___3 = read_historybool(0, 1);
printf("POINT: 83\n");

  if (! tmp___3) {
printf("POINT: 84\n");
    tmp___4 = read_historybool(1, 1);
printf("POINT: 85\n");

    if (! tmp___4) {
printf("POINT: 86\n");
      tmp___5 = read_historybool(2, 1);
printf("POINT: 87\n");

      if (! tmp___5) {
printf("POINT: 88\n");
        temp_count = 0;
        tmp___0 = read_history_int8(3, 0);
printf("POINT: 89\n");

        if ((int )VALUE1 == (int )tmp___0) {
printf("POINT: 90\n");
          temp_count ++;
        }
        tmp___1 = read_history_int8(3, 0);
printf("POINT: 91\n");

        if ((int )VALUE2 == (int )tmp___1) {
printf("POINT: 92\n");
          temp_count ++;
        }
        tmp___2 = read_history_int8(3, 0);
printf("POINT: 93\n");

        if ((int )VALUE3 == (int )tmp___2) {
printf("POINT: 94\n");
          temp_count ++;
        }
printf("POINT: 95\n");

        if ((int )VALUE1 != (int )VALUE2) {
printf("POINT: 96\n");
printf("POINT: 97\n");

          if ((int )VALUE1 != (int )VALUE3) {
printf("POINT: 98\n");
printf("POINT: 99\n");

            if ((int )VALUE2 != (int )VALUE3) {
printf("POINT: 100\n");
printf("POINT: 101\n");

              if (! (temp_count == 1)) {
printf("POINT: 102\n");
                return (0);
              }
            } else {
printf("POINT: 104\n");
              goto _L___0;
            }
          } else {
printf("POINT: 106\n");
            goto _L___0;
          }
        } else
        _L___0: /* CIL Label */ 
printf("POINT: 107\n");

        if (! (temp_count > 1)) {
printf("POINT: 108\n");
          return (0);
        }
      }
    }
  }
  tmp___10 = read_history_int8(3, 1);
printf("POINT: 109\n");

  if ((int )tmp___10 > -2) {
printf("POINT: 110\n");
    tmp___6 = read_history_int8(3, 0);
printf("POINT: 111\n");

    if ((int )tmp___6 == (int )nomsg) {
printf("POINT: 112\n");
      tmp___7 = read_historybool(0, 1);
printf("POINT: 113\n");

      if (tmp___7) {
printf("POINT: 114\n");
        tmp___8 = read_historybool(1, 1);
printf("POINT: 115\n");

        if (tmp___8) {
printf("POINT: 116\n");
          tmp___9 = read_historybool(2, 1);
printf("POINT: 117\n");

          if (! tmp___9) {
printf("POINT: 118\n");
            return (0);
          }
        } else {
printf("POINT: 120\n");
          return (0);
        }
      } else {
printf("POINT: 122\n");
        return (0);
      }
    }
  }
  tmp___11 = read_history_int8(3, 0);
printf("POINT: 123\n");

  if ((int )tmp___11 != (int )nomsg) {
printf("POINT: 124\n");
    tmp___12 = read_history_int8(3, 0);
printf("POINT: 125\n");

    if (! ((int )VALUE1 == (int )tmp___12)) {
printf("POINT: 126\n");
      tmp___13 = read_history_int8(3, 0);
printf("POINT: 127\n");

      if (! ((int )VALUE2 == (int )tmp___13)) {
printf("POINT: 128\n");
        tmp___14 = read_history_int8(3, 0);
printf("POINT: 129\n");

        if (! ((int )VALUE3 == (int )tmp___14)) {
printf("POINT: 130\n");
          return (0);
        }
      }
    }
  }
  return (1);
}
}
void gate1_each_pals_period(void) 
{ 
  int8_t next_state ;
  msg_t tmp ;
  int tmp___0 ;

  {

  
  scanf("%", &gate1Failed);
  
  write_historybool(0, gate1Failed);
printf("POINT: 131\n");

  if (gate1Failed) {
printf("POINT: 132\n");

    
printf("POINT: 133\n");

    if ((nomsg != nomsg) && (g1v_new == nomsg)){
printf("POINT: 134\n");
    g1v_new = nomsg;
    }
    else{
    g1v_new = g1v_new;
    }
    
    
    return;
  }

  
  scanf("%c", &tmp);
  
  next_state = tmp;
printf("POINT: 135\n");

  if ((int )next_state == 0) {
printf("POINT: 136\n");
    tmp___0 = 1;
printf("POINT: 137\n");

  } else if ((int )next_state == 1) {
printf("POINT: 138\n");
    tmp___0 = 1;
printf("POINT: 139\n");

  } else if ((int )next_state == 2) {
printf("POINT: 140\n");
    tmp___0 = 1;
  } else {
printf("POINT: 142\n");
    tmp___0 = 0;
  }

  
printf("POINT: 143\n");

  if ((next_state != nomsg) && (g1v_new == nomsg)){
printf("POINT: 144\n");
    g1v_new = next_state;
    }
    else{
    g1v_new = g1v_new;
    }
    
  
  return;
}
}
void gate2_each_pals_period(void) 
{ 
  int8_t next_state ;
  msg_t tmp ;
  int tmp___0 ;

  {

  
  scanf("%", &gate2Failed);
  
  write_historybool(1, gate2Failed);
printf("POINT: 145\n");

  if (gate2Failed) {
printf("POINT: 146\n");
    
printf("POINT: 147\n");

     if ((nomsg != nomsg) && (g2v_new == nomsg)){
printf("POINT: 148\n");
    g2v_new = nomsg;
    }
    else{
    g2v_new = g2v_new;
    }
    
    
    
    return;
  }
  
  scanf("%c", &tmp);
  
  next_state = tmp;
printf("POINT: 149\n");

  if ((int )next_state == 0) {
printf("POINT: 150\n");
    tmp___0 = 1;
printf("POINT: 151\n");

  } else if ((int )next_state == 1) {
printf("POINT: 152\n");
    tmp___0 = 1;
printf("POINT: 153\n");

  } else if ((int )next_state == 2) {
printf("POINT: 154\n");
    tmp___0 = 1;
  } else {
printf("POINT: 156\n");
    tmp___0 = 0;
  }


  
printf("POINT: 157\n");

    if ((next_state != nomsg) && (g2v_new == nomsg)){
printf("POINT: 158\n");
    g2v_new = next_state;
    }
    else{
    g2v_new = g2v_new;
    }
    
    
  return;
}
}
void gate3_each_pals_period(void) 
{ 
  int8_t next_state ;
  msg_t tmp ;
  int tmp___0 ;

  {

  
  scanf("%", &gate3Failed);
  
  write_historybool(2, gate3Failed);
printf("POINT: 159\n");

  if (gate3Failed) {
printf("POINT: 160\n");

    
printf("POINT: 161\n");

      if ((nomsg != nomsg) && (g3v_new == nomsg)){
printf("POINT: 162\n");
    g3v_new = nomsg;
    }
    else{
    g3v_new = g3v_new;
    }
    
    
    
    return;
  }
  
  scanf("%c", &tmp);
    
    
  next_state = tmp;
printf("POINT: 163\n");

  if ((int )next_state == 0) {
printf("POINT: 164\n");
    tmp___0 = 1;
printf("POINT: 165\n");

  } else if ((int )next_state == 1) {
printf("POINT: 166\n");
    tmp___0 = 1;
printf("POINT: 167\n");

  } else if ((int )next_state == 2) {
printf("POINT: 168\n");
    tmp___0 = 1;
  } else {
printf("POINT: 170\n");
    tmp___0 = 0;
  }


  
printf("POINT: 171\n");

  if ((next_state != nomsg) && (g3v_new == nomsg)){
printf("POINT: 172\n");
    g3v_new = next_state;
    }
    else{
    g3v_new = g3v_new;
    }
    
    
  
  return;
}
}
void voter(void) 
{ 
  int8_t voted_value ;

  {
  voted_value = nomsg;
  VALUE1 = g1v_old;
  g1v_old = nomsg;
  VALUE2 = g2v_old;
  g2v_old = nomsg;
  VALUE3 = g3v_old;
  g3v_old = nomsg;
printf("POINT: 173\n");

  if ((int )VALUE1 == (int )VALUE2) {
printf("POINT: 174\n");
printf("POINT: 175\n");

    if ((int )VALUE1 == (int )nomsg) {
printf("POINT: 176\n");
      voted_value = VALUE3;
    } else {
printf("POINT: 178\n");
      voted_value = VALUE1;
    }
printf("POINT: 179\n");

  } else if ((int )VALUE1 == (int )VALUE3) {
printf("POINT: 180\n");
printf("POINT: 181\n");

    if ((int )VALUE1 == (int )nomsg) {
printf("POINT: 182\n");
      voted_value = VALUE2;
    } else {
printf("POINT: 184\n");
      voted_value = VALUE1;
    }
printf("POINT: 185\n");

  } else if ((int )VALUE1 != (int )nomsg) {
printf("POINT: 186\n");
    voted_value = VALUE1;
printf("POINT: 187\n");

  } else if ((int )VALUE2 != (int )nomsg) {
printf("POINT: 188\n");
    voted_value = VALUE2;
printf("POINT: 189\n");

  } else if ((int )VALUE3 != (int )nomsg) {
printf("POINT: 190\n");
    voted_value = VALUE3;
  } else {
printf("POINT: 192\n");
  }
  write_history_int8(3, voted_value);
  return;
}
}
void (*nodes[4])(void)  = {      & gate1_each_pals_period,      & gate2_each_pals_period,      & gate3_each_pals_period,      & voter};



int main(void) 
{ 
  int c1 ;
  int i2 ;
  kappa = 0;
  {
  c1 = 0;
  
  gate1Failed = nondet_bool(); __CPROVER_input("gate1Failed",gate1Failed);
  gate2Failed = nondet_bool(); __CPROVER_input("gate2Failed",gate2Failed);
  gate3Failed = nondet_bool(); __CPROVER_input("gate3Failed",gate3Failed);
  
  VALUE1 = nondet_char(); __CPROVER_input("VALUE1",VALUE1);
  VALUE2 = nondet_char(); __CPROVER_input("VALUE2",VALUE2);
  VALUE3 = nondet_char(); __CPROVER_input("VALUE3",VALUE3);
  
  gate1Failed_History_0 = nondet_bool(); __CPROVER_input("gate1Failed_History_0",gate1Failed_History_0);
  gate1Failed_History_1 = nondet_bool(); __CPROVER_input("gate1Failed_History_1",gate1Failed_History_1);
  gate1Failed_History_2 = nondet_bool(); __CPROVER_input("gate1Failed_History_2",gate1Failed_History_2);
  
  gate2Failed_History_0 = nondet_bool(); __CPROVER_input("gate2Failed_History_0",gate2Failed_History_0);
  gate2Failed_History_1 = nondet_bool(); __CPROVER_input("gate2Failed_History_1",gate2Failed_History_1);
  gate2Failed_History_2 = nondet_bool(); __CPROVER_input("gate2Failed_History_2",gate2Failed_History_2);
  
  gate3Failed_History_0 = nondet_bool(); __CPROVER_input("gate3Failed_History_0",gate3Failed_History_0);
  gate3Failed_History_1 = nondet_bool(); __CPROVER_input("gate3Failed_History_1",gate3Failed_History_1);
  gate3Failed_History_2 = nondet_bool(); __CPROVER_input("gate3Failed_History_2",gate3Failed_History_2);
  
  votedValue_History_0 = nondet_char(); __CPROVER_input("votedValue_History_0",votedValue_History_0);
  votedValue_History_1 = nondet_char(); __CPROVER_input("votedValue_History_1",votedValue_History_1);
  votedValue_History_2 = nondet_char(); __CPROVER_input("votedValue_History_2",votedValue_History_2);
  
  
  i2 = init();

  g1v_old = nomsg;
  g1v_new = nomsg;
  g2v_old = nomsg;
  g2v_new = nomsg;
  g3v_old = nomsg;
  g3v_new = nomsg;
  i2 = 0;
printf("POINT: 193\n");

    while (i2 < 2) {
printf("POINT: 194\n");
    {
    gate1_each_pals_period();
    gate2_each_pals_period();
    gate3_each_pals_period();
    voter();
    g1v_old = g1v_new;
    g1v_new = nomsg;
    g2v_old = g2v_new;
    g2v_new = nomsg;
    g3v_old = g3v_new;
    g3v_new = nomsg;
    c1 = check();
    i2++;
    }
  }
}

return 0;
}
