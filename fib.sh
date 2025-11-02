read -p "Enter range: " r
a=0
b=1
while [ $a -lt $r ]; do
	echo "$a"
	c=$((a+b))
	a=$b
	b=$c

done
