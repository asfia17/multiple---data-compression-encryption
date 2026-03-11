#include"headers.h"
#include"declarations.h"

void* mainMenu(void *arg)
{
#ifdef DEBUG
	printf("%s: %d: Begin \n",__func__,__LINE__);
#endif

	printf("%s: %d: _____MAIN MENU_____\n",__func__,__LINE__);
	printf("%s: %d: 1. Compress File\n",__func__,__LINE__);
	printf("%s: %d: 2. Compression Statistics\n",__func__,__LINE__);
	printf("%s: %d: 3. DeCompress File\n",__func__,__LINE__);
	printf("%s: %d: 4. DeCompression Statistics\n",__func__,__LINE__);
	printf("%s: %d: 0. Exit Poject\n",__func__,__LINE__);
	printf("%s: %d:  Enter Your choice:\n",__func__,__LINE__);
	scanf("%d",&val);

#ifdef DEBUG
	printf("%s: %d: End \n",__func__,__LINE__);
#endif
	return (void*)&val;
}
