#include "headers.h"
#include "dataStructures.h"
#include "declarations.h"

void* compress3(void *arg)
{
	unsigned char byt,c,cc,by1;
	unsigned int fsize,l;
	int ret,cfd;
	DSCompress *pdc;
	DSFindloc dfl;
#ifdef DEBUG
        printf("%s: %d: Begin  \n",__func__,__LINE__);
#endif

	pdc=(DSCompress*)arg;
	fsize=lseek(pdc->fd,0,SEEK_END)-1;
	lseek(pdc->fd,0,SEEK_SET);
	dfl.ma = pdc->ma;
	printf("%s: %d: Give name to 3-bit compressed file:  \n",__func__,__LINE__);
	cfd=*(int*)(*afp[6])((void*)"creating");

	while(fsize>0)
	{
		byt ^= byt;
		by1 ^= by1;
		ret = read(pdc->fd,&dfl.ch,1);			//read1
		if(ret == -1)
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		l=*(int*)(*afp[16])((void*)&dfl);
		cc=c=(char)l;
		c<<=5;
		byt |=c;

		if(fsize==0)
		{
			byt|=0x1C;              // ccc11111
			goto WRITE;
		}
                ret = read(pdc->fd,&dfl.ch,1);			//read2
                if(ret == -1)
                {
                        perror("read");
                        (*afp[1])((void*)"failure");
                }
                fsize--;
                l=*(int*)(*afp[16])((void*)&dfl);
                cc=c=(char)l;
                c<<=5;
                c>>=3;
                byt |=c;

                if(fsize==0)
                {
                        byt|=0x03;        //cccccc11
                        goto WRITE;
			byt ^= byt;
                        byt|=0x80;        // 1zzzzzzz
                        goto WRITE;
                }
                ret = read(pdc->fd,&dfl.ch,1);			//read3
                if(ret == -1)
                {
                        perror("read");
                        (*afp[1])((void*)"failure");
                }		  
		fsize--;
                l=*(int*)(*afp[16])((void*)&dfl);
                cc=c=(char)l;
                c<<=5;
                c>>=6;
                byt |=c;

                ret=write(cfd,&byt,1);				//write1
                if(ret == -1)
                {
                        perror("write");
                        (*afp[1])((void*)"failure");
                }
                byt ^= byt;
                c=cc;
                c<<=7;
                byt |=c;

                if(fsize==0)
                {
                        byt|=0x70;	//c111zzzz
                        goto WRITE;
                }

                ret = read(pdc->fd,&dfl.ch,1);			//read4
                if(ret == -1)
                {
                        perror("read");
                        (*afp[1])((void*)"failure");
                }

                fsize--;
                l=*(int*)(*afp[16])((void*)&dfl);
                cc=c=(char)l;
                c<<=5;
                c>>=1;
		byt |=c;

                if(fsize==0)
                {
                        byt|=0x0E;           //cccc111z
                        goto WRITE;
                }

                ret = read(pdc->fd,&dfl.ch,1);			//read5
                if(ret == -1)
                {
                        perror("read");
                        (*afp[1])((void*)"failure");
                }

                fsize--;
                l=*(int*)(*afp[16])((void*)&dfl);
                cc=c=(char)l;
                c<<=5;
                c>>=4;
                byt |=c;

                if(fsize==0)
                {
                        byt|=0x01;	//ccccccc1
                        goto WRITE;
			byt ^= byt;
                        byt|=0xC0;	//11zzzzzz
                        goto WRITE;
                }
                ret = read(pdc->fd,&dfl.ch,1);			//read6
                if(ret == -1)
                {
                        perror("read");
                        (*afp[1])((void*)"failure");
             	}
	     	fsize--;
                l=*(int*)(*afp[16])((void*)&dfl);
                cc=c=(char)l;
                c<<=5;
                c>>=7;
                byt |=c;

                ret=write(cfd,&byt,1);				//write2
                if(ret==-1)
                {
                        perror("write");
                        (*afp[1])((void*)"failure");
                }
                byt ^= byt;
                c=cc;
                c<<=6;
                byt |= c;
                if(fsize==0)
                {
			byt|=0x38;	//cc111000
                        goto WRITE;
                }
                ret = read(pdc->fd,&dfl.ch,1);			//read7
                if(ret == -1)
                {
                        perror("read");
                        (*afp[1])((void*)"failure");
                }

                fsize--;
                l=*(int*)(*afp[16])((void*)&dfl);
                cc=c=(char)l;
                c<<=5;
                c>>=2;
		byt |=c;

                if(fsize==0)
                {
                        byt|=0x07;	//ccccc111
                        goto WRITE;
                }
                ret = read(pdc->fd,&dfl.ch,1);			//read8
                if(ret == -1)
                {
                        perror("read");
                        (*afp[1])((void*)"failure");
                }
                fsize--;
                l=*(int*)(*afp[16])((void*)&dfl);
                cc=c=(char)l;
                c<<=5;
                c>>=5;
                byt |=c;
                if(fsize==0)
                {
                        byt|=0xE0;	//11100000
                        goto WRITE;
                }              
WRITE:
                ret=write(cfd,&byt,1);
                if(ret==-1)
                {
                        perror("write");
                        (*afp[1])((void*)"failure");
                }
	}
	close(cfd);
#ifdef DEBUG 
        printf("%s: %d: End. \n",__func__,__LINE__);
#endif
        return 0;
}

