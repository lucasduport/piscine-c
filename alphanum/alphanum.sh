#!/bin/sh

while IFS='' read -r line; do
    if [  $(($(echo -n "$line" | grep -c -Ex "^[0-9]$" ))) -eq 1 ]; then
        echo "it is a digit"
    elif [  $(($(echo -n "$line" | grep -c -Ex "^[0-9]+$" ))) -eq 1 ]; then
        echo "it is a number"
    elif [  $(($(echo -n "$line" | grep -c -Ex "^[a-zA-Z]+$" ))) -eq 1 ]; then
        echo "it is a word"
    elif [  $(($(echo -n "$line" | grep -c -Ex "^[a-zA-Z0-9]+$" ))) -eq 1 ]; then
        echo "it is an alphanum"
    elif [  $(($(echo -n "$line" | grep -c -Px '( |\t)*' ))) -ge 1 ]\
        || [ "$line" = '' ]; then
        echo "it is empty"
    else
        echo "it is too complicated"
    fi
done
