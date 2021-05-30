#include "util.h"

vector<string> tokenise(string input, char delim) {
    vector<string> tokens;
    string interim;
    stringstream stream(input);

    while(getline(stream, interim, delim)) {
        tokens.push_back(interim);
    }

    return tokens;
}