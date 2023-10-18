#!/bin/sh

if [ $# -ne 3 ]; then
    echo "Usage: ./seq.sh FIRST INCREMENT LAST" >&2
    exit 1;
fi

FIRST=$(($1))
LAST=$(($3))
INCREMENT=$(($2))

if [ $FIRST -eq $LAST ]; then
    echo "$FIRST"
    exit 0
fi

if [ $FIRST -lt $LAST ]; then
    if [ $INCREMENT -lt 0 ]; then
        exit 1
    else      
        while [ $FIRST -le $LAST ]; do
            echo "$FIRST"
            FIRST=$(($FIRST + $INCREMENT))
        done
        exit 0
    fi
fi

if [ $INCREMENT -gt 0 ]; then
    exit 1
else      
    while [ $FIRST -ge $LAST ]; do
        echo "$FIRST"
        FIRST=$(($FIRST + $INCREMENT))
    done
    exit 0
fi
