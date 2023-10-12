#!/bin/sh

sed -nE 's/^[a-zA-Z0-9]+[ *a-zA-Z0-9]*\([ *a-zA-Z0-9]*\)$/$&;/p' "$1"
