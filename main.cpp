#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int alphaScores[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

class Word
{
    pair<int, string> wordWithScore;
    int calculateScore()
    {
        int sum = 0;
        int length = this->wordWithScore.second.length();
        for (int i = 0; i < length; i++)
        {
            sum += alphaScores[this->wordWithScore.second[i]-'a'];
        }
        return sum;
    }
public:
    Word(string word)
    {
        this->wordWithScore.second = word;
        this->wordWithScore.first = calculateScore();
    }
    int getScore()
    {
        return this->wordWithScore.first;
    }
    string getWord()
    {
        return this->wordWithScore.second;
    }
    pair<int, string> getWordWithScore() const
    {
        return this->wordWithScore;
    }
};
void getFile(string filename, ifstream& file);
void sortDictionary(vector<Word>& dictionary);
vector<string> getMaxScoreScrabble(string rack, vector<Word> dictionary);


int main()
{
    ifstream file;
    string line;
    vector<Word> dictionary;

    getFile("dictionary", file);

    if (file.is_open())
    {
        while (getline (file,line))
        {
            Word word(line);
            dictionary.push_back(word);
        }
    }

    sortDictionary(dictionary);

    string rack="a_cd";
    vector<string> wordSuggestions = getMaxScoreScrabble(rack, dictionary);
    for(string s : wordSuggestions){
        cout<<s<<"\n";
    }


}

void getFile(string filename, ifstream& file)
{
    ifstream f(filename.c_str());
    if (f.is_open())
    {
        file.open(filename.c_str());
        return;
    }
    cout<<"\n unable to open file";
}

bool wordCompare(const Word& word1, const Word& word2)
{
    return word1.getWordWithScore() > word2.getWordWithScore();
}

void sortDictionary(vector<Word>& dictionary)
{
    sort(dictionary.begin(), dictionary.end(), wordCompare);
}

vector<string> getMaxScoreScrabble(string rack, vector<Word> dictionary)
{
    vector<string> wordSuggestions;
    for(Word word : dictionary)
    {
        if(word.getWord().length()<=rack.length())
        {
            string s(rack);
            bool flag = true;
            for(char c : word.getWord())
            {
                int index = s.find(c);
                if (index == string::npos)
                {
                    index = s.find('_');
                    if (index == string::npos )
                    {
                        flag = false;
                        break;
                    }
                }
                s.erase(index, 1);
            }
            if (flag)
            {
                wordSuggestions.push_back(word.getWord());
                //return word.getWord();
            }
        }
    }
    return wordSuggestions;
}



