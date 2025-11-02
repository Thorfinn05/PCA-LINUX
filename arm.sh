read -p "Enter num: " n
sum=0
while [ $n -gt 0 ]; do
	dig=$((n%10))
	sum=$((sum+dig**3))
	n=$((n/10))
done
echo "$sum"
