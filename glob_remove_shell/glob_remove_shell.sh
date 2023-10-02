#!/bin/sh

if [ $# -ne 1 ]; then
  ext=txt
else
  ext=$1
fi

if [ $(echo *.${ext}) = "*.${ext}" ]; then
  exit 1;
else
  for file in *.${ext}; do
    rm -f $file
  done
fi
