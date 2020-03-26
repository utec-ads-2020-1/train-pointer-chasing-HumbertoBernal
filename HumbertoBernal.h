//
// Created by Humberto Bernal on 3/25/20.
//

#ifndef POINTER_CHASING_TRY1_HUMBERTOBERNAL_H
#define POINTER_CHASING_TRY1_HUMBERTOBERNAL_H
using namespace std;

void chasing(int **A[], int a, int *B[], int b, int C[], int c){
    for (int j = 0; j < a ; ++j) {A[j]= nullptr;}
    for (int j = 0; j < b ; ++j) {B[j]= nullptr;}
    cout << "\nPara finalizar la funcion debes escribir: endtest\n";
    bool checker = false;
    int maxChars = 64, n, m;
    char instruction[maxChars];
    string digit = "hello";

    while(digit !="endtest"){
        getline(cin, digit);
        if (digit == "endtest"){
            break;
        }
        strcpy(instruction, digit.c_str());
        for (int i = 0; i < digit.size() ; ++i) {
            //Revisa que el valor sea A o B
            if (instruction[i]== 32){
                continue;
            }else if (instruction[i] == 65 and instruction[i+4]==66){
                if(i+7 != digit.size()){
                    for (int j = i+8; j < digit.size() ; ++j) {
                        if (instruction[j] == 32){checker = false; j=j+3;}
                        else{checker = true; j = digit.size();}
                    }
                    if (checker){
                        cout <<"\n"<< 0 ;
                        break;
                    }
                }

                n = (int)instruction[i+2] - 48;
                m = (int)instruction[i+6] - 48;
                if ( (n == 0 or n == 1 or n == 2 or n == 3 or n == 4) and (m == 0 or m==1 or m==2 or m==3)){
                    A[n]= &B[m];
                    cout <<"\n"<< 1 ;
                    break;
                } else{
                    cout <<"\n"<< 0 ;
                    break;
                }
            } else if (instruction[i] == 66 and instruction[i+4]==67){
                n = (int)instruction[i+2] - 48;
                m = (int)instruction[i+6] - 48;
                if ( (n == 0 or n == 1 or n == 2 or n == 3) and (m == 0 or m==1 or m==2)){
                    B[n]= &C[m];
                    cout <<"\n"<< 1;
                    break;
                } else{
                    cout <<"\n"<< 0 ;
                    break;
                }
            }else{
                cout <<"\n"<< 0 ;
                break;
            }
        }
    }
}

#endif //POINTER_CHASING_TRY1_HUMBERTOBERNAL_H
