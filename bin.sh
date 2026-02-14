#!/bin/bash

i=13

for f in data/sex/incest/gar/*; do
	echo "med[$i] = \""$f"\";"
	i=$((i + 1))
done;
