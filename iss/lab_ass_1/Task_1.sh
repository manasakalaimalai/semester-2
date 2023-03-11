#!/bin/bash

m=$1
n=$2
a=$1
b=$2
function gcd() {
# I am using the Euclidean algorithm for finding LCM and GCD
while true
do
r=$(( $m % $n )) # Divide m by n and let r be the remainder.
if [ $r -eq 0 ] # If r equals 0 the algorithm terminate;
then
echo GCD: $n
lcm $n
break
fi
m=$n #  Set m to n, n to r and go back to first step on line 9
n=$r
done
} 

function lcm() {
echo LCM: $((($a*$b)/$1))
}
gcd $m $n
