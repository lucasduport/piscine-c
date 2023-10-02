#!/bin/sh

if [ $# -ne 2 ]; then
  echo "Usage: ./hcf.sh num1 num2"
  exit 1
fi

if [ $2 -eq 0 ]; then
  echo "Exception: division by 0"
  exit 2
fi

if [ $1 -eq 0 ]; then
  echo $2
  exit 0
fi

a="$1"
b="$2"

while [ $b -gt 0 ]; do
  q=$(( $a / $b ))
  r=$(( $a % $b ))
  a=$b
  b=$r
done

echo $a
