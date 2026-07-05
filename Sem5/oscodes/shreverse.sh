echo "Enter a number: "
read n
rev=0
while [ $n -ne 0 ]
do
 dig=$((n%10))
 rev=$((rev * 10 + dig))
 n=$((n / 10))
done

echo "$rev"
