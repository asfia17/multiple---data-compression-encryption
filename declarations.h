#ifndef DEBUG
#define DEBUG
#endif

#ifndef NOF
#define NOF 23
#endif

int init();

extern int val;

extern void* (*afp[NOF])(void*);	//array of function pointers or
					//generic function

extern void* mainMenu(void*);
extern void* exitProject(void*);
extern void* compression(void*);
extern void* compStatistics(void*);
extern void* deCompression(void*);
extern void* deCompStatistics(void*);
extern void* openFile(void*);
extern void* createMasterArray(void*);
extern void* unique(void*);
extern void* codeLength(void*);

extern void* compress2(void*);
extern void* compress3(void*);
extern void* compress4(void*);
extern void* compress5(void*);
extern void* compress6(void*);
extern void* compress7(void*);

extern void* findLocation(void*);

extern void* deCompress2(void*);
extern void* deCompress3(void*);
extern void* deCompress4(void*);
extern void* deCompress5(void*);
extern void* deCompress6(void*);
extern void* deCompress7(void*);
