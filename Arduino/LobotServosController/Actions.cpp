//舵机编号从上往下依次为10 11 12 13 14 15
//中心位置为1500

#include "Actions.h"

LobotServoController controller;

Actions::Actions() {
}
Actions::~Actions() {
}

void Actions::initialization() {
  controller.moveServos(5, 1000, 10, 1500, 11, 1500, 12, 1500, 13, 1500, 14, 1500, 15, 1500);
  delay(1000);
}

//1 死亡 身体僵硬 挺直 位置低 没有明显运动
void Actions::action_group_1() {
  int posi[6] = {1500,500,1640,1440,1840,1820};

  LobotServo servos[6];
  for(int i=0;i<6;i++){
    servos[i].ID = i+10;
    servos[i].Position = posi[i];
  }

  controller.moveServos(servos,6,2000);
  delay(2000); 
}

//2 焦虑走动  有一些琐碎动作的前提下  头在低位 身体大结构有变化的运动  且关节11旋转
void Actions::action_group_2() {
  int posi[5][6] = {{180,60,0,0,0,90},{90,120,30,30,180,90},{0,60,0,0,0,90},{90,120,30,30,180,90},{180,60,0,0,0,90}};
  LobotServo servos[6];
  for(int j=0;j<5;j++){
    for(int i=0;i<6;i++){
      posi[j][i] = map(posi[j][i],0,180,500,2500);
      servos[i].ID = i+10;
      servos[i].Position = posi[j][i];
    }
    controller.moveServos(servos,6,500);
    delay(500);
  } 
}

//3 观望 专注凝视 头部抬起 定在一定高度保持不变的前提下  身体有弯折角度变化（例如身体抬高 头就降低  头部高度大致不变
void Actions::action_group_3() {
  int posi[2][6] = {{30,50,0,140,150,90},{150,50,0,140,30,90}};
  
  LobotServo servos[6];

  for(int j=0;j<2;j++){
    for(int i=0;i<6;i++){
      posi[j][i] = map(posi[j][i],0,180,500,2500);
      servos[i].ID = i+10;
      servos[i].Position = posi[j][i];
    }
    controller.moveServos(servos,6,500);
    delay(500);
  } 
}

//4 刻板行为 身体呈僵硬大直角  头尽量向下营造出脖子低下的感觉 关节11来回旋转80度角  旋转的过程中头一直机械摇动  并在两端静止3秒 头也静止
void Actions::action_group_4() {
  int posi[5][6] = {{170,90,0,0,180,90},{90,90,0,0,90,90},{10,90,0,0,0,90},{90,90,0,0,90,90},{170,90,0,0,180,90}};
  
  LobotServo servos[6];

  for(int j=0;j<5;j++){
    for(int i=0;i<6;i++){
      posi[j][i] = map(posi[j][i],0,180,500,2500);
      servos[i].ID = i+10;
      servos[i].Position = posi[j][i];
    }
    controller.moveServos(servos,6,1000);
    delay(1000);
    if(j%2==0){
        delay(3000);  
    }
  }
}

//5 悠闲 C型弯曲斜头部 晃头
void Actions::action_group_5() {
  
}

//6 疗伤 L型卧倒 头部背对人
void Actions::action_group_6() {
    controller.moveServos(5, 2000, 10, 1500, 11, 2450, 12, 1100, 13, 2500, 14, 500, 15, 2500);
    delay(2000);
    controller.moveServos(5, 2000, 10, 1500, 11, 2450, 12, 1100, 13, 2500, 14, 500, 15, 500);
    delay(2000);
}

//7 休眠 7型大角度弯折 缓慢小角度轻微摆动关节14
void Actions::action_group_7() {
  randomSeed(analogRead(5));
  int random_number1 = (int) random(1450, 1550);
  int random_number2 = (int) random(1350, 1650);
  controller.moveServos(5, 300, 10, random_number1, 11, 1300, 12, 500, 13, 500, 14, random_number2, 15, 1500);
  delay(50);
  controller.moveServos(5, 300, 10, random_number1, 11, 1300, 12, 500, 13, 500, 14, random_number2, 15, 1500);
  delay(50);

}

