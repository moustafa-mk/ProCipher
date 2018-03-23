#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void XORcipher(char specialChar, string cipheredHEX, int x);
void XORcipher(char specialChar, string cipheredHEX);

int main(){
    int v,k;
    cout<<"Aloha There!\n";
    while(true){
        cout<<"what do you like to do today \n"<<"1-cipher a message \n"<<"2-decipher a message \n"<<"3-End \n";
        cin>>v;

    if(v == 1){
    cout<< "choose the cipher you want to use \n"<<"1-affine \n2-caesar \n3-Atbash \n4-ROT13 \n5-Baconian \n6-Simple Substitution \n7-polybius square \n8-Morse code \n9-XOR cipher \n10-Rail-Fence cipher \n";
    cin>>k;

    if(k == 1){
        string alpha ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string text;
        int a,b,x = 0;
        cin.ignore();
        cout << "Enter text: ";
        getline(cin,text);
        cout<<"Enter a and b where : aX+b is the general formula to cipher; ";
        cin>>a>>b;
        for(unsigned int i = 0; i < text.size(); i++){
            if(islower(text[i])){
                text[i] = toupper(text[i]);
            }
        }
        for(unsigned int y = 0; y < text.size(); y++){
            for(unsigned int w = 0; w < alpha.size(); w++){
                if(text[y] == alpha[w]){
                    x = (int)(alpha[w] - 'A' );
                    x = (a*x+b)%26;
                    char z = 'A'+x;
                    cout<<z;
                }
            }
        }
    }

    if(k == 2){
        int x=0;
        string text,alpha ="ABCDEFGHIJKLMNOPQRSTUVWXYZ",alpha2="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        cin.ignore();
        cout << "Enter text: ";
        getline(cin,text);
        cout<<"Enter the key: ";
        cin>>x;
        for(unsigned int i = 0; i < text.size(); i++){
            if(islower(text[i])){
                text[i] = toupper(text[i]);
            }
        }
        rotate(alpha.begin(), alpha.end()-x, alpha.end());
        for(unsigned int y = 0; y < text.size(); y++){
            for(unsigned int w = 0; w < alpha.size(); w++){
                if(text[y] == alpha2[w]){
                    cout<<alpha[w];
                }
            }
        }
        cout << endl;
    }

    if(k == 3){
        string alpha ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string rever="ZYXWVUTSRQPONMLKJIHGFEDCBA";
        string text ;
        cin.ignore();
        cout << "Enter text: ";
        getline(cin,text);
        for(unsigned int i = 0; i < text.size(); i++){
            if(islower(text[i])){
                text[i] = toupper(text[i]);
            }
        }
        for(unsigned int y = 0; y < text.size(); y++){
            for(unsigned int w = 0; w < alpha.size(); w++){
                if(text[y] == alpha[w]){
                    cout<<rever[w];
                }
            }
        }
        cout << endl;
    }

    if(k == 4){
        string text, part1="ABCDEFGHIJKLM";
        string part2="NOPQRSTUVWXYZ";
        cin.ignore();
        cout << "Enter text: ";
        getline(cin,text);
        for(unsigned int i = 0; i < text.size(); i++){
            if(islower(text[i])){
                text[i] = toupper(text[i]);
            }
        }

        for(unsigned int y = 0; y < text.size(); y++){
            for(unsigned int w = 0; w < part1.size(); w++){
                if(text[y] == part1[w]){
                        cout<<part2[w];
                }
                if(text[y] == part2[w]){
                    cout<<part1[w];
                }
            }
        }
        cout << endl;
    }

    if(k == 5){
        string alpha ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string text,binary;
        cin.ignore();
        cout << "Enter text: ";
        getline(cin,text);
        for(unsigned int i = 0; i < text.size(); i++){
            if(islower(text[i])){
                text[i] = toupper(text[i]);
            }
        }
        for (unsigned int y=0 ; y<text.size(); y++)
        {
            for (int w=0 ; w<26 ; w++)
            {
                if (text[y]==alpha[w])
                {
                    binary = bitset<5>(w).to_string();
                    for (int k=0 ; k<5 ; k++)
                    {
                        if (binary [k]== '0')
                        {
                            cout<< "a";
                        }
                        else if (binary[k]== '1')
                        {
                        cout<< "b";
                        }
                    }
                }
            }
            cout<< " ";
        }
        cout << endl;
    }

    if(k == 6){
        string text,key;
        int counter;
        char alphaupper [26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        char alphalower [26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        char cipher [26];
        counter = 5;
        memset(cipher, 0, 26);
        cout<< "please enter a key of 5 unique letters: "<<endl;
        cin.ignore();
        getline(cin,key);
        bool isnotkey=true;
        for (int i=0;i<5;i++)
        {
            cipher[i]=key[i];
        }
        for (int i=0;i<26;i++)
        {
            for (int j=0;j<5;j++)
            {
                if (alphalower[i]==key[j])
                {
                    isnotkey=false;
                    break;
                }
            }
            if (isnotkey==true)
            {
                cipher[counter]=alphalower[i];
                counter++;
            }
            isnotkey=true;
        }
        cout<< "please enter the message to cipher: ";
        getline(cin,text);
        for (int i=0;i<26;i++)
        {
            for (int j=0;j<26;j++)
            {
                if (text[i]==alphaupper[j] || text[i]==alphalower[j])
                {
                    text[i]=cipher[j];
                    j=0;
                    break;
                }
            }
        }
        cout<<"the cipher text is: "<<text<<endl;
    }

    if(k == 7){
        int key;
        int arr1 [5][5]=
            {
                { 'A', 'B', 'C', 'D', 'E' },
                { 'F', 'G', 'H', 'I', 'J' },
                { 'K', 'L', 'M', 'N', 'O' },
                { 'P', 'Q', 'R', 'S', 'T' },
                { 'U', 'V', 'X', 'Y', 'Z' }
            };
        int arr2[5][5];
        cout<<"enter the key of 5 integers: ";
        for (int i=0 ; i<5 ; i++)
        {
            cin >>key;
            for (int j=0 ; j<5 ; j++)
            {
                arr2[key-1][j]=arr1[i][j];
            }
        }
        bool is_equal=true;
        string text ;
        cin.ignore();
        cout << "Enter text: ";
        getline(cin,text);
        for(unsigned int i = 0; i < text.size(); i++){
            if(islower(text[i])){
                text[i] = toupper(text[i]);
            }
        }
        for (unsigned int y = 0 ; y< text.size() ; y++)
        {
            for (int w=0 ; w<5 ; w++)
            {
                for (int k=0 ; k<5 ; k++)
                {
                    if (text[y]==arr2[w][k])
                    {
                        cout<<w+1<<k+1;
                    }
                    else if (text[y]== ' ' && is_equal)
                    {
                        cout<< ' ';
                        is_equal = false;
                    }
                }
            }
            is_equal=true;
        }
        cout << endl;
    }

    if(k == 8){
        string alpha[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        string morseAlpha[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
        string text, charInAlpha = "";
        int index = 0;
        cout << "Enter text: ";
        cin.ignore();
        getline(cin,text);
        for(unsigned int i = 0; i < text.size(); i++){
            if(islower(text[i])){
                text[i] = toupper(text[i]);
            }
        }
        for(int r=0; r<text.size(); r++){
            for(int w=0;w<26;w++){
                //cout << morseAlpha[w] << endl;
                charInAlpha = text[r];
                //cout << charInAlpha << endl;
                if(charInAlpha==alpha[w]){
                    cout<<morseAlpha[w]<<" ";
                }
                /*else if (charInAlpha==" "){
                    cout<<"  ";
                }*/
            }
        }
        cout<<endl;
    }

    if(k == 9){
    char specialChar;
        string toBeCiphered, cipheredText, deCiphered, cipheredTextHex, cipheredHEX;
        cout << "Enter the special character: ";
                cin >> specialChar;
                cout << "\nEnter the text to be ciphered: ";
                cin.ignore();
                getline(cin, toBeCiphered);
                XORcipher(specialChar, toBeCiphered);
    }

    if(k == 10){
        string text;
    int key;
    cout<<"enter the text you want to cipher: ";
    cin.ignore();
    getline(cin,text);
    cout<<"enter the key : ";
    cin>>key;

    for(int i=0;i<text.size();i++) {
        if(text[i]==' ' ){
            text.erase(i,1);
        }
        if(text[i+1]==' '){
            text.erase(i+1,1);
        }
    }

    string code[key][text.size()];

    for(int k=0;k<key;k++){
        for(int l=0;l<text.size();l++){
            code[k][l]='.';
            }
        }
    int row=0, col=0, counter=0;
    bool dir_down=true;

    while(true){
        code[row][col]=text[counter];

        counter++;

        if(row == key-1){
            dir_down=false;
        }

        if(row==0){
            dir_down = true;
        }

        if(dir_down == false){
            row--;
            col++;
        }

        else if(dir_down == true){
            row++;
            col++;
        }

        if( counter == text.size())
            break;
    }

        for(int p=0;p<key;p++){
            for(int w=0;w<text.size();w++){
                    if(code[p][w]!=".")
                        cout<<code[p][w];
            }
        }
        cout << endl;
    }

}

    if(v == 2){
    cout<< "choose the cipher you want to use \n"<<"1-affine \n2-caesar \n3-Atbash \n4-ROT13 \n5-Baconian \n6-Simple Substitution \n7-polybius square \n8-Morse code \n9-XOR cipher \n10-Rail-Fence cipher \n";
    cin>>k;

    if(k == 1){
    string alpha ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string text;
    	int c,b,y = 0;
	cin.ignore();
	cout << "Enter text: ";
	getline(cin,text);
	cout<<"Enter c and b where : c(y-b) is the general formula to cipher; ";
	cin>>c>>b;

	for(unsigned int i = 0; i < text.size(); i++){
		if(islower(text[i])){
			text[i] = toupper(text[i]);
		}
	}
	for(unsigned int a = 0; a < text.size(); a++){
		for(unsigned int w = 0; w < alpha.size(); w++){
			if(text[a] == alpha[w]){
				y = (int)(alpha[w] - 'A' );
				y = c*(y-b)%26;
				if(y<0)
                    y=y+26;
				char z = 'A'+y;
                 cout<<z;

			}}}
			cout<<endl;
}

    if(k == 2){
    int x=0;
    string text,alpha ="ABCDEFGHIJKLMNOPQRSTUVWXYZ",alpha2="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cin.ignore();
	cout << "Enter text: ";
	getline(cin,text);
	cout<<"Enter the key: ";
	cin>>x;
    for(unsigned int i = 0; i < text.size(); i++){
		if(islower(text[i])){
			text[i] = toupper(text[i]);
		}
	}
    rotate(alpha.begin(), alpha.begin()+x, alpha.end());

    for(unsigned int y = 0; y < text.size(); y++){
		for(unsigned int w = 0; w < alpha.size(); w++){
			if(text[y] == alpha2[w]){
                  cout<<alpha[w]; }
                  }
			}
    cout<<endl;
}

    if(k == 3){
        string alpha ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string rever="ZYXWVUTSRQPONMLKJIHGFEDCBA";
        string text ;
        cin.ignore();
        cout << "Enter text: ";
        getline(cin,text);
        for(unsigned int i = 0; i < text.size(); i++){
            if(islower(text[i])){
                text[i] = toupper(text[i]);
            }
        }

        for(unsigned int y = 0; y < text.size(); y++){
            for(unsigned int w = 0; w < rever.size(); w++){
                if(text[y] == rever[w]){
                        cout<<alpha[w];
                }
            }
        }
        cout << endl;
    }

    if(k == 4){
        string text, part1="ABCDEFGHIJKLM";
        string part2="NOPQRSTUVWXYZ";
        cin.ignore();
        cout << "Enter text: ";
        getline(cin,text);
        for(unsigned int i = 0; i < text.size(); i++){
            if(islower(text[i])){
                text[i] = toupper(text[i]);
            }
        }

        for(unsigned int y = 0; y < text.size(); y++){
            for(unsigned int w = 0; w < part1.size(); w++){
                if(text[y] == part1[w]){
                    cout<<part2[w];
                }
                if(text[y] == part2[w]){
                    cout<<part1[w];
                }
            }
        }
        cout << endl;
    }

    if(k == 5){
        char lowerCase[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
        string code[27] = {"aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba","aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb","baaaa","baaab","baaba","baabb","babaa","babab","babba","babbb","bbaaa","bbaab","bbaba"};
        string toBeDeciphered;
        string encodedChar = "";
        string decipheredText = "";
        cout << "Enter text to be deciphered: ";
        cin.ignore();
        getline(cin, toBeDeciphered);

        for(int i=0; i<toBeDeciphered.size(); i++){
            if(i == toBeDeciphered.size()-1){
                encodedChar += toBeDeciphered[i];
            }
            if(toBeDeciphered[i] != ' ' && i != toBeDeciphered.size()-1){
                encodedChar += toBeDeciphered[i];
            }
            else{
                for(int j=0; j<27; j++){
                    if(encodedChar == code[j]){
                        decipheredText += lowerCase[j];
                        encodedChar = "";
                        break;
                    }
                }
            }
        }
        cout << decipheredText << endl;
    }

    if(k == 6){
    string text,key;
    int choise;
    int counter;
    char alphaupper [26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char alphalower [26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char cipher [26];
        counter = 5;
        memset(cipher, 0, 26);
        cout<< "please enter a key of 5 unique letters: "<<endl;
        cin.ignore();
            getline(cin,key);
            bool isnotkey=true;
            for (int i=0;i<5;i++)
            {
                cipher[i]=key[i];
            }
            for (int i=0;i<26;i++)
            {
                for (int j=0;j<5;j++)
                {
                    if (alphalower[i]==key[j])
                    {
                        isnotkey=false;
                        break;
                    }
                }
                if (isnotkey==true)
                {
                cipher[counter]=alphalower[i];
                counter++;

                }

                isnotkey=true;
            }
            cout<< "please enter the message to decipher: ";
            getline(cin,text);
            for (int i=0;i<26;i++)
            {
                for (int j=0;j<26;j++)
                {
                    if (text[i]==cipher[j])
                    {
                        text[i]=alphalower[j];
                        j=0;
                        break;
                    }
                }
            }
            cout<<"the decipher text is: "<<text<<endl;
}

    if(k == 7){
            size_t row , col, counter=0;
            int key;
            string character;
        int arr1 [5][5]=
            {
                { 'A', 'B', 'C', 'D', 'E' },
                { 'F', 'G', 'H', 'I', 'J' },
                { 'K', 'L', 'M', 'N', 'O' },
                { 'P', 'Q', 'R', 'S', 'T' },
                { 'U', 'V', 'X', 'Y', 'Z' }
            };
            int arr2[5][5];
            cout<<"enter the key of 5 integers: ";
            for (int i=0 ; i<5 ; i++)
            {
                cin >> key;
                for (int j=0 ; j<5 ; j++)
                {
                    arr2[key-1][j]=arr1[i][j];
                }

            }

            /*for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    cout << arr2[i][j] << endl;
                }
            }*/

            string text;
            cout << "Enter text: ";
            cin.ignore();
            getline(cin,text);
            for(int i=0;i<text.size();i++) {
                if(text[i]==' ' ){
                    text.erase(i,1);
                }
                if(text[i+1]==' '){
                    text.erase(i+1,1);
                }
            }

            for (unsigned int y = 0 ; y < text.size() ; y++)
            {
                if(counter < text.size()){
                    character = text[counter];

                    if(character == " "){
                        counter++;
                        character = text[counter];
                    }
                    //cout << character << endl;
                    row=stoi(character,nullptr,10);
                    //cout << row << endl;
                    counter++;
                    character = text[counter];
                    col=stoi(character,nullptr,10);
                    //cout << col << endl;
                    counter++;

                    cout << (char) arr2[row-1][col-1];
                }

                /*for (int w=0; w<5; w++)
                {
                    for (int k=0; k<5; k++)
                    {
                        if ((row == w && col == k)
                        {
                            cout << (char) arr2[w+1][k+1];
                        }
                    }
                }*/
            }
            cout << endl;
    }

    if(k == 8){
        string alpha[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        string morseAlpha[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
        string text, charInMorse = "";
        int index = 0;
        cout << "Enter text: ";
        cin.ignore();
        getline(cin,text);
        for(int r =0;r<text.size();r++){
        index = r;
        charInMorse = "";
        while(text[index] != ' ' && index < text.size()){
            charInMorse += text[index];
            r = index++;
        }
        //cout << charInMorse << endl;
        for(int w=0;w<26;w++){
            if(charInMorse == morseAlpha[w]){
               cout << alpha[w] << " ";
            }
            /*else if (text[r] == ' '){
                cout<<"  ";
            }*/
        }

	}
	cout<<endl;
    }

    if(k == 9){
        char specialChar;
        string toBeCiphered, cipheredText, deCiphered, cipheredTextHex, cipheredHEX;
        cout << "Enter the special character: ";
                cin >> specialChar;
                cout << "\nEnter HEX number: ";
                cin.ignore();
                getline(cin, cipheredHEX);
                XORcipher(specialChar, cipheredHEX, 3);
    }

    if(k == 10){
    string text,newtext="";
    int key;
    cout<<"enter the text you want to Decipher: ";
    cin.ignore();
    getline(cin,text);
    cout<<"enter the key : ";
    cin>>key;

    for(int i=0;i<text.size();i++) {
        if(text[i]==' ' ){
            text.erase(i,1);
        }
        if(text[i+1]==' '){
            text.erase(i+1,1);
        }
    }

    string code[key][text.size()];

    for(int k=0;k<key;k++){
        for(int l=0;l<text.size();l++){
            code[k][l]='.';
            }
        }


    int y=0, row=0, col=0, counter=0;
    bool dir_down=true;

    /*
    while(true){
        //henaaaa b2a runtimeerror:)))))))))))))))))))))))))))))))))))))))
        code[row][col]=text[counter];
        counter+=2;
        if(row == key-1){
            dir_down=false;
        }

        if(row==0){
            dir_down = true;
        }

        if(dir_down == false){
            row--;
            col++;
        }

        else if(dir_down == true){
            row++;
            col++;
        }

        if( counter >= text.size() && y == 0){
            //row=0;
            //col=0;
            counter=1;
            y++;
        }
        else if(counter >= text.size() && y == 1){
            break;
        }
/*for(int h=0;h<key;h++){
    for(int r=0;r<text.size();r++){
        code[h][r]='.';
        }
    }
        if(y<key){
        break;}}
}
    }
    */

    //Initialize desired track with *
    for (int i=0; i < text.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        code[row][col++] = "'*";

        dir_down ? row++ : row--;
    }

    int charIndex = 0;

    //Fill the 2D array with ciphered text
    for(int i=0; i<key; i++){
        for(int j=0; j<text.length(); j++){
            if(code[i][j] == "'*" && charIndex < text.length()){
                code[i][j] = text[charIndex];
                charIndex++;
            }
        }
    }

    //Read the 2D array to get deciphered text
    row = 0, col = 0;
    for (int i=0; i< text.length(); i++)
    {

        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        if (code[row][col] != "." && code[row][col] != "*"){
            newtext += code[row][col];
            col++;
        }

        dir_down?row++: row--;
    }

    //print the deciphered text
    cout << newtext << endl;
}

}

    if(v == 3){
    return 0;
}

}

}



void XORcipher(char specialChar, string toBeCiphered){
    /*string cipheredText = "";
    //int cipheredTextint;
    string hexOfText = "";
    stringstream stream;
    int specialHex, temp;
    vector <int> textDec;
    char textHexChar[100];
    vector <int> textHex;
    stream << hex << (int) specialChar;
    stream >> hex >> specialHex;
    //cout << specialHex << endl;*/
    cout << "Hex before ciphering: ";

    for(size_t i=0; i<toBeCiphered.size(); i++){
        //cout << (int) toBeCiphered[i] << endl;
        //temp = (int) toBeCiphered[i];
        //cout << "temp= " << temp << endl;
        //textDec.push_back(temp);
        //cout << textHexChar[i] << endl;
        cout << hex << (int) toBeCiphered[i] << " ";
    }

    /*for(int i=0; i<textDec.size(); i++){

        //itoa(textDec[i], textHexChar, 16);
        //cout << textHexChar << endl;
        //textHex.push_back(textHexChar);
        cout << textHex[i];
    }*/
    cout << endl << "Hex after ciphering: ";
    //cout << textHexChar << endl;*/

    for (size_t i=0; i<toBeCiphered.size(); i++){
        /*hexOfText += ((int) (toBeCiphered[i]));
        cipheredText += (specialHex ^ textHexChar[i]);
        cipheredTextint += (specialHex ^ textHexChar[i]);
        cout << textHexChar[i] << endl;
        cout << cipheredText << endl;
        cout << cipheredTextint << endl;
        //cout << hex << (int) hexOfText[i];*/
        cout << hex << (specialChar ^ toBeCiphered[i]);
        cout << " ";
    }
    cout << endl;
    //return cipheredText;
}

void XORcipher(char specialChar, string cipheredHEX, int x){
    vector <long> cipheredHEXarr;
    string character;
    //cout << cipheredHEX.size() << endl;
    for(size_t i=0; i<cipheredHEX.size(); i++){
        if(cipheredHEX[i] != ' '){
            character = cipheredHEX[i];
            if(cipheredHEX[i+1] != ' ' && i != cipheredHEX.size()-1){
                character += cipheredHEX[i+1];
                cipheredHEXarr.push_back(stol(character, nullptr, 16));
                i++;
            }
            else
                cipheredHEXarr.push_back(stol(character, nullptr, 16));
        }
    }
    //cout << cipheredHEXarr.size() << endl;
    for(size_t i=0; i<cipheredHEXarr.size(); i++){
        cout << (char) (specialChar ^ cipheredHEXarr[i]);
    }
    cout << endl;
}
