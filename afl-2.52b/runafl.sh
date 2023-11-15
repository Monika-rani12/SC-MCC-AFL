BENCHMARK=$1
BOUND=$2
RAND1=$(( ( RANDOM % 100 )  + 1 ))
#rm -r testcase-Random/aseed.txt
#echo $RAND1 > testcase-Random/aseed.txt
afl-gcc -fno-stack-protector -z execstack $BENCHMARK.c -o $BENCHMARK
timeout 300 afl-fuzz -m none -i ./testcase-Random/ -o ./results-afl-$BENCHMARK/ ./$BENCHMARK
if [ $? -eq 1 ]; then 
timeout 300 afl-fuzz -m none -C -i ./testcase-Random/ -o ./results-afl-$BENCHMARK/ ./$BENCHMARK
fi
./optimization.sh $BENCHMARK $BOUND
pwd
experimental/crash_triage/triage_crashes.sh results-afl-$BENCHMARK/default/ $BENCHMARK &> results-afl-$BENCHMARK/crashdetail.txt
sed '/Assertion /!d' results-afl-$BENCHMARK/crashdetail.txt > results-afl-$BENCHMARK/temp.txt
#sed '/Assertion \`0\' failed /!d' results-afl-$BENCHMARK/crashdetail.txt > results-afl-$BENCHMARK/temp.txt
# Assertion `0' failed
sort -u results-afl-$BENCHMARK/temp.txt > results-afl-$BENCHMARK/finalcrashes.txt
rm results-afl-$BENCHMARK/temp.txt
totalerrors=$(ls -l | grep -c "assert(" $BENCHMARK.c)
detectederrors=$(ls -l | grep -c "failed" results-afl-$BENCHMARK/finalcrashes.txt)
if [ -f $BENCHMARK-lines.txt ];
then
alarms=$(wc -l < $BENCHMARK-lines.txt)
unreachableerrors=$(($totalerrors - $alarms))
fi

echo "******Final Result Report from AFL ******"
echo "******Final Result Report from AFL******" >> results-afl-$BENCHMARK/$BENCHMARK-report.txt
echo "Total number Injected Errors =:$totalerrors"
echo "Total number Injected Errors =:$totalerrors" >> results-afl-$BENCHMARK/$BENCHMARK-report.txt
#echo "Total number unreachable Errors =:$unreachableerrors"
#echo "Total number unreachable Errors =:$unreachableerrors" >> results-afl-$BENCHMARK/$BENCHMARK-report.txt
echo "Total number Detected Errors =:$detectederrors"
echo "Total number Detected Errors =:$detectederrors" >> results-afl-$BENCHMARK/$BENCHMARK-report.txt
#mv Time-$BENCHMARK.txt results-afl-$BENCHMARK
rm $BENCHMARK*
#rm -r results-afl-$BENCHMARK/queue



