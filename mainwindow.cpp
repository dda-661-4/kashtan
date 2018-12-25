#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QQueue>
#include <QStack>
//#include <stack>

QString s="";
int len_s,q_s=0;
int i = 0;
QString SPACE=" ";
QString checker;
QString descriptor="";
QChar c[200];
int d=0;

 QQueue <int> lenta;
  QStack <int> magazin2;

int Table[61][30]={
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //1 -1001
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 2 -1002
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},// 3- 1003
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,57,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},// 4- 1004
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},// 5 - 1005
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,19,0,0,0,0,19,0,0,0,0,0,0,0,19,0,0,0,0,0},//6 - 1006
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//7 - 1007
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,61,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //8 - 1008
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,8,7,9,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //9 - 1009
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,11,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //10 -1010
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,53,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //11 -1011
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,52,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //12 - 1012
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,54,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //13 -1013
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,55,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //14 - 1014
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //15 -1015
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,42,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},// //16 -1016
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //17 -1017
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,56,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //18 - 1018
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //19 -1019
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //20 -1020
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,58,43,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //21 -1021
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //22 - 1022
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //23 - 1023
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,59,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //24 -1024
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,22,0,0,0,0,21,0,0,0,0,0,0,0,23,0,0,0,0,0},  //25 -1025
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,62,0,0,0,0,0,0,20,0,0,0,0,20,0,0,0,0,0,0,0,20,0,0,0,0,0}, //26 - 1026
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,0,0,0,0,0,0,0,0,0,0,0,0},  //27 -1027
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //28 -1028
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,0,0,0,0,0},//29 -1029
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //30 -1030
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,45,0,0,0,0,0,0,0,63,0,0,0,0,0,0,0,0,0,0,0},//31 - 1031
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//32 - 1032
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,27,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//33 - 1033
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//34 - 1034
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//35 -1035
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,64,0,0,0,0,0,0,0,0,0,0,46,47,48,49,0,0,0,0,0,0},//36 -1036
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,50,0,0,0,0,0},//37 -1037
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//38 -1038
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//39 -1039
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,33,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//40 - 1040
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,34,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//41 - 1041
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,36,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//42 - 1042
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,35,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//43 -1043
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,37,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//44 -1044
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//45 - 1045
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//46 - 1046
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,51,0},//47 -1047
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,60,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//48 - 1
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,60,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//49 - 3
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,60,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//50 - 4
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,60,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//51 - 9
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,60,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//52 - 13
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//53 - 14
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,0,0,0,0,0,0,0,0,0,0,0,0},//54 - 17
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,0,0,0,0,0,0,0,0,0,0,0},//55 - 18
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,0,0,0,0,0,0,0,0,0,0},//56 - 19
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,0,0,0,0},//57 - 25
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,0,0,0},//58 -26
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,0,0},//59 -27
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//60 - 999
};





QString s1=":";
QString s3="$";
QString s9=";";
QString s10=",";
QString s13="[";
QString s14="]";
QString s15="C";
QString s17="(";
QString s18=")";
QString s19=":=";
QString s20="+";
QString s210="-";
QString s220="*";
QString s230="/";
QString s100="=";


QString s2="b";
QString s21="e";
QString s22="g";
QString s23="i";
QString s24="n";

QString s4="e";
QString s41="n";
QString s42="d";

QString s5="r";
QString s51="e";
QString s52="a";
QString s53="l";

QString s6="i";
QString s61="n";
QString s62="t";
QString s63="e";
QString s64="g";
QString s65="r";

QString s7="l";
QString s71="a";
QString s72="b";
QString s73="e";
QString s74="l";

QString s8="B";
QString s81="o";
QString s82="l";

QString s12="a";
QString s121="r";
QString s122="y";

QString s16="o";
QString s161="u";
QString s162="t";
QString s163="p";

QString s240="f";
QString s241="o";
QString s242="r";

QString s25="s";
QString s251="t";
QString s252="e";
QString s253="p";

