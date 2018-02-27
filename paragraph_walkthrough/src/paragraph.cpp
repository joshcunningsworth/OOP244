#include <iostream>
using namespace std;
#define WIDTH 8

class Word {
	char* text;
    int nletters;
    public:
    Word() {
        text = NULL;
        nletters = 0;
        cout << 'W';
    }
    Word(const char* s) {
        nletters = 0;
        while(s[nletters] != '\0')
            nletters++;
        text = new char[nletters];
        for (int i = 0; i < nletters; i++)
            text[i] = s[i];
        cout << 'X';
    }
    Word(const Word& p) {
        text = NULL;
        *this = p;  // calls assignment operator below
        cout << 'Y';
    }
    ~Word() {
        if (text != NULL) delete [] text;
        cout << "~W" << nletters;
    }
    Word& operator=(const Word& p) {
        if (this != &p) {
            if (text != NULL) delete [] text;
            nletters = 0;
            if (p.text != NULL) {
                text = new char[p.nletters];
                while(nletters < p.nletters) {
                    text[nletters] = p.text[nletters];
                    nletters++;
                }
            }
            else
                text = NULL;
        }
        cout << 'V';
        return *this;
    }
    int nLetters() const { return nletters; }
    friend ostream& operator<<(ostream& os, const Word& w) {
        if (w.text != NULL)
            for (int i = 0; i < w.nletters; i++)
                os << w.text[i];
        else
            os << "***";
        os << ' ';
        return os;
    }
};

class Paragraph {
	Word* word;
    int mwords;
    int nwords;
    int width;
public:
    Paragraph() {
    	word  = NULL;
        width = WIDTH;
        nwords = 0;
        mwords = 0;
        cout << 'P' << endl;
    }
    Paragraph(const Paragraph& c) {
        word  = NULL;
        *this = c;  // calls assignment operator below
        cout << "cP";
    }
    Paragraph& operator=(const Paragraph& c) {
        if (this != &c) {
            if (word != NULL) delete [] word;
            if (c.word != NULL) {
                word = new Word[c.mwords];
                cout << endl;
                for (int i = 0; i < c.nwords; i++)
                    word[i] = c.word[i];  // calls Word assignment operator
            }
            else
                word = NULL;
            width  = c.width;
            nwords = c.nwords;
            mwords = c.mwords;
        }
        cout << "=P";
        return *this;
    }
    ~Paragraph() {
    	if (word != NULL) delete [] word;
        cout << '\n' << nwords << "~P" << endl;
    }
    void make(int m) {
        if(word == NULL){
        	word = new Word[m];
            mwords = m;
            nwords = 0;
            width  = WIDTH;
        }
    }
    void setWidth(int w) { width = w; }
    friend ostream& operator<<(ostream& os, const Paragraph& p) {
        int nextWord = 0;
        for(int i = 0; i < p.nwords; i++){
        	if (nextWord + p.word[i].nLetters() > p.width) {
                os << '\n';
                nextWord = 0;
            }
            cout << p.word[i];
            nextWord += p.word[i].nLetters() + 1;
        }
        return os;
    }
    Paragraph& operator+=(const char* w) {
        if (nwords < mwords) {
            cout << "\n+=";
            word[nwords] = w;  // calls Word constructor, then Word = operator
            nwords++;
        }
        return *this;
    }
};

int main() {

    Paragraph p;
    cout << "--------\n";
    p.make(5);
    p += "This";
    p += "is";
    p += "hard";
    cout << "\n--------\n";
    cout << p << endl;
    cout << "--------\n";
    Paragraph q = p;
    q.setWidth(6);
    q += "too";
    cout << "\n--------\n";
    cout << q << endl;
    cout << "---------------\n";
    return 0;
}
