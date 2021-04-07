# tee break

This demo doesn't really "break `tee`" so much as it demonstrates a limitation when using it with a program that doesn't line-buffer its output (`./bin/tee_breaker | tee -a tee.log`).

without line buffering:
```
$ make run
gcc -o bin/tee_breaker tee_breaker.c
gcc -o bin/line_buffer line_buffer.c
./run.sh
{{  ""mmssgg""::  ""hheelllloo!!""  }}

{{  ""mmssgg""::  ""ggooooddbbyyee  ::((""  }}
```

It also shows that you can work around this by piping output into a program that does the line buffering for you (`./bin/tee_breaker | ./bin/line_buffer | tee -a tee.log`).

with line buffering:
```
$ make run-buffered
gcc -o bin/tee_breaker tee_breaker.c
gcc -o bin/line_buffer line_buffer.c
BUFFER_LINES=true ./run.sh
{ "msg": "hello!" }
{ "msg": "hello!" }
{ "msg": "goodbye :(" }
{ "msg": "goodbye :(" }
```