QString s26="u";
QString s261="n";
QString s262="t";
QString s263="i";
QString s264="l";

QString s27="d";
QString s271="o";

QString s28="a";
QString s281="n";
QString s282="d";


int dlinna=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ok_clicked()
{
  s=ui->Text->toPlainText();
  len_s=s.size();
  MainWindow::razbor_stroki();
}

void MainWindow::razbor_stroki()
{

    for(int i =0 ; i< len_s;i++)
    {
        c[i]=s[i];
    }

    for( i = 0 ;i< len_s;i++)
    {
        if(c[i]==SPACE)
        {
            q_s++;
        }
   //ui->line->setText(QString::number(q_s));
    }

int l=0;

    for(i =0 ; i< len_s;i++)
    {
        if(c[i]!='\n'&&c[i]!=SPACE)
      {
       checker=QString::number(MainWindow::exception(i));

       if(checker!="11")
       {
          l=0;
       }
          if(l==0)
          {
              if(checker=="11")
              {
                  lenta.push_back(11);
              }
              descriptor=descriptor + checker + " ";
              //qDebug()<<checker;
          }

           if(checker=="11")
           {
               l++;
           }
        }

    }
   /*    if(checker=="11")
        {
            if(d==0)
            {
            descriptor=descriptor+"11"+ " ";
            d++;
            }
        }

        if(c[i]==s9||c[i]==s1||c[i]==s10||c[i]==s13||c[i]==s14||c[i]==s17||c[i]==s18||c[i]==s20||c[i]==s210||c[i]==s220||c[i]==s230||c[i]==s3)
        {
           checker=QString::number(MainWindow::exception(i));
           descriptor=descriptor + checker + " ";
        }

         if(c[i]==s2||c[i]==s4||c[i]==s5||c[i]==s6||c[i]==s7||c[i]==s8||c[i]==s12||c[i]==s16||c[i]==s240||c[i]==s25||c[i]==s26||c[i]==s27)
         {
             checker=QString::number(MainWindow::exception(i));
             if(checker=="11")
             {
                 descriptor=descriptor+"11"+ " ";
             }
             else
             {
             descriptor=descriptor+checker+" ";
             }
         }
      }
    ui->line->setText(descriptor);

   */

ui->line->setText(descriptor);
    magazin2.push(0);
   magazin2.push(0);

    magazin2.push(1);
    //qDebug()<<Table[magazin2.top()][lenta.front()];
    //qDebug()<<lenta.front();
    //qDebug()<<Table[magazin2.top()][lenta.front()];
    while(Table[magazin2.top()][lenta.front()]>1)
    {
       //  qDebug()<<magazin2.last();
     MainWindow::working(Table[magazin2.top()][lenta.front()]);
       ui->textic->appendPlainText("Lenta"+ QString::number(lenta.front()) +"\t"+ "command"+ QString::number(Table[magazin2.top()][lenta.front()]));
       //qDebug()<<magazin2.last();
    }
    /*while (!lenta.isEmpty())
        qDebug() << lenta.dequeue();
*/
    descriptor="";
    //ui->textic->appendPlainText("Lenta"+ QString::number(0) +"\t"+ "command"+ QString::number(1));
}

