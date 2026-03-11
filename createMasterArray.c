#include"headers.h"
#include"dataStructures.h"
#include"declarations.h"

void* createMasterArray(void *arg)
{
	int fd,fsize,ret;
	DSUnique dsu;
#ifdef DEBUG
	printf("%s: %d: Begin\n",__func__,__LINE__); 
#endif
	
	fd = *(int*)arg;
	fsize=lseek(fd,0,SEEK_END)-1;
        if(fsize==-1)
        {
                perror("lseek");
                (*afp[1])((void*)"failure");	//exitProject()
        }
        printf("%s: File size is: %d\n",__func__,fsize);
	lseek(fd,0,SEEK_SET);
	dsu.ma = (char*)malloc(128);
	if(!dsu.ma)
	{
		perror("malloc");
		close(fd);
                (*afp[1])((void*)"failure");	//exitProject()
	}
	memset(dsu.ma, '\0', 128);
	dsu.size = 0;
	while(fsize > 0)
	{
		ret = read(fd, &dsu.ch, 1);
		if(ret == -1)
		{
			perror("read");
        	        (*afp[1])((void*)"failure");	//exitProject()
		}
		if ( *(int*)(*afp[8])((void*)&dsu) )	//unique()
		{
			*(dsu.ma+dsu.size++) = dsu.ch;
		}
		fsize--;
	}
	*(dsu.ma+dsu.size) = '\0';

#ifdef DEBUG 
	printf("%s: %d: End. \n",__func__,__LINE__);
#endif
	return (void*)dsu.ma;
}
