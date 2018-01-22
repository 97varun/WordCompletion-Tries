#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include </usr/include/ncurses.h>

#include "../include/Trie.h"

using namespace std;

const int kb = 127;	// backspace key

class wordPredictor {
	string input;

	vector<string> loadWords() {
		ifstream infile;
		infile.open("./data/words_alpha.txt");

		vector<string> words;

		if (!infile.good())	cout << "Screwed!" << endl;

		string tmp;
		while (infile.good() && !infile.eof()) {
			infile >> tmp;
			words.push_back(tmp);
		}

		return words;
	}

	Trie getTrie() {
		Trie T;
		vector<string> words = loadWords();

		for (int i = 0; i < (int) words.size(); ++i) {
			T.insertString(words[i]);
		}

		return T;
	}
public:
	wordPredictor() {
		input = "";
	}

	void run() {
		
		Trie T = getTrie();

		initscr();
		noecho();
		cbreak();
		mousemask(ALL_MOUSE_EVENTS, NULL);

		printw("Search: ");
		char ch = getch();

		do {
			// appropriate action for key entered
			if (ch == '\n' || ch == KEY_MOUSE)	continue;

			if (ch == kb) {
				if ((int) input.size())	input.pop_back();
			} else {
				input += ch;
			}

			// update screen
			clear();
			printw("Search: %s", input.c_str());
			refresh();

			// print new list of words
			// predict only after the user enters 3 or more characters.
			if ((int) input.size() > 2) {
				vector<string> wl = T.getWords(input);
				for (auto i : wl) {
					printw("\n        %s", i.c_str());
				}
				refresh();
			}

			// wait for next character
			ch = getch();
		} while (ch != '\n');

		endwin();
	}
};



int main() {

	wordPredictor app;

	app.run();

	return 0;
}
