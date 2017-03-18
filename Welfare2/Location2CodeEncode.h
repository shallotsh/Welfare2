#pragma once
#include<iostream>
#include<vector>
#include<set>
#include <algorithm>

using std::vector;
using std::set;

typedef struct {
	int codeSeq[2];
	int freq;
} Location2Code;

typedef enum {
	A, B
}ABEnum;

const int encodeDict[10][10] = {
	{ 2, 3, 4, 5, 7, 8, 9, -1 },				// => 0
	{ 2, 3, 4, 6, 7, 8, 9, -1 },				// => 1
	{ 0, 1, 3, 5, 7, 8, -1 },					// => 2
	{ 0, 1, 2, 5, 7, 8, -1 },					// => 3
	{ 0, 1, 5, 6, 9, -1 },						// => 4
	{ 0, 2, 4, 7, 9, -1 },						// => 5
	{ 1, 3, 4, 8, 9, -1 },						// => 6
	{ 0, 2, 3, 5, 8, -1 },						// => 7
	{ 0, 1, 2, 3, 6, 7, -1 },					// => 8
	{ 0, 1, 4, 5, 6, -1 }						// => 9
};


class Location2CodeEncode {
private:
	bool isGenACode;
	bool isGenBCode;
	bool isACodeSaved;
	bool isBCodeSaved;

public:
	vector<Location2Code> aCode;
	vector<Location2Code> bCode;
	vector<Location2Code> tmpCode;

	Location2CodeEncode();

	~Location2CodeEncode();

	/*****************************
	*	生成A码
	*	@author: shallotsh
	*	@since: 1.0
	********************************/
	int generateACode(set<int> numbers);

	/*****************************
	*	生成B码
	*	@author: shallotsh
	*	@since: 1.0
	********************************/
	int generateBCode(set<int> numbers);


	/*****************************
	*	胆杀
	*	@author: shallotsh
	*	@since: 1.0
	********************************/
	int killCode(set<int> boldCode);

	/*****************************
	*	是否生成A码
	*	@author: shallotsh
	*	@since: 1.0
	********************************/
	bool isGenerateACode();

	/*****************************
	*	是否生成B码
	*	@author: shallotsh
	*	@since: 1.0
	********************************/
	bool isGenerateBCode();

	/*****************************
	*	是否保存了A码
	*	@author: shallotsh
	*	@since: 1.0
	********************************/
	bool isSavedACode();

	/*****************************
	*	是否保存了B码
	*	@author: shallotsh
	*	@since: 1.0
	********************************/
	bool isSavedBCode();

	/*****************************
	*	去重
	*	@author: shallotsh
	*	@since: 1.0
	********************************/
	bool removeDuplication(vector<Location2Code> &);


	/*****************************
	*	保存临时编码到目标编码
	*	@author: shallotsh
	*	@since: 1.0
	********************************/
	int save(vector<Location2Code> &, ABEnum);


	/*****************************
	*	排序
	*	@author: shallotsh
	*	@since: 1.0
	********************************/
	void sortByFreq(vector<Location2Code>&);

	/*****************************
	*	清除所有数据
	*	@author: shallotsh
	*	@since: 1.0
	********************************/
	bool clear();

	/*****************************
	*	打印
	*	@author: shallotsh
	*	@since: 1.0
	********************************/
	void print(vector<Location2Code> code);
};