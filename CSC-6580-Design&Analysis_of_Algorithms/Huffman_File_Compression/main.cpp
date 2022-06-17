#include <iostream>
#include <fstream>
#include <string>
#include <stdc++.h>

using namespace std;

map<char, string> huffmanCodes;
  
map<string, char> decodes;

map<char, int> frequency;
  
struct Node
{
    char byte;
    int frequency;
    Node *left, *right;
  
    Node(char b, int f)
    {
        left = right = NULL;
        this->byte = b;
        this->frequency = f;
    }
};
  
struct compare
{
    bool operator()(Node* l, Node* r)
    {
        return (l->frequency > r->frequency);
    }
};

priority_queue<Node*, vector<Node*>, compare> heap;

void stringToCharArray(string s, char arr[])
{
    for (int i = 0; i < s.length(); i++)
    {
        arr[i] = s[i];
    }
}

void storeCodes(struct Node* root, string str)
{
    if (root==NULL)
    {
        return;
    }
    
    if (root->byte != '$')
    {
        huffmanCodes[root->byte] = str;
    }
    
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}
  
void huffmanTree(int size)
{
    struct Node *l, *r, *t;
    
    for (map<char, int>::iterator v=frequency.begin(); v!=frequency.end(); v++)
    {
        heap.push(new Node(v->first, v->second));
    }
    
    while (heap.size() != 1)
    {
        l = heap.top();
        heap.pop();
        
        r = heap.top();
        heap.pop();
        
        t = new Node('$', l->frequency + r->frequency);
        t->left = l;
        t->right = r;
        
        heap.push(t);
    }
    
    storeCodes(heap.top(), "");
}
  
int calcFrequency(string fileName)
{
    char ch;
    int length = 0;
    char file[fileName.length()];
    stringToCharArray(fileName, file);
    
    FILE* filep = fopen(file, "rb");
    while ((ch = fgetc(filep)) != EOF)
    {
        length++;
        frequency[ch]++;
    }
    
    fclose(filep);
    
    cout<<"Inputted File Size "<<length<<endl;
    return length;
}

void decodeFile(struct Node* root, string encodedFileName, string outputFileName)
{
    string buff;
    char ch;
    int size = 0;
    ofstream out(outputFileName);
    
    struct Node* curr = root;
    
    FILE* filep = fopen(encodedFileName.c_str(), "rb");
    fseek(filep, 0L, SEEK_END);
    int fileSize = ftell(filep);
    rewind(filep);
    int offset = fgetc(filep) - '0';
    for (int i = 0; i < fileSize-1; i++)
    {
        ch = fgetc(filep);

        buff = bitset<8>(ch).to_string();
        
        if(i == fileSize-2 && offset > 0)
        {
            buff = buff.substr(buff.length()-offset,buff.length());
            
            for (int i = 0; i < buff.length(); i++)
            {
                if (buff[i] == '0')
                   curr = curr->left;
                else
                   curr = curr->right;

                if (curr->left==NULL and curr->right==NULL)
                {
                    size++;
                    out << curr->byte;
                    curr = root;
                }
            }
        }
        else
        {
            for (int i = 0; i < buff.length(); i++)
            {
                if (buff[i] == '0')
                   curr = curr->left;
                else
                   curr = curr->right;

                if (curr->left==NULL and curr->right==NULL)
                {
                    size++;
                    out << curr->byte;
                    curr = root;
                }
            }
        }
    }
    
    string temp = "";
    
    out.close();
    cout<<"Decoded File Size "<<size<<endl;
}

