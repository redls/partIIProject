package PartIIProject;

//import home.laura.stanford-english-corenlp-2016-10-31-models;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.StringReader;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import edu.stanford.nlp.ling.CoreLabel;
import edu.stanford.nlp.ling.HasWord;
import edu.stanford.nlp.ling.Sentence;
import edu.stanford.nlp.process.*;
public class StartPoint {

	public static void main(String[] args) {
		Map<String, Long> vocabulary = new HashMap<String, Long>();
		 try {
			BufferedReader bufferReader = new BufferedReader(new FileReader("/home/laura/Project/partIIProject/testReading.txt"));
			String currentLine;
			
			File writeFile = new File("/home/laura/Project/partIIProject/outputParsing.txt");
			// if file doesnt exists, then create it
			if (!writeFile.exists()) {
				writeFile.createNewFile();
			}
			FileWriter fw = new FileWriter(writeFile.getAbsoluteFile());
			BufferedWriter bufferWrite = new BufferedWriter(fw);
			while ((currentLine = bufferReader.readLine()) != null) {
				DocumentPreprocessor dp = new DocumentPreprocessor(currentLine);
				for (List<HasWord> sentence : dp) {
					   String sentenceString = Sentence.listToString(sentence);
					   bufferWrite.write(sentenceString);
				}
			}
			
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		 
		 

		 String sent2 = "This is another sentence...";
		 TokenizerFactory<CoreLabel> tokenizerFactory =
				    PTBTokenizer.factory(new CoreLabelTokenFactory(), "");
	     List<CoreLabel> rawWords2 =
				    tokenizerFactory.getTokenizer(new StringReader(sent2)).tokenize();
		 System.out.println(rawWords2);		
	}
}
