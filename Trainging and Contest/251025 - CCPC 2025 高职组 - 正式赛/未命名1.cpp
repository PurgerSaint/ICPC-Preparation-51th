#include <stdio.h>
int main()
{
    int a, b, c, s;
    a=1;
    b=2;
    c=3;
    s=5*6;

    printf("%d, %d, %d\n", a++, b--, ++c);
    printf("a=%d, b=%d, c=%d\n", a, b, c);

    printf("%d, s=%d\n", a+b+c, s=5*6 );
    printf("%f",a);
    return 0;
}

