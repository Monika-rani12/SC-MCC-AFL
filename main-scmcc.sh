echo SC-MCC-AFL
#VERSION= V1 or V2 or V3 or V4
#BOUND= Provide the loop bound

export BENCHMARK=$1
export VERSION=$2
export BOUND=$3

mkdir $BENCHMARK-RESULTS

cp Programs/GCOV/$BENCHMARK.c SequenceGenerator/
cp Programs/GCOV/$BENCHMARK.c CBMC/
cp Programs/GCOV/$BENCHMARK.c MutationAnalysis/
#cp Programs/GCOV/$BENCHMARK.c ../afl-2.52b/

#This code below is for MCDC i.e. Mode 1

Ares1=$(date +%s.%N)
let dtA=0

cd CBMC
./PartialMetaProg.sh $BENCHMARK.c
mv keyValues.txt ../SequenceGenerator/
cd ..

cd SequenceGenerator
./seqshell-mcdc.sh $BENCHMARK.c $VERSION 
cp exp/meta/MetaWithBraces-V$VERSION.c ../../afl-2.52b/
cd ..

Ares2=$(date +%s.%N)
dtA=$(echo "$Ares2 - $Ares1" | bc)
ddA=$(echo "$dtA/86400" | bc)
dtA2=$(echo "$dtA-86400*$ddA" | bc)
dhA=$(echo "$dtA2/3600" | bc)
dtA3=$(echo "$dtA2-3600*$dhA" | bc)
dmA=$(echo "$dtA3/60" | bc)
dsA=$(echo "$dtA3-60*$dmA" | bc)
echo "****************Time Analysis MCDC Mode1 Report - Start**************************" >> Time-$BENCHMARK-MODE1.txt
echo "***Total MCDC Meta Program generator runtime in seconds" $dtA >> Time-$BENCHMARK-MODE1.txt
printf "Total MCDC Meta Program generator runtime: %d:%02d:%02d:%02.4f\n" $ddA $dhA $dmA $dsA >> Time-$BENCHMARK-MODE1.txt


Ares1=$(date +%s.%N)
dtA=0
cd ../afl-2.52b
./runafl.sh MetaWithBraces-V$VERSION $BOUND
mv results-afl-MetaWithBraces-V$VERSION/cleaned-TCs ../SC-MCC-AFL-Modified/$BENCHMARK-Mode1-TC
mv results-afl-MetaWithBraces-V$VERSION ../SC-MCC-AFL-Modified/
#rm MetaWithBraces-V$VERSION*
cd ../SC-MCC-AFL-Modified


#cd CBMC
#./mcdc-cbmc.sh $BENCHMARK $VERSION $BOUND
#cd ..

##cd SequenceGenerator
##javac DetectAssertions.java
##java DetectAssertions $BENCHMARK
##cd ..


##rdfind -deleteduplicates true -makeresultsfile false $BENCHMARK-Mode2-TC

Ares2=$(date +%s.%N)
dtA=$(echo "$Ares2 - $Ares1" | bc)
ddA=$(echo "$dtA/86400" | bc)
dtA2=$(echo "$dtA-86400*$ddA" | bc)
dhA=$(echo "$dtA2/3600" | bc)
dtA3=$(echo "$dtA2-3600*$dhA" | bc)
dmA=$(echo "$dtA3/60" | bc)
dsA=$(echo "$dtA3-60*$dmA" | bc)
echo "***Total MCDC TCG runtime in seconds" $dtA >> Time-$BENCHMARK-MODE1.txt
printf "Total MCDC TCG runtime: %d:%02d:%02d:%02.4f\n" $ddA $dhA $dmA $dsA >> Time-$BENCHMARK-MODE1.txt

Xres1=$(date +%s.%N)
let dtX=0
cd MutationAnalysis
./MA_SC_MCC_V2.sh $BENCHMARK 1
cd ..

Xres2=$(date +%s.%N)
dtX=$(echo "$Xres2 - $Xres1" | bc)
ddX=$(echo "$dtX/86400" | bc)
dtX2=$(echo "$dtX-86400*$ddX" | bc)
dhX=$(echo "$dtX2/3600" | bc)
dtX3=$(echo "$dtX2-3600*$dhX" | bc)
dmX=$(echo "$dtX3/60" | bc)
dsX=$(echo "$dtX3-60*$dmX" | bc)
echo "***Total MA runtime in seconds" $dtX >> Time-$BENCHMARK-MODE1.txt
printf "Total MA runtime: %d:%02d:%02d:%02.4f\n" $ddX $dhX $dmX $dsX >> Time-$BENCHMARK-MODE1.txt
echo "****************Time Mutation Analysis MODE1 Report - End**************************" >> Time-$BENCHMARK-MODE1.txt



