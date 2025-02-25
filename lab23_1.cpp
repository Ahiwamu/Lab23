#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename, vector<string> names, vector<int> scores, vector<char> grades){
    ifstream source;
    source.open("name_score.txt");
    string text;


    while(getline(source, text))
    {
        char s[] = "";
        int i = 0;
        while(text[i]){
            s[i] = s[i] + text[i];
            i++;
        }

        char format[] = "%[^:]: %d %d %d";
        char n[100];
        int a, b, c;
        int sum = 0;

        sscanf(s, format, n, &a, &b, &c);
        sum = a + b + c;
        char g = score2grade(sum);
        
        string t;
        int j = 0;
        while(n[j]){
            t[j] = t[j] + n[j];
            j++;
        }

        cout << text << endl;
        names.push_back(t);
        scores.push_back(sum);
        grades.push_back(g);

    }
    
}
/*
void getCommand(){

}

void searchName(){

}

void searchGrade(){

}
*/

int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);

    for(int i = 0; i < names.size(); i++){
        for(int j = 0; j < names[i].size(); j++){
            cout << names[i][j] << " ";
        }
        cout << endl;
    }
    
    /*
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    */
    return 0;
}
