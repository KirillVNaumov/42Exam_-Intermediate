#include <stdlib.h>
#include <stdio.h>
#include "t_point.h"

void    fill(char **tab, t_point size, t_point begin, char point)
{
    if (!(begin.x < size.x && begin.y < size.y && begin.x >= 0 && begin.y >= 0))
        return ;
    if (point != tab[begin.y][begin.x])
        return ;
    tab[begin.y][begin.x] = 'F';
    begin.x = begin.x - 1; // 6 4
    fill(tab, size, begin, point);
    begin.x = begin.x + 2; // 8 4
    fill(tab, size, begin, point);
    begin.x = begin.x - 1;
    begin.y = begin.y - 1; // ?(7 3) 8 3
    fill(tab, size, begin, point);
    begin.y = begin.y + 2;
    fill(tab, size, begin, point);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    if (!(begin.x < size.x && begin.y < size.y && begin.x >= 0 && begin.y >= 0))
        return ;
    fill(tab, size, begin, tab[begin.y][begin.x]);
}

char** make_area(char** zone, t_point size)
{
        char** new;

        new = malloc(sizeof(char*) * size.y);
        for (int i = 0; i < size.y; ++i)
        {
                new[i] = malloc(size.x + 1);
                for (int j = 0; j < size.x; ++j)
                        new[i][j] = zone[i][j];
                new[i][size.x] = '\0';
        }

        return new;
}

int main(void)
{
        t_point size = {8, 5};
        char *zone[] = {
                "11111111",
                "10001001",
                "10010001",
                "10110001",
                "11100001",
        };

        char**  area = make_area(zone, size);
        for (int i = 0; i < size.y; ++i)
                printf("%s\n", area[i]);
        printf("\n");

        t_point begin = {6, 4};
        flood_fill(area, size, begin);
        for (int i = 0; i < size.y; ++i)
                printf("%s\n", area[i]);
        return (0);
}