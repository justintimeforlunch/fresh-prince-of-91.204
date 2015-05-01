// Copyright 2015 Justin Nguyen

#include "MarkovModel.hpp"
#include <unordered_map>
#include <string>
#include <vector>
#include <exception>

MarkovModel::MarkovModel(std::string text, int k) {
    _order = k;
    int height = 0;
    int temp = k;
    std::string tmpText = text;
    for (unsigned int i = 0; i < text.size(); ++i) {
        if (_alphabet.count(text.at(i)) == 0) {
            _alphabet.insert(std::make_pair(static_cast<char>(text.at(i)),
                                            static_cast<int>(height)));
            height += 1;
        }
    }
    if (k != 0)
        text = text + text.substr(0, temp - 1);
    int length = 0;
    for (unsigned int i = 0; i < text.size(); ++i) {
        if (_kgrams.count(text.substr(i, temp)) == 0) {
            _kgrams.insert(std::make_pair(text.substr(i, temp),
                                          static_cast<int>(length)));
            length += 1;
        }
    }
    _freq.resize(_kgrams.size());
    for (unsigned int i = 0; i < _kgrams.size(); i++)
         _freq[i] = 0;
    for (unsigned int i = 0; i < tmpText.size(); ++i) {
        if ((_kgrams.count(text.substr(i, temp))) == 0) {
             throw std::runtime_error("kgram did not get loaded before");
        } else {
            _freq[_kgrams.at(text.substr(i,
                 temp))] = _freq[_kgrams.at(text.substr(i, temp))] + 1;
        }
    }
    _fCount.resize(_kgrams.size());
    for (unsigned int i = 0; i < _kgrams.size(); ++i) {
         _fCount[i].resize(_alphabet.size());
         for (unsigned int j = 0; j < _alphabet.size(); ++j) {
            _fCount[i][j] = 0;
        }
    }
    std::string tmpNew;
    if (k == 1) {
        tmpNew = text + text.substr(0, k);
    } else if (k == 0) {
        tmpNew = text;
    } else {
        tmpNew = text + text.substr(k - 1, k - 1);
    }
    std::string blob = "";
    int N, M;
    for (unsigned int i = 0; i < tmpNew.size() - (k); ++i) {
        blob = tmpNew.substr(i, k);
        N = _kgrams.at(blob);
        M = _alphabet.at(*((tmpNew.substr(i + k, 1)).c_str()));
        _fCount[N][M] += 1;
    }
}

MarkovModel::~MarkovModel() {
}

int MarkovModel::order() {
    return _order;
}

int MarkovModel::freq(std::string kgram) {
    int size = kgram.size();
    if (size != order())
        throw std::runtime_error("kgrams is not the same size as order");
    std::unordered_map<std::string, int>::const_iterator j;
    j = _kgrams.find(kgram);
    if (j == _kgrams.end())
        return 0;
    else
        return (_freq[j->second]);
}

int MarkovModel::freq(std::string kgram, char c) {
    int size = kgram.size();
    if (size != order()) {
        throw std::runtime_error("length of kgram must be the size of order");
    }
    std::unordered_map<std::string, int>::const_iterator j;
    j = _kgrams.find(kgram);
    std::unordered_map<char, int>::const_iterator k = _alphabet.find(c);
    if (j == _kgrams.end() || k == _alphabet.end())
        return 0;
    else
        return _fCount[(_kgrams.find(kgram))->second]
    [(_alphabet.find(c))->second];
}

char MarkovModel::randk(std::string kgram) {
    int size = kgram.size();
    if (size != order()) {
        throw std::runtime_error("kgram is not the same size as order");
    } else {
        std::unordered_map<std::string, int>::const_iterator j;
        j = _kgrams.find(kgram);
        if (j == _kgrams.end()) {
            throw std::runtime_error("Error: cannot find kgram.");
        } else {
            auto it = _alphabet.begin();
            std::advance(it, rand() % _alphabet.size());
            while (_fCount[j->second][it->second] == 0)
                std::advance(it, rand() % _alphabet.size());
            return (it->first);
        }
    }
}

std::string MarkovModel::gen(std::string kgram, int T) {
    int size = kgram.size();
    if (size != order()) {
        throw std::runtime_error("kgram is not the same size as order");
    } else {
        std::string result = kgram;
        for (int i = 0; i < T; i++) {
            result = result + (randk(result.substr(i, order())));
        }
        return result;
    }
}
