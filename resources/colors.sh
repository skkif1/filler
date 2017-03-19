#!/bin/sh

cat \
	| sed "s|O|$(echo "\033[0;31mO\033[0m")|g" \
	| sed "s|o|$(echo "\033[0;33mo\033[0m")|g" \
	| sed "s|X|$(echo "\033[0;32mX\033[0m")|g" \
	| sed "s|x|$(echo "\033[0;34mx\033[0m")|g" \
