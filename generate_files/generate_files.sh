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
      ;;

    "-e" | "--extension")
      ext=$2
    ;;
  esac
  shift 2
done

touch "$fn-$nb.$ext"
