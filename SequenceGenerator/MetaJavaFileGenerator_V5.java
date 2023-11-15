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

public class MetaJavaFileGenerator_V5{
    public static int maxAssertionCount=0;
    public static void main(String[] args) throws FileNotFoundException, IOException {

	String fileName = "";
	if (args.length > 0) {
    		fileName = args[0];
    	}else{
	        System.err.println("File name not provided!");
	        System.exit(1);
    	}

	BufferedReader keyValueFile=new BufferedReader(new FileReader("keyValues.txt"));
	String eachValue=keyValueFile.readLine();
	Map<String,String> mapOfPredAndSeq=new HashMap<String,String>();
	////System.out.println("*********************"+mapPredicate.size());

	while(eachValue!=null){
		String nextLine = keyValueFile.readLine();
  		char search = ';';             // Character to search is 'a'.
  
  		int count=0;
  		for(int i=0; i<nextLine.length(); i++)
  		{
      			if(nextLine.charAt(i) == search)
      			count++;
  		}
		count=count/2;
		if(maxAssertionCount<count){
			maxAssertionCount=count;
			System.out.println("*********************eachLine1 "+maxAssertionCount);
		}
		System.out.println("*********************counter "+count);
		////System.out.println("eachValue*********************"+eachValue);
		mapOfPredAndSeq.put(eachValue,nextLine );
		eachValue = keyValueFile.readLine();
	}

        BufferedReader PC=new BufferedReader(new FileReader("exp/Condition_And_Predicates.txt"));
        String r=PC.readLine();
	Map<String,String> mapPredicate=new HashMap<String,String>();
        Map<String,String> mapDecisions=new HashMap<String,String>();
        
        while(r!=null){
	    String predicate = r;
	    String finalPredicateArray="";
	    mapPredicate.put(predicate, finalPredicateArray);
            r=PC.readLine();

        }
	

	BufferedReader originalFile=new BufferedReader(new FileReader(fileName));
	String eachLine=originalFile.readLine();
	
	
        PrintWriter out_metaFile_V3=new PrintWriter("exp/meta/MetaWithBracesWhile-V3.c");
	////System.out.println("*********************"+mapPredicate.size());

	while(eachLine!=null){
		for(String eachPredicate : mapPredicate.keySet()){
			if(eachLine.contains(" while(")||eachLine.contains(" while (")||eachLine.contains(" while(") ||eachLine.contains("for(")||eachLine.contains(" for(")||eachLine.contains(" for (")||eachLine.contains("  for (")){
//				int k1_f=eachPredicate.indexOf('(');
//				int k2_f=eachPredicate.lastIndexOf(')');
				String eachPredicate1=eachPredicate.substring(1, eachPredicate.length()-1);
				////System.out.println("*********************eachPredicate "+eachPredicate1);
					if(eachLine.replaceAll("\\s+","").contains(eachPredicate1)){
//						String assertStmts = mapPredicate.get(eachPredicate);
						////System.out.println("predicate1*********************"+eachLine);
						String DecisionAndConditions ="";
						//MCDC statements from mcdc mode 
	    					if(mapOfPredAndSeq.containsKey(eachLine)){
							DecisionAndConditions = mapOfPredAndSeq.get(eachLine);
							DecisionAndConditions=DecisionAndConditions.replace("(signedlongint)", "");
							DecisionAndConditions=DecisionAndConditions.replace("; ", ";\n");
							////System.out.println("DecisionAndConditions*********************"+DecisionAndConditions);
//							assertStmts = assertStmts + "\n" + DecisionAndConditions;
//	    					}else{
//	    					
//					String assertStmts1 = "assert("+eachPredicate1+");";					
//					String assertStmts2 = "assert(!("+eachPredicate1+"));";
//										
//					DecisionAndConditions = DecisionAndConditions + "\n" +assertStmts1 + "\n" +assertStmts2;
					}
	    					
	    					//decision assert statements from meta program 
//	    					String assertDecStmts = mapDecisions.get(eachPredicate);
//	    					assertDecStmts=assertDecStmts.replace("$", "||");
//	    					if(assertStmts.contains(assertDecStmts)){
//							assertDecStmts=""; //to avoid redundant decision seq
//	    					}

//	    					String asserts_scmcc[] = assertStmts.split("\\r?\\n");
//	    					String asserts_mcdc[] = DecisionAndConditions.split("\\r?\\n");
//	    					List<String> slist =  new ArrayList(Arrays.asList(asserts_scmcc));
//	    					String assertStmts1 ="";
//        					for (String s : asserts_mcdc) {
//            						if (slist.contains(s)) {
//                						slist.remove(s);
//            						} else {
//                					slist.add(s);
//                					assertStmts1=assertStmts1+"\n"+s;
//            						}
//             
//        					}
//						// Print the result
//						for (String n : slist) {
//    							//System.out.println(n);
//    							assertStmts1=assertStmts1+"\n"+n;
//						}
						eachLine=eachLine.replace(eachLine, eachLine +"\n" + DecisionAndConditions);
						
						
						int openBraces = 0;
						int closeBraces = 0;
						while(true){
							out_metaFile_V3.println(eachLine);
							out_metaFile_V3.flush();
							eachLine = originalFile.readLine();
							if(eachLine.contains("{")){
								openBraces++;
							}
							if(eachLine.contains("}")){
								if(openBraces==closeBraces)
									break;
								closeBraces++;
							}
						}
						eachLine=eachLine.replace(eachLine,DecisionAndConditions +"\n" +eachLine);

						break;
					}
					

				
			}
			
		}
		out_metaFile_V3.println(eachLine);
		out_metaFile_V3.flush();
		////System.out.println("*********************"+eachLine);
		
		eachLine = originalFile.readLine();
	}

	originalFile=new BufferedReader(new FileReader("exp/meta/MetaWithBracesWhile-V3.c"));
	eachLine=originalFile.readLine();
	
        out_metaFile_V3=new PrintWriter("exp/meta/MetaWithBraces-V4.c");
	////System.out.println("*********************"+mapPredicate.size());

	while(eachLine!=null){
		for(String eachPredicate : mapPredicate.keySet()){
			
			if(!(eachLine.contains(" while(")||eachLine.contains(" while (")||eachLine.contains(" while(") ||eachLine.contains(" for(")||eachLine.contains(" for (")||eachLine.contains("  for (") || eachLine.contains("assert("))){
//			String assertStmts = mapPredicate.get(eachPredicate);
			if(eachLine.replaceAll("\\s+","").contains(eachPredicate)){
				
//				if(assertStmts.contains("||")){
//					assertStmts=assertStmts.replace("||", "&&");
//				}
				//assertStmts=assertStmts.replace("$", "||");
				////System.out.println("predicate1*********************"+eachLine);
				
				//decision and condition assert statements from mcdc mode 
				String DecisionAndConditions="";
	    			if(mapOfPredAndSeq.containsKey(eachLine)){
					DecisionAndConditions = mapOfPredAndSeq.get(eachLine);
					DecisionAndConditions=DecisionAndConditions.replace("(signedlongint)", "");
					DecisionAndConditions=DecisionAndConditions.replace("; ", ";\n");
					mapOfPredAndSeq.put(eachLine,DecisionAndConditions);
					int counter = 0;
					if(DecisionAndConditions.contains("usymb")){
					for (int index = DecisionAndConditions.indexOf("usymb");
     						index > 0;
     						index = DecisionAndConditions.indexOf("usymb", index + 1))		
						{

//System.out.println("predicate1*********************"+DecisionAndConditions);
    							counter++;
							String var="usymb"+counter;
//System.out.println("counter*********************"+index);
if(counter>9){
DecisionAndConditions =DecisionAndConditions.substring(0, index)+ var + 
DecisionAndConditions.substring(index+var.length()-2);
} else
DecisionAndConditions =DecisionAndConditions.substring(0, index)+ var + 
DecisionAndConditions.substring(index+var.length()-1);
//System.out.println("counter*********************"+var);
					
						}
					
					}

					
					}	
	    				
//	    			//decision assert statements from meta program 
//	    			String assertDecStmts = mapDecisions.get(eachPredicate);
//				assertDecStmts=assertDecStmts.replace("$", "||");
//				if(assertStmts.contains(assertDecStmts)){
//					assertDecStmts=""; //to avoid redundant decision seq
//	    			}
//	    			
//						String asserts_scmcc[] = assertStmts.split("\\r?\\n");
//	    					String asserts_mcdc[] = DecisionAndConditions.split("\\r?\\n");
//	    					List<String> slist =  new ArrayList(Arrays.asList(asserts_scmcc));
//	    					String assertStmts1 ="";
//        					for (String s : asserts_mcdc) {
//            						if (slist.contains(s)) {
//                						slist.remove(s);
//                						//System.out.println(s);
//            						} 
//            					
//             
//        					}
//						// Print the result
//						for (String n : slist) {
//    							
//    							assertStmts1=assertStmts1+"\n"+n;
//						}
				eachLine=eachLine.replace(eachLine,DecisionAndConditions +"\n" + eachLine);
				////System.out.println("*********************eachLine1 "+eachLine);
				break;
			}
			}else  if(eachLine.contains("assert(")){
				eachLine=eachLine.replace("||", "&&");
				eachLine=eachLine.replace("$", "");
				
			}
			
			
		}
//		System.out.println("*********************counter123 "+maxAssertionCount);
		if(eachLine.contains("#define BOUND")){
//				String initvars=eachLine+"\n"+"int usymb1,usymb2, usymb3,usymb4, usymb5, usymb6, usymb7, usymb8, usymb9, usymb10, usymb11,usymb12,usymb13,usymb14,usymb15,usymb16,usymb17,usymb18,usymb19,usymb20,usymb21,usymb22,usymb23,usymb24,usymb25,usymb26,usymb27,usymb28,usymb29,usymb30,usymb31,usymb32,usymb33,usymb34,usymb35,usymb36,usymb37,usymb38,usymb39,usymb40,usymb41,usymb42,usymb43,usymb44,usymb45,usymb46,usymb47,usymb48,usymb49;";
				String initvars=eachLine+"\n"+"int usymb1";
				for(int itr=2; itr<=maxAssertionCount; itr++){
					initvars = initvars+",usymb"+itr;
				}
				initvars=initvars+";";
				eachLine=eachLine.replace(eachLine, initvars);
			}
		if(eachLine.contains("int X")){
//				String symbvars=eachLine+"\n"+"scanf(\"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\",&usymb1,&usymb2, &usymb3,&usymb4, &usymb5, &usymb6, &usymb7, &usymb8, &usymb9, &usymb10, &usymb11,&usymb12,&usymb13,&usymb14,&usymb15,&usymb16,&usymb17,&usymb18,&usymb19,&usymb20,&usymb21,&usymb22,&usymb23,&usymb24,&usymb25,&usymb26,&usymb27,&usymb28,&usymb29,&usymb30,&usymb31,&usymb32,&usymb33,&usymb34,&usymb35,&usymb36,&usymb37,&usymb38,&usymb39,&usymb40,&usymb41,&usymb42,&usymb43,&usymb44,&usymb45,&usymb46,&usymb47,&usymb48,&usymb49);";
//				String symbvars=eachLine+"\n"+"scanf(\"%d";
//				for(int itr=2; itr<=maxAssertionCount; itr++){
//					symbvars = symbvars+"%d";
//				}
//				symbvars=symbvars+"\",&usymb1";
//				for(int itr=2; itr<=maxAssertionCount; itr++){
//					symbvars = symbvars+",&usymb"+itr;
//				}
//				symbvars=symbvars+");";
//				eachLine=eachLine.replace(eachLine, symbvars);

				String symbvars1=eachLine+"\n";
				String symbvars2="";
				for(int itr=1; itr<=maxAssertionCount; itr++){
					symbvars2 =symbvars2+ "scanf(\"%d\",&usymb"+itr+");"+"\n";
				}
				eachLine=eachLine.replace(eachLine, symbvars1+symbvars2);

			}
		out_metaFile_V3.println(eachLine);
		out_metaFile_V3.flush();
		
		eachLine = originalFile.readLine();
	}

//	LineNumberReader lineNumberReader = new LineNumberReader(new FileReader("exp/meta/MetaWithBraces-V4.c"));
//	eachLine=lineNumberReader.readLine();
//	PrintWriter out_metaFile_Loop=new PrintWriter("exp/meta/LoopAssertStatements.csv");
//	
//	while(eachLine!=null){
//			//////System.out.println("Reading"+eachLine);
//			//LoopNum++;
//			eachLine = generateDB(eachLine, mapOfPredAndSeq, lineNumberReader, out_metaFile_Loop);
//			///////////////////////////////////////////////////////////////
//		eachLine=lineNumberReader.readLine();
//		
//	}
//	lineNumberReader.close();
	
            
    }
//	public static int LoopNum = 1;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	public static String generateDB(String eachLine,  Map<String,String> mapOfPredAndSeq, LineNumberReader lineNumberReader, PrintWriter out_metaFile_Loop) throws IOException{
//		
//		if((eachLine.contains(" while(")||eachLine.contains(" while (")||eachLine.contains(" while(") ||eachLine.contains(" for(")||eachLine.contains(" for (")||eachLine.contains("  for ("))&& !eachLine.contains(" while(0)") && !eachLine.contains(" for(;0;)") && !eachLine.contains(" while(1)") && !eachLine.contains(" for(;1;)")){
//				for(String eachPredicate : mapOfPredAndSeq.keySet()){
//				
//					//////System.out.println("Reading");
//				String eachPredicate1=eachPredicate.substring(1, eachPredicate.length()-1);
//				//////System.out.println("*********************eachPredicate "+eachPredicate1);
//					if(eachPredicate1.length()!=1 && eachLine.replaceAll("\\s+","").contains(eachPredicate1)){
//						
//						int enteringLNum = lineNumberReader.getLineNumber();
//						//////System.out.println("Line number of "+eachLine+" at line "+lineNumberReader.getLineNumber());
//						
//						String assertStmts = mapOfPredAndSeq.get(eachPredicate);
//						String[] lines = assertStmts.split("\r\n|\r|\n");
//						int totalLines = lines.length-1;
//						if(lines.length ==1){
//							totalLines=2;
//						}
//						//////System.out.println("Total Lines "+lines.length);
//						while(true){
//							eachLine = lineNumberReader.readLine();
//							if(eachLine.contains("}")){
//								//LoopNum++;
//								break;
//							}else if(eachLine.contains("{")){
//								eachLine = generateDB(eachLine,  mapOfPredAndSeq, lineNumberReader, out_metaFile_Loop);
//							}
//						}
//						int closingLNum = lineNumberReader.getLineNumber()-1;
//						
//						for(int itr=1; itr<=totalLines; itr++){
//							String linedata = "L"+LoopNum+";"+enteringLNum+";"+(enteringLNum+itr)+";"+((closingLNum-totalLines)+itr);
//							out_metaFile_Loop.println(linedata);
//							out_metaFile_Loop.flush();
//							//if(itr==totalLines){LoopNum++;}
//						}
//						++LoopNum;
//						break;
//						
//					}
//					
//				
//			}
//		}
//		return eachLine;
//	}
}
