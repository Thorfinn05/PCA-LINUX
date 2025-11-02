read -p "Enter num: " n
if [ $n -lt 2 ]; then
	echo "$n -> Not Prime."
	exit
fi
for (( i=2; i<n/2; i++ )); do
	if ((n%i == 0)); then
		echo "$n -> Not Prime"
		exit
	fi
done
echo "$n -> Prime"

