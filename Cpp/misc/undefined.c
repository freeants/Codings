/*
    This program generates undefied behavior.
*/

int main(int argc, char const *argv[])
{
    unsigned long a[1];
    a[3] = 0x7ffff7b36cebUL;
    return 0;
}
