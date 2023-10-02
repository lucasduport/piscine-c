#!/bin/sh

fn=default
nb=1
ext=txt

while [ $# -gt 1 ]; do
    case $1 in
    
    "-f" | "--filename")
        fn=$2
        ;;

    "-n" | "--number")
        nb=$2
        if ! [[ "$nb" =~ [0-9]+ ]]; then
          exit 1
        fi
      ;;

    "-e" | "--extension")
        ext=$2
        ;;
    *)
        exit 1
        ;;
    esac
    shift 2
done

for i in $(seq 1 $nb); do
    touch -- "${fn}-${i}.${ext}"
done
