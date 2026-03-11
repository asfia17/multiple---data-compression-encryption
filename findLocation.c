#include"headers.h"
#include"dataStructures.h"
#include"declarations.h"

void* findLocation(void *arg)
{
	int len;
	DSFindloc *pdf;
#ifdef DEBUG
//	printf("%s: %d: Begin\n",__func__,__LINE__); 
#endif
	pdf = (DSFindloc*)arg;

	len = strlen(pdf->ma);
	for(val=0; val<len; val++)
	{
		if(pdf->ch == *(pdf->ma+val))
			return (void*)&val;
	}
        printf("%s: %d: ERROR: character Not Found in the master array\n",__func__,__LINE__);
	(*afp[1])((void*)"failure");      //exitProject()
#ifdef DEBUG 
  //      printf("%s: %d: End. \n",__func__,__LINE__);
#endif
        return 0;
}

