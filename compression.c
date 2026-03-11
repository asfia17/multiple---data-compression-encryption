#include"headers.h"
#include"dataStructures.h"
#include"declarations.h"

void* compression(void *arg)
{
	int cl,ret,ekey;
	DSCompress dsc;
#ifdef DEBUG
	printf("%s: %d: Begin\n",__func__,__LINE__); 
#endif

	printf("%s: %d: Give the name of file to open compression:\n",__func__,__LINE__);
//	do{
	getchar();
	dsc.fd = *(int*)(*afp[6])((void*)"reading");	//openFile()
	printf("%s: Open file for compression. fd:%d\n",__func__,dsc.fd);

	dsc.ma =(char*)(*afp[7])((void*)&dsc.fd);	//crateMasterArray()
	printf("%s: MAster Array: %s\n",__func__,dsc.ma);

	cl = *(int*)(*afp[9])((void*)dsc.ma);	//codeLength()
	printf("%s: %d: CodeLength:%d\n",__func__,__LINE__,cl);

	lseek(dsc.fd, 0, SEEK_SET);

	if ( (cl>=2) && (cl<=7) )
		(*afp[cl+8])((void*)&dsc);	//compress2to7()
	else 
	{
		printf("%s: %d: ERROR:Function call\n",__func__,__LINE__);
		(*afp[1])((void*)"failure");	//exitProgram()
	}
	close(dsc.fd);

	printf("%s: %d: Give the name to Encryption Key file: \n",__func__,__LINE__);
	ekey = *(int*)(*afp[6])((void*)"creating");	//openFile()
	ret=write(ekey, dsc.ma, strlen(dsc.ma));
	if (ret==-1)
	{
		perror("write");
		(*afp[1])((void*)"failure");     //exitProgram()
	}
//	}while(1);
//	printf("%s: %d: Do You Want to Compress more(y/n) \n",__func__,__LINE__);

	
	close(ekey);
#ifdef DEBUG 
	printf("%s: %d: End \n",__func__,__LINE__);
	
#endif
	return 0;
}
