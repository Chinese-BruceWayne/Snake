#pragma once
#include "Snake.h"

extern long long *Map;

static const long long ww = (1<<28)|1;
static const long long cw = (1<<28)|(1<<14)|1;
static const long long rw = ~(~0<<28)^(1<<13)^(1<<15)^(1<<14);

extern long long MapBit0[];
extern long long MapBit1[];
extern long long MapBit2[];

extern inline long long Mask(int shift);
bool ReadMapPoint(long long *parmap, int x, int y);
int ReadMap(Obstacle **o, long long *parmap, int row, int col);