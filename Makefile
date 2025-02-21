include ./Make.defines

PROGS =	CRC32_count
OBJS = CRC32_count.o CRC32_func.o

all:	${PROGS}

${OBJS}: CRC32_func.h

CRC32_count:	${OBJS}
		${CC} ${CFLAGS} -o $@ ${OBJS} ${LIBS}

clean:
		rm -f ${PROGS} core core.* *.o temp.* *.out typescript*
