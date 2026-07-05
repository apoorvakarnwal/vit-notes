echo "Enter number: "
read n

isprime=1
for((i=2;i<n;i++))
do
 if [ $((n%i)) -eq 0 ]; then
  isprime=0
  break
 fi
done

if [ $isprime -eq 0 ]; then 
 echo "Number is not prime"
else
 echo "Number is prime"
fi
