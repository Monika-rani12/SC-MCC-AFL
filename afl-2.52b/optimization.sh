echo sanghu
BENCHMARK=$1
BOUND=$2
mkdir results-afl-$BENCHMARK/non-cleaned-TCs
mkdir results-afl-$BENCHMARK/cleaned-TCs
#replaced queue with crashes
rm results-afl-$BENCHMARK/default/crashes/*~
copycount=1;
#replaced queue with crashes
for f in results-afl-$BENCHMARK/default/crashes/*
do
sed 's/\s\+/\n/g' $f > temp1.txt
afl-tmin -i temp1.txt -o results-afl-$BENCHMARK/cleaned-TCs/Ct$copycount.txt ./$BENCHMARK
#afl-tmin -i $f -o results-afl-$BENCHMARK/non-cleaned-TCs/Ct$copycount.txt ./$BENCHMARK
copycount=$(($copycount+1)) 
done
#find results-afl-$BENCHMARK/non-cleaned-TCs -size  0 -print -delete
#rdfind -deleteduplicates true -makeresultsfile false results-afl-$BENCHMARK/non-cleaned-TCs
#copycount1=1;
#for f in results-afl-$BENCHMARK/crashes/i*
#do
##cp -P $f results-afl-$BENCHMARK/cleaned-TCs/Ct$copycount1.txt
##copycount1=$(($copycount1+1)) 
#sed 's/\s\+/\n/g' $f > results-afl-$BENCHMARK/cleaned-TCs/Ct$copycount1.txt
##sed 's/\s\+/\n/g' $f > temp1.txt
##cat temp1.txt
##awk '!NF{$0="0"}1' temp1.txt > results-afl-$BENCHMARK/cleaned-TCs/Ct$copycount1.txt
##cp -P $f temp$copycount1.txt
##echo $BOUND
##head -n$BOUND temp$copycount1.txt > results-afl-$BENCHMARK/cleaned-TCs/Ct$copycount1.txt
#copycount1=$(($copycount1+1)) 
#done
find results-afl-$BENCHMARK/cleaned-TCs/ -size 0 -delete
rdfind -deleteduplicates true -makeresultsfile false results-afl-$BENCHMARK/cleaned-TCs
rm -r results-afl-$BENCHMARK/non-cleaned-TCs

rm -f temp*.txt
