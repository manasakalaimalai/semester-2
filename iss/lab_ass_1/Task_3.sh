#!/bin/bash

ip_address=$1
split_ip=${ip_address//[.]/' '}
my_arr=()
for val in $split_ip; do
  my_arr+=($(echo "obase=2;$val" | bc) ' ')
done
for val in "${my_arr[*]}"; do
  echo -e "$val\t "
done

