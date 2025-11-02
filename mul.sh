read -p "Enter num: " n
for i in {1..10}; do
	m=$((n*i))
	echo "$n * $i = $m"
done

