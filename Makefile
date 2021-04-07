CC=gcc

.PHONY: clean
clean:
	rm -rf bin/
	mkdir bin

tee-breaker: tee_breaker.c
	$(CC) -o bin/tee_breaker tee_breaker.c

line-buffer: line_buffer.c
	$(CC) -o bin/line_buffer line_buffer.c

all: tee-breaker line-buffer

run: all
	./run.sh

run-buffered: all
	BUFFER_LINES=true ./run.sh
