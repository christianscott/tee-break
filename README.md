# tee break

without line buffering:
```
$ make run
gcc -o bin/tee_breaker tee_breaker.c
gcc -o bin/line_buffer line_buffer.c
./run.sh
{{  ""mmssgg""::  ""hheelllloo!!""  }}

{{  ""mmssgg""::  ""ggooooddbbyyee  ::((""  }}
```

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
