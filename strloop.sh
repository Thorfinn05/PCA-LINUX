








read -p "Enter a string: " str
for ((i=0; i<${#str}; i++)); do
	echo ${str:i:1}
done
