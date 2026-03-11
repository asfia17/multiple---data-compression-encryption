#include"headers.h"
#include"dataStructures.h"
#include"declarations.h"

void* compress4(void *arg)
{
	unsigned char c, byt;
	int i, fsize, ret, l, cfd,flag;
	char *compfile;
	DSCompress *pdc;
	DSFindloc dfl;
#ifdef DEBUG
        printf("%s: %d: B0egin\n",__func__,__LINE__); 
#endif

	pdc = (DSCompress*)arg;

	fsize = lseek(pdc->fd, 0, SEEK_END)-1;
	lseek(pdc->fd, 0, SEEK_SET)-1;
	dfl.ma = pdc->ma;
        printf("%s: %d: Give name to 4-bit compressed file: \n",__func__,__LINE__); 
	cfd = *(int*)(*afp[6])((void*)"creating");	//openFile()
	while(fsize > 0)
	{
		byt ^= byt;
		ret =read(pdc->fd, &dfl.ch, 1);
		if(ret == -1)
		{
			perror("read");
			(*afp[1])((void*)"failure");    //exitProgram()
		}
		fsize--;
		l = *(int*)(*afp[16])((void*)&dfl);     //findLocation()
		c = (char)l;
		c <<= 4;
		byt |= c;
		if(fsize == 0)
		{
			byt |=0x0F;	
			goto WRITE;
		}

		ret = read(pdc->fd, &dfl.ch, 1);
		if(ret == -1)
		{
			perror("read");
			(*afp[1])((void*)"failure");    //exitProgram()
		}
		fsize--;
		l = *(int*)(*afp[16])((void*)&dfl);	//findLocation()
		c = (char)l;
		c <<= 4;
		c >>= 4;
		byt |= c;
		if(fsize == 0)
		{
			flag = 1;
			goto WRITE;
		}
WRITE:
		ret = write(cfd, &byt, 1);
		if(ret == -1)
		{
			perror("write");
			(*afp[1])((void*)"failure");    //exitProgram()
		}
		if(flag == 1)
		{
			byt ^= byt;
			byt |= 0xF0;
			ret = write(cfd, &byt, 1);
			if(ret == -1)
			{	
				perror("write");
				(*afp[1])((void*)"failure");    //exitProgram()
			}
		}
	}
        printf(" %d: cfd \n",cfd);

	close(cfd);
#ifdef DEBUG 
        printf("%s: %d: End. \n",__func__,__LINE__);
#endif
        return 0;
}

