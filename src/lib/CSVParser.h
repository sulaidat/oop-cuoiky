#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <sstream>
#include <string>
#include <vector>
using namespace std;

namespace CSVParser {

    const char COMMA = ',';
    const char QUOTE = '"';

    enum ParseError {
        Success,
        ImproperQuote,
        UnpairedQuote,          // only accept paired quote ("") in Quote State
        UnclosedQuote,
        InsufficientColumns,
    };

    enum ParseState {
        Initial,
        Data,
        Quote, 
        QuoteInQuote
    };

    ParseError parseLine(const string &line, vector<string> &values);
    string writeLine(const vector<string> &values);

}

#endif
