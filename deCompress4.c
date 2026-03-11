#include"headers.h"
#include"dataStructures.h"
#include"declarations.h"

void* deCompress4(void *arg)
{
	unsigned char ch, cc, dc;
	int dfd, fsize;
	unsigned int i;
	DSCompress *pdd;
#ifdef DEBUG
        printf("%s: %d: Begin\n",__func__,__LINE__); 
#endif

	pdd = (DSCompress*)arg;

        printf("%s: %d: Give Name to 4-bit DeCompress file:\n",__func__,__LINE__);
	dfd = *(int*)(*afp[6])((void*)"creating"); 
	fsize = lseek(pdd->fd, 0, SEEK_END)-1;
	lseek(pdd->fd, 0, SEEK_SET);

	while(1)
	{
		if( read(pdd->fd, &ch, 1) ==-1 )
		{
			perror("read");
			(*afp[1])((void*)"failure");
		}
		fsize--;
		cc = ch;
		ch >>= 4;
		if(ch == 15)
			break;
		i^=i;
		i = (unsigned int)ch;
		dc = *(pdd->ma+i);
		if( write(dfd, &dc, 1) == -1)
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
		ch = cc;
		ch <<= 4;
		ch >>= 4;
		if(ch == 15)
			break;
		i^=i;
		i = (unsigned int)ch;
		dc = *(pdd->ma+i);
		if( write(dfd, &dc, 1) ==-1 )
		{
			perror("write");
			(*afp[1])((void*)"failure");
		}
	}
	close(dfd);

#ifdef DEBUG 
        printf("%s: %d: End. \n",__func__,__LINE__);
#endif
        return 0;
}

