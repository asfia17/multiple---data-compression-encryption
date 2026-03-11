#! /bin/bash

CC=gcc
CF=-c
DF=-DDEBUG

mdcaeuit: main.o init.o mainMenu.o compression.o compStatistics.o deCompression.o deCompStatistics.o exitProject.o openFile.o createMasterArray.o unique.o codeLength.o compress2.o compress3.o compress4.o compress5.o compress6.o compress7.o findLocation.o deCompress2.o deCompress3.o deCompress4.o deCompress5.o deCompress6.o deCompress7.o
	${CC} -o mdcaeuit main.o init.o mainMenu.o compression.o compStatistics.o deCompression.o deCompStatistics.o exitProject.o openFile.o createMasterArray.o unique.o codeLength.o compress2.o compress3.o compress4.o compress5.o compress6.o compress7.o findLocation.o deCompress2.o deCompress3.o deCompress4.o deCompress5.o deCompress6.o deCompress7.o


deCompress2.o: deCompress2.c headers.h declarations.h
	${CC} ${CF} ${DF} deCompress2.c
deCompress3.o: deCompress3.c headers.h declarations.h
	${CC} ${CF} ${DF} deCompress3.c
deCompress4.o: deCompress4.c headers.h declarations.h
	${CC} ${CF} ${DF} deCompress4.c
deCompress5.o: deCompress5.c headers.h declarations.h
	${CC} ${CF} ${DF} deCompress5.c
deCompress6.o: deCompress6.c headers.h declarations.h
	${CC} ${CF} ${DF} deCompress6.c
deCompress7.o: deCompress7.c headers.h declarations.h
	${CC} ${CF} ${DF} deCompress7.c
findLocation.o: findLocation.c headers.h declarations.h
	${CC} ${CF} ${DF} findLocation.c
compress2.o: compress2.c headers.h declarations.h
	${CC} ${CF} ${DF} compress2.c
compress3.o: compress3.c headers.h declarations.h
	${CC} ${CF} ${DF} compress3.c
compress4.o: compress4.c headers.h declarations.h
	${CC} ${CF} ${DF} compress4.c
compress5.o: compress5.c headers.h declarations.h
	${CC} ${CF} ${DF} compress5.c
compress6.o: compress6.c headers.h declarations.h
	${CC} ${CF} ${DF} compress6.c
compress7.o: compress7.c headers.h declarations.h
	${CC} ${CF} ${DF} compress7.c
codeLength.o: codeLength.c headers.h declarations.h
	${CC} ${CF} ${DF} codeLength.c
unique.o: unique.c headers.h declarations.h
	${CC} ${CF} ${DF} unique.c
createMasterArray.o: createMasterArray.c headers.h declarations.h
	${CC} ${CF} ${DF} createMasterArray.c
openFile.o: openFile.c headers.h declarations.h
	${CC} ${CF} ${DF} openFile.c
exitProject.o: exitProject.c headers.h declarations.h
	${CC} ${CF} ${DF} exitProject.c
deCompStatistics.o: deCompStatistics.c headers.h declarations.h
	${CC} ${CF} ${DF} deCompStatistics.c
deCompression.o: deCompression.c headers.h declarations.h
	${CC} ${CF} ${DF} deCompression.c
compStatistics.o: compStatistics.c headers.h declarations.h
	${CC} ${CF} ${DF} compStatistics.c
compression.o: compression.c headers.h declarations.h
	${CC} ${CF} ${DF} compression.c
mainMenu.o: mainMenu.c headers.h declarations.h
	${CC} ${CF} ${DF} mainMenu.c
init.o: init.c headers.h declarations.h
	${CC} ${CF} ${DF} init.c
main.o: main.c headers.h declarations.h
	${CC} ${CF} ${DF} main.c

clean:
	-rm -f *.o
	-rm -f mdcaeuit

