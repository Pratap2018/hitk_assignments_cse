
## Code compilation steps 

:octocat:

#### Step 1: Source code => Preprocessed Source code 

> gcc -E sample.c > sample.i

It generates Preprocessed Code (extension is [filename.i] ) 

#### Step 2: Preprocessed Source code =>  Assembly Code 

> gcc -S sample.i 

It generates Preprocessed Code (extension is filename.s)

#### Step 3: Assembly code => Object File

> gcc -c sample.s -o sample.o 
	OR
> ar  sample.s -o sample.o

It will create the object file from the assembly code .

#### Step 4: ObjectFile  =>  Executable binary 

> gcc sample.o -o sample 

It will create executable file 

Now simply run the binary by
> ./sample  