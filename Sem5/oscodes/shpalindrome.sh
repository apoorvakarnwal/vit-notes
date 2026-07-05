echo "Enter a number:"
read num
temp=$num
reverse=0
while [ $temp -ne 0 ]
do
  digit=$((temp % 10))
  reverse=$((reverse * 10 + digit))
  temp=$((temp / 10))
done

if [ $num -eq $reverse ]; then
  echo "$num is a palindrome."
else
  echo "$num is not a palindrome."
fi

