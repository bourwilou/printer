# printer
a basic and limited print like python function in c/11 
## exemple 
``` c
#include "printer.h"

int main(void)
{
	print(0,"-------------begin------------ \n");
	print(2,"hello {} from {} \n","WORLD","PRINTER");

	for (int i = 0; i < 10; ++i)
	{
		print(2,"{}+1 = {} \n",i,i+1);
	}
	print(1,"this is %{} escaped and not this {} \n","\"test\"");
	return 0;
}
```
