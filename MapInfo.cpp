#include "MapInfo.h"

long long *Map = MapBit2;

long long MapBit0[]=
{
	~(~0<<29),
	ww,ww,ww,ww,ww,ww,ww,ww,ww,ww,ww,ww,ww,ww,ww,ww,	//16
	ww,ww,ww,ww,ww,ww,ww,ww,							//8
	~(~0<<29)
};
long long MapBit1[]=
{
	~(~0<<29),
	cw,cw,cw,ww,ww,cw,cw,cw,ww,ww,cw,cw,cw,cw,ww,ww,	//16
	cw,cw,cw,ww,ww,cw,cw,cw,							//8
	~(~0<<29)
};
long long MapBit2[]=
{
	~(~0<<29),
	cw,cw,cw,cw,cw,cw,cw,cw,cw,rw,ww,ww,				//12
	ww,ww,rw,cw,cw,cw,cw,cw,cw,cw,cw,cw,				//12
	~(~0<<29)
};

inline long long Mask(int shift){ return 1<<shift; }

bool ReadMapPoint(long long *parmap, int x, int y)
{
	return parmap[y] & Mask(x);
}

int ReadMap(Obstacle **o, long long *parmap, int row, int col)
{
	int oNum = 0;
	for( int j=0; j<row; ++j )
		for( int i=0; i<col; ++i)
			if( ReadMapPoint(parmap,i,j) ) oNum++;
	*o = new Obstacle[oNum];
	int pos = 0;
	for( int j=0; j<row; ++j )
		for( int i=0; i<col; ++i)
			if( ReadMapPoint(parmap,i,j) )
			{
				(*o)[pos].x = i*2;
				(*o)[pos].y = j;
				pos++;
			}
	return oNum;
}
