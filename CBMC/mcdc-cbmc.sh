
export BENCHMARK=$1
export VERSION=$2
export BOUND=$3

#./cbmc --smt2 --beautify --refine-strings --cover cover MetaWithBraces-V$VERSION.c --unwind $BOUND  > $BENCHMARK-result-MCDC.txt
./cbmc --z3 --cover cover MetaWithBraces-V$VERSION.c --unwind $BOUND  > $BENCHMARK-result-MCDC.txt

#sed '0,/** Results:/d' $BENCHMARK-result-MCDC.txt > $BENCHMARK-temp1.txt
#sed '/Trace/,$d' $BENCHMARK-temp1.txt > $BENCHMARK-temp2.txt
#sed '/ASSERTION VIOLATION: FAILURE/!d' $BENCHMARK-temp2.txt > $BENCHMARK-temp3.txt
#sed 's/^.*\(line \)/\1/' $BENCHMARK-temp3.txt > $BENCHMARK-temp4.txt
#sed -n 's/^[^0-9]*\([0-9]\{1,\}\).*$/\1/p' $BENCHMARK-temp4.txt > $BENCHMARK-Violated-Lines.txt
#detectederrors=$(wc -l < $BENCHMARK-Violated-Lines.txt)
#echo "******Total Violated Lines from CBMC******" > $BENCHMARK-MODE1-ASSERT-REPORT.txt
#echo "Total number Detected Errors (not unique)=: $detectederrors" >> $BENCHMARK-MODE1-ASSERT-REPORT.txt
#sed '/__CPROVER_assert(/!d' MetaWithBraces-V$VERSION.c > $BENCHMARK-temp6.txt
#detectedAllAsserts=$(wc -l < $BENCHMARK-temp6.txt)
#detectedDuplicates=$(wc -l < ../SequenceGenerator/exp/meta/LoopAssertStatements.csv)
#let totalAssertCount=detectedAllAsserts-detectedDuplicates
#echo "Total number unique assert statements =: $totalAssertCount" >> $BENCHMARK-MODE1-ASSERT-REPORT.txt
#rm -r *-temp*.txt


cp $BENCHMARK-result-MCDC.txt $BENCHMARK-result-MCDC-original.txt
sed -i '0,/Test suite:/d' $BENCHMARK-result-MCDC.txt 
sed -i '/^$/d'  $BENCHMARK-result-MCDC.txt 
cat $BENCHMARK-result-MCDC.txt > temp_testcases.txt
line=$(cat  temp_testcases.txt | head -n 1) 
count=${line//[^,]}
#echo "${#count}"
sed -i '1d' temp_testcases.txt
sed -i -e $'s/,/\\\n/g' $BENCHMARK-result-MCDC.txt 
total_varcount=$((${#count} + 1))
counter=1
testcaseCount=1

mkdir $BENCHMARK-Mode1-TC
while read -r line; do 
	
	line=$(echo "$line" | sed 's/^[^=]*=//g')
        echo "$line" >> "$BENCHMARK-Mode1-TC/BT$testcaseCount.txt"
        if [ $(($counter % $total_varcount)) == 0 ]; then
		line=$(cat  temp_testcases.txt | head -n 1) 
		count=${line//[^,]}
		total_varcount=$((${#count} + 1))
		sed -i '1d' temp_testcases.txt
		counter=0
#		echo "$counter"
		testcaseCount=`expr $testcaseCount + 1`
	fi
	counter=`expr $counter + 1`
	
done <  $BENCHMARK-result-MCDC.txt
rm temp_testcases.txt
mv $BENCHMARK-Mode1-TC ../



