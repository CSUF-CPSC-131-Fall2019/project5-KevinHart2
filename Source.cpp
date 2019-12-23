#include "WordFrequency.h"
#include "sanitize.h"
#include<fstream>
#include<sstream>

using namespace std;

WordFrequency::WordFrequency() {

}

void WordFrequency::readIn(const string& filename) {
	
	string word;
	ifstream file;
	file.open(filename);
	
	while (file >> word) {

		sanitize(word);

		if (word.at(word.size() - 1) == '.' || word.at(word.size() - 1) == '!' || word.at(word.size() - 1) == '?') {

			word = word.erase(word.size() - 1, 1);
		}
		++hmap[word];
	}
	file.close();	
}

size_t WordFrequency::numberOfWords() {

	return hmap.size();
}
size_t WordFrequency::wordCount(const string & word) {

	return hmap.at(word);
}

string WordFrequency::mostFrequentWord() {

	string secondWord;
	size_t x = 0; // max

	for (auto l = hmap.begin(); l != hmap.end(); ++l) {

		if (l->second > x) {

			x = l->second;
			secondWord = l->first;
		}
	}
	return secondWord;
}

size_t WordFrequency::maxBucketSize() {

	size_t maxAmount = 0;

	for (int i = 0; i < hmap.bucket_count(); i++) {

		if (hmap.bucket_size(i) > maxAmount) {

			maxAmount = hmap.bucket_size(i);
		}
	}
	return maxAmount;
}