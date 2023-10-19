#!/bin/sh

if [ $# -ne 2 ]; then
    exit 1
fi

if [ ! -f "$1" ] || [ ! -r "$1" ]; then
    exit 1
fi

if ! [ "$2" -eq "$2" ] 2> /dev/null; then
    exit 1;
fi

if [ "$2" -le 0 ]; then
    exit 1;
fi

if [ $(($(wc -l "$1" | cut -d " " -f 1))) -lt $(($2)) ]; then
    exit 1
fi

LINE=$(head -n "$2" "$1" | tail -n 1)
echo "$(echo $LINE | cut -d ";" -f 2) is $(echo $LINE | cut -d ";" -f 3)"
