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


public class MetaJavaFileGenerator_V6{
    public static int maxAssertionCount=0;
    public static void main(String[] args) throws FileNotFoundException, IOException {

	String fileName = "";
	if (args.length > 0) {
    		fileName = args[0];
    	}else{
	        System.err.println("File name not provided!");
	        System.exit(1);
    	}

	
        BufferedReader PC=new BufferedReader(new FileReader("exp/Condition_And_Predicates.txt"));
        String r=PC.readLine();
        String predicate1 = r;
        int no_of_pred=0;
	Map<String,String> mapPredicate=new HashMap<String,String>();
        Map<String,String> mapDecisions=new HashMap<String,String>();
        
        while(r!=null){

int indexOfAnd = 0, indexOfOr = 0, count = 0;
Map<Integer,String> mapPosition=new HashMap<Integer,String>();
        while (true) {
            indexOfAnd = r.indexOf("&&", indexOfAnd);
            if (indexOfAnd != -1) {
                mapPosition.put(indexOfAnd, "&&");
                indexOfAnd += 2;
            } else {
                break;
            }
        }	
	while (true) {
            indexOfOr = r.indexOf("||", indexOfOr);
            if (indexOfOr != -1) {
                mapPosition.put(indexOfOr, "||");
                indexOfOr += 2;
            } else {
                break;
            }
        }
Map<Integer, String> sortedMapPosition = new TreeMap<Integer, String>(mapPosition);
List<Integer> sortedKeys = new ArrayList<Integer>(sortedMapPosition.keySet());	    
//Set<Integer> sortedKeys = sortedMapPosition.keySet();
	    String predicate = r;
	    String finalPredicateArray="";
	    String finalPredicateArray1="";
	    String decisionPredicate="";
	    String assertStmts1 = "";					
	   String assertStmts2 = "";
            if(r.contains("&&")||r.contains("||")){
		
            	r=r.replace("&&", "~");
            	r=r.replace("||", "~");
	    	r=r.replace("(", "");
	    	r=r.replace(")", "");
            	String p[]=r.split("~");
            	no_of_pred++;
	    	BufferedReader PC1=new BufferedReader(new FileReader("exp/predicateResults"+no_of_pred+".txt"));
	    	PrintWriter out_cp_onlyvalue=new PrintWriter("exp/meta/metaFileOfPred-"+no_of_pred+".txt");
            
            	String r1=PC1.readLine();
	    	String tVal[] = null;
		int counter=0;
	    	for(int n1=0;n1<p.length;n1++){
			int insertFlag = 0;
			counter = 0;
			while(r1!=null){
				String finalPredicate = "";
	        		tVal=r1.split(",");
				Integer sortedKeysIndex = -1;
				for(int n2=0;n2<tVal.length;n2++){
					if(insertFlag==0 && p[n2].contains("!")){
						p[n2] = p[n2].replace("!=","$");
						if(p[n2].contains("!")){
							p[n2] = p[n2].replace("!","!(");
							p[n2] = p[n2].replace("$","!=");
							p[n2] = p[n2]+")";
						}else
							p[n2] = p[n2].replace("$","!=");	
					}
					////System.out.println(tVal[n2]);
					//Integer mapIndex=sortedKeys.get(sortedKeysIndex);
					if(tVal[n2].equals("F")){
						
						if(sortedKeysIndex != -1){
							////System.out.println("!"+p[n2] + finalPredicate.contains(p[n2]));
                                			finalPredicate = finalPredicate + sortedMapPosition.get(sortedKeys.get(sortedKeysIndex))+ "!("+p[n2]+")";
						}else{
							
							////System.out.println("!"+p[n2] + finalPredicate.contains(p[n2]));
                                			finalPredicate = "!("+p[n2]+")";
						}
						

					}else{
						if(sortedKeysIndex != -1){
							////System.out.println(p[n2]);
			                        	finalPredicate = finalPredicate + sortedMapPosition.get(sortedKeys.get(sortedKeysIndex)) + p[n2];
						}else{
							////System.out.println(p[n2]);
			                        	finalPredicate = p[n2];
						}
					}
					
					sortedKeysIndex++;
//					if(insertFlag==0){
//					assertStmts1 = "assert(("+p[n2]+") );";					
//					assertStmts2 = "assert((!("+p[n2]+")) );";
//					finalPredicateArray1 = finalPredicateArray1 + assertStmts1 + "\n" +assertStmts2;
//					}
		
				}
				counter++;
				String var="usymb"+counter;
				decisionPredicate = finalPredicate;
				finalPredicate = "if("+var+"){assert(!("+finalPredicate+"));}";
				finalPredicateArray = finalPredicateArray + "\n" +finalPredicate;	
				////System.out.println("*********************"+finalPredicate);
				out_cp_onlyvalue.println(finalPredicate);
				out_cp_onlyvalue.flush();	
				tVal=null;

				r1=PC1.readLine();
				insertFlag=1;
	
			}

			
		if(maxAssertionCount<counter){
			maxAssertionCount=counter;
		}

	    	}
	        
	    	////System.out.println("*********************"+p.length);

            }
//            if(finalPredicateArray==""){
//					assertStmts1 = "assert("+predicate+");";					
//					assertStmts2 = "assert(!("+predicate+"));";
//										
//					finalPredicateArray = finalPredicateArray + "\n" +assertStmts1 + "\n" +assertStmts2;
//					}
	    //System.out.println("2*********************"+finalPredicateArray);
	    finalPredicateArray = finalPredicateArray + "\n" +finalPredicateArray1;
	    //System.out.println("1*********************"+predicate);
	    
	    
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
				int k1_f=eachPredicate.indexOf('(');
				int k2_f=eachPredicate.lastIndexOf(')');
				String eachPredicate1=eachPredicate.substring(1, eachPredicate.length()-1);
				////System.out.println("*********************eachPredicate "+eachPredicate1);
					if(eachLine.replaceAll("\\s+","").contains(eachPredicate1)){
						String assertStmts = mapPredicate.get(eachPredicate);
						
						eachLine=eachLine.replace(eachLine, eachLine +"\n" + assertStmts);
						
						
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
						eachLine=eachLine.replace(eachLine,assertStmts +"\n" +eachLine);

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
			String assertStmts = mapPredicate.get(eachPredicate);
			if(eachLine.replaceAll("\\s+","").contains(eachPredicate)){
				
				if(assertStmts.contains("||")){
					assertStmts=assertStmts.replace("||", "&&");
				}
				eachLine=eachLine.replace(eachLine,assertStmts +"\n" + eachLine);
				////System.out.println("*********************eachLine1 "+eachLine);
				break;
			}
			}else  if(eachLine.contains("assert(")){
				eachLine=eachLine.replace("||", "&&");
				eachLine=eachLine.replace("$", "");
			}
			
			
			
		}
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
//			eachLine = generateDB(eachLine, mapPredicate, lineNumberReader, out_metaFile_Loop);
//			///////////////////////////////////////////////////////////////
//		eachLine=lineNumberReader.readLine();
//		
//	}
//	lineNumberReader.close();
	
            
    }
//	public static int LoopNum = 1;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	public static String generateDB(String eachLine,  Map<String,String> mapPredicate, LineNumberReader lineNumberReader, PrintWriter out_metaFile_Loop) throws IOException{
//		
//		if((eachLine.contains(" while(")||eachLine.contains(" while (")||eachLine.contains(" while(") ||eachLine.contains(" for(")||eachLine.contains(" for (")||eachLine.contains("  for ("))&& !eachLine.contains(" while(0)") && !eachLine.contains(" for(;0;)") && !eachLine.contains(" while(1)") && !eachLine.contains(" for(;1;)")){
//				for(String eachPredicate : mapPredicate.keySet()){
//				
//					//////System.out.println("Reading");
//				String eachPredicate1=eachPredicate.substring(1, eachPredicate.length()-1);
//				//////System.out.println("*********************eachPredicate "+eachPredicate1);
//					if(eachPredicate1.length()!=1 && eachLine.replaceAll("\\s+","").contains(eachPredicate1)){
//						
//						int enteringLNum = lineNumberReader.getLineNumber();
//						//////System.out.println("Line number of "+eachLine+" at line "+lineNumberReader.getLineNumber());
//						
//						String assertStmts = mapPredicate.get(eachPredicate);
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
//								eachLine = generateDB(eachLine,  mapPredicate, lineNumberReader, out_metaFile_Loop);
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
