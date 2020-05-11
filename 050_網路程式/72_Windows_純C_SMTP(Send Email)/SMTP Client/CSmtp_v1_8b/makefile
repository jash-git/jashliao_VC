# Automatyczny makefile

CC = g++
CFLAGS = -Wall -O2 -DLINUX
ONLYCOMPILE = $(CC) $(CFLAGS) -c -g
OBJFILES :=  $(patsubst %.cpp,%.o,$(wildcard *.cpp))
PROGNAME = CSmtp

all: $(PROGNAME)

$(PROGNAME) : $(OBJFILES)
	$(CC) -o $(PROGNAME) $(OBJFILES)

%.o: %.cpp
	${ONLYCOMPILE} -o $@ $<

clean:
	rm *.o
