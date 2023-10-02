#!/bin/sh

[ $# -ne 1 ] && (echo "Sorry, expected 1 argument but $# were passed"; exit 1)
[ $# -eq 1 ] && [ ! -f "$1" ] && (echo "$1:"; printf "\tis not a valid file\n") && exit 2
[ $# -eq 1 ] && [ -f "$1" ] && cat $1
