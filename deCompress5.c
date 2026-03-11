#include "headers.h"
#include "dataStructures.h"
#include "declarations.h"

void* deCompress5(void *arg)
{
	int i, ret, dfd, fsize;
	unsigned char ch,c,dc,byt;
	DSCompress *pdd;
#ifdef DEBUG
	printf("%s: %d: Begin\n",__func__, __LINE__);
#endif

	pdd = (DSCompress*)arg;

	printf("%s: %d: Give Name to 5-bit DeCompress file:\n", __func__, __LINE__);
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
		c>>=3;
		i^=i;
		i= (unsigned int)c;
		dc=*(pdd->ma+i);
		if(write(dfd,&dc,1)==-1)                               //write 1
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		c=ch;
		c<<=5;
		c>>=3;
		byt|=c;
		if(read(pdd->fd,&ch,1)==-1)		//read 2
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		c=ch;
		c>>=6;
		c=byt|c;
		if(c == 31)
			break;
		i^=i;
		i=(unsigned int)c;
		dc=*(pdd->ma+i);
		if(write(dfd,&dc,1)==-1)                               //write 2
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		c=ch;
		c<<=2;
		c>>=3;
		if(c == 31)
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
		c<<=7;
		c>>=3;
		byt^=byt;
		byt=c;		//000a0000
		if(read(pdd->fd,&ch,1)==-1)		//read 3
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		c=ch;
		c>>=4;
		c=byt|c;		//000abcde
		if(c == 31)
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
		c>>=3;
		byt^=byt;
		byt=c;
		if(read(pdd->fd,&ch,1)==-1)		//read 4
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}

		fsize--;
		c=ch;
		c>>=7;
		c=byt|c;
		if(c == 31)
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
		c<<=1;
		c>>=3;
		if(c == 31)
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
		c<<=6;
		c>>=3;
		byt^=byt;
		byt=c;
		if(read(pdd->fd,&ch,1)==-1)		//read 5
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		c=ch;
		c>>=5;
		c=byt|c;
		if(c == 31)
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
		c<<=3;
		c>>=3;
		if(c == 31)
			break;
		i^=i;
		i=(unsigned int)c;
		dc=*(pdd->ma+i);
		if(write(dfd,&dc,1)==-1)                               //write 8
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}

	}
	close(dfd);
#ifdef DEBUG
	printf("%s: End\n",__func__);
#endif
	return 0;
}
