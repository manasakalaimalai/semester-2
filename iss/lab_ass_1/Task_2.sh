#!/bin/bash

cal >> output.txt # (1)
echo $(date +"%Y / %m / %d") >> output.txt # (2)
printf 'ISS is cool\n%.0s' {1..100} >> output.txt # (3)
cat output.txt # (4)
head -n 3 output.txt # (5)
echo
sed -n '6,15'p output.txt # (6)
echo "Number of lines:"
cat output.txt | wc -l # (7)
echo "I'm UG1" >> output.txt # (8)
echo "Number of words:"
cat output.txt | wc -w # (9)
echo "I'm studying ISS" >> output.txt # (10)
awk '{ print $4 }' output.txt # (11)
cut -d' ' -f2-5 output.txt # (12)
#out=$((wc -l)) output.txt
awk '{ print $3 }' output.txt | ghead -n -5 # (13)
cut -d' ' -f2,4 output.txt # (14)
