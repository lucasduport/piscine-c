#!/bin/sh

if [ $# -eq 1 ]; then
    echo $(($1))
    exit
fi
while read -r line; do
    echo $(($line))
done
