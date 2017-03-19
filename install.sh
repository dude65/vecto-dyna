#!/bin/bash

cmake CMakeLists.txt && make

success="$?"

if [ "$success" -eq 0 ]; then
	echo "Successfully installed"
else
	echo "Problems detected. Fix problems and rerun script." >&2
fi

exit "$success"
