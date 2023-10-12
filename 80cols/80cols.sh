#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

if [ ! -r "$1" ]; then
    exit 1
fi

while read -r line; do
    if [ $(( $(wc -m <<< "$line") )) -gt 80 ]; then
        echo -e "$line"
    fi
done<$1
