#!/bin/sh

if [ $# -eq 1 ]; then
    if [ ! -f "$1" ]; then
        echo "$1:"; printf "\tis not a valid file\n"; exit 2
    else
        cat $1
    fi
else
    echo "Sorry, expected 1 argument but $# were passed"
    exit 1
fi
