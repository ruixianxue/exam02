typedef struct  s_point
{
    int x;
    int y;
}               t_point;

void    fill(char **tab, t_point size, char target, int x, int y)
{
    if (x < 0 || x >= size.x || y < 0 || y >= size.y || \
        tab[y][x] == 'F' || tab[y][x] != target)
        return ;
    tab[y][x] = 'F';
    fill(tab, size, target, x + 1, y);
    fill(tab, size, target, x - 1, y);
    fill(tab, size, target, x, y + 1);
    fill(tab, size, target, x, y - 1);
}

void    flood_fill(char **tab, t_point size, t_point begin)
{
    char    target = tab[begin.y][begin.x];
    fill(tab, size, target, begin.x, begin.y);
}
