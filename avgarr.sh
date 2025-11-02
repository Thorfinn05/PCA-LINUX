read -p "Enter aray: " -a arr
sum=0
for ((i=0; i<${#arr[@]}; i++)); do
	sum=$((sum+arr[i]))
done
avg=$((sum/${#arr[@]}))
echo "$avg"
