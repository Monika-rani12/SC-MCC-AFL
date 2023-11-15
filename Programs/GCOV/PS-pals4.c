//This is program pals_lcr.8_false-unreach-call.1.ufo.UNBOUNDED.pals.c









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
port_t p4  ;
char p4_old ;
char p4_new ;
char id4  ;
char st4  ;
msg_t send4  ;
bool mode4  ;
port_t p5  ;
char p5_old ;
char p5_new ;
char id5  ;
char st5  ;
msg_t send5  ;
bool mode5  ;
port_t p6  ;
char p6_old ;
char p6_new ;
char id6  ;
char st6  ;
msg_t send6  ;
bool mode6  ;
port_t p7  ;
char p7_old ;
char p7_new ;
char id7  ;
char st7  ;
msg_t send7  ;
bool mode7  ;
port_t p8  ;
char p8_old ;
char p8_new ;
char id8  ;
char st8  ;
msg_t send8  ;
bool mode8  ;
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
      r1 = 7;
    }
    r1 = r1 + 1;
    m1 = p8_old;
    p8_old = nomsg;
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
      } else
printf("POINT: 23\n");

      if ((int )m2 == (int )id2) {
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
      } else
printf("POINT: 35\n");

      if ((int )m3 == (int )id3) {
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
void node4(void) 
{ 
  msg_t m4 ;

  {
  m4 = nomsg;
printf("POINT: 41\n");

  if (mode4) {
printf("POINT: 42\n");
    m4 = p3_old;
    p3_old = nomsg;
printf("POINT: 43\n");

    if ((int )m4 != (int )nomsg) {
printf("POINT: 44\n");
printf("POINT: 45\n");

      if ((int )m4 > (int )id4) {
printf("POINT: 46\n");
        send4 = m4;
      } else
printf("POINT: 47\n");

      if ((int )m4 == (int )id4) {
printf("POINT: 48\n");
        st4 = (char)1;
      }
    }
    mode4 = (bool)0;
  } else {
printf("POINT: 50\n");

printf("POINT: 51\n");

    if ((send4 != nomsg) && (p4_new == nomsg)){
printf("POINT: 52\n");
    p4_new = send1;
    }
    else{
    p4_new = p4_new;
    }

    mode4 = (bool)1;
  }
  return;
}
}
void node5(void) 
{ 
  msg_t m5 ;

  {
  m5 = nomsg;
printf("POINT: 53\n");

  if (mode5) {
printf("POINT: 54\n");
    m5 = p4_old;
    p4_old = nomsg;
printf("POINT: 55\n");

    if ((int )m5 != (int )nomsg) {
printf("POINT: 56\n");
printf("POINT: 57\n");

      if ((int )m5 > (int )id5) {
printf("POINT: 58\n");
        send5 = m5;
      } else
printf("POINT: 59\n");

      if ((int )m5 == (int )id5) {
printf("POINT: 60\n");
        st5 = (char)1;
      }
    }
    mode5 = (bool)0;
  } else {
printf("POINT: 62\n");
      
printf("POINT: 63\n");

    if ((send5 != nomsg) && (p5_new == nomsg)){
printf("POINT: 64\n");
    p5_new = send5;
    }
    else{
    p5_new = p5_new;
    }  


    mode5 = (bool)1;
  }
  return;
}
}
void node6(void) 
{ 
  msg_t m6 ;

  {
  m6 = nomsg;
printf("POINT: 65\n");

  if (mode6) {
printf("POINT: 66\n");
    m6 = p5_old;
    p5_old = nomsg;
printf("POINT: 67\n");

    if ((int )m6 != (int )nomsg) {
printf("POINT: 68\n");
printf("POINT: 69\n");

      if ((int )m6 > (int )id6) {
printf("POINT: 70\n");
        send6 = m6;
      } else
printf("POINT: 71\n");

      if ((int )m6 == (int )id6) {
printf("POINT: 72\n");
        st6 = (char)1;
      }
    }
    mode6 = (bool)0;
  } else {
printf("POINT: 74\n");
    
printf("POINT: 75\n");

    if ((send6 != nomsg) && (p6_new == nomsg)){
printf("POINT: 76\n");
    p6_new = send6;
    }
    else{
    p6_new = p6_new;
    }
    
    
    mode6 = (bool)1;
  }
  return;
}
}
void node7(void) 
{ 
  msg_t m7 ;

  {
  m7 = nomsg;
printf("POINT: 77\n");

  if (mode7) {
printf("POINT: 78\n");
    m7 = p6_old;
    p6_old = nomsg;
printf("POINT: 79\n");

    if ((int )m7 != (int )nomsg) {
printf("POINT: 80\n");
printf("POINT: 81\n");

      if ((int )m7 > (int )id7) {
printf("POINT: 82\n");
        send7 = m7;
      } else
printf("POINT: 83\n");

      if ((int )m7 == (int )id7) {
printf("POINT: 84\n");
        st7 = (char)1;
      }
    }
    mode7 = (bool)0;
  } else {
printf("POINT: 86\n");
    
printf("POINT: 87\n");

    if ((send7 != nomsg) && (p7_new == nomsg)){
printf("POINT: 88\n");
    p7_new = send7;
    }
    else{
    p7_new = p7_new;
    }
    
    
    mode7 = (bool)1;
  }
  return;
}
}
void node8(void) 
{ 
  msg_t m8 ;

  {
  m8 = nomsg;
printf("POINT: 89\n");

  if (mode8) {
printf("POINT: 90\n");
    m8 = p7_old;
    p7_old = nomsg;
printf("POINT: 91\n");

    if ((int )m8 != (int )nomsg) {
printf("POINT: 92\n");
printf("POINT: 93\n");

      if ((int )m8 > (int )id8) {
printf("POINT: 94\n");
        send8 = m8;
      } else
printf("POINT: 95\n");

      if ((int )m8 == (int )id8) {
printf("POINT: 96\n");
        st8 = (char)1;
      }
    }
    mode8 = (bool)0;
  } else {
printf("POINT: 98\n");
    
printf("POINT: 99\n");

    if ((send8 != nomsg) && (p8_new == nomsg)){
printf("POINT: 100\n");
    p8_new = send8;
    }
    else{
    p8_new = p8_new;
    }
    
    mode8 = (bool)1;
  }
  return;
}
}
void (*nodes[8])(void)  = 
  {      & node1,      & node2,      & node3,      & node4, 
        & node5,      & node6,      & node7,      & node8};
int init(void) 
{ 
  int tmp ;

  {
printf("POINT: 101\n");

  if ((int )r1 == 0) {
printf("POINT: 102\n");
printf("POINT: 103\n");

    if ((int )id1 >= 0) {
printf("POINT: 104\n");
printf("POINT: 105\n");

      if ((int )st1 == 0) {
printf("POINT: 106\n");
printf("POINT: 107\n");

        if ((int )send1 == (int )id1) {
printf("POINT: 108\n");
printf("POINT: 109\n");

          if ((int )mode1 == 0) {
printf("POINT: 110\n");
printf("POINT: 111\n");

            if ((int )id2 >= 0) {
printf("POINT: 112\n");
printf("POINT: 113\n");

              if ((int )st2 == 0) {
printf("POINT: 114\n");
printf("POINT: 115\n");

                if ((int )send2 == (int )id2) {
printf("POINT: 116\n");
printf("POINT: 117\n");

                  if ((int )mode2 == 0) {
printf("POINT: 118\n");
printf("POINT: 119\n");

                    if ((int )id3 >= 0) {
printf("POINT: 120\n");
printf("POINT: 121\n");

                      if ((int )st3 == 0) {
printf("POINT: 122\n");
printf("POINT: 123\n");

                        if ((int )send3 == (int )id3) {
printf("POINT: 124\n");
printf("POINT: 125\n");

                          if ((int )mode3 == 0) {
printf("POINT: 126\n");
printf("POINT: 127\n");

                            if ((int )id4 >= 0) {
printf("POINT: 128\n");
printf("POINT: 129\n");

                              if ((int )st4 == 0) {
printf("POINT: 130\n");
printf("POINT: 131\n");

                                if ((int )send4 == (int )id4) {
printf("POINT: 132\n");
printf("POINT: 133\n");

                                  if ((int )mode4 == 0) {
printf("POINT: 134\n");
printf("POINT: 135\n");

                                    if ((int )id5 >= 0) {
printf("POINT: 136\n");
printf("POINT: 137\n");

                                      if ((int )st5 == 0) {
printf("POINT: 138\n");
printf("POINT: 139\n");

                                        if ((int )send5 == (int )id5) {
printf("POINT: 140\n");
printf("POINT: 141\n");

                                          if ((int )mode5 == 0) {
printf("POINT: 142\n");
printf("POINT: 143\n");

                                            if ((int )id6 >= 0) {
printf("POINT: 144\n");
printf("POINT: 145\n");

                                              if ((int )st6 == 0) {
printf("POINT: 146\n");
printf("POINT: 147\n");

                                                if ((int )send6 == (int )id6) {
printf("POINT: 148\n");
printf("POINT: 149\n");

                                                  if ((int )mode6 == 0) {
printf("POINT: 150\n");
printf("POINT: 151\n");

                                                    if ((int )id7 >= 0) {
printf("POINT: 152\n");
printf("POINT: 153\n");

                                                      if ((int )st7 == 0) {
printf("POINT: 154\n");
printf("POINT: 155\n");

                                                        if ((int )send7 == (int )id7) {
printf("POINT: 156\n");
printf("POINT: 157\n");

                                                          if ((int )mode7 == 0) {
printf("POINT: 158\n");
printf("POINT: 159\n");

                                                            if ((int )id8 >= 0) {
printf("POINT: 160\n");
printf("POINT: 161\n");

                                                              if ((int )st8 == 0) {
printf("POINT: 162\n");
printf("POINT: 163\n");

                                                                if ((int )send8 == (int )id8) {
printf("POINT: 164\n");
printf("POINT: 165\n");

                                                                  if ((int )mode8 == 0) {
printf("POINT: 166\n");
printf("POINT: 167\n");

                                                                    if ((int )id1 != (int )id2) {
printf("POINT: 168\n");
printf("POINT: 169\n");

                                                                      if ((int )id1 != (int )id3) {
printf("POINT: 170\n");
printf("POINT: 171\n");

                                                                        if ((int )id1 != (int )id4) {
printf("POINT: 172\n");
printf("POINT: 173\n");

                                                                          if ((int )id1 != (int )id5) {
printf("POINT: 174\n");
printf("POINT: 175\n");

                                                                            if ((int )id1 != (int )id6) {
printf("POINT: 176\n");
printf("POINT: 177\n");

                                                                              if ((int )id1 != (int )id7) {
printf("POINT: 178\n");
printf("POINT: 179\n");

                                                                                if ((int )id1 != (int )id8) {
printf("POINT: 180\n");
printf("POINT: 181\n");

                                                                                  if ((int )id2 != (int )id3) {
printf("POINT: 182\n");
printf("POINT: 183\n");

                                                                                    if ((int )id2 != (int )id4) {
printf("POINT: 184\n");
printf("POINT: 185\n");

                                                                                      if ((int )id2 != (int )id5) {
printf("POINT: 186\n");
printf("POINT: 187\n");

                                                                                        if ((int )id2 != (int )id6) {
printf("POINT: 188\n");
printf("POINT: 189\n");

                                                                                          if ((int )id2 != (int )id7) {
printf("POINT: 190\n");
printf("POINT: 191\n");

                                                                                            if ((int )id2 != (int )id8) {
printf("POINT: 192\n");
printf("POINT: 193\n");

                                                                                              if ((int )id3 != (int )id4) {
printf("POINT: 194\n");
printf("POINT: 195\n");

                                                                                                if ((int )id3 != (int )id5) {
printf("POINT: 196\n");
printf("POINT: 197\n");

                                                                                                  if ((int )id3 != (int )id6) {
printf("POINT: 198\n");
printf("POINT: 199\n");

                                                                                                    if ((int )id3 != (int )id7) {
printf("POINT: 200\n");
printf("POINT: 201\n");

                                                                                                      if ((int )id3 != (int )id8) {
printf("POINT: 202\n");
printf("POINT: 203\n");

                                                                                                        if ((int )id4 != (int )id5) {
printf("POINT: 204\n");
printf("POINT: 205\n");

                                                                                                          if ((int )id4 != (int )id6) {
printf("POINT: 206\n");
printf("POINT: 207\n");

                                                                                                            if ((int )id4 != (int )id7) {
printf("POINT: 208\n");
printf("POINT: 209\n");

                                                                                                              if ((int )id4 != (int )id8) {
printf("POINT: 210\n");
printf("POINT: 211\n");

                                                                                                                if ((int )id5 != (int )id6) {
printf("POINT: 212\n");
printf("POINT: 213\n");

                                                                                                                  if ((int )id5 != (int )id7) {
printf("POINT: 214\n");
printf("POINT: 215\n");

                                                                                                                    if ((int )id5 != (int )id8) {
printf("POINT: 216\n");
printf("POINT: 217\n");

                                                                                                                      if ((int )id6 != (int )id7) {
printf("POINT: 218\n");
printf("POINT: 219\n");

                                                                                                                        if ((int )id6 != (int )id8) {
printf("POINT: 220\n");
printf("POINT: 221\n");

                                                                                                                          if ((int )id7 != (int )id8) {
printf("POINT: 222\n");
                                                                                                                            tmp = 1;
                                                                                                                          } else {
printf("POINT: 224\n");
                                                                                                                            tmp = 0;
                                                                                                                          }
                                                                                                                        } else {
printf("POINT: 226\n");
                                                                                                                          tmp = 0;
                                                                                                                        }
                                                                                                                      } else {
printf("POINT: 228\n");
                                                                                                                        tmp = 0;
                                                                                                                      }
                                                                                                                    } else {
printf("POINT: 230\n");
                                                                                                                      tmp = 0;
                                                                                                                    }
                                                                                                                  } else {
printf("POINT: 232\n");
                                                                                                                    tmp = 0;
                                                                                                                  }
                                                                                                                } else {
printf("POINT: 234\n");
                                                                                                                  tmp = 0;
                                                                                                                }
                                                                                                              } else {
printf("POINT: 236\n");
                                                                                                                tmp = 0;
                                                                                                              }
                                                                                                            } else {
printf("POINT: 238\n");
                                                                                                              tmp = 0;
                                                                                                            }
                                                                                                          } else {
printf("POINT: 240\n");
                                                                                                            tmp = 0;
                                                                                                          }
                                                                                                        } else {
printf("POINT: 242\n");
                                                                                                          tmp = 0;
                                                                                                        }
                                                                                                      } else {
printf("POINT: 244\n");
                                                                                                        tmp = 0;
                                                                                                      }
                                                                                                    } else {
printf("POINT: 246\n");
                                                                                                      tmp = 0;
                                                                                                    }
                                                                                                  } else {
printf("POINT: 248\n");
                                                                                                    tmp = 0;
                                                                                                  }
                                                                                                } else {
printf("POINT: 250\n");
                                                                                                  tmp = 0;
                                                                                                }
                                                                                              } else {
printf("POINT: 252\n");
                                                                                                tmp = 0;
                                                                                              }
                                                                                            } else {
printf("POINT: 254\n");
                                                                                              tmp = 0;
                                                                                            }
                                                                                          } else {
printf("POINT: 256\n");
                                                                                            tmp = 0;
                                                                                          }
                                                                                        } else {
printf("POINT: 258\n");
                                                                                          tmp = 0;
                                                                                        }
                                                                                      } else {
printf("POINT: 260\n");
                                                                                        tmp = 0;
                                                                                      }
                                                                                    } else {
printf("POINT: 262\n");
                                                                                      tmp = 0;
                                                                                    }
                                                                                  } else {
printf("POINT: 264\n");
                                                                                    tmp = 0;
                                                                                  }
                                                                                } else {
printf("POINT: 266\n");
                                                                                  tmp = 0;
                                                                                }
                                                                              } else {
printf("POINT: 268\n");
                                                                                tmp = 0;
                                                                              }
                                                                            } else {
printf("POINT: 270\n");
                                                                              tmp = 0;
                                                                            }
                                                                          } else {
printf("POINT: 272\n");
                                                                            tmp = 0;
                                                                          }
                                                                        } else {
printf("POINT: 274\n");
                                                                          tmp = 0;
                                                                        }
                                                                      } else {
printf("POINT: 276\n");
                                                                        tmp = 0;
                                                                      }
                                                                    } else {
printf("POINT: 278\n");
                                                                      tmp = 0;
                                                                    }
                                                                  } else {
printf("POINT: 280\n");
                                                                    tmp = 0;
                                                                  }
                                                                } else {
printf("POINT: 282\n");
                                                                  tmp = 0;
                                                                }
                                                              } else {
printf("POINT: 284\n");
                                                                tmp = 0;
                                                              }
                                                            } else {
printf("POINT: 286\n");
                                                              tmp = 0;
                                                            }
                                                          } else {
printf("POINT: 288\n");
                                                            tmp = 0;
                                                          }
                                                        } else {
printf("POINT: 290\n");
                                                          tmp = 0;
                                                        }
                                                      } else {
printf("POINT: 292\n");
                                                        tmp = 0;
                                                      }
                                                    } else {
printf("POINT: 294\n");
                                                      tmp = 0;
                                                    }
                                                  } else {
printf("POINT: 296\n");
                                                    tmp = 0;
                                                  }
                                                } else {
printf("POINT: 298\n");
                                                  tmp = 0;
                                                }
                                              } else {
printf("POINT: 300\n");
                                                tmp = 0;
                                              }
                                            } else {
printf("POINT: 302\n");
                                              tmp = 0;
                                            }
                                          } else {
printf("POINT: 304\n");
                                            tmp = 0;
                                          }
                                        } else {
printf("POINT: 306\n");
                                          tmp = 0;
                                        }
                                      } else {
printf("POINT: 308\n");
                                        tmp = 0;
                                      }
                                    } else {
printf("POINT: 310\n");
                                      tmp = 0;
                                    }
                                  } else {
printf("POINT: 312\n");
                                    tmp = 0;
                                  }
                                } else {
printf("POINT: 314\n");
                                  tmp = 0;
                                }
                              } else {
printf("POINT: 316\n");
                                tmp = 0;
                              }
                            } else {
printf("POINT: 318\n");
                              tmp = 0;
                            }
                          } else {
printf("POINT: 320\n");
                            tmp = 0;
                          }
                        } else {
printf("POINT: 322\n");
                          tmp = 0;
                        }
                      } else {
printf("POINT: 324\n");
                        tmp = 0;
                      }
                    } else {
printf("POINT: 326\n");
                      tmp = 0;
                    }
                  } else {
printf("POINT: 328\n");
                    tmp = 0;
                  }
                } else {
printf("POINT: 330\n");
                  tmp = 0;
                }
              } else {
printf("POINT: 332\n");
                tmp = 0;
              }
            } else {
printf("POINT: 334\n");
              tmp = 0;
            }
          } else {
printf("POINT: 336\n");
            tmp = 0;
          }
        } else {
printf("POINT: 338\n");
          tmp = 0;
        }
      } else {
printf("POINT: 340\n");
        tmp = 0;
      }
    } else {
printf("POINT: 342\n");
      tmp = 0;
    }
  } else {
printf("POINT: 344\n");
    tmp = 0;
  }
  return (tmp);
}
}
int check(void) 
{ 
  int tmp ;

  {
printf("POINT: 345\n");

  if ((((((((int )st1 + (int )st2) + (int )st3) + (int )st4) + (int )st5) + (int )st6) + (int )st7) + (int )st8 <= 1) {
printf("POINT: 346\n");
printf("POINT: 347\n");

    if ((int )r1 >= 8) {
printf("POINT: 348\n");
      goto _L;
    } else
printf("POINT: 349\n");

    if ((((((((int )st1 + (int )st2) + (int )st3) + (int )st4) + (int )st5) + (int )st6) + (int )st7) + (int )st8 == 0) {
printf("POINT: 350\n");
      _L: /* CIL Label */ 
printf("POINT: 351\n");

      if ((int )r1 < 8) {
printf("POINT: 352\n");
        tmp = 1;
      } else
printf("POINT: 353\n");

      if ((((((((int )st1 + (int )st2) + (int )st3) + (int )st4) + (int )st5) + (int )st6) + (int )st7) + (int )st8 == 1) {
printf("POINT: 354\n");
        tmp = 1;
      } else {
printf("POINT: 356\n");
        tmp = 0;
      }
    } else {
printf("POINT: 358\n");
      tmp = 0;
    }
  } else {
printf("POINT: 360\n");
    tmp = 0;
  }
  return (tmp);
}
}



int main(void) 
{ 
kappa =0 ;
  int c1 ;
  int i2 ;
  
  {
  c1 = 0;

  
  
  scanf("%c", &r1);
    
  scanf("%c", &id1);
  scanf("%c", &st1);
  scanf("%c", &send1);
  scanf("%", &mode1);

  scanf("%c", &id2);
  scanf("%c", &st2);
  scanf("%c", &send2);
  scanf("%", &mode2);
  
  scanf("%c", &id3);
  scanf("%c", &st3);
  scanf("%c", &send3);
  scanf("%", &mode3);
  
  
  scanf("%c", &id4);
  scanf("%c", &st4);
  scanf("%c", &send4);
  scanf("%", &mode4);

  scanf("%c", &id5);
  scanf("%c", &st5);
  scanf("%c", &send5);
  scanf("%", &mode5);
  
  scanf("%c", &id6);
  scanf("%c", &st6);
  scanf("%c", &send6);
  scanf("%", &mode6);
  
  scanf("%c", &id7);
  scanf("%c", &st7);
  scanf("%c", &send7);
  scanf("%", &mode7);
  
  scanf("%c", &id8);
  scanf("%c", &st8);
  scanf("%c", &send8);
  scanf("%", &mode8);
  
  
  
  i2 = init();

  p1_old = nomsg;
  p1_new = nomsg;
  p2_old = nomsg;
  p2_new = nomsg;
  p3_old = nomsg;
  p3_new = nomsg;
  p4_old = nomsg;
  p4_new = nomsg;
  p5_old = nomsg;
  p5_new = nomsg;
  p6_old = nomsg;
  p6_new = nomsg;
  p7_old = nomsg;
  p7_new = nomsg;
  p8_old = nomsg;
  p8_new = nomsg;
  i2 = 0;
printf("POINT: 361\n");

  while (i2 < 1) {
printf("POINT: 362\n");
    {
    node1();
    node2();
    node3();
    node4();
    node5();
    node6();
    node7();
    node8();
    p1_old = p1_new;
    p1_new = nomsg;
    p2_old = p2_new;
    p2_new = nomsg;
    p3_old = p3_new;
    p3_new = nomsg;
    p4_old = p4_new;
    p4_new = nomsg;
    p5_old = p5_new;
    p5_new = nomsg;
    p6_old = p6_new;
    p6_new = nomsg;
    p7_old = p7_new;
    p7_new = nomsg;
    p8_old = p8_new;
    p8_new = nomsg;
    c1 = check();
    i2++;
    }
  }
}

return 0;
}
