#include <string.h>

class Validation {
public:

    static bool validateTitle(char* title){
        //Possible length of title = 10
        if(strlen(title) > 10){
            return false;
        }
        //Checking if title consist of no letters
        int noLetterCounter = 0;
        for (int i = 0; title[i] != '\0'; i++) {
            if((title[i] < 'a' || title[i] > 'z' )  &&  (title[i] < 'A' || title[i] > 'Z'))
                noLetterCounter++;
        }

		return !(noLetterCounter > 3);
    }
	
    static bool validateBody(char* body){
        // body length 0-20
        return !(strlen(body) > 20 || strlen(body) == 0);
    }

    //Possible length of password from 4 to 10
    static bool validatePassword(char* password){
        if(strlen(password) < 4 || strlen(password) > 10){
            return false;
        }
        //count digits in password
        int digitCounter = 0;
        for (int i = 0; password[i] != '\0'; i++) {
            if (password[i] >= '0' && password[i] <= '9')
                digitCounter++;
        }
        //no digit included in password
        return !(digitCounter == 0);
    }

};

