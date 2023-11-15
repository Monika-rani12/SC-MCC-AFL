

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*; 
import java.io.LineNumberReader;

/**
 *
 * @author user
 */
public class DetectAssertions{
    public static int LoopNum = 1;
    public static void main(String[] args) throws FileNotFoundException, IOException {
	String fileName = "";
	if (args.length > 0) {
    		fileName = args[0];
    	}else{
	        System.err.println("File name not provided!");
	        System.exit(1);
    	}
        BufferedReader PC=new BufferedReader(new FileReader("../CBMC/"+fileName+"-Violated-Lines.txt"));
        String r=PC.readLine();
	List<String> assertLineNumbers=new ArrayList<String>();
        int countAllAV=0;
        while(r!=null){

	    countAllAV++;
	    assertLineNumbers.add(r);
            r=PC.readLine();

        }
	int countLoopAV=0, countUniqueLoopAV=0;
	BufferedReader PC1=new BufferedReader(new FileReader("exp/meta/LoopAssertStatements.csv"));
	String line=PC.readLine();
	String[] football = new String[4];
	PrintWriter out_metaFile_Loop=new PrintWriter("exp/meta/LoopAssertStatementsFinal.csv");
	while ((line = PC1.readLine()) != null) {
    		football = line.split(";");
		boolean isViolatedFirst = false, isViolatedSecond = false;
    		if(assertLineNumbers.contains(football[2])) {
			line = line +";" + football[2];
			isViolatedFirst = true;
			countLoopAV++;
		}else{line = line +";";}
    		if(assertLineNumbers.contains(football[3])){
			line = line +";" + football[3];
			isViolatedSecond = true;
			countLoopAV++;
		}else{line = line +";";}
		if(isViolatedFirst){
			line = line +";" + football[2];
			countUniqueLoopAV++;
		}else if(isViolatedSecond){
			line = line +";" + football[3];
			countUniqueLoopAV++;
		}
		out_metaFile_Loop.println(line);
		out_metaFile_Loop.flush();
	}
	PrintWriter out_report=new PrintWriter("exp/meta/out_report.txt");
	int feasible_num=(countAllAV - countLoopAV + countUniqueLoopAV);
	out_report.println(feasible_num);
	out_report.flush();
	//System.out.println("Total Number of feasible assertion violations = "+feasible_num);

   }
}
