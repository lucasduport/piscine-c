#!/bin/sh

if [ $# -ne 2 ]; then
    exit 1
fi

if [ ! -f "$1" ]; then
    exit 1
fi

LINE=$(sed -n "$2"p "$1")
echo $LINE | sed -n "s/[^\;]*\;\([^\;]*\)\;\([^\;]*\)\;.*/\1 is \2/p"
