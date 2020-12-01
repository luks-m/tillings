#include <stdio.h>
#include <stdlib.h>
#include "web.h"
 
void web_export(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD])
{
  FILE* fd = fopen("output.html", "w");
 
  fprintf(fd, "<!DOCTYPE html>\n");
  fprintf(fd, "<html>\n");
  fprintf(fd, "\t<head>\n");
  fprintf(fd, "\t\t<title>Tilings</title>\n");
  fprintf(fd, "\t\t<meta charset=\"utf-8\">\n");
  fprintf(fd, "\t</head>\n");
  fprintf(fd, "\t<body>\n");
 
  fprintf(fd, "\t\t<table style=\"border: solid 1px black;\">\n");
  for (unsigned y = 0; y < MAX_SIZE_BOARD; y++)
    {
      fprintf(fd, "\t\t\t<tr>\n");
      for (unsigned x = 0; x < MAX_SIZE_BOARD; x++)
        {
			if (tile(b,x,y) != NULL)
            {
	      fprintf(
		      fd,
		      "\t\t\t\t\t<td style=\"padding: 0; width: 0; height: 0; border-left: %dpx solid %s; border-right: %dpx solid %s; border-bottom: %dpx solid %s; border-top: %dpx solid %s;\">%d</td>\n",
		      BORDER_SIZE,
		      color_name(tile_edge(tile(b,x,y), WEST)),
		      BORDER_SIZE,
		      color_name(tile_edge(tile(b,x,y), EAST)),
		      BORDER_SIZE,
		      color_name(tile_edge(tile(b,x,y), SOUTH)),
		      BORDER_SIZE,
		      color_name(tile_edge(tile(b,x,y), NORTH)),
			  owner(b, x, y)
		      );
            }
			else
            {
	      fprintf(
		      fd,
		      "\t\t\t\t\t<td style=\"padding: 0; width: 0; height: 0; border-left: %dpx solid transparent; border-right: %dpx solid transparent; border-bottom: %dpx solid transparent; border-top: %dpx solid transparent;\"></td>\n",
		      BORDER_SIZE,
		      BORDER_SIZE,
		      BORDER_SIZE,
		      BORDER_SIZE
		      );
            }
        }
      fprintf(fd, "\t\t\t</tr>\n");
    }
  fprintf(fd, "\t\t</table>\n");
  fprintf(fd, "\t</body>\n");
  fprintf(fd, "</html>");
 
  fclose(fd);
}
