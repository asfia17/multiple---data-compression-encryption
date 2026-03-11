#include"headers.h"
#include"dataStructures.h"
#include"declarations.h"

void* deCompression(void *arg)
{
	int fd,ret,cl;
	DSCompress ddc;

#ifdef DEBUG
	printf("%s: %d: Begin\n",__func__,__LINE__); 
#endif

	printf("%s: %d: Input Encryption Key File:\n",__func__,__LINE__);
	getchar();
	ddc.fd = *(int*)(*afp[6])((void*)"reading");	//openFile()
	printf("%s: %d: Encryption Key found fd:%d\n",__func__,__LINE__,ddc.fd);
	ddc.ma = (char*)malloc(128);
	if(!ddc.ma)
	{
		perror("malloc");
		(*afp[1])((void*)"failure");	//exitProject()
	}
	memset(ddc.ma, '\0', 128);

	ret = read(ddc.fd, ddc.ma, 128);
	if(ret == -1)
	{
		perror("read");
		(*afp[1])((void*)"failure");    //exitProgram()
	}

	printf("%s: %d: MasterArray:%s\n",__func__,__LINE__,ddc.ma);
	close(ddc.fd);

	printf("%s: %d: Give the name of compressed file to DeCompress:\n",__func__,__LINE__);
	ddc.fd = *(int*)(*afp[6])((void*)"reading");        //openFile()
	printf("%s: %d: Compressed File Opened. fd:%d\n",__func__,__LINE__,ddc.fd);

	cl = *(int*)(*afp[9])((void*)ddc.ma);	//codeLength()
	printf("%s: %d code Length:%d\n",__func__,__LINE__,cl);
	
	if((cl>=2) && (cl<=7))
		(*afp[cl+15])((void*)&ddc);
	else 
	{
		printf("%s: %d: ERROR:Function call\n",__func__,__LINE__);
		(*afp[1])((void*)"failure");    //exitProgram()
		
	}
	close(ddc.fd);

#ifdef DEBUG 
	printf("%s: %d: End \n",__func__,__LINE__);
	
#endif
	return 0;
}
