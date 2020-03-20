#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "gameUtils.h"

#pragma region º¯ÊýÁÐ±í

void initMap(char *p_map)
{
	char (*p_row)[COLUMN];
	for (p_row = p_map; p_row < p_map + ROW; p_row++)
	{
		for (char **p_col = p_row; **p_col < p_row + COLUMN; **p_col++)
			**p_col = "¨ˆ";
	}
}

#pragma endregion
