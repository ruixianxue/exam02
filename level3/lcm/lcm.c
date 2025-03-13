unsigned int    lcm(unsigned int a, unsigned int b)
{
    int g = (a > b) ? a : b;
    if (a == 0 || b == 0)
        return (0);
    while (1)
    {
        if (g % a == 0 && g % b == 0)
            return (g);
        g++;
    }
}
