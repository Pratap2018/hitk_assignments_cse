#include<stdio.h>

void new_func1(void);

void func1(void)

{

printf("\nInside func1\n");

int i = 0;

for(;i<0xffffffff;i++);

new_func1();

return;

}
static void func2(void)

{

printf("\nInside func2\n");

int i = 0;

for(;i<0xffffffaa;i++);

return;

}
int main(void)

{

printf("\nInside main()\n");

int i = 0;

for(;i<0xffffff;i++);

func1();

func2();

return 0;

}
