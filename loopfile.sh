read -p "Enter any file extension: " ext
for file in *.$ext; do
	echo $file
done
