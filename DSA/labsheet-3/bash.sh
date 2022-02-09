
counter=1
while [ $counter -le 10000 ]
do
	gcc submission.c && ./a.out
	((counter++))
done
