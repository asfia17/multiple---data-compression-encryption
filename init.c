#include"headers.h"
#include"declarations.h"

int val;

void* (*afp[NOF])(void*);        //array of function pointers or
                                        //generic function
void* mainMenu(void*);
void* exitProject(void*);
void* compression(void*);
void* compStatistics(void*);
void* deCompression(void*);
void* deCompStatistics(void*);
void* openFile(void*);
void* createMasterArray(void*);
void* unique(void*);
void* codeLength(void*);

void* compress2(void*);
void* compress3(void*);
void* compress4(void*);
void* compress5(void*);
void* compress6(void*);
void* compress7(void*);

void* findLocation(void*);

void* deCompress2(void*);
void* deCompress3(void*);
void* deCompress4(void*);
void* deCompress5(void*);
void* deCompress6(void*); 
void* deCompress7(void*);

int init()
{
        afp[0] = mainMenu;
        afp[1] = exitProject;
        afp[2] = compression;
        afp[3] = compStatistics;
        afp[4] = deCompression;
        afp[5] = deCompStatistics;
        afp[6] = openFile;
        afp[7] = createMasterArray;
        afp[8] = unique;
        afp[9] = codeLength;

        afp[10] = compress2;
        afp[11] = compress3;
        afp[12] = compress4;
        afp[13] = compress5;
        afp[14] = compress6;
        afp[15] = compress7;
        afp[16] = findLocation;

        afp[17] = deCompress2;
        afp[18] = deCompress3;
        afp[19] = deCompress4;
        afp[20] = deCompress5;
        afp[21] = deCompress6;
	afp[22] = deCompress7;
        return 0;
}
