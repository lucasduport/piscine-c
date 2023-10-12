#!/bin/sh

if [ $# -eq 1 ]; then
    echo $(($1))
    exit
fi
read expr
if [ $# -eq 0 ]; then
    echo $(($expr))
else
    while [ 1 -eq 1 ]; do
        echo $(($expr))
        read expr
    done
fi
