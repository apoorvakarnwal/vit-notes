echo "Enter the number of terms for the Fibonacci sequence:"
read n
a=0
b=1
for((i=1;i<=n;i++))
do
  echo "$a "
  temp=$((a+b))
  a=$b
  b=$temp
done