//8 虚弱 Z型缩躺 随机秒数抽动关节14
void Actions::action_group_8() {
  int random_delay1 = 0;
  int times_of_loop = 0;

  randomSeed(analogRead(5));
  times_of_loop = (int) random(2, 6);
  for(int i = 0; i < times_of_loop; i++){
    randomSeed(analogRead(5));
    random_delay1 = (int) random(50, 100);
    controller.moveServos(5, 50, 10, 1500, 11, 2400, 12, 700, 13, 2100, 14, 1500, 15, 1500);
    delay(random_delay1);
    randomSeed(analogRead(5));
    random_delay1 = (int) random(50, 100);
    controller.moveServos(5, 50, 10, 1500, 11, 2500, 12, 900, 13, 1950, 14, 1500, 15, 1500);
    delay(random_delay1);
  }
}

//9 埋伏伏击 L型卧倒
void Actions::action_group_9() {
  controller.moveServos(5, 2000, 10, 1500, 11, 600, 12, 600, 13, 600, 14, 1500, 15, 1500);
  delay(2000);
  controller.moveServos(5, 2000, 10, 1500, 11, 2400, 12, 2400, 13, 600, 14, 1500, 15, 1500);
  delay(2000);
  controller.moveServos(5, 2000, 10, 1500, 11, 1800, 12, 500, 13, 1800, 14, 1500, 15, 1500); //扑杀可以用这个
  delay(2000);
  controller.moveServos(5, 2000, 10, 1500, 11, 2000, 12, 1000, 13, 1500, 14, 1500, 15, 1500);
  delay(2000);
  for(int i = 0; i < 3; i++) {
    controller.moveServos(5, 4000, 10, 1600, 11, 2000, 12, 1000, 13, 1500, 14, 1200, 15, 1500);
    delay(4000);
    controller.moveServos(5, 4000, 10, 1400, 11, 2000, 12, 1000, 13, 1500, 14, 1800, 15, 1500);
    delay(4000);
  }
}

//10 理毛 整饰身体
void Actions::action_group_10() {
  controller.moveServos(5, 2000, 10, 1500, 11, 2400, 12, 1600, 13, 2500, 14, 500, 15, 1500);
  delay(2000);
  for(int i = 1; i < 8; i++) {
    controller.moveServos(5, 1000, 10, 1500, 11, 2400, 12, 2400, 13, 2500, 14, 2000, 15, 1000);
    delay(1000);
    controller.moveServos(5, 1000, 10, 1600, 11, 2300, 12, 2500, 13, 2400, 14, 2300, 15, 2000);
    delay(1000);
  }
}

//11 拱来拱去 7型朝下 关节14控制大幅度抬头拱动 速度快 间隔3秒以上  每动一次 头部也旋转20度（往返型）
void Actions::action_group_11() {
  controller.moveServos(5, 1500, 10, 1500, 11, 1600, 12, 800, 13, 800, 14, 1500, 15, 1500);
  delay(1500);
  for(int i = 0; i < 10; i++) {
    controller.moveServos(5, 200, 10, 1500, 11, 1800, 12, 800, 13, 800, 14, 1500, 15, 1500);
    delay(200);
    controller.moveServos(5, 200, 10, 1500, 11, 2000, 12, 1100, 13, 1200, 14, 1500, 15, 1500);
    delay(200);
    controller.moveServos(5, 200, 10, 1500, 11, 1800, 12, 1100, 13, 1200, 14, 1500, 15, 1500);
    delay(200);
    controller.moveServos(5, 200, 10, 1500, 11, 1600, 12, 800, 13, 800, 14, 1500, 15, 1500);
    delay(200);
  }
}

//12 期待指令 闪电型 面朝人 关节13有节奏间歇性快速旋转15度控制它兴奋跳动  头部每5秒转动90度
void Actions::action_group_12() {
  controller.moveServos(5, 200, 10, 1500, 11, 1000, 12, 500, 13, 2000, 14, 500, 15, 1400);
  delay(200);
  controller.moveServos(5, 200, 10, 1500, 11, 1200, 12, 900, 13, 1800, 14, 2500, 15, 1600);
  delay(200);
}

