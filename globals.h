#ifndef GLOBAL_H
#define GLOBAL_H

const int PIN_ID = A7;

const int PIN_DOOR_0 = 3;
const int PIN_DOOR_1 = 5;
const int PIN_DOOR_2 = 6;
const int PIN_DOOR_3 = 9;
const int PIN_DOOR_4 = 10;
const int PIN_DOOR_5 = 11;

const int POS_D0[] = {150, 50};
const int POS_D1[] = {50, 160};
const int POS_D2[] = {45, 160};
const int POS_D3[] = {150, 50};
const int POS_D4[] = {90, 0};
const int POS_D5[] = {150, 50};


#endif // GLOBAL_H

//doors cannot be allowed to close too far because they go beyond the guide rails
//backwards means the door is opening when reported as closed and vice versa

//start module d0 is backwards 
//start module d1 is closing too far
//start module d2 is closing too far
//start module d3 is backwards like d0
//start module d4 is closing too far
//start module d5 is backwards
