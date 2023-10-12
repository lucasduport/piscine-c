#!/bin/sh

for i in $(ls "$1"); do
    if [ $(( $(file "$1/$i" | grep -c ":*ASCII text*") )) -eq 1 ]; then
        echo "$(file "$1/$i")"
    fi
done