//13 发泄 Z字缩躺 用力不停摔动关节14 使头砸地 频率5秒内3到8次随机（如果可以）  头部每隔3次砸动（关节14往返3次） 旋转90度
void Actions::action_group_13() {
  int random_delay1 = 0;
  int random_delay2 = 0;
  int times_of_loop = 0;
  int offset = 0;
  for(int i = 0; i < 3; i++) {
    randomSeed(analogRead(5));
    times_of_loop = (int) random(2, 5);
    random_delay2 = (int) random(500, 1500);
    offset = (int) random(0, 300);
    for(int i = 0; i < times_of_loop; i++){
      randomSeed(analogRead(5));
      random_delay1 = (int) random(800, 1200);
      controller.moveServos(5, random_delay1, 10, 1500, 11, 1600+offset, 12, 600, 13, 2500, 14, 2200+offset, 15, 1500);
      delay(random_delay1);
      randomSeed(analogRead(5));
      random_delay1 = (int) random(50, 100);
      controller.moveServos(5, random_delay1, 10, 1500, 11, 2100, 12, 600, 13, 2000, 14, 800-offset, 15, 1500);
      delay(random_delay1);
    }
    delay(random_delay2);
  }
}

//14 训练 听从指令 N型仰 控制器按动时 转变为I型 再恢复成N型
//需要传感器传入参数控制俯仰，此处暂时简略参数
void Actions::action_group_14(/*bool touch*/) {
  controller.moveServos(5, 2000, 10, 1500, 11, 800, 12, 1800, 13, 1800, 14, 1500, 15, 1500);
  delay(2000);
  /*
  while(1) {
    controller.moveServos(5, 2000, 10, 1500, 11, 800, 12, 1800, 13, 1800, 14, 1500, 15, 1500);
    delay(2000);
    if(touch) {
      controller.moveServos(5, 2000, 10, 1500, 11, 1800, 12, 1200, 13, 1200, 14, 1500, 15, 1500);
      delay(2000);
    }
  }
  */
}
//15 打滚 撒娇 一型仰躺 中部拱起放平循环 快速摇头
void Actions::action_group_15() {
  controller.moveServos(5, 500, 10, 1500, 11, 900, 12, 1800, 13, 1800, 14, 500, 15, 1400);
  delay(500);
  controller.moveServos(5, 500, 10, 1500, 11, 600, 12, 1500, 13, 1500, 14, 2500, 15, 1600);
  delay(500);
}

//16 美梦 C型折叠 头朝人 嘴巴开合
void Actions::action_group_16() {
  controller.moveServos(5, 2000, 10, 1500, 11, 650, 12, 650, 13, 650, 14, 1500, 15, 1600);
  delay(2000);
  controller.moveServos(5, 2000, 10, 1500, 11, 500, 12, 500, 13, 550, 14, 1500, 15, 1400);
  delay(2000);
}

//17 蹭 亲  /型挺身 关节11缓慢上下摆动20度 朝向人 头旋转90往返  （2-5秒一个往返）嘴快速开合
void Actions::action_group_17() {
  int posi[11][6] = {{90,90,0,180,90,75},{90,110,40,160,90,105},{90,90,0,180,90,75},{90,110,40,160,90,105},{90,90,0,180,90,75},
  {90,90,0,180,70,90},{90,90,0,180,130,90},{90,90,0,180,70,90},{90,90,0,180,130,90}};
  
  LobotServo servos[6];

  for(int j=0;j<11;j++){
    for(int i=0;i<6;i++){
      posi[j][i] = map(posi[j][i],0,180,500,2500);
      servos[i].ID = i+10;
      servos[i].Position = posi[j][i];
    }
    controller.moveServos(servos,6,500);
    delay(500);
  } 
}

