if [ -z "$1" ]; then
	echo "No arguments supplied"
else
	for var in "$@"
	do
		mkdir "ex$var"
	done
fi
