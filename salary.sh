echo "enter salary of user"
read sal
TA=$((sal * 5/100))
DA=$((sal * 10/100))
hra=$((sal * 7/100))
gs=$(($TA+$DA+$hra+$sal))
echo "total=$TA"
echo "DA IS=$DA"
echo "hra is=$hra"
echo "gross salary is=$gs"
epf=$((sal*12/100))
esi=$((sal*2/100))
ded=$(($epf+$esi))
net=$(($gs-$ded))
echo "net salary is=$net"