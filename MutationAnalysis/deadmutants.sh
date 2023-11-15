echo sanghu
BENCHMARK=$1
sed -E -e '/-:|call|unconditional|branch|-block|#####|\$\$\$\$\$/d' $BENCHMARK.c.gcov > tmp1.txt
cut -d: -f1-2 tmp1.txt > tmp2.txt
sed 's/.*://' tmp2.txt > $BENCHMARK-CoveredLines.txt
sed -r -i 's/\s+//g' $BENCHMARK-CoveredLines.txt
cp $BENCHMARK-CoveredLines.txt $BENCHMARK-Mutants
rm tmp*.txt
mkdir $BENCHMARK-ReachedMutants
cd $BENCHMARK-Mutants
ls -v *.c > files.txt 
while read q; do
echo $q > tmp1.txt
cut -d_ -f1-3 tmp1.txt > tmp2.txt
sed 's/.*_//' tmp2.txt > tmp3.txt
grep -F -x -v -f $BENCHMARK-CoveredLines.txt tmp3.txt
if [ $? == 1 ]
then
echo $q >> ../$BENCHMARK-ReachedMutantsList.txt
var=($q)
cp  $var ../$BENCHMARK-ReachedMutants
else
echo $q >> ../$BENCHMARK-DeadMutantsList.txt
fi
rm tmp*.txt
done <files.txt
rm files.txt
cd ..