//18 扑杀 /型低位挺身 关节13 14 协同缓慢回缩 猛地伸直（关节12同时猛地抬高20度）头部甩动
void Actions::action_group_18() {
  int rotating = 0;
  int random_delay = 0;
  controller.moveServos(5, 500, 10, 1500, 11, 600, 12, 600, 13, 600, 14, 1500, 15, 1500);
  delay(500);
  controller.moveServos(5, 500, 10, 1500, 11, 2400, 12, 2400, 13, 600, 14, 1500, 15, 1500);
  delay(500);
  controller.moveServos(5, 500, 10, 1500, 11, 1800, 12, 500, 13, 1800, 14, 1500, 15, 1500);
  delay(500);
  controller.moveServos(5, 500, 10, 1500, 11, 1300, 12, 500, 13, 1300, 14, 1500, 15, 1500);
  delay(500);

  randomSeed(analogRead(5));
  random_delay = (int) random(1000, 3000);
  rotating = (int) random(1200, 1800);
  controller.moveServos(5, 200, 10, rotating, 11, 2300, 12, 1400, 13, 1600, 14, 1500, 15, 1500);
  delay(200);
  controller.moveServos(5, 800, 10, rotating, 11, 1300, 12, 500, 13, 1300, 14, 1500, 15, 1500);
  delay(random_delay);
}

//19 跑跳 活动身体 L型低位挺直 关节14摆动3下 转到C型 关节12 摆动2下（循环）
void Actions::action_group_19() {
    for(int i = 0; i < 3; i++) {
      controller.moveServos(5, 300, 10, 1500, 11, 2450, 12, 2500, 13, 500, 14, 1500, 15, 1500);
      delay(300);
      controller.moveServos(5, 300, 10, 1500, 11, 2450, 12, 2500, 13, 1500, 14, 1500, 15, 1500);
      delay(300);
    }
    for(int i = 0; i < 2; i++) {
      controller.moveServos(5, 300, 10, 1500, 11, 2450, 12, 2500, 13, 2500, 14, 1500, 15, 1500);
      delay(300);
      controller.moveServos(5, 300, 10, 1500, 11, 2450, 12, 2500, 13, 1500, 14, 1500, 15, 1500);
      delay(300);
    }

}

