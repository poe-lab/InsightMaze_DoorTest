#ifndef GLOBAL_H
#define GLOBAL_H

const int PIN_ID = A7;

const int PIN_DOOR_0 = 3;
const int PIN_DOOR_1 = 5;
const int PIN_DOOR_2 = 6;
const int PIN_DOOR_3 = 9;
const int PIN_DOOR_4 = 10;
const int PIN_DOOR_5 = 11;

// In order of Sector. 0 being opening, 1 being Main 1, 2 being Main 2, 3 being end sector.
// OPEN HEIGHT, CLOSE HEIGHT
const int POS_D0[][2] = {{138,70},  {38,108}, {158,87},  {150,50}};
const int POS_D1[][2] = {{145,80},  {50,136}, {175,95},  {50,160}};
const int POS_D2[][2] = {{155,80},  {18,83} , {8,80},    {45,160}};
const int POS_D3[][2] = {{145,80},  {33,101}, {175,110}, {150,50}};
const int POS_D4[][2] = {{10,70},   {131,63}, {7,75},    {90,0}};
const int POS_D5[][2] = {{170,100}, {165,94}, {106,29},  {150,50}};


#endif GLOBAL_H