#!/bin/sh

echo "Enter number"
read number

if [ $number -ge 10 ]; then
    echo "Greater than 10"
else 
    ehco "Lesser than 10"
fi