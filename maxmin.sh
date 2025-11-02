read -p "Enter array: " -a arr
max=${arr[0]}
min=${arr[0]}
for i in "${arr[@]}"; do
	if [ $i -lt $min ]; then
		min=$i;
	fi
	if [ $i -gt $max ]; then
		max=$i
	fi
done
echo "Max: $max, Min: $min"
