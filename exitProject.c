#include"headers.h"
#include"declarations.h"

void* exitProject(void *arg)
{
	char *status;
#ifdef DEBUG
	printf("%s: %d: Begin \n",__func__,__LINE__);
#endif
	status = (char*)arg;

	if(strncmp (status, "success", 7) == 0)
		exit(EXIT_SUCCESS);	
	else if(strncmp (status, "failure", 7) == 0)
		exit(EXIT_FAILURE);
	else 	
		printf("%s: Error Invalid status!\n",__func__);
#ifdef DEBUG
	printf("%s: %d: End\n",__func__,__LINE__);
#endif
	return 0;
}
