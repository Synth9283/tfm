target = tfm
src = $(wildcard src/*.c)
obj = $(src:.c=.o)
flags = -g -O3 -lncurses

all: $(target)

$(target): main.c $(obj)
	gcc $^ $(flags) -o $@

%.o: %.c
	gcc -c $(flags) $^ -o $@

clean:
	rm -rfv src/*.o $(target)
