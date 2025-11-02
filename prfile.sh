read -p "Enter arr: " -a arr
for i in "${arr[@]}"; do
	echo "Contnt of $i: "
	echo "$(cat "$i")"
done

