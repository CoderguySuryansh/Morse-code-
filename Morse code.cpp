#include <iostream>
#include <map>
#include <sstream>

using namespace std;

// Function to convert a text message to Morse code
string textToMorse(const string& text) {
    const map<char, string> morseCode = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."},
        {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
        {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
        {'8', "---.."}, {'9', "----."},
        {' ', " "}
    };

    stringstream morseStream;
    for (char c : text) {
        char upperC = toupper(c);
        if (morseCode.find(upperC) != morseCode.end()) {
            morseStream << morseCode.at(upperC) << " ";
        }
    }

    return morseStream.str();
}

// Function to convert Morse code to a text message
string morseToText(const string& morse) {
    const map<string, char> textCode = {
        {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},
        {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'},
        {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'},
        {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'},
        {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
        {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'},
        {"-.--", 'Y'}, {"--..", 'Z'},
        {"-----", '0'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'},
        {"....-", '4'}, {".....", '5'}, {"-....", '6'}, {"--...", '7'},
        {"---..", '8'}, {"----.", '9'},
        {" ", ' '}
    };

    stringstream textStream;
    istringstream morseStream(morse);
    string morseChar;

    while (getline(morseStream, morseChar, ' ')) {
        if (textCode.find(morseChar) != textCode.end()) {
            textStream << textCode.at(morseChar);
        }
    }

    return textStream.str();
}

int main() {
    cout << "Morse Code Translator" << endl;

    int choice;
    cout << "Choose an option:" << endl;
    cout << "1. Convert text to Morse code" << endl;
    cout << "2. Convert Morse code to text" << endl;
    cout << "Your choice: ";
    cin >> choice;

    cin.ignore(); // Ignore the newline character left by cin

    if (choice == 1) {
        string text;
        cout << "Enter the text to convert to Morse code: ";
        getline(cin, text);

        string morseCode = textToMorse(text);
        cout << "Morse code: " << morseCode << endl;
    } else if (choice == 2) {
        string morseCode;
        cout << "Enter the Morse code to convert to text: ";
        getline(cin, morseCode);

        string text = morseToText(morseCode);
        cout << "Text: " << text << endl;
    } else {
        cout << "Invalid choice. Please choose option 1 or 2." << endl;
    }

    return 0;
}
