#include"headers.h"
#include"declarations.h"

int main()
{
	int choice;
#ifdef DEBUG
	printf("%s: %d: Begin\n",__func__,__LINE__);
#endif
	init();
	while(1)
	{
		choice = *(int*)(*afp[0])(0);	//mainMenu()
		if( choice == 0 )
			(*afp[choice+1])((void*)"success");	//exitProgram()
		else if((choice >= 1) && (choice <= 4))
			(*afp[choice+1])(0);	// otherFunctions
		else
			printf("%s: %d: Invalid Choice!!\n",__func__,__LINE__);
	}


#ifdef DEBUG 
	printf("%s: %d: End\n",__func__,__LINE__);
#endif
	return 0;
}
