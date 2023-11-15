# SC-MCC

This README file is authored by Golla Monika Rani and Sangharatna Godboley.
This experimental data is provided for the results shown in the paper titled
"Automated SC-MCC Test Case Generation using Coverage Guided Fuzzing".
========================================================================

We have provided "SC-MCC-AFL-Results.zip" file which contains all the results mentioned in the paper.
=========================================================================

1. File Structure:

SC-MCC/CBMC/cbmc
SC-MCC/CBMC/goto-cc
SC-MCC/CBMC/goto-instrument
SC-MCC/CBMC/LICENSE
SC-MCC/CBMC/mcdc-cbmc.sh
SC-MCC/CBMC/PartialMetaProg.sh
SC-MCC/CBMC/cbmc
SC-MCC/CBMC/cbmc_script.sh
SC-MCC/CBMC/scmcc-cbmc.sh
==========================
SC-MCC/MutationAnalysis/deadmutants.sh
SC-MCC/MutationAnalysis/MA_SC_MCC_V2.sh
SC-MCC/MutationAnalysis/mutator.py
SC-MCC/MutationAnalysis/mutator.sh
===========================
SC-MCC/SequenceGenerator/exp/
SC-MCC/SequenceGenerator/MCDC_Sequence_Generator_multiple.class
SC-MCC/SequenceGenerator/MCDC_Sequence_Generator_multiple.java
SC-MCC/SequenceGenerator/MCDC_Sequence_Generator_multiple_mcdc.class
SC-MCC/SequenceGenerator/MCDC_Sequence_Generator_multiple_mcdc.java
SC-MCC/SequenceGenerator/MetaJavaFileGenerator_V5.class
SC-MCC/SequenceGenerator/MetaJavaFileGenerator_V5.java
SC-MCC/SequenceGenerator/MetaJavaFileGenerator_V6.class
SC-MCC/SequenceGenerator/MetaJavaFileGenerator_V6.java
SC-MCC/SequenceGenerator/seqshell.sh
SC-MCC/SequenceGenerator/seqshell-mcdc.sh
=============================
SC-MCC/main-scmcc.sh
SC-MCC/README.md
SC-MCC/run-scmcc.sh

========================================================================
2. To replicate the results for the sample program mentioned in the paper wrt., both the modes: (It will take less than a minute)
--------------------------
Run
./main-scmcc.sh mcdc_Program 4 2
---------------------------

Below folders will be generated. Here, Mode1 folder contains the results of MC/DC whereas Mode2 folder contains SC-MCC results.
----------------------------------
SC-MCC/mcdc_Program-RESULTS/Mode1/
SC-MCC/mcdc_Program-RESULTS/Mode1/CBMC/
SC-MCC/mcdc_Program-RESULTS/Mode1/PredicatesResults/
SC-MCC/mcdc_Program-RESULTS/Mode1/mcdc_Program-Mode1-Mutation/
SC-MCC/mcdc_Program-RESULTS/Mode1/mcdc_Program-Mode1-TC/
========================
SC-MCC/mcdc_Program-RESULTS/Mode2/
SC-MCC/mcdc_Program-RESULTS/Mode2/CBMC/
SC-MCC/mcdc_Program-RESULTS/Mode2/meta/
SC-MCC/mcdc_Program-RESULTS/Mode2/PredicatesResults/
SC-MCC/mcdc_Program-RESULTS/Mode2/mcdc_Program-Mode2-Mutation/
SC-MCC/mcdc_Program-RESULTS/Mode2/mcdc_Program-Mode2-TC/

-----------------------------------

Further:
SC-MCC/mcdc_Program-RESULTS/Mode1/CBMC/MetaWithBraces-V4.c
SC-MCC/mcdc_Program-RESULTS/Mode2/CBMC/MetaWithBraces-V4.c
SC-MCC/mcdc_Program-RESULTS/Mode1/mcdc_Program-Mode1-TC/BT1.txt
SC-MCC/mcdc_Program-RESULTS/Mode2/mcdc_Program-Mode2-TC/BT1.txt
SC-MCC/mcdc_Program-RESULTS/Mode2/mcdc_Program-Mode2-TC/BT2.txt
SC-MCC/mcdc_Program-RESULTS/Mode1/mcdc_Program-Mode1-Mutation/Cov_report-mcdc_Program-Mode1.txt
SC-MCC/mcdc_Program-RESULTS/Mode2/mcdc_Program-Mode2-Mutation/Cov_report-mcdc_Program-Mode2.txt
SC-MCC/mcdc_Program-RESULTS/Mode1/mcdc_Program-Mode1-Mutation/mcdc_Program-report.txt
SC-MCC/mcdc_Program-RESULTS/Mode2/mcdc_Program-Mode2-Mutation/mcdc_Program-report.txt
SC-MCC/mcdc_Program-RESULTS/Mode1/Time-mcdc_Program-MODE1.txt
SC-MCC/mcdc_Program-RESULTS/Mode2/Time-mcdc_Program-MODE2.txt

a. The file "MetaWithBraces-V4.c" of Mode1/CBMC folder contains the meta program w.r.t., MC/DC coverage criterion.

b. The file "MetaWithBraces-V4.c" of Mode2/CBMC folder contains the meta program w.r.t., SC-MCC coverage criterion.


c. The files "CT*.txt" of Mode1/mcdc_Program-Mode1-TC/ folder corresponds to the test cases obtained by executing MC/DC meta program using AFL.

d. The files "CT*.txt" of Mode2/mcdc_Program-Mode2-TC/ folder corresponds to the test cases obtained by executing SC-MCC meta program using CBMC.

e. The file "Cov_report-mcdc_Program-Mode1.txt” of Mode1/mcdc_Program-Mode1-Mutation/ folder contains the gCov coverage report upon executing MC/DC meta program with its test cases.

f. The file "Cov_report-mcdc_Program-Mode2.txt” of Mode2/mcdc_Program-Mode2-Mutation/ folder contains the gCov coverage report upon executing SC-MCC meta program with its test cases.

g. The file "mcdc_Program-report.txt” of Mode1/mcdc_Program-Mode1-Mutation/ folder contains the Mutation analysis report w.r.t., MC/DC test cases.
-------------------------------------------------------------
============Mutation Score Report============
Total number of Alive Mutants =: 32
Total number of Killed Mutants =: 10
Total number of Mutants =: 42
Mutation Score =: 23%
============Report-Finish====================
-------------------------------------------------------------

h. The file "mcdc_Program-report.txt” of Mode2/mcdc_Program-Mode2-Mutation/ folder contains the Mutation analysis report w.r.t., SC-MCC test cases.
-------------------------------------------------------------
============Mutation Score Report============
Total number of Alive Mutants =: 31
Total number of Killed Mutants =: 11
Total number of Mutants =: 42
Mutation Score =: 26%
============Report-Finish====================
-------------------------------------------------------------

i. The file "Time-mcdc_Program-MODE1.txt” of Mode1 folder contains the Execution time information w.r.t., MC/DC criterion.

j. The file "Time-mcdc_Program-MODE2.txt”  of Mode2 folder contains the Execution time information w.r.t., SC-MCC criterion.

========================================================================
======================================================================
Contact:
For any questions and enquiry please contact below:

1. Golla Monika Rani, Emails: gm720080@student.nitw.ac.in, gmonikarani@gmail.com
2. Sangharatna Godboley, Emails: sanghu@nitw.ac.in, sanghu1790@gmail.com
======================================================================