void MainWindow::working(int g)
{
    switch(g)
    {

    case 2:
    {
        magazin2.pop();
        magazin2.push(3);
        magazin2.push(48);
        magazin2.push(2);
        break;
    }
     case 3:
    {
        magazin2.pop();
        magazin2.push(4);
        break;
    }
        case 4:
    {
        magazin2.pop();
        magazin2.push(8);
        magazin2.push(7);
        break;
    }
    case 5:
    {
        magazin2.pop();
        magazin2.push(5);
        break;
    }
    case 6:
    {
        magazin2.pop();
        magazin2.push(10);
        magazin2.push(9);
        break;
    }
    case 7:
    {
        magazin2.pop();
        magazin2.push(11);
        break;
    }
    case 8:
    {
        magazin2.pop();
        magazin2.push(12);
        break;
    }
    case 9:
    {
        magazin2.pop();
        magazin2.push(13);
        break;
    }
    case 10:
    {
        magazin2.pop();
        magazin2.push(14);
        break;
    }
    case 11:
    {
        magazin2.pop();
        magazin2.push(15);
        break;
    }
    case 12:
    {
        magazin2.pop();
         magazin2.push(16);
        break;
    }
    case 13:
    {
        magazin2.pop();
        magazin2.push(17);
        break;
    }
    case 14:
    {
        magazin2.pop();
         magazin2.push(18);
          magazin2.push(4);
        break;
    }
    case 15:
    {
        magazin2.pop();
        magazin2.
          magazin2.push(21);
           magazin2.push(20);
        break;
    }
    case 16:
    {
        magazin2.pop();
         magazin2.push(53);
          magazin2.push(23);
           magazin2.push(52);
            magazin2.push(22);
        break;
    }
    case 17:
    {
        magazin2.pop();
         magazin2.push(4);
        break;
    }
    case 18:
    {
        magazin2.pop();
         magazin2.push(24);
          magazin2.push(48);
           magazin2.push(24);
        break;
    }
    case 19:
    {
        magazin2.pop();
        magazin2.push(26);
        magazin2.push(25);
        break;
    }
    case 20:
    {
        magazin2.pop();
        magazin2.push(6);
        break;
    }
    case 21:
    {
        magazin2.pop();
        magazin2.push(27);
        break;
    }
    case 22:
    {
        magazin2.pop();
        magazin2.push(28);
        break;
    }
    case 23:
    {
        magazin2.pop();
        magazin2.push(29);
        break;
    }
    case 24:
    {
        magazin2.pop();
        magazin2.push(31);
        magazin2.push(4);
        break;
    }
    case 25:
    {
        magazin2.pop();
        magazin2.push(51);
        magazin2.push(33);
        magazin2.push(56);
        magazin2.push(32);
        break;
    }
    case 26:
    {
        magazin2.pop();
        magazin2.push(53);
        magazin2.push(24);
        magazin2.push(52);
        magazin2.push(4);
        break;
    }
    case 27:
    {
        magazin2.pop();
        magazin2.push(34);
        break;
    }
    case 28:
    {
        magazin2.pop();
        magazin2.push(36);
        magazin2.push(35);
        break;
    }
    case 29:
    {
        magazin2.pop();
        magazin2.push(24);
        break;
    }
    case 30:
    {
        magazin2.pop();
        magazin2.push(37);
        break;
    }
    case 31:
    {
        magazin2.pop();
        magazin2.push(4);
        break;
    }
    case 32:
    {
        magazin2.pop();
        lenta.pop_front();
        break;
    }
    case 33:
    {
        magazin2.pop();
        magazin2.push(24);
        break;
    }
    case 34:
    {
        magazin2.pop();
        magazin2.push(43);
        break;
    }
    case 35:
    {
        magazin2.pop();
        magazin2.push(24);
        break;
    }
    case 36:
    {
        magazin2.pop();
        magazin2.push(44);
        break;
    }
    case 37:
    {
        magazin2.pop();
        magazin2.push(45);
        magazin2.push(56);
        magazin2.push(32);
        break;
    }
    case 38:
    {
        magazin2.pop();
        magazin2.push(47);
        magazin2.push(46);
        break;
    }

    case 39:
    {
        magazin2.pop();
        magazin2.push(4);
        break;
    }
    case 40:
    {
        magazin2.pop();
        magazin2.push(50);
        qDebug()<<magazin2.last();
        magazin2.push(6);
        magazin2.push(49);
        magazin2.push(5);
        lenta.pop_front();
        break;
    }
    case 41:
    {
        magazin2.pop();
        break;
    }
    case 42:
    {
        magazin2.pop();
         magazin2.push(19);
         lenta.pop_front();
        break;
    }
    case 43:
    {
        magazin2.pop();
        break;
    }
    case 44:
    {
        magazin2.pop();
        magazin2.push(51);
        magazin2.push(55);
        magazin2.push(30);
        magazin2.push(54);
        lenta.pop_front();
        break;
    }
    case 45:
    {
        magazin2.pop();
        break;
    }
    case 46:
    {
        magazin2.pop();
        break;
    }
    case 47:
    {
        magazin2.pop();
        break;
    }
    case 48:
    {
        magazin2.pop();
        break;
    }
    case 49:
    {
        magazin2.pop();
        break;
    }
    case 50:
    {
        magazin2.pop();
        magazin2.push(51);
        magazin2.push(42);
        magazin2.push(59);
        magazin2.push(41);
        magazin2.push(58);
        magazin2.push(40);
        magazin2.push(57);
        magazin2.push(39);
        magazin2.push(56);
        magazin2.push(38);
        lenta.pop_front();
        break;
    }
    case 51:
    {
        magazin2.pop();
        magazin2.push(46);
        lenta.pop_front();
        break;
    }
    case 52:
    {
        magazin2.pop();
        lenta.pop_front();
        break;
    }
    case 53:
    {
        magazin2.pop();
        lenta.pop_front();
        break;
    }
    case 54:
    {
        magazin2.pop();
        lenta.pop_front();
        break;
    }
    case 55:
    {
        magazin2.pop();
        lenta.pop_front();
        break;
    }
    case 56:
    {
        magazin2.pop();
        lenta.pop_front();
        break;
    }
    case 57:
    {
        magazin2.pop();
        lenta.pop_front();
        break;
    }
    case 58:
    {
        magazin2.pop();
        lenta.pop_front();
        break;
    }
    case 59:
    {
        magazin2.pop();
        lenta.pop_front();
        break;
    }
    case 60:
    {
        magazin2.pop();
        lenta.pop_front();
        break;
    }
    case 61:
    {
        magazin2.pop();
        break;
    }
    case 62:
    {
        magazin2.pop();
        break;
    }
    case 63:
    {
        magazin2.pop();
        break;
    }
    case 64:
    {
        magazin2.pop();
        break;
    }
   }
}

