#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

if [ ! -r "$1" ]; then
    exit 1
fi

while IFS='' read -r line; do
    if [ $(( $(IFS=''; printf '%s\n' ${line} | wc -m) )) -gt 80 ]; then
        printf '%s\n' "${line}"
    fi
done< "$1"
