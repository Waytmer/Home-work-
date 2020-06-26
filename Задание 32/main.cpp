#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

bool IsNumber(char c);
int PrioritetMatematicalSymbols(char c);
string InfNotationConvertToPolNotation(string InfNotation);
double AccountPolNotation(string PolNotation);

int main()
{

    string InfNotation;
    stack <char> num;
	cout<<"Input InfNotation for convert to PolNotation\nInfNotation:";
   getline(cin,InfNotation);


    cout <<"PolNotation:"<< InfNotationConvertToPolNotation(InfNotation) << endl;

    cout <<"Account PolNotation = " <<AccountPolNotation(InfNotationConvertToPolNotation(InfNotation)) << endl;

    system("pause");
    return 1;
}

bool IsNumber(char c) {
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
        return 1;
    }
    else{
      return 0;
    }
}

int PrioritetMatematicalSymbols(char c) {
    switch (c) {
    case '^':
        return 3;
        break;
    case '/':
        return 2;
        break;
    case '*':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '(':
        return 0;
        break;
    case ')':
        return 0;
        break;
    default:
        return -1;
        break;
    }
}

string InfNotationConvertToPolNotation(string InfNotation) {
    char c = ' ';
    int i = 0;
    string PolNotation;
    stack <char> sign;
    while (i < InfNotation.size()) {
        c = InfNotation[i];
        i++;
        if (c == ' ') {
            if (PolNotation[PolNotation.size() - 1] != ' ') {
                PolNotation.push_back(c);

            }

        }
        else if (c == '-' && (i - 1) < (InfNotation.size()) - 1 && IsNumber(InfNotation[i])) {
            PolNotation.push_back(c);

        }
        else if (IsNumber(c) || c == '.') {
            PolNotation.push_back(c);

        }
        else if (c == '(') {
            sign.push(c);

        }
        else if (c == ')') {
            while (sign.top() != '(') {
                PolNotation.push_back(sign.top());
                sign.pop();
            }
            sign.pop();

        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (true) {
                if (!sign.empty()) {
                    if (PrioritetMatematicalSymbols(sign.top()) > PrioritetMatematicalSymbols(c)) {
                        if (InfNotation[i - 1] != ' ') PolNotation.push_back(' ');
                        PolNotation.push_back(sign.top());
                        sign.pop();
                        continue;

                    }
                   else if (c == '^' && sign.top() == '^') {
                        break;
                    }
                    else if (PrioritetMatematicalSymbols(sign.top()) == PrioritetMatematicalSymbols(c)) {
                        PolNotation.push_back(sign.top());
                        sign.pop();
                        continue;
                    }

                }
                break;
            }
            sign.push(c);
            continue;
        }
    }
    while (!sign.empty()) {
        if (PolNotation[PolNotation.size() - 1] != ' ') {
            PolNotation.push_back(' ');
        }
        PolNotation.push_back(sign.top());
        sign.pop();
    }
    if (PolNotation[PolNotation.size() - 1] != ' ') {
        PolNotation.push_back(' ');
    }
    return PolNotation;
}

double AccountPolNotation(string PolNotation) {

    string num = "";
    num.clear();
    stack<double> temp;
    double value=0;

    for(int i=0;i < PolNotation.size();i++) {

        if (IsNumber(PolNotation[i]) || PolNotation[i] == '.') {
            num += PolNotation[i];
        }
        if (PolNotation[i] == '-' && IsNumber(PolNotation[i + 1])) {
            num += PolNotation[i];
            i++;
            continue;
        }
        if (PolNotation[i] == ' ' && IsNumber(PolNotation[i - 1])) {
            temp.push(stod(num));
            num = "";
        }
        switch (PolNotation[i]) {
        case '+':
            value = temp.top();
            temp.pop();

            value = temp.top() + value;;
            temp.pop();
            temp.push(value);
            break;
        case '-':
            value = temp.top();
            temp.pop();

            value = temp.top() - value;
            temp.pop();
            temp.push(value);
            break;
        case '*':
            value = temp.top();

            temp.pop();
            value = temp.top() * value;
            temp.pop();
            temp.push(value);
            break;
        case '/':
            value = temp.top();
            temp.pop();
            value = temp.top() / value;
            temp.pop();
            temp.push(value);
            break;
        case '^':
            value = temp.top();
            temp.pop();

            value = pow(temp.top(), value);
            temp.pop();
            temp.push(value);
            break;
        }

    }

    return temp.top();
}

