echo monika
#!/bin/ksh
export BENCHMARK=$1
export MODE=$2
mkdir $MODE
cd $MODE
#Need to add command for test case generator 
python ../mutator.py ../$BENCHMARK.c $BENCHMARK-Mutants

#./mutator.sh $BENCHMARK
rm a.out

#The below code is to run tests on Original Program
gcc ../${BENCHMARK}.c
echo "GHHHH"
ls
mkdir ${BENCHMARK}-Original
pwd
let a=1
for b in `ls -v ../../SequenceGenerator/$BENCHMARK-$MODE-TestCases/T*.txt`; 
do 
./a.out < ${b} > op-${a}.txt
mv op-${a}.txt ${BENCHMARK}-Original
((a =a+1));
done
rm a.out

#The below code is to run tests on all mutants
let c=1
let t=0
let k=0
for y in `ls -v ${BENCHMARK}-Mutants/*.c`;
do
gcc ${y}
if [ $? == 0 ]
then
echo "${y}: MUTANT IS COMPILABLE \n" >> Mutant-compilable-check.txt
else
echo "${y}: MUTANT IS NOT-COMPILABLE \n" >> Mutant-compilable-check.txt
fi
mkdir ${BENCHMARK}-OP-${c}
((t =t+1));
let r=1
for z in `ls -v ../../SequenceGenerator/$BENCHMARK-$MODE-TestCases/T*.txt`; 
do 
./a.out < ${z} > op-${r}.txt
mv op-${r}.txt ${BENCHMARK}-OP-${c}
diff ${BENCHMARK}-Original/op-${r}.txt ${BENCHMARK}-OP-${t}/op-${r}.txt
if [ $? == 0 ]
then
echo "Mutant Alive"
else
echo "Mutant Killed"
echo $y "killed due to" $z >> killed-Mutants-report.txt
((k =k+1));
break;
fi
((r =r+1));
done
rm a.out
#rm -r ${BENCHMARK}-OP-${t}
((c =c+1));
done
#rm -r ${BENCHMARK}-Original
((a = ${t} - ${k} ))
((mscore = (${k} * 100) / ${t}))
echo "============Mutation Score Report============"
echo "============Mutation Score Report============" >> $BENCHMARK-report.txt
echo "Total number of Alive Mutants =: ${a}"
echo "Total number of Alive Mutants =: ${a}" >> $BENCHMARK-report.txt 
echo "Total number of Killed Mutants =: ${k}"
echo "Total number of Killed Mutants =: ${k}" >> $BENCHMARK-report.txt 
echo "Total number of Mutants =: ${t}"
echo "Total number of Mutants =: ${t}" >> $BENCHMARK-report.txt 
echo "Mutation Score =: ${mscore}%"
echo "Mutation Score =: ${mscore}%" >> $BENCHMARK-report.txt 
echo "============Report-Finish===================="
echo "============Report-Finish====================" >> $BENCHMARK-report.txt

mkdir $BENCHMARK-RESULTS
mv Mutant-compilable-check.txt $BENCHMARK-RESULTS
mv killed-Mutants-report.txt $BENCHMARK-RESULTS
mv $BENCHMARK-report.txt $BENCHMARK-RESULTS
mv $BENCHMARK-Mutants $BENCHMARK-RESULTS
# below is the code for removing dead mutants
filenames=`(cd ${BENCHMARK}-RESULTS/${BENCHMARK}-Mutants && ls)`
for eachfile in $filenames
do
   echo $eachfile | grep -oP '\d+' | head -n1  >> lineNumDup.txt
   
done
cat lineNumDup.txt | sort | uniq > MutantlineNum.txt
gcc -fprofile-arcs -ftest-coverage -g ../${BENCHMARK}.c -o ${BENCHMARK}

for q in `ls -v ../../SequenceGenerator/$BENCHMARK-$MODE-TestCases/*`;
do
./${BENCHMARK} < $q
done
gcov ${BENCHMARK}.c > report-${BENCHMARK}.txt

while read p; do
  #array=$(echo $p | sed 's/:/\n/g')
p=$(echo -e "${p}" | tr -d '[[:space:]]')
IFS=:
array=($p)
  if [ "${array[0]//[0-9]}" = "" ]; then
  if [ "${array[0]}" -gt 0 ]; then
        echo ${array[1]} >> ExecutedLineNumbers.txt
  fi
  fi
done <${BENCHMARK}.c.gcov

grep -F -x -v -f ExecutedLineNumbers.txt MutantlineNum.txt > NotExecutedLN.txt

mapfile -t myArray < NotExecutedLN.txt
while IFS= read -r line; do
    myArray+=("$line")
    echo $myArray
done < NotExecutedLN.txt

for eachfile in $filenames
do
   LineNum=$(echo $eachfile | grep -oP '\d+' | head -n1)
   #echo 'LINENUM'
   if [[ "${myArray[@]}" =~ "$LineNum" ]]; then
       echo $eachfile
       rm ${BENCHMARK}-RESULTS/${BENCHMARK}-Mutants/$eachfile
   fi  


done

rm ExecutedLineNumbers.txt
rm MutantlineNum.txt
rm NotExecutedLN.txt
rm lineNumDup.txt

