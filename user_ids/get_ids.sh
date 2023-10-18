#!/bin/sh

cat /etc/passwd | cut -d ":" -f 3 | sort -nr
