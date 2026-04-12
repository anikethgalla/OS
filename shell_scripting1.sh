#!/bin/sh

echo "Enter name"
read name
echo "Enter age"
read age
echo "Enter scores"
read  m1 m2 m3 m4 m5

echo "$m1 $m2 $m3 $m4 $m5"
score=$(((m1+m2+m3+m4+m5)/5))

if [ $score -ge 90 ]; then
    echo "A"
elif [ $score -ge 80 ]; then
    echo "B"
else
    echo "Fail"
fi
