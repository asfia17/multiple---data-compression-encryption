#include "headers.h"
#include "dataStructures.h"
#include "declarations.h"

void* deCompress3(void *arg)
{
	int ret, dfd, fsize,i2;
	unsigned char ch,c,c1,dc,c2,byt;
	unsigned int i;
	DSCompress *pdd;
#ifdef DEBUG
	printf("%s: %d: Begin\n",__func__, __LINE__);
#endif

	pdd = (DSCompress*)arg;

	printf("%s: %d: Give Name to 3-bit DeCompress file:\n", __func__, __LINE__);
	dfd = *(int*)(*afp[6])((void*)"creating");
	fsize = lseek(pdd->fd, 0, SEEK_END)-1;
	lseek(pdd->fd, 0, SEEK_SET);


	while(fsize>0)
	{
		byt^=byt;
		if(read(pdd->fd,&ch,1)==-1)                //read 1
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		c=ch;
		c>>=5;
		i^=i;
		i= (unsigned int)c;
		dc=*(pdd->ma+i);
		if(write(dfd,&dc,1)==-1)                               //write 1
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		c=ch;
		c<<=3;
		c>>=5;
		if(c==0x07)
		{
			break;
		}
		i^=i;
		i=(unsigned int)c;
		dc=*(pdd->ma+i);
		if(write(dfd,&dc,1)==-1)                               //write 2
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		c=ch;
		c<<=6;
		c>>=5;
		byt|=c;
		if(read(pdd->fd,&ch,1)==-1)
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		c=ch;
		c>>=7;
		c=byt|c;
		if(c == 0x07)
			break;
		i^=i;
		i=(unsigned int)c;
		dc=*(pdd->ma+i);
		if(write(dfd,&dc,1)==-1)                               //write 3
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		c=ch;
		c<<=1;
		c>>=5;
		if(c == 0x07)
			break;
		i^=i;
		i=(unsigned int)c;
		dc=*(pdd->ma+i);
		if(write(dfd,&dc,1)==-1)                               //write 4
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		c=ch;
		c<<=4;
		c>>=5;
		if(c == 0x07)
			break;
		i^=i;
		i=(unsigned int)c;
		dc=*(pdd->ma+i);
		if(write(dfd,&dc,1)==-1)                               //write 5
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		c=ch;
		c<<=7;
		c>>=5;
		byt^=byt;
		byt|=c;
		if(read(pdd->fd,&ch,1)==-1)
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		c=ch;
		c>>=6;
		c=byt|c;
		if(c == 0x07)
			break;
		i^=i;
		i=(unsigned int)c;
		dc=*(pdd->ma+i);
		if(write(dfd,&dc,1)==-1)                               //write 6
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		c=ch;
		c<<=2;
		c>>=5;
		if(c == 0x07)
			break;
		i^=i;
		i=(unsigned int)c;
		dc=*(pdd->ma+i);
		if(write(dfd,&dc,1)==-1)                               //write 7
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		c=ch;
		c<<=5;
		c>>=5;
		if(c == 0x07)
			break;
		i=(unsigned int)c;
		dc=*(pdd->ma+i);
		if(write(dfd,&dc,1)==-1)                               //write 8
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
	}
	close(dfd);
	printf("%s: End\n",__func__);
	return 0;
}
