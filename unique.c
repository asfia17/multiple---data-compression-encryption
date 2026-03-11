#include"headers.h"
#include"dataStructures.h"
#include"declarations.h"

void* unique(void *arg)
{
	int i;
	DSUnique *pdu;

#ifdef DEBUG
//        printf("%s: %d: Begin\n",__func__,__LINE__); 
#endif
	pdu = (DSUnique*)arg;
	val = 1;

	if(pdu->size == 0)
		val = 1;
	for(i=0; i<pdu->size; i++)
	{
		if(pdu->ch == *(pdu->ma+i))
			val =  0;
	}

#ifdef DEBUG 
  //       printf("%s: %d: End. \n",__func__,__LINE__);
#endif
        return (void*)&val;
}

