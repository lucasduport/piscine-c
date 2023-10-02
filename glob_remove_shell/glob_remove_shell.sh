#!/bin/sh

if [ $# -ne 1 ]; then
    ext=txt
else
    ext=$1
fi

for file in *.${ext}; do
    if [ $file = "*.${ext}" ] && [ ! -f "*.${ext}" ]; then
        exit 1;
    fi
        rm -f $file
done
