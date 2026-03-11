#include"headers.h"
#include"declarations.h"

void* codeLength(void *arg)
{
	int len;
	char *ma;
#ifdef DEBUG
        printf("%s: %d: Begin\n",__func__,__LINE__); 
#endif
	ma = (char*)arg;
	len = strlen(ma);

	if(len < 4)
		val = 2;
	else if(len < 8)
		val = 3;
	else if(len < 16)
		val = 4;
	else if(len < 32)
		val = 5;
	else if(len < 64)
		val = 6;
	else if(len < 128)
		val = 7;

#ifdef DEBUG 
        printf("%s: %d: End. \n",__func__,__LINE__);
#endif
        return (void*)&val;
}

