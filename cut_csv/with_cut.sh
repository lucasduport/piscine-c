#!/bin/sh

if [ $# -ne 2 ]; then
    exit 1
fi

if [ ! -f "$1" ]; then
    exit 1
fi

LINE=$(head -n "$2" "$1" | tail -n 1)
echo "$(echo $LINE | cut -d ";" -f 2) is $(echo $LINE | cut -d ";" -f 3)"
