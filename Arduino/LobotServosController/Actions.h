#ifndef ACTIONS_H
#define ACTIONS_H

#include "LobotServoController.h"

class Actions {
  public:
    Actions();
    ~Actions();

  public:
    void initialization();
    void action_group_1();
    void action_group_2();
    void action_group_3();
    void action_group_4();
    void action_group_5();
    void action_group_6();
    void action_group_7();
    void action_group_8();
    void action_group_9();
    void action_group_10();
    void action_group_11();
    void action_group_12();
    void action_group_13();
    void action_group_14(/*bool touch*/);
    void action_group_15();
    void action_group_16();
    void action_group_17();
    void action_group_18();
    void action_group_19();
    void action_group_20();
    void action_group_21();
    void action_group_22();
    void action_group_23();
    void action_group_24();
    void action_group_25();
    void action_group_26();
    void action_group_27(double leap_x, double leap_y);
};

#endif
