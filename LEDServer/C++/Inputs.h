#include "stdio.h"
#include "stdlib.h"

class Inputs
{
public:
	Inputs(void);
	~Inputs(void);

	static void staticclassfunction(int i){
    printf("Static Class (%i)\n", i);
  }
};
