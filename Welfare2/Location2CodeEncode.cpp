#include "stdafx.h"
#include "Location2CodeEncode.h"

using namespace std;

Location2CodeEncode::Location2CodeEncode() {
	isGenACode = false;
	isGenBCode = false;
	isACodeSaved = false;
	isBCodeSaved = false;
}

Location2CodeEncode::~Location2CodeEncode() {
	clear();
}


int Location2CodeEncode::generateACode(set<int> numbers) {
	if (!numbers.size()) {
		return -1;
	}
	tmpCode.clear();
	isGenACode = false;
	isACodeSaved = false;

	for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		if (*it > 9 || *it < 0) {
			continue;
		}
		for (int i = 0; i < 10 && encodeDict[*it][i] != -1; i++) {
			Location2Code code;
			code.codeSeq[0] = *it;
			code.codeSeq[1] = encodeDict[*it][i];
			code.freq = 1;
			tmpCode.push_back(code);
		}
	}

	// 去重
	removeDuplication(tmpCode);

	if (tmpCode.size()) {
		isGenACode = true;
	}

	return tmpCode.size();
}

int Location2CodeEncode::generateBCode(set<int> numbers) {
	if (!numbers.size()) {
		return -1;
	}
	tmpCode.clear();
	isGenBCode = false;

	for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		if (*it > 9 || *it < 0) {
			continue;
		}
		for (int i = 0; i < 10 && encodeDict[*it][i] != -1; i++) {
			Location2Code code;
			code.codeSeq[0] = encodeDict[*it][i];
			code.codeSeq[1] = *it;
			code.freq = 1;
			tmpCode.push_back(code);
		}
	}

	isBCodeSaved = false;

	// 去重
	removeDuplication(tmpCode);

	if (tmpCode.size()) {
		isGenBCode = true;
	}

	return tmpCode.size();
}

int Location2CodeEncode::killCode(set<int> boldCode) {
	if (!boldCode.size()) {
		return 0;
	}
	int before = tmpCode.size();
	for (vector<Location2Code>::iterator it = tmpCode.begin(); it != tmpCode.end();) {
		bool isContainsBoldCode = false;
		for (set<int>::iterator itb = boldCode.begin(); itb != boldCode.end(); itb++) {
			if (it->codeSeq[0] == *itb || it->codeSeq[1] == *itb) {
				isContainsBoldCode = true;
				break;
			}
		}
		if (!isContainsBoldCode) {
			it = tmpCode.erase(it);
			continue;
		}
		it++;
	}
	return before - tmpCode.size();
}

void Location2CodeEncode::print(vector<Location2Code> code) {
	if (!code.size()) {
		return;
	}

	for (vector<Location2Code>::iterator it = code.begin(); it != code.end(); it++) {
		cout << it->codeSeq[0] << it->codeSeq[1] << " --> " << it->freq << endl;
	}
}

bool Location2CodeEncode::clear() {
	aCode.clear();
	bCode.clear();
	isGenACode = false;
	isGenBCode = false;
	isACodeSaved = false;
	isBCodeSaved = false;
	return true;
}

bool equal(const vector<Location2Code>::iterator a, const vector<Location2Code>::iterator b) {
	return a->codeSeq[0] == b->codeSeq[0] && a->codeSeq[1] == b->codeSeq[1];
}

bool Location2CodeEncode::removeDuplication(vector<Location2Code> &code) {
	if (!tmpCode.size()) {
		return false;
	}
	for (vector<Location2Code>::iterator it = code.begin() + 1; it != code.end(); ) {
		bool isDuplication = false;
		for (vector<Location2Code>::iterator itNext = code.begin(); itNext != it; itNext++) {
			if (equal(it, itNext)) {
				isDuplication = true;
				itNext->freq += it->freq;
				break;
			}
		}
		if (isDuplication) {
			it = code.erase(it);
			continue;
		}
		it++;
	}
	return true;
}


int Location2CodeEncode::save(vector<Location2Code> &target, ABEnum ab) {

	if (!tmpCode.size() || (!isGenACode && !isGenBCode) || (isACodeSaved && isBCodeSaved)) {
		return 0;
	}

	for (vector<Location2Code>::iterator it = tmpCode.begin(); it != tmpCode.end(); it++) {
		target.push_back(*it);
	}

	if (ab == A) {
		isACodeSaved = true;
	}
	else if (ab == B) {
		isBCodeSaved = true;
	}

	int before = target.size();

	removeDuplication(target);

	sortByFreq(target);

	return target.size() - before;
}

bool comp(const Location2Code &a, const Location2Code &b)
{
	if (a.codeSeq[0] == b.codeSeq[0])
	{
		return a.codeSeq[1] < b.codeSeq[1];
	}
	else
		return a.codeSeq[0] < b.codeSeq[0];
}

bool compWithFreq(const Location2Code &a, const Location2Code &b) {
	if (a.freq == b.freq) {
		return comp(a, b);
	}
	else {
		return a.freq > b.freq;
	}
}

void Location2CodeEncode::sortByFreq(vector<Location2Code> &code) {
	if (code.size() <= 1) {
		return;
	}

	sort(code.begin(), code.end(), compWithFreq);
}


bool Location2CodeEncode::isGenerateACode() {
	return isGenACode;
}

bool Location2CodeEncode::isGenerateBCode() {
	return isGenBCode;
}

bool Location2CodeEncode::isSavedACode() {
	return isACodeSaved;
}

bool Location2CodeEncode::isSavedBCode() {
	return isBCodeSaved;
}

