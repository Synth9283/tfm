target = tfm
compiler = gcc
src = $(wildcard src/*.c)
obj = $(src:.c=.o)
flags = -g -O3 -static -lncurses

all: $(target)

$(target): main.c $(obj)
	$(compiler) $^ $(flags) -o $@

%.o: %.c
	$(compiler) -c $(flags) $^ -o $@

clean:
	rm -rfv src/*.o $(target)
