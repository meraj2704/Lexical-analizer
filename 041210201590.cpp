#include <bits/stdc++.h>
using namespace std;

string punctuation = "";
string peranthisis = "";
vector<string>keyword;
vector<string>identifier;
vector<string>constant;
vector<string>operatorr;
vector<string>invalid;

//for separator this function
bool isSeparator(char ch)
{
    string value = " ,;:";
    // string pun = "";
    for (int i = 0; i < value.length(); i++)
    {
        if (ch == value[i])
        {
            if (ch != ' ')
                punctuation += ch;

            return true;
        }
    }
    return false;
}

//check peranthisis
bool isPeranthisis(char ch)
{
    string value = "(){}[]";
    for (int i = 0; i < value.length(); i++)
    {
        if (ch == value[i])
        {
            peranthisis += ch;
            return true;
        }
    }
    return false;
}
//check operator
bool isOperator(char ch)
{
    string value = "+-*/<>=";
    for (int i = 0; i < value.length(); i++)
    {
        if (ch == value[i])
        {
            return true;
        }
    }
    return false;
}
//check keyword
bool isKeyword(string s)
{
    string keyword[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typeof", "union", "unsigned", "void", "volatile", "while"};
    for (int i = 0; i < sizeof(keyword) / sizeof(string); i++)
    {
        if (s == keyword[i])
            return true;
    }
    return false;
}
bool isIdentifier(string s)
{
    bool valid = true;
    if (isKeyword(s))
        valid = false;
    if ((s[0] >= '0') && (s[0] <= '9'))
        valid = false;
    if (valid)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z')) || ((s[i] >= '0') && (s[i] <= '9') || (s[i]) == '_'))
                continue;
            else
            {
                valid = false;
                break;
            }
        }
    }
    return valid;
}
//check constant
bool isNumber(string s)
{
    bool valid = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (((s[i] >= '0') && (s[i] <= '9')) || (s[i] == '.'))
            continue;
        else
        {
            valid = false;
            break;
        }
    }
    // cout << s << " " << valid << endl;
    return valid;
}

// parse the string and 
void parse(string s)
{
    vector<string> tokens;
    string token = "";
    string pun = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isSeparator(s[i]))
        {
            if (token != "")
            {
                tokens.push_back(token);
            }
            token = "";
        }
        else if (isPeranthisis(s[i]))
        {
            if (token != "")
            {
                tokens.push_back(token);
            }
            token = "";
        }
        else if (isOperator(s[i]))
        {
            if (token != "")
            {
                tokens.push_back(token);
                token = "";
            }
            else
            {
                token.push_back(s[i]);
                tokens.push_back(token);
                token = "";
            }
        }
        else
        {
            token = token + s[i];
        }
    }
    if (token != "")
    {
        tokens.push_back(token);
        token = "";
    }
    // for(int i=0; i<tokens.size(); i++)
    // cout << tokens[i] << endl;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (isKeyword(tokens[i]))
        {
            // cout << "'" << tokens[i] << "'"
            //      << "is a keyword" << endl;
            keyword.push_back(tokens[i]);
        }
        else if (isIdentifier(tokens[i]))
        {
            // cout << "'" << tokens[i] << "'"
            //      << "is a identifier" << endl;
            identifier.push_back(tokens[i]);
        }
        else if (isNumber(tokens[i]))
        {
            // cout << "'" << tokens[i] << "'"
            //      << "is a constant" << endl;
            // int num = stoi(tokens[i]);
            constant.push_back(tokens[i]);
        }
        else if (isOperator(tokens[i][0]))
         {
        //     cout << "'" << tokens[i] << "'"
        //          << "is a operator" << endl;
            operatorr.push_back(tokens[i]);
        }
        else
        {   
            string flo = tokens[i];
            int a=0;
            // cout << "token i " << tokens[i]<< endl;
            // cout << flo << endl;
            // cout << "enter on it" << endl;
            // cout << flo.length() << endl;
            for(int j=0; j<flo.length(); j++)
            {
                // if(flo[0]=='.')
                // {
                //     a=0;
                    
                // }
                if(flo[j]=='.') a++;
            }
            if(a==1)
            {
                if(isNumber(flo))
                {
                    constant.push_back(flo);
                }
                else{
                    invalid.push_back(flo);
                }
            }
            else invalid.push_back(flo);
        }
    }
    // for(int i=0; i<tokens.size(); i++)
    // {
    //     cout << tokens[i] << endl;
    // }
    
    cout << "Keywords : ";
    if (keyword.size() == 0)
    {
        cout << "NULL" << endl;
    }
    else
    {
        for (int i = 0; i < keyword.size(); i++)
        {
            cout << keyword[i] << " ";
        }
        cout << endl;
    }
    cout << "Identifier : ";
    if (identifier.size() == 0)
    {
        cout << "NULL" << endl;
    }
    else
    {
        for (int i = 0; i < identifier.size(); i++)
        {
            cout << identifier[i] << " ";
        }
        cout << endl;
    }
    cout << "Constant : ";
    if (constant.size() == 0)
    {
        cout << "NULL" << endl;
    }
    else
    {
        for (int i = 0; i < constant.size(); i++)
        {
            cout << constant[i] << " ";
        }
        cout << endl;
    }
    cout << "Operator : ";
    if (operatorr.size() == 0)
    {
        cout << "NULL" << endl;
    }
    else
    {
        for (int i = 0; i < operatorr.size(); i++)
        {
            cout << operatorr[i] << " ";
        }
        cout << endl;
    }
    cout << "punctuation : ";
    if (punctuation == "")
    {
        cout << "NULL" << endl;
    }
    else
    {
        for (int i = 0; i < punctuation.length(); i++)
        {
            cout << punctuation[i] << " ";
        }
        cout << endl;
    }
    cout << "Peranthisis : ";
    if (peranthisis == "")
    {
        cout << "NULL" << endl;
    }
    else
    {
        for (int i = 0; i < peranthisis.length(); i++)
        {
            cout << peranthisis[i] << " ";
        }
        cout << endl;
    }
    cout << "Invalid : ";
    if (invalid.size() == 0)
    {
        cout << "NULL" << endl;
    }
    else
    {
        for (int i = 0; i < invalid.size(); i++)
        {
            cout << invalid[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    
    string s;
    getline(cin,s);
    parse(s);
    return 0;
}