#include <iostream>
#include <stack>
using namespace std;

int main() {
    const string L = "({[", R = ")}]"; bool err; stack <char> K; int p; char c; string str; cin >> str;
    for(int i=0; i < str.size(); i++){
        p = L.find(str[i]);
        if(p>=0){
            K.push(str[i]);
        }
        p = R.find(str[i]);
        if(p>=0){
            if(K.empty()){
                err = true;
            }
            else{
                c = K.top(); K.pop();
                if(p!=L.find(c)){
                    err = true;
            }
        if(err){break;}   
        }}}
    if(!err && K.empty()){
        cout <<"True";
    }
    else{
        cout<<"Wrong";
    }
}
//С клавиатуры вводится число n - кол-во строк, затем n-слов, каждая в след. строке. Вывести слова в алфавитном порядке 
// с указанием их количества в словаре. Удалить слово, введенное и снова вывести словарь на экран.