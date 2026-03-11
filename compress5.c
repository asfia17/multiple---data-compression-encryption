#include"headers.h"
#include"dataStructures.h"
#include"declarations.h"

void* compress5(void *arg)
{
	unsigned char cc, byt,byt1,c;
	int i,ret,cfd;
	unsigned int loc, fsize;
	DSCompress *pdc;
	DSFindloc dfl;

#ifdef DEBUG
	printf("%s: %d: Begin\n", __func__, __LINE__);
#endif
	pdc = (DSCompress*)arg;
	fsize = lseek(pdc->fd, 0, SEEK_END)-1;
	lseek(pdc->fd, 0, SEEK_SET)-1;
	dfl.ma = pdc->ma;
	printf("%s: %d: Give name to 5-bit compressed file:\n",__func__,__LINE__);
	cfd = *(int*)(*afp[6])((void*)"creating");

	while(fsize>0)
	{
		byt^=byt;
		ret=read(pdc->fd,&dfl.ch,1);     //read 1
		if(ret==-1)
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		loc =*(int*)(*afp[16])((void*)&dfl);
		c=cc=(unsigned char)loc;
		c<<=3;
		byt|=c;
		if(fsize==0)
		{
			byt|=0x07;    // ccccc111
			goto WRITE;
			byt^=byt;
			byt=0xC0;	//11zzzzzz
			goto WRITE;
		}
		ret=read(pdc->fd,&dfl.ch,1);    // read 2
		if(ret==-1)
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		loc =*(int*)(*afp[16])((void*)&dfl);
		c=cc=(unsigned char)loc;
		c<<=3;
		c>>=5;
		byt|=c;
		ret = write(cfd, &byt, 1);	//write 1
		if(ret == -1)
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		byt^=byt;
		c=cc;
		c<<=6;
		byt|=c;
		if(fsize==0)
		{
			byt|=0x3E; // cc11111z
			goto WRITE;
		}
		ret=read(pdc->fd,&dfl.ch,1);     //read 3
		if(ret==-1)
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		loc =*(int*)(*afp[16])((void*)&dfl);
		c=cc=(unsigned char)loc;
		c<<=3;
		c>>=2;
		byt|=c;
		if(fsize==0)
		{
			byt|=0x01; // ccccccc1
			goto WRITE;
			byt^=byt;
			byt|= 0xF0; //1111zzzz
			goto WRITE;
		}
		ret=read(pdc->fd,&dfl.ch,1);        //read 4
		if(ret==-1)
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		loc =*(int*)(*afp[16])((void*)&dfl);
		c=cc=(unsigned char)loc;
		c<<=3;
		c>>=7;
		byt|=c;
		ret = write(cfd, &byt, 1);	//write 2
		if(ret == -1)
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		byt^=byt;
		c=cc;
		c<<=4;
		byt|=c;
		if(fsize==0)
		{
			byt|=0x0F;      //cccc1111
			goto WRITE;
			byt|= 0x80;    //1zzzzzz
			goto WRITE;
		}
		ret=read(pdc->fd,&dfl.ch,1);     //read 5
		if(ret==-1)
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		loc =*(int*)(*afp[16])((void*)&dfl);
		c=cc=(unsigned char)loc;
		c<<=3;
		c>>=4;
		byt|=c;
		ret = write(cfd, &byt, 1);	//write 3
		if(ret == -1)
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		byt^=byt;
		c=cc;
		c<<=7;
		byt|=c;
		if(fsize==0)
		{
			byt|=0x7C;    //c11111zz
			goto WRITE;
		}
		ret=read(pdc->fd,&dfl.ch,1);  // read 6
		if(ret==-1)
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		loc =*(int*)(*afp[16])((void*)&dfl);
		c=cc=(unsigned char)loc;
		c<<=3;
		c>>=1;
		byt|=c;
		if(fsize==0)
		{
			byt|=0x03; //cccccc11
			goto WRITE;
			byt|=0xE0; //111zzzzz
			goto WRITE;
		}
		ret=read(pdc->fd,&dfl.ch,1);   //read 7
		if(ret==-1)
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		loc =*(int*)(*afp[16])((void*)&dfl);
		c=cc=(unsigned char)loc;
		c<<=3;
		c>>=6;
		byt|=c;
		ret = write(cfd, &byt, 1);	//write 4
		if(ret == -1)
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		byt^=byt;
		c=cc;
		c<<=5;
		byt|=c;
		if(fsize==0)
		{
			byt|=0x1F;  //ccc11111
			goto WRITE;
		}
		ret=read(pdc->fd,&dfl.ch,1); // read 8
		if(ret==-1)
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		loc =*(int*)(*afp[16])((void*)&dfl);
		c=cc=(unsigned char)loc;
		c<<=3;
		c>>=3;
		byt|=c;
/*		if(fsize==0)
		{
			byt1|=0xF8;  //11111zzz
			goto WRITE;
		}*/
WRITE:
		ret = write(cfd, &byt, 1);
		if(ret == -1)
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}

	}

#ifdef DEBUG
	printf("%s: %d: End\n", __func__, __LINE__);
#endif
	return 0;
}
