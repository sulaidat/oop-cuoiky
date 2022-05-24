#include "../src/lib/CSVParser.h"
#include <iostream>
#include <cassert>
using namespace std;

int main () {
    vector<string> values;
    string line = "\"Joan \"\"the bone\"\", Anne\",Jet,\"9th, at Terrace plc\",Desert City,CO,00123";
    assert(CSVParser::parseLine(line, values) == CSVParser::ParseError::Success);
    assert(values.size() == 6);
    assert(values[0] == "Joan \"the bone\", Anne");
    assert(values[1] == "Jet");
    assert(values[2] == "9th, at Terrace plc");
    assert(values[3] == "Desert City");
    assert(values[4] == "CO");
    assert(values[5] == "00123");

    string line2 = CSVParser::writeLine(values);
    assert(line2 == line);
    cout << line2 << "\n";

    // string fields[6];
    // assert(CSVParser::parseLineToArgs(line,
    //                                   fields[0],
    //                                   fields[1],
    //                                   fields[2],
    //                                   fields[3],
    //                                   fields[4],
    //                                   fields[5]) == CSVParser::ParseError::Success);
    // assert(fields[0] == "Joan \"the bone\", Anne");
    // assert(fields[1] == "Jet");
    // assert(fields[2] == "9th, at Terrace plc");
    // assert(fields[3] == "Desert City");
    // assert(fields[4] == "CO");
    // assert(fields[5] == "00123");

    // string line3 = CSVParser::writeArgsToLine(fields[0],
    //                                           fields[1],
    //                                           fields[2],
    //                                           fields[3],
    //                                           fields[4],
    //                                           fields[5]);
    // assert(line3 == line);

    // cout << "CSVParser passed\n";
    return 0;
}