//20 完全放松地躺着 一型仰躺 嘴缓慢开合
void Actions::action_group_20() {
  int posi[2][6] = {{0,10,90,90,90,85},{0,10,90,90,90,95}};
  
  LobotServo servos[6];

  for(int j=0;j<2;j++){
    for(int i=0;i<6;i++){
      posi[j][i] = map(posi[j][i],0,180,500,2500);
      servos[i].ID = i+10;
      servos[i].Position = posi[j][i];
    }
    controller.moveServos(servos,6,2000);
    delay(2000);
  } 
}
void Actions::action_group_21() {
  int posi[2][6] = {{0,0,90,90,180,90},{150,45,60,40,70,90}};
  int timee[2]={6000,100};
  LobotServo servos[6];

  for(int j=0;j<2;j++){
    for(int i=0;i<6;i++){
      posi[j][i] = map(posi[j][i],0,180,500,2500);
      servos[i].ID = i+10;
      servos[i].Position = posi[j][i];
    }
    controller.moveServos(servos,6,timee[j]);
    delay(timee[j]);
  } 
}
void Actions::action_group_22() {
  int posi[7][6] = {{0,90,90,90,90,90},{90,45,0,0,150,90},{110,135,45,120,30,90},{70,70,0,180,120,90},{70,70,0,180,20,90},{70,70,0,180,120,90},{70,70,0,180,20,90}};
  int timee[7] = {500,500,500,500,200,200,200};
  LobotServo servos[6];

  for(int j=0;j<7;j++){
    for(int i=0;i<6;i++){
      posi[j][i] = map(posi[j][i],0,180,500,2500);
      servos[i].ID = i+10;
      servos[i].Position = posi[j][i];
    }
    controller.moveServos(servos,6,timee[j]);
    delay(timee[j]);
  } 
}
void Actions::action_group_23() {
  int posi[5][6] = {{90,180,120,0,70,75},{90,140,180,90,130,105},{90,140,180,90,70,75},{90,140,180,90,70,105},{90,140,180,90,70,75}};
  int timee[5] = {3000,3000,500,200,200};
  LobotServo servos[6];

  for(int j=0;j<5;j++){
    for(int i=0;i<6;i++){
      posi[j][i] = map(posi[j][i],0,180,500,2500);
      servos[i].ID = i+10;
      servos[i].Position = posi[j][i];
      ;
    }
    controller.moveServos(servos,6,timee[j]);
    delay(timee[j]);
  } 
  
  int pposi[5][6] = {{90,140,180,90,70,105},{90,140,180,90,70,75},{90,140,180,90,70,105},{90,140,180,90,70,75},{90,140,180,90,70,105}};
  int ttimee[5] = {200,200,200,200,200};

  for(int j=0;j<5;j++){
    for(int i=0;i<6;i++){
      pposi[j][i] = map(pposi[j][i],0,180,500,2500);
      servos[i].ID = i+10;
      servos[i].Position = pposi[j][i];
      ;
    }
    controller.moveServos(servos,6,ttimee[j]);
    delay(ttimee[j]);
  } 
}
void Actions::action_group_24() {
  int posi[9][6] = {{90,90,90,90,90,90},{90,90,20,40,90,90},{90,90,20,40,170,90},{90,90,20,40,30,90},{90,90,20,40,60,90},{90,90,20,40,20,90},{90,90,20,40,70,90},{90,90,20,40,20,90},{90,90,20,40,70,90}};
  int timee[9] = {2000,2000,5000,5000,1000,1000,500,500,500};
  LobotServo servos[6];

  for(int j=0;j<9;j++){
    for(int i=0;i<6;i++){
      posi[j][i] = map(posi[j][i],0,180,500,2500);
      servos[i].ID = i+10;
      servos[i].Position = posi[j][i];
    }
    controller.moveServos(servos,6,timee[j]);
    delay(timee[j]);
  } 
}
void Actions::action_group_25() {
  randomSeed(analogRead(5));
  int posi[9][6] = {{random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150)},{random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150)},{random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150)},{random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150)},{random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150)},{random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150)},{random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150)},{random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150)},{random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150),random(30, 150)}};
  int timee[9] = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
  LobotServo servos[6];

  for(int j=0;j<9;j++){
    for(int i=0;i<6;i++){
      posi[j][i] = map(posi[j][i],0,180,500,2500);
      servos[i].ID = i+10;
      servos[i].Position = posi[j][i];
    }
    controller.moveServos(servos,6,timee[j]);
    delay(timee[j]);
  }
}
void Actions::action_group_26() {
  int posi[14][6] = {{0,90,0,180,180,90},
  {0,90,0,130,180,90},{0,90,0,180,180,90},{0,90,0,130,180,90},
  {0,90,0,180,180,75},{0,90,0,180,180,105},{0,90,0,180,180,75},
  {180,90,0,180,180,90},{180,90,0,0,180,90},
  {180,90,180,0,180,90},{180,90,130,0,180,90},{180,90,180,0,180,90},{180,90,130,0,180,90},{180,90,180,0,180,90}};
  int timee[14] = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
  LobotServo servos[6];

  for(int j=0;j<14;j++){
    for(int i=0;i<6;i++){
      posi[j][i] = map(posi[j][i],0,180,500,2500);
      servos[i].ID = i+10;
      servos[i].Position = posi[j][i];
    }
    controller.moveServos(servos,6,timee[j]);
    delay(timee[j]);
  } 
}
void Actions::action_group_27(double leap_x, double leap_y) {
  int posi[6] = {leap_x,120,leap_y,90,90,90};
  int timee = 100;
  LobotServo servos[6];

  for(int i=0;i<6;i++){
    posi[i] = map(posi[i],0,180,500,2500);
    servos[i].ID = i+10;
    servos[i].Position = posi[i];
  }
  controller.moveServos(servos,6,timee);
  delay(timee);
}
