#include<iostream>
#include<vector>
#include "adapt_huffman_dsa.cpp"

vector<bool> ahcode(string in)   {
    vector<bool> out,code;
    int k,fact,l = in.length();
    Tree h;
    bool parity;
    for(int i=0; i < l; i++)    {
        k=0;
        if(in[i]<97 || in[i]>122)   
            cout<<"<<The characters in the message goes out of the range>>\n<<The result is meaningless>>"<<endl;
        code = h.search((int)in[i]);
        parity = code.back();
        code.pop_back();
        if(parity)  {
            for(int j=0; j < code.size(); j++)
                out.push_back(code[j]);
        }
        else{
            code.clear();
            code = h.searchnyt();
            for(int j=0; j < code.size(); j++)
                out.push_back(code[j]);
            if(in[i]>117)   {
                k = in[i]-107;
                fact = 8;
            }
            else    {
                k = in[i]-97;
                fact = 16;
            }
            while(fact>0)  {
                parity = k>=fact;
                k = k%fact;
                fact /= 2;
                out.push_back(parity);
            }
        }
        code.clear();
        h.append((int)in[i]);
    }
    return out;
}

int main()  {
    string in;
    cout<<"Enter a string\n";
    cin>>in;
    vector<bool> code = ahcode(in);
    cout<<"Adaptive Huffman Code:\n";
    for(int i=0; i<code.size(); i++)
        cout<<code[i];
    float rate = 100.0*(float)((in.length()*5.0)-code.size())/(5*in.length());
    cout<<endl<<rate<<"% compression w.r.t 5-bit representation"<<endl;
    return 0;
}