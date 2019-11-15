#### Software_tools_lab HITK
~Compile~ with -g 
eg.
```
gcc -g -o [outfilename] [source]
```
Invoke gdb  
```
gdb ./[outfilename]
```
----
```
b main - Puts a breakpoint at the beginning of the program

b - Puts a breakpoint at the current line

b N - Puts a breakpoint at line N

b +N - Puts a breakpoint N lines down from the current line

b fn - Puts a breakpoint at the beginning of function "fn"

d N - Deletes breakpoint number N

info break - list breakpoints

r - Runs the program until a breakpoint or error

c - Continues running the program until the next breakpoint or error

f - Runs until the current function is finished

s - Runs the next line of the program

s N - Runs the next N lines of the program

n - Like s, but it does not step into functions

u N - Runs until you get N lines in front of the current line

p var - Prints the current value of the variable "var"

bt - Prints a stack trace

u - Goes up a level in the stack

d - Goes down a level in the stack

q - Quits gdb
```

##### factorial.c

```
pratap@pratap-desktop:~/hitk_assignments_cse/software_tools_lab/gdb$ gcc -g -o factorial factorial.c
pratap@pratap-desktop:~/hitk_assignments_cse/software_tools_lab/gdb$ gdb ./factorial

(gdb) l
1       #include<stdio.h>
2       int main(){
3               int i,num,j;
4               printf("Enter the number : ");
5               scanf("%d",&num);
6               for(i=1;i<num;i++){
7                       j*=i;
8               }
9               printf("The factorial of %d os %d \n",num,j);
10      }
(gdb) b 3
Breakpoint 1 at 0x731: file factorial.c, line 3.
(gdb) b 4
Note: breakpoint 1 also set at pc 0x731.
Breakpoint 2 at 0x731: file factorial.c, line 4.
(gdb) r
Starting program: /home/pratap/hitk_assignments_cse/software_tools_lab/gdb/factorial 

Breakpoint 1, main () at factorial.c:4
4               printf("Enter the number : ");
(gdb) info locals 
i = -7184
num = 21845
j = 32767
(gdb) n
5               scanf("%d",&num);
(gdb) b
Breakpoint 3 at 0x555555554742: file factorial.c, line 5.
(gdb) n
Enter the number : 5
6               for(i=1;i<num;i++){
(gdb) n
7                       j*=i;
(gdb) info locals 
i = 1
num = 5
j = 32767
(gdb) c
Continuing.
The factorial of 5 os 786408 
[Inferior 1 (process 18578) exited normally]
(gdb) 

```


##### Segfault.c

```
l
1       #include <stdio.h>
2       int main()
3       {
4               int i;
5               int *p;
6               *p=25;
7               printf("i is %d and *p is %d",i,*p);
8               return 0;
9       }
(gdb) b 4
Breakpoint 1 at 0x652: file segfault.c, line 4.
(gdb) b 6
Note: breakpoint 1 also set at pc 0x652.
Breakpoint 2 at 0x652: file segfault.c, line 6.
(gdb) r
Starting program: /home/pratap/hitk_assignments_cse/software_tools_lab/gdb/segfault 

Breakpoint 1, main () at segfault.c:6
6               *p=25;
(gdb) watch i
Hardware watchpoint 3: i
(gdb) watch p
Hardware watchpoint 4: p
(gdb) watch *p
Hardware watchpoint 5: *p
(gdb) n

Program received signal SIGSEGV, Segmentation fault.
0x0000555555554656 in main () at segfault.c:6
6               *p=25;
(gdb) info locals 
i = 32767
p = 0x0
(gdb) n

Program terminated with signal SIGSEGV, Segmentation fault.
```