mkdir $BENCHMARK-RESULTS/Mode1
mkdir $BENCHMARK-RESULTS/Mode1/PredicatesResults
mkdir $BENCHMARK-RESULTS/Mode1/CBMC
mv SequenceGenerator/keyValues.txt $BENCHMARK-RESULTS/Mode1/CBMC
mv SequenceGenerator/exp/meta $BENCHMARK-RESULTS/Mode1/
mv SequenceGenerator/exp/* $BENCHMARK-RESULTS/Mode1/PredicatesResults
mv SequenceGenerator/$BENCHMARK.c $BENCHMARK-RESULTS/Mode1/PredicatesResults
rm SequenceGenerator/err.txt
#mv CBMC/$BENCHMARK-result-MCDC-original.txt $BENCHMARK-RESULTS/Mode1/CBMC
#mv CBMC/$BENCHMARK-result-MCDC.txt $BENCHMARK-RESULTS/Mode1/CBMC
#mv CBMC/$BENCHMARK-Violated-Lines.txt $BENCHMARK-RESULTS/Mode1/CBMC
#mv CBMC/$BENCHMARK-MODE1-ASSERT-REPORT.txt $BENCHMARK-RESULTS/Mode1/CBMC
#mv SequenceGenerator/MetaWithBraces-V$VERSION.c $BENCHMARK-RESULTS/Mode1/CBMC
mv CBMC/$BENCHMARK.c $BENCHMARK-RESULTS/Mode1/CBMC
#mv $BENCHMARK-resultCheck.txt $BENCHMARK-RESULTS/Mode1/CBMC
mv $BENCHMARK-Mode1-TC $BENCHMARK-RESULTS/Mode1
mv Time-$BENCHMARK-MODE1.txt $BENCHMARK-RESULTS/Mode1
mv MutationAnalysis/$BENCHMARK-Mode*-Mutation $BENCHMARK-RESULTS/Mode1/
mv results-afl-MetaWithBraces-V$VERSION $BENCHMARK-RESULTS/Mode1/


cp Programs/GCOV/$BENCHMARK.c SequenceGenerator/
cp Programs/GCOV/$BENCHMARK.c CBMC/
cp Programs/GCOV/$BENCHMARK.c MutationAnalysis/
#cp Programs/GCOV/$BENCHMARK.c ../afl-2.52b/

#This code below is for SC-MCC from CBMC Bug finding i.e. Mode 2

Ares1=$(date +%s.%N)
let dtA=0

#cd CBMC
#./PartialMetaProg.sh $BENCHMARK.c
#mv keyValues.txt ../SequenceGenerator/
#cd ..

cd SequenceGenerator
./seqshell.sh $BENCHMARK.c $VERSION 
cp exp/meta/MetaWithBraces-V$VERSION.c ../../afl-2.52b/
cd ..

Ares2=$(date +%s.%N)
dtA=$(echo "$Ares2 - $Ares1" | bc)
ddA=$(echo "$dtA/86400" | bc)
dtA2=$(echo "$dtA-86400*$ddA" | bc)
dhA=$(echo "$dtA2/3600" | bc)
dtA3=$(echo "$dtA2-3600*$dhA" | bc)
dmA=$(echo "$dtA3/60" | bc)
dsA=$(echo "$dtA3-60*$dmA" | bc)
echo "****************Time Analysis SC-MCC Mode2 Report - Start**************************" >> Time-$BENCHMARK-MODE2.txt
echo "***Total SC-MCC Meta Program generator runtime in seconds" $dtA >> Time-$BENCHMARK-MODE2.txt
printf "Total SC-MCC Meta Program generator runtime: %d:%02d:%02d:%02.4f\n" $ddA $dhA $dmA $dsA >> Time-$BENCHMARK-MODE2.txt


Ares1=$(date +%s.%N)
dtA=0
cd ../afl-2.52b
./runafl.sh MetaWithBraces-V$VERSION $BOUND
mv results-afl-MetaWithBraces-V$VERSION/cleaned-TCs ../SC-MCC-AFL-Modified/$BENCHMARK-Mode2-TC
mv results-afl-MetaWithBraces-V$VERSION ../SC-MCC-AFL-Modified/
#rm MetaWithBraces-V$VERSION*
cd ../SC-MCC-AFL-Modified
#cd CBMC
#./scmcc-cbmc.sh $BENCHMARK $VERSION $BOUND
#cd ..

##cd SequenceGenerator
##javac DetectAssertions.java
##java DetectAssertions $BENCHMARK
##cd ..


##rdfind -deleteduplicates true -makeresultsfile false $BENCHMARK-Mode2-TC

Ares2=$(date +%s.%N)
dtA=$(echo "$Ares2 - $Ares1" | bc)
ddA=$(echo "$dtA/86400" | bc)
dtA2=$(echo "$dtA-86400*$ddA" | bc)
dhA=$(echo "$dtA2/3600" | bc)
dtA3=$(echo "$dtA2-3600*$dhA" | bc)
dmA=$(echo "$dtA3/60" | bc)
dsA=$(echo "$dtA3-60*$dmA" | bc)
echo "***Total SC-MCC TCG runtime in seconds" $dtA >> Time-$BENCHMARK-MODE2.txt
printf "Total SC-MCC TCG runtime: %d:%02d:%02d:%02.4f\n" $ddA $dhA $dmA $dsA >> Time-$BENCHMARK-MODE2.txt

Xres1=$(date +%s.%N)
dtX=0
#cp -r $BENCHMARK-RESULTS/Mode1/$BENCHMARK-Mode1-TC/* $BENCHMARK-Mode2-TC/
if [ "$(ls -A $BENCHMARK-Mode2-TC)" ]; then
cd MutationAnalysis
./MA_SC_MCC_V2.sh $BENCHMARK 2
cd ..
fi

Xres2=$(date +%s.%N)
dtX=$(echo "$Xres2 - $Xres1" | bc)
ddX=$(echo "$dtX/86400" | bc)
dtX2=$(echo "$dtX-86400*$ddX" | bc)
dhX=$(echo "$dtX2/3600" | bc)
dtX3=$(echo "$dtX2-3600*$dhX" | bc)
dmX=$(echo "$dtX3/60" | bc)
dsX=$(echo "$dtX3-60*$dmX" | bc)
echo "***Total MA runtime in seconds" $dtX >> Time-$BENCHMARK-MODE2.txt
printf "Total MA runtime: %d:%02d:%02d:%02.4f\n" $ddX $dhX $dmX $dsX >> Time-$BENCHMARK-MODE2.txt
echo "****************Time Mutation Analysis Mode2 Report - End**************************" >> Time-$BENCHMARK-MODE2.txt



mkdir $BENCHMARK-RESULTS/Mode2
mkdir $BENCHMARK-RESULTS/Mode2/PredicatesResults
mkdir $BENCHMARK-RESULTS/Mode2/CBMC
#mv SequenceGenerator/keyValues.txt $BENCHMARK-RESULTS/Mode2/
mv SequenceGenerator/exp/meta $BENCHMARK-RESULTS/Mode2/
mv SequenceGenerator/exp/* $BENCHMARK-RESULTS/Mode2/PredicatesResults
mv SequenceGenerator/$BENCHMARK.c $BENCHMARK-RESULTS/Mode2/PredicatesResults
rm SequenceGenerator/err.txt
#mv CBMC/$BENCHMARK-result-SC-MCC-original.txt $BENCHMARK-RESULTS/Mode2/CBMC
#mv CBMC/$BENCHMARK-result-SC-MCC.txt $BENCHMARK-RESULTS/Mode2/CBMC
#mv CBMC/$BENCHMARK-Violated-Lines.txt $BENCHMARK-RESULTS/Mode2/CBMC
#mv CBMC/$BENCHMARK-MODE2-ASSERT-REPORT.txt $BENCHMARK-RESULTS/Mode2/CBMC
#mv CBMC/MetaWithBraces-V$VERSION.c $BENCHMARK-RESULTS/Mode2/CBMC
mv CBMC/$BENCHMARK.c $BENCHMARK-RESULTS/Mode2/CBMC
#mv $BENCHMARK-resultCheck.txt $BENCHMARK-RESULTS/Mode2/CBMC
mv $BENCHMARK-Mode2-TC $BENCHMARK-RESULTS/Mode2
mv Time-$BENCHMARK-MODE2.txt $BENCHMARK-RESULTS/Mode2
mv MutationAnalysis/$BENCHMARK-Mode*-Mutation $BENCHMARK-RESULTS/Mode2/
mv results-afl-MetaWithBraces-V$VERSION $BENCHMARK-RESULTS/Mode2/

cat $BENCHMARK-RESULTS/Mode1/$BENCHMARK-Mode1-Mutation/Cov_report-${BENCHMARK}-Mode1.txt
cat $BENCHMARK-RESULTS/Mode2/$BENCHMARK-Mode2-Mutation/Cov_report-${BENCHMARK}-Mode2.txt

cat $BENCHMARK-RESULTS/Mode1/$BENCHMARK-Mode1-Mutation/$BENCHMARK-report.txt 
cat $BENCHMARK-RESULTS/Mode2/$BENCHMARK-Mode2-Mutation/$BENCHMARK-report.txt
