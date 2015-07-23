import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;
import java.util.ArrayList;
class Scrabble {
	
	public static String sortWord(String word){
		char[] charactersInTheWord = word.toCharArray();
        Arrays.sort(charactersInTheWord);
        String sortedWord = new String(charactersInTheWord);
        return sortedWord;
		}
	

	public ArrayList<String> generateAllCombinations(String rack){
		ArrayList<String> combinations = new ArrayList<String>();
		{
			for(char c : rack){
				for(int i =0 ; i<rack.length();i++){
					rack.substring(rack.indexOf('c'),;
				}
			}
		}
	}
	
	public static void main(String arg[])throws IOException{
	BufferedReader br = new BufferedReader(
        new InputStreamReader(new FileInputStream("input.txt")));
		PrintWriter writer = new PrintWriter ("anagramsoutput.txt", "UTF-8");
   		HashMap<String,String> anagrams = new HashMap<String,String>();
		String word;
		while((word = br.readLine()) != null){
			String sortedWord = sortWord(word);
			if(anagrams.get(sortedWord)!=null) {
				String value = anagrams.get(sortedWord) ;
				value = value + " " + word;
				anagrams.put(sortedWord,value);
			}
			else
				anagrams.put(sortedWord,word);
	
		}
		for(Map.Entry<String, String> entry: anagrams.entrySet()) 
			if (entry.getValue().indexOf(" ") != -1)
				writer.println(entry.getValue());
	}
	
}