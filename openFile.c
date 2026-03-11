#include"headers.h"
#include"declarations.h"

void* openFile(void *arg)
{
	int i;
	char *filename, *mode;
#ifdef DEBUG
	printf("%s: %d: Begin\n",__func__,__LINE__); 
#endif
	mode = arg;

	filename = (char*)malloc(20);
	if(!filename)
	{
		perror("malloc");
		(*afp[1])((void*)"failure");    //exitProgram()
	}
	memset(filename, '\0', 20);
	i = 0;
	val = -1;
	do
	{
		*(filename+i) = getchar();
		if(*(filename+i) == '\n')
			break;
		i++; 
	}while(1);
	*(filename+i)='\0';
	if(strncmp((char*)mode,"writing",7) == 0)
		val = open(filename, O_WRONLY);
	else if(strncmp((char*)mode,"reading",7) == 0)
		val = open(filename, O_RDONLY);
	else if(strncmp((char*)mode,"creating",8) == 0)
		val = open(filename, O_CREAT|O_WRONLY);
	else
		printf("%s: Invalid file open mode\n",__func__);
	if(val == -1)
	{
		perror("open");
		(*afp[1])((void*)"failure");    //exitProgram()
	}
	free(filename);

#ifdef DEBUG 
	printf("%s: %d: End. \n",__func__,__LINE__);
#endif
	return (void*)&val;
}
