#!/bin/sh

# Here we will use command substitution to fetch our result, as it spawns a
# subshell 'res' will only be alive inside the command substitution
if [ $# -ne 1 ]; then
    exit 1
fi

f=1
i=1

while [ $i -le $1 ]; do
    f=$(($f * $i))
    i=$(($i + 1))
done
echo $f

