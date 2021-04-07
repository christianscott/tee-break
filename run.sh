#! /usr/bin/env bash

run() {
    if [[ "${BUFFER_LINES:-}" == "true" ]]; then
        ./bin/tee_breaker | ./bin/line_buffer | tee -a tee.log
    else
        ./bin/tee_breaker | tee -a tee.log
    fi
}

run &
pid_1="$!"

run &
pid_2="$!"

wait $pid_1
wait $pid_2
