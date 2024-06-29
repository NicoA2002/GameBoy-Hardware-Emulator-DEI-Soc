#include <stdint.h>

#define GB_TEST_FRAME_COUNT 4
#define GB_TEST_FRAME_WIDTH 8
#define GB_TEST_FRAME_HEIGHT 8

/* Piskel data for "GB_TEST" */

//tiles
static const uint8_t tile_map[360] = {
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,2,2,
2,2,2,3,3,2,2,2,2,2,2,2,2,2,2,3,3,3,3,2,
2,2,3,3,3,3,3,2,2,2,2,2,2,2,2,2,3,3,3,2,
2,2,2,3,3,2,2,2,2,2,2,2,2,2,2,2,2,3,3,2,
2,2,2,2,2,2,2,2,2,2,2,3,3,3,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,2,2,2,2,2,
2,2,2,3,2,2,2,2,2,2,2,3,3,3,2,2,2,2,2,2,
2,2,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
2,2,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,0,1,0,2,2,2,2,2,2,2,
0,0,0,0,0,2,2,0,0,0,1,1,1,0,0,0,0,0,0,0,
1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1};

static const uint8_t tile_data[4][64] = {
{
2, 2, 2, 2, 2, 2, 2, 2, 
2, 2, 2, 2, 2, 2, 2, 2, 
1, 2, 0, 2, 2, 1, 2, 1, 
0, 0, 1, 2, 2, 0, 2, 0, 
0, 1, 0, 2, 2, 0, 2, 0, 
0, 0, 0, 0, 2, 0, 0, 1, 
0, 0, 0, 1, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0
},
{
0, 0, 0, 0, 0, 0, 0, 0, 
0, 1, 0, 0, 0, 0, 0, 1, 
0, 0, 0, 1, 0, 0, 0, 0, 
0, 1, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 1, 0, 
0, 1, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 1, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 1, 0, 0
},
{
2, 2, 2, 2, 2, 2, 2, 2, 
2, 2, 2, 2, 2, 2, 2, 2, 
2, 2, 2, 2, 2, 2, 2, 2, 
2, 2, 2, 2, 2, 2, 2, 2, 
2, 2, 2, 2, 2, 2, 2, 2, 
2, 2, 2, 2, 2, 2, 2, 2, 
2, 2, 2, 2, 2, 2, 2, 2, 
2, 2, 2, 2, 2, 2, 2, 2
},
{
3, 3, 3, 3, 3, 3, 3, 3, 
3, 3, 3, 3, 3, 3, 3, 3, 
3, 3, 3, 3, 3, 3, 3, 3, 
3, 3, 3, 3, 3, 3, 3, 3, 
3, 3, 3, 3, 3, 3, 3, 3, 
3, 3, 3, 3, 3, 3, 3, 3, 
3, 3, 3, 3, 3, 3, 3, 3, 
3, 3, 3, 3, 3, 3, 3, 3
}
};