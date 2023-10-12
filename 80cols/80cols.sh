#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

if [ ! -r "$1" ]; then
    exit 1
fi

while IFS='' read -r line; do
    if [ $(( $(wc -c <<< $line) )) -gt 80 ]; then
        echo -e "$line"
    fi
done<$1
