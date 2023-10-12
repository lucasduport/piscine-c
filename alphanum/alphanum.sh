#!/bin/sh

while IFS='' read -r line; do
    if [  $(($(echo -n "$line" | grep -c -Ex "^[0-9]$" ))) -eq 1 ]; then
        echo "it is digit"
    elif [  $(($(echo -n "$line" | grep -c -Ex "^[0-9]+$" ))) -eq 1 ]; then
        echo "it is a number"
    elif [  $(($(echo -n "$line" | grep -c -Ex "^[a-zA-Z]+$" ))) -eq 1 ]; then
        echo "it is a word"
    elif [  $(($(echo -n "$line" | grep -c -Ex "^[a-zA-Z0-9]+$" ))) -eq 1 ]; then
        echo "it is an alphanum"
    elif [  $(($(echo -n "$line" | grep -c -Ex "^[ \t]*$" ))) -eq 1 ]; then
        echo "it is empty"
    else
        printf %s $line
        echo "it is too complicated"
    fi
done
