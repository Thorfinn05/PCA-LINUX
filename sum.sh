read -p "Enter n: " n
sum=0
while [ $n -gt 0 ]; do
	dig=$((n%10))
	sum=$((sum*10+dig))
	n=$((n/10))
done
echo "$sum"
