/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package sjg_project;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class MCDC_Sequence_Generator_multiple {
    public static void main(String[] args) throws IOException {
    	String fileName = "";
    	if (args.length > 0) {
    		fileName = args[0];
    	}else{
	        System.err.println("File name not provided!");
	        System.exit(1);
    	}
         BufferedReader fpReadPredicate1 = null;
        try {
        
        
            //---------enter the c file name to generate the conditions and prediactes
            //fpReadPredicate1 = new BufferedReader(new FileReader("nsichneu.c"));
            fpReadPredicate1 = new BufferedReader(new FileReader(fileName));
            String r=fpReadPredicate1.readLine();
            PrintWriter out_cp=new PrintWriter("exp/Condition_And_Predicates.txt");
            while(r!=null){
            //if((!r.contains("#")&&!r.contains("//"))&&(r.contains(" if(")||r.contains(" if (")||r.contains(" while(")||r.contains(" while (")||r.contains(" for(")||r.contains(" for (")||r.contains("<=")||r.contains("==")||r.contains(">=")||r.contains("!=")||r.contains("<")||r.contains(">")||r.contains("&&")||r.contains("||"))){
            if((!r.contains("#")&&!r.contains("//")&&!r.contains("<<")&&!r.contains("'>'")&&!r.contains("'<'")&&!r.contains(">>"))&&(((r.contains(" if(")||r.contains(" if (")||r.contains("    if (")||r.contains(" while(")||r.contains(" while (")||r.contains(" while(")||r.contains("while(1)")||r.contains("while(0)")||r.contains(" for(")||r.contains(" for (")||r.contains("   for (")))||((r.contains("<=")||r.contains("==")||r.contains(">=")||r.contains("!=")||r.contains("<")||r.contains(">")||r.contains("&&")||r.contains("||"))))){
            
            if(r.contains(" for(")||r.contains(" for (")||r.contains("  for (")){
            int k1_f=r.indexOf(';');
            int k2_f=r.lastIndexOf(';');
            r=r.substring(k1_f + 1, k2_f);
            r="("+r+")";
            }
            r=r.trim();
            int p1=r.indexOf('(');
            int p2=r.lastIndexOf(')');
            r=r.substring(p1, p2+1);
            r=r.replace(" ", "");
            out_cp.println(r);
	    //System.out.println("*********************"+r);
            out_cp.flush();
            }
            r=fpReadPredicate1.readLine();
            }
            
          //--------------------------------------------------------

          //---------------Creating a java file corresponding to every predicate in order to evalaute the truth values with the dont care items.
           BufferedReader readpred=new BufferedReader(new FileReader("exp/Condition_And_Predicates.txt"));
           String r1=readpred.readLine();
          int pc=0;
          
           int predicate_count=0;
           while(r1!=null){
           if(r1.contains("&&")||r1.contains("||")){
           predicate_count++;
           r1=r1.replace("||", "@"); //change from `
             r1=r1.replace("&&", "#");
             r1=r1.replace(" ", "");r1=r1.replace("+", "");
             r1=r1.replace(" ", "");r1=r1.replace("-", "");
             r1=r1.replace(" ", "");r1=r1.replace("*", "");
             r1=r1.replace(" ", "");r1=r1.replace("/", ""); 
             r1=r1.replace(" ", "");r1=r1.replace("%", "");
             r1=r1.replace("[", "");
             r1=r1.replace("]", "");
           
             
             r1=r1.replace("1", "");r1=r1.replace("2", "");r1=r1.replace("3", "");r1=r1.replace("4", "");r1=r1.replace("5", "");r1=r1.replace("6", "");
             r1=r1.replace("7", "");r1=r1.replace("8", "");r1=r1.replace("9", "");r1=r1.replace("0", "");
             r1=r1.replace("P", "");
          r1=r1.replace(")==(","");
             r1=r1.replace(")!=(","");
             r1=r1.replace(")>=(","");
             r1=r1.replace(")<=(","");
             r1=r1.replace(")>(","");
             r1=r1.replace(")<(","");
             
             r1=r1.replace("==(","(");
             r1=r1.replace("!=(","(");
             r1=r1.replace(">=(","(");
             r1=r1.replace("<=(","(");
             r1=r1.replace(">(","(");
             r1=r1.replace("<(","(");
             
             r1=r1.replace(")==",")");
             r1=r1.replace(")!=",")");
             r1=r1.replace(")>=",")");
             r1=r1.replace(")<=",")");
             r1=r1.replace(")>",")");
             r1=r1.replace(")<",")");
			 
			 //Some modification on on 13/082018 based on changes made in RCCTechnique on 29/07/2018, some predicateResults were getting missed due to missing of following code.
			 r1=r1.replace("(==","(");
             r1=r1.replace("(!=","(");
             r1=r1.replace("(>=","(");
             r1=r1.replace("(<=","(");
             r1=r1.replace("(>","(");
             r1=r1.replace("(<","(");
             
             r1=r1.replace("==)",")");
             r1=r1.replace("!=)",")");
             r1=r1.replace(">=)",")");
             r1=r1.replace("<=)",")");
             r1=r1.replace(">)",")");
             r1=r1.replace("<)",")");
			 
			 
			 
             /////////////////////////////////////

             
             r1=r1.replace("()", "EMPTY");
             String req_r=r1;
             r1=r1.replace("(", "");
             r1=r1.replace(")","");

              r1=r1.replace("!=","Y;Y");
              r1=r1.replace("!","");
              r1=r1.replace("Y;Y","!=");
               //int i_char=65;
               int i_char=93;
             String k[]=r1.split("@"); //change from `
             if(k.length>=2){
              for(String rp:k){
                  req_r=req_r.replaceFirst(rp, (char)i_char+++"");
              if(rp.contains("#")){
              String k1[]=rp.split("#");
              for(String rp1:k1){
              req_r=req_r.replaceFirst(rp1, (char)i_char+++"");}
              }
              }
             }else{String k1[]=r1.split("#");
              for(String rp1:k1){
              req_r=req_r.replaceFirst(rp1, (char)i_char+++"");}
              }
             //i_char=65;
             i_char=93;
            req_r=req_r.replace("@", "||"); //change from `
             req_r=req_r.replace("#", "&&");
             // System.out.println("..................."+req_r);
              pc++;
               PrintWriter out_pred=new PrintWriter("Seq_For_Pred"+pc+".java");
           out_pred.println("import java.io.FileNotFoundException;\n" +
"import java.io.PrintWriter;\n" +
"public class Seq_For_Pred"+pc+"{\n" +
"    public static void main(String[] args) throws FileNotFoundException {");
              out_pred.println(" String k"+predicate_count+"=\""+req_r+"\";\n" +
"        String m"+predicate_count+"=k"+predicate_count+";\n" +
"       k"+predicate_count+"=k"+predicate_count+".replace(\"|\", \"k"+predicate_count+"\");\n" +
"        k"+predicate_count+"=k"+predicate_count+".replace(\"(\", \"\").replace(\")\", \"\").replaceAll(\"&\", \"\").replaceAll(\"!\", \"\").replaceAll(\"k"+predicate_count+"\", \"\");\n" +
"        int no_of_var"+predicate_count+"=k"+predicate_count+".length();\n" +
"        int p"+predicate_count+"=(int) Math.pow(2, no_of_var"+predicate_count+");\n" +
"        boolean tt"+predicate_count+"[][]=new boolean[p"+predicate_count+"][no_of_var"+predicate_count+"+1];\n" +
"        for (int b_val_str"+predicate_count+"=0;b_val_str"+predicate_count+"<p"+predicate_count+";b_val_str"+predicate_count+"++){\n" +
"        String maxAmpStr"+predicate_count+" = Integer.toBinaryString(b_val_str"+predicate_count+");\n" +
"            String catstring"+predicate_count+"=\"\";\n" +
"            if(maxAmpStr"+predicate_count+".length()<no_of_var"+predicate_count+"){\n" +
"            int hm"+predicate_count+"=no_of_var"+predicate_count+"-maxAmpStr"+predicate_count+".length();\n" +
"            for(int h2"+predicate_count+"=0;h2"+predicate_count+"<hm"+predicate_count+";h2"+predicate_count+"++){\n" +
"                catstring"+predicate_count+"=catstring"+predicate_count+"+\"0\";\n" +
"            }\n" +
"            maxAmpStr"+predicate_count+"=catstring"+predicate_count+"+maxAmpStr"+predicate_count+";\n" +
"            }");

              out_pred.println("char[] arr"+predicate_count+" = maxAmpStr"+predicate_count+".toCharArray();\n" +
"    for (int i"+predicate_count+"=0; i"+predicate_count+"<maxAmpStr"+predicate_count+".length()&&i"+predicate_count+"<no_of_var"+predicate_count+"; i"+predicate_count+"++){\n" +
"        if (arr"+predicate_count+"[i"+predicate_count+"] == '1'){             \n" +
"            tt"+predicate_count+"[b_val_str"+predicate_count+"][i"+predicate_count+"] = true;  \n" +
"        }\n" +
"        else if (arr"+predicate_count+"[i"+predicate_count+"] == '0'){\n" +
"             tt"+predicate_count+"[b_val_str"+predicate_count+"][i"+predicate_count+"] = false; \n" +
"        }\n" +
"      }\n" +
"        }\n" +
"        int no_of_con"+predicate_count+"[]=new int[p"+predicate_count+"];\n" +
"        \n" +
"          String dup_dont"+predicate_count+"[][]=new String[p"+predicate_count+"][no_of_var"+predicate_count+"+1];\n" +
"       for(int h1"+predicate_count+"=0;h1"+predicate_count+"<p"+predicate_count+";h1"+predicate_count+"++){\n" +
"        boolean exp_val"+predicate_count+"=false;\n" +
"        int upto"+predicate_count+"=0;\n" +
"        int keep"+predicate_count+"[]=new int[no_of_var"+predicate_count+"];\n" +
"        for(int h3"+predicate_count+"=0;h3"+predicate_count+"<no_of_var"+predicate_count+";h3"+predicate_count+"++){\n" +
"        keep"+predicate_count+"[h3"+predicate_count+"]=h3"+predicate_count+";\n" +
"        }");
              //------------------------------------------
              String str_req_r=req_r;
              char[] arr2 = str_req_r.toCharArray();
              String expr="";
    for (int i=0,j=0; i<str_req_r.length(); i++){
    //System.out.println("llop..."+arr2[i]);
    if(arr2[i]!='<'){
    //if(arr2[i]>='A'&&arr2[i]<='Z'){
    if((arr2[i]>=']') && (arr2[i]<='{')){
    expr=expr+"tt"+predicate_count+"[h1"+predicate_count+"][keep"+predicate_count+"["+j+"]++]";
    j++;
    //System.out.println("first..........."+expr);
    }
    else{
    	//System.out.println(""+expr);
        expr=expr+arr2[i];
    }
    }
    }
               //System.out.println(""+expr);
               out_pred.println(" exp_val"+predicate_count+"="+expr+";");

               out_pred.println("tt"+predicate_count+"[h1"+predicate_count+"][no_of_var"+predicate_count+"]=exp_val"+predicate_count+";\n" +
"        for(int h3"+predicate_count+"=0;h3"+predicate_count+"<no_of_var"+predicate_count+";h3"+predicate_count+"++){\n" +
"        if(keep"+predicate_count+"[h3"+predicate_count+"]==h3"+predicate_count+")\n" +
"        {dup_dont"+predicate_count+"[h1"+predicate_count+"][h3"+predicate_count+"]=\"X\";}\n" +
"        else{\n" +
"                 if(tt"+predicate_count+"[h1"+predicate_count+"][h3"+predicate_count+"]==true){\n" +
"     dup_dont"+predicate_count+"[h1"+predicate_count+"][h3"+predicate_count+"]=\"T\";\n" +
"     }\n" +
"     else{\n" +
"     dup_dont"+predicate_count+"[h1"+predicate_count+"][h3"+predicate_count+"]=\"F\";\n" +
"    }}\n" +
"        } \n" +
"        if(tt"+predicate_count+"[h1"+predicate_count+"][no_of_var"+predicate_count+"]==true)\n" +
"        dup_dont"+predicate_count+"[h1"+predicate_count+"][no_of_var"+predicate_count+"]= \"T\";\n" +
"        else\n" +
"            dup_dont"+predicate_count+"[h1"+predicate_count+"][no_of_var"+predicate_count+"]= \"F\";\n" +
"       }\n" +
"    \n" +
"    int bitset"+predicate_count+"[]=new int[p"+predicate_count+"];\n" +
"    for(int hr"+predicate_count+"=0;hr"+predicate_count+"<p"+predicate_count+";hr"+predicate_count+"++)bitset"+predicate_count+"[hr"+predicate_count+"]=0;\n" +
"    for(int h1"+predicate_count+"=0;h1"+predicate_count+"<p"+predicate_count+";h1"+predicate_count+"++){\n" +
"      for(int h2"+predicate_count+"=h1"+predicate_count+"+1;h2"+predicate_count+"<p"+predicate_count+";h2"+predicate_count+"++){\n" +
"          int k_mat"+predicate_count+"=0;\n" +
"      if(bitset"+predicate_count+"[h2"+predicate_count+"]==0){\n" +
"        for(int h3"+predicate_count+"=0;h3"+predicate_count+"<=no_of_var"+predicate_count+";h3"+predicate_count+"++){\n" +
"        if(dup_dont"+predicate_count+"[h1"+predicate_count+"][h3"+predicate_count+"].equals(dup_dont"+predicate_count+"[h2"+predicate_count+"][h3"+predicate_count+"])) k_mat"+predicate_count+"++;\n" +
"        }\n" +
"        if(k_mat"+predicate_count+"==no_of_var"+predicate_count+"+1)\n" +
"        { \n" +
"            bitset"+predicate_count+"[h2"+predicate_count+"]=1;}\n" +
"       \n" +
"      }\n" +
"      }\n" +
"    }\n" +
"    ");

              out_pred.println("//-----------------Counting MCC Rows---------------\n" +
"    int mcc_rows"+predicate_count+"=0;\n" +
"     for(int ik"+predicate_count+"=0;ik"+predicate_count+"<p"+predicate_count+";ik"+predicate_count+"++){\n" +
"           if(bitset"+predicate_count+"[ik"+predicate_count+"]==0){\n" +
"               mcc_rows"+predicate_count+"++;\n" +
"           }\n" +
"     }\n" +
"     //------------------------------------------------\n" +
"     String MCC_Data"+predicate_count+"[][]=new String[mcc_rows"+predicate_count+"][no_of_var"+predicate_count+"+1];\n" +
"     for(int ik"+predicate_count+"=0,ikp1"+predicate_count+"=0;ik"+predicate_count+"<p"+predicate_count+";ik"+predicate_count+"++){\n" +
"           if(bitset"+predicate_count+"[ik"+predicate_count+"]==0){\n" +
"           for(int h2"+predicate_count+"=0;h2"+predicate_count+"<=no_of_var"+predicate_count+";h2"+predicate_count+"++){\n" +
"               MCC_Data"+predicate_count+"[ikp1"+predicate_count+"][h2"+predicate_count+"]=dup_dont"+predicate_count+"[ik"+predicate_count+"][h2"+predicate_count+"];\n" +
"               }\n" +
"              ikp1"+predicate_count+"++; \n" +
"           }\n" +
"          \n" +
"        }\n" );






   out_pred.println("  PrintWriter out_truthTable"+predicate_count+"=new PrintWriter(\"exp/predicateResults"+predicate_count+".txt\");\n" +
"    int array_mark"+predicate_count+"[]=new int[mcc_rows"+predicate_count+"];\n" +
"    for(int je"+predicate_count+"=0;je"+predicate_count+"<no_of_var"+predicate_count+";je"+predicate_count+"++)\n" +
"        {\n" +
"            for(int je1"+predicate_count+"=0;je1"+predicate_count+"<mcc_rows"+predicate_count+";je1"+predicate_count+"++){\n" +
"                 if(array_mark"+predicate_count+"[je1"+predicate_count+"]==0){\n" +
"                 for(int je3"+predicate_count+"=0;je3"+predicate_count+"<no_of_var"+predicate_count+";je3"+predicate_count+"++){out_truthTable"+predicate_count+".print(\"\"+MCC_Data"+predicate_count+"[je1"+predicate_count+"][je3"+predicate_count+"]+\",\");\n" +
"                 }\n" +
"                     out_truthTable"+predicate_count+".println();\n" +
"                     array_mark"+predicate_count+"[je1"+predicate_count+"]=1;\n" +
"                 }\n" +
"               out_truthTable"+predicate_count+".flush(); " +
"                 }\n"+
"                 }\n"
);


              out_pred.flush();
                out_pred.println("            }\n" +
"        \n" +
" \n" +
"}"); out_pred.flush();
           }

           r1=readpred.readLine();
           }

        } catch (FileNotFoundException ex) {
            Logger.getLogger(MCDC_Sequence_Generator_multiple.class.getName()).log(Level.SEVERE, null, ex);
        }

    }
}


