int MainWindow::exception(int k)
{
  if(c[k]==s9)
  {
      lenta.push_back(9);
      return 9;
  }
  if(c[k]==s1)
  {
      if(c[k+1]==s100)
      {
          i++;
          d=0;
          lenta.push_back(19);
          return 19;
      }
      else
      {
          lenta.push_back(1);
      return 1;
      }
  }
  if(c[k]==s3)
  {
      i++;
      lenta.push_back(3);
      return 3;
  }
  if(c[k]==s10)
  {
      lenta.push_back(10);
      return 10;
  }
  if(c[k]==s13)
  {
lenta.push_back(13);
      return 13;
  }
  if(c[k]==s14)
  {
lenta.push_back(14);
      return 14;
  }
  if(c[k]==s15)
  {
  lenta.push_back(15);
      return 15;
  }
  if(c[k]==s17)
  {
   lenta.push_back(17);
      return 17;
  }
  if(c[k]==s18)
  {
lenta.push_back(18);
      return 18;
  }
  if(c[k]==s20)
  {
lenta.push_back(20);
      return 20;
  }
  if(c[k]==s210)
  {
lenta.push_back(21);
      return 21;
  }
  if(c[k]==s220)
  {
lenta.push_back(22);
      return 22;
  }
  if(c[k]==s230)
  {
lenta.push_back(23);
      return 23;
  }
  if(c[k]==s2)
  {

    if(c[k+1]==s21)
    {
        i++;
        if(c[k+2]==s22)
        {
            i++;
            if(c[k+3]==s23)
            {
                i++;
                if(c[k+4]==s24)
                {
                    i++;
                    d=0;
                    lenta.push_back(2);
                    return 2;
                }
            }
        }
    }
  }
  if(c[k]==s4)
  {

      if(c[k+1]==s41)
      {
          i++;
          if(c[k+2]==s42)
          {
              i++;
              d=0;
              lenta.push_back(4);
              return 4;
          }
      }
  }
  if(c[k]==s5)
  {

      if(c[k+1]==s51)
      {
          i++;
          if(c[k+2]==s52)
          {
              i++;
              if(c[k+3]==s53)
              {
                  i++;
                  d=0;
                  lenta.push_back(5);
                  return 5;
              }
          }
      }
  }
  if(c[k]==s6)
  {

      if(c[k+1]==s61)
      {
          i++;
          if(c[k+2]==s62)
          {
              i++;
              if(c[k+3]==s63)
              {
                  i++;
                  if(c[k+4]==s64)
                  {
                      i++;
                      if(c[k+5]==s63)
                      {
                          i++;
                          if(c[k+6]==s65)
                          {
                              i++;
                              d=0;
                              lenta.push_back(6);
                              return 6;
                          }
                      }
                  }
              }
          }
      }
  }

  if(c[k]==s7)
  {

      if(c[k+1]==s71)
      {
          i++;
          if(c[k+2]==s72)
          {
              i++;
              if(c[k+3]==s73)
              {
                  i++;
                  if(c[k+4]==s74)
                  {
                      i++;
                      d=0;
                      lenta.push_back(7);
                     return 7;
                  }
              }
          }
      }
  }

  if(c[k]==s8)
  {

      if(c[k+1]==s81)
      {
          i++;
          if(c[k+2]==s81)
          {
              i++;
              if(c[k+3]==s82)
              {
                  i++;
                  d=0;
                  lenta.push_back(8);
                  return 8;
              }
          }
      }
  }

  if(c[k]==s12)
  {

      if(c[k+1]==s121)
      {
          i++;
          if(c[k+2]==s121)
          {
              i++;
              if(c[k+3]==s12)
              {
                  i++;
                  if(c[k+4]==s122)
                  {
                      i++;
                      d=0;
                      lenta.push_back(12);
                      return 12;
                  }
              }
          }
      }
  }

  if(c[k]==s16)
  {

      if(c[k+1]==s161)
      {
          i++;
          if(c[k+2]==s162)
          {
              i++;
              if(c[k+3]==s163)
              {
                  i++;
                  if(c[k+4]==s161)
                  {
                      i++;
                      if(c[k+5]==s162)
                      {
                          i++;
                          d=0;
                          lenta.push_back(16);
                          return 16;
                      }
                  }
              }
          }
      }
  }

  if(c[k]==s240)
  {

      if(c[k+1]==s241)
      {
          i++;
          if(c[k+2]==s242)
          {
              i++;
              d=0;
              lenta.push_back(24);
              return 24;
          }
      }
  }

  if(c[k]==s25)
  {

      if(c[k+1]==s251)
      {
          i++;
          if(c[k+2]==s252)
          {
              i++;
              if(c[k+3]==s253)
              {
                  i++;
                  d=0;
                  lenta.push_back(25);
                  return 25;
              }
          }
      }
  }

  if(c[k]==s26)
  {

      if(c[k+1]==s261)
      {
          i++;
          if(c[k+2]==s262)
          {
              i++;
              if(c[k+3]==s263)
              {
                  i++;
                  if(c[k+4]==s264)
                  {
                      i++;
                      d=0;
                      lenta.push_back(26);
                      return 26;
                  }
              }
          }
      }
  }

  if(c[k]==s27)
  {

      if(c[k+1]==s271)
      {
          i++;
          d=0;
          lenta.push_back(27);
          return 27;
      }
  }

  if(c[k]==s28)
  {

      if(c[k+1]==s281)
      {
          i++;
          if(c[k+2]==s282)
          {
              i++;
              d=0;
              lenta.push_back(28);
              return 28;
          }
      }
  }
  if(c[k]=='0'||c[k]=='1'||c[k]=='2'||c[k]=='3'||c[k]=='4'||c[k]=='5'||c[k]=='6'||c[k]=='7'||c[k]=='8'||c[k]=='9')
  {
      lenta.push_back(15);
      return 15;
  }
  return 11;
}


