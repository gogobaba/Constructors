#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Mystring{
private:
    char* buffer;
    int len;
public:
    Mystring(const char* initstring){
        buffer = NULL;
        cout<<"Default constructor invoking"<<endl;
        if(initstring != NULL){
            len = strlen(initstring);
            buffer = new char[len+1];
            memcpy(buffer,initstring,len);
        }
    }
    
    //CopyConstructor
    Mystring(const Mystring& copystring){
        buffer = NULL;
        cout<<"copy constructor invoking"<<endl;
        if(copystring.buffer != NULL){
            buffer = new char[strlen(copystring.buffer)];
            memcpy(buffer,copystring.buffer,strlen(copystring.buffer));
        }
    }
    
    //MoveConstructor
    Mystring(Mystring&& moveSource) { 
        if(moveSource.buffer != NULL) 
        {   cout<<"MoveConstructor invoking"<<endl;
            buffer = moveSource.buffer; } 
        
    }
    
    //operator_overloading
    void operator =(const Mystring& copystring){
          buffer = NULL;
        cout<<"copy constructor invoking"<<endl;
        if(copystring.buffer != NULL){
            buffer = new char[strlen(copystring.buffer)];
            memcpy(buffer,copystring.buffer,strlen(copystring.buffer));
        }
    }
    
    ~Mystring(){
        if(buffer != NULL){
            cout<<"invoking destructor"<<endl;
            delete[] buffer;
        }
    }
    
    int getLength(){
        return strlen(buffer);
    }
    
    const char* getString(){
        return buffer;
    }
};

Mystring copy(Mystring& copy){
    Mystring copyForReturn(copy.getString());
    return copyForReturn;
}

void UseMyString(Mystring copystring){
    cout<<copystring.getString()<<endl;
}

int main()
{
    Mystring sayGoodBye("Bye Bye");
    Mystring sayGoodBye2(copy(sayGoodBye));
   
    return 0;
}

