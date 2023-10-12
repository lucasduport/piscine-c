#!/bin/sh

sed -nE 's/^[a-zA-Z]+[*a-zA-Z0-9_ ]*\([ *a-zA-Z0-9_]+[, *a-zA-Z0-9_]*\);?$/$&;/p' "$1"
