#include<iostream>
#include<vector>
#include "adapt_huffman_dsa.cpp"

string ahDecode(vector<bool> code)  {
    string m;
    Tree h;
    int data,i=0;
    while(i<code.size())  {
        data = h.traverse(code,i);
        if(data)    {
            m += (char)data;
            h.append(data);
        }
        else    {
            for(int j=0; j<4; j++)  {
                data *= 2;
                if(code[i])
                    data += 1;
                i++;
            }
            if(data<10) {
                data *=2;
                if(code[i])
                    data += 1;
                i++;
            }
            else
                data += 10;
            m += (char)(data+97);
            h.append(data+97);
        }
    }
    return m;
}

int main()  {
    vector<bool> code;
    string in, message;
    cout<<endl<<"Adaptive Huffman Code - Enter the codeword:\n";
    cin>>in;
    for(int i=0;i<in.length();i++)  {
        code.push_back(in[i]=='1');
        if(in[i]!='0' && in[i]!='1')    {
            cout<<"not a valid code"<<endl;
            return 0;
        }
    }
    message = ahDecode(code);
    cout<<endl<<"The message is:\n"<<message<<endl;
    return 0;
}