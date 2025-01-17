package InputProcessing;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StringReader;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import edu.stanford.nlp.ling.CoreLabel;
import edu.stanford.nlp.ling.HasWord;
import edu.stanford.nlp.ling.Sentence;
import edu.stanford.nlp.process.CoreLabelTokenFactory;
import edu.stanford.nlp.process.DocumentPreprocessor;
import edu.stanford.nlp.process.PTBTokenizer;
import edu.stanford.nlp.process.TokenizerFactory;

public class RetrieveVocabulary {
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
			long indexReview = 0;
			while ((currentLine = bufferReader.readLine()) != null) {
				indexReview++;
				DocumentPreprocessor dp = new DocumentPreprocessor(new StringReader(currentLine));
				for (List<HasWord> sentence : dp) {
				   for(HasWord i: sentence) {
					   String word = i.word().toLowerCase();
					   if (vocabulary.containsKey(word)) {
						   long count = vocabulary.get(word);
						   vocabulary.put(word, count + 1);
					   } else vocabulary.put(word, (long) 1);
				   }
				   String sentenceString = Sentence.listToString(sentence);		
				   bufferWrite.write(indexReview + " " + sentenceString + "\n");
				   
				}		
			}
			bufferWrite.close();
			bufferReader.close();
			File writeFileVocabulary = new File("/home/laura/Project/partIIProject/Vocabulary.txt");
			// if file doesnt exists, then create it
			if (!writeFileVocabulary.exists()) {
				writeFileVocabulary.createNewFile();
			}
			FileWriter fileWriterVocabulary = new FileWriter(writeFileVocabulary.getAbsoluteFile());
			BufferedWriter bufferWriteVocabulary = new BufferedWriter(fileWriterVocabulary);
			for(String word: vocabulary.keySet()) {
				bufferWriteVocabulary.write(word + " " + vocabulary.get(word) + "\n");
			}
			bufferWriteVocabulary.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		 

		 String sent2 = "This 's is another sentence...";
		 TokenizerFactory<CoreLabel> tokenizerFactory =
				    PTBTokenizer.factory(new CoreLabelTokenFactory(), "");
	     List<CoreLabel> rawWords2 =
				    tokenizerFactory.getTokenizer(new StringReader(sent2)).tokenize();
		 System.out.println(rawWords2);		
	}
}
