#ifndef _WEB_H_
#define _WEB_H_

#include "tile.h"
#include "color.h"
#include "board.h"

#define BORDER_SIZE 8
#define CELL_SIZE 20

void web_export(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD]);

#endif //_WEB_H_
