#!/bin/bash

while read -r line; do
	echo "$line" | grep 'Plateau' > /dev/null
	if [[ $? == 0 ]]; then
		#sleep 0.01
		clear
	fi
	echo "$line"
done < /dev/stdin
