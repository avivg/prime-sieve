
.PHONY: all

all: csieve

csieve: csieve.c
	$(CC) -o $@.out $^ -O2

clean:
	rm -f csieve.out