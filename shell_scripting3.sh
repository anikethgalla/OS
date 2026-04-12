#!/bin/sh
if [ $# -ne 3 ]; then
echo "Not given 3 numbers"
fi

n1=$1
n2=$2
n3=$3

if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]; then
    echo "$1 is the greatest"
elif [ $n2 -gt $n3 ] && [ $n2 -gt $n1 ]; then
    echo "$3 is the greatest"
else 
    echo "$3 is the greatest"
fi