void encodeFile(string fileName, string encodeFileName)
{
    string encodeBuff = "";
    char ch;
    int length = 0;
    FILE* filep = fopen(fileName.c_str(), "rb");
    ofstream out(encodeFileName);
    fseek(filep, 0L, SEEK_END);
    int fileSize = ftell(filep);
    rewind(filep);
    
    for (int i = 0; i < fileSize; i++)
    {
        ch = fgetc(filep);
        length+=huffmanCodes[ch].length();
    }
    
    out<<length%8;
    
    rewind(filep);
    
    for (int i = 0; i < fileSize; i++)
    {
        ch = fgetc(filep);
        encodeBuff += huffmanCodes[ch];
        
        if(encodeBuff.length() >= 8)
        {
            out<<static_cast<uint_fast8_t>(bitset<8>(encodeBuff.substr(0,8)).to_ulong());
            encodeBuff = encodeBuff.substr(8,encodeBuff.length());
        }
    }
    
    fclose(filep);
    
    if(encodeBuff.length() > 0)
    {
        out<<static_cast<uint_fast8_t>(bitset<8>(encodeBuff).to_ulong());
    }
    
    out.close();
}

void printFrequency()
{
    string fileName = "";
    
    cout<<"Enter the file name you would like to compress: ";
    cin >> fileName;
    
    int length = calcFrequency(fileName);
    huffmanTree(length);
    
    for (auto v = frequency.begin(); v != frequency.end(); v++)
    {
        cout<<v->first<<": "<< v->second<<endl;
    }
}

void encode()
{
    cin.clear();
    string orgFile = "";
    string encodedFile = "";
    
    cout<<"Enter the original file name: ";
    cin >> orgFile;
    
    int length = calcFrequency(orgFile);
    huffmanTree(length);
    
    cout<<"Enter the name of the encoded ouput file: ";
    cin >> encodedFile;
    
    encodeFile(orgFile, encodedFile);
    
    cout<<"File Encoded! See results in "<<encodedFile<<endl;
}

void decode()
{
    cin.clear();
    string orgFile = "";
    string encodedFile = "";
    string decodedFile = "";
    
    cout<<"Enter the original file name: ";
    cin >> orgFile;
    
    int length = calcFrequency(orgFile);
    huffmanTree(length);
    
    cout<<"Enter the name of the encoded file: ";
    cin >> encodedFile;
    
    cout<<"Enter the name of the decode ouput file: ";
    cin >> decodedFile;
    
    decodeFile(heap.top(), encodedFile, decodedFile);
    
    cout<<"File Decoded! See results in "<<decodedFile<<endl;
}

void encode_decode()
{
    cin.clear();
    string inputFile = "";
    string decodeOutputFile = "";
    string encodeOutputFile = "";
    
    cout<<"Enter the file name you would like to compress: ";
    cin >> inputFile;
    
    int length = calcFrequency(inputFile);
    huffmanTree(length);
    
    cout<<"Enter the name of the encoded output file: ";
    cin >> encodeOutputFile;
    
    encodeFile(inputFile, encodeOutputFile);
    
    cout<<"File Encoded!"<<endl;
    
    cout<<"Enter the name of the decoded output file: ";
    cin >> decodeOutputFile;
    
    decodeFile(heap.top(), encodeOutputFile, decodeOutputFile);
    
    cout<<"File Decoded!"<<endl;
    
}

void testing()
{
    cin.clear();
    string stop = "";
    string inputFile = "testData.txt";
    string decodeOutputFile = "testData2.txt";
    string encodeOutputFile = "testData.huf";
    
    int length = calcFrequency(inputFile);
    huffmanTree(length);
    
    encodeFile(inputFile, encodeOutputFile);
    
    cout<<"File Encoded!"<<endl;
    
    decodeFile(heap.top(), encodeOutputFile, decodeOutputFile);
    
    cout<<"File Decoded!"<<endl;
}
  
int main()
{
    int user_choice = 0;
    cout<<"Please enter option 1-4\n1. Encode a File\n2. Decode a File\n3. Encode and Decode a File\n4. Print Frequency Table For File"<<endl;
    cin >> user_choice;
    
    switch (user_choice)
    {
        case 1:
            encode();
            break;
        case 2:
            decode();
            break;
        case 3:
            encode_decode();
            break;
        case 4:
            printFrequency();
            break;
        case 5:
            testing();
        default: cout<<"Not a valid Entry"<<endl;
            break;
    }

    return 0;
}
