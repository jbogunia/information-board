#include <string>

using namespace std;

class Explore{
    string text, title;

public:
    Explore(string titleNew, string textNew){
        title = titleNew;
        text = textNew;
    }

    string getTitle();
    string getText();

};

string Explore::getTitle() {
    return title;
};

string Explore::getText() {
    return text;
}