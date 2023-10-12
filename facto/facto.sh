#!/bin/sh

# Here we will use command substitution to fetch our result, as it spawns a
# subshell 'res' will only be alive inside the command substitution
if [ $# -eq 0 ]; then
    exit 1
fi

facto() {
    f=1
    for i in $(seq 1 $1); do
        f=$(($f * $i))
    done
}

facto $1
echo $f
