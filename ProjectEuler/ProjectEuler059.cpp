#include <iostream>
#include <fstream>

using namespace std;

/*
Each character on a computer is assigned a unique code and the preferred
standard is ASCII (American Standard Code for Information Interchange).
For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII,
then XOR each byte with a given value, taken from a secret key.
The advantage with the XOR function is that using the same encryption key on the cipher text,
restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message,
and the key is made up of random bytes. The user would keep the encrypted message
and the encryption key in different locations, and without both "halves",
it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users,
so the modified method is to use a password as a key.
If the password is shorter than the message, which is likely,
the key is repeated cyclically throughout the message.
The balance for this method is using a sufficiently long password key for security,
but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters.
Using 0059_cipher.txt, a file containing the encrypted ASCII codes,
and the knowledge that the plain text must contain common English words,
decrypt the message and find the sum of the ASCII values in the original text.

Answer: 129448 (43.354ms)

Tags: XOR
*/

/*
Common English words:
the, is, of, a, an, and

More generally, the original text is composed mainly of alpha-numerical characters.
ASCII printable characters start from the code 32, so code below would indicate that the key is incorrect.

If I can decrypt these words in the text, it should be the original text.
*/

void ProjectEuler059(){
    ifstream cipherFile;
    string line;

    cipherFile.open("../Resources/0059_cipher.txt");
    if (cipherFile.is_open()){
        std::getline (cipherFile,line);
    }
    cipherFile.close();

    // Convert ASCII code text to char and remove ','
    string encodedMessage = "";
    unsigned char character = '\0';
    for(auto it = line.begin(); it != line.end(); it++){
        if(',' == *it){
            encodedMessage.push_back(character);
            character = '\0';
        } else {
            if(character > '\0'){
                character *= 10;
            }

            character += *it - '0';
        }
    }

    // push last character
    encodedMessage.push_back(character);
    character = '\0';


    for(unsigned char first = 'a'; first <= 'z'; first++){
        if((encodedMessage[0] ^ first) < 32){
            continue;
        }

        for(unsigned char second = 'a'; second <= 'z'; second++){
            if((encodedMessage[1] ^ second) < 32){
                continue;
            }

            for(unsigned char third = 'a'; third <= 'z'; third++){
                if((encodedMessage[2] ^ third) < 32){
                    continue;
                }

                string decipheredMessage = "";
                unsigned sum = 0;
                unsigned char keyIndex = 0;
                for(auto it = encodedMessage.begin(); it != encodedMessage.end(); it++){
                    switch(keyIndex){
                        case 0: character = *it ^ first; break;
                        case 1: character = *it ^ second; break;
                        case 2: character = *it ^ third; break;
                    }

                    sum += character;
                    decipheredMessage.push_back(character);
                    keyIndex = (keyIndex + 1)%3;
                }

                if (decipheredMessage.find(" the ") != string::npos
                    && decipheredMessage.find(" is ") != string::npos // turns out 'is' is not necessary to find the solution
                ){
                    cout << decipheredMessage << "\n\n";
                    cout << sum << "\n";
                    return;
                }
            }
        }
    }
}
