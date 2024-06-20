class Node {
public:
    vector<Node*> arr;
    bool flag;

public:
    Node(){
        flag=false;
        arr.resize(26,NULL);
    }

};

class Trie {
    Node* root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string& word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->arr[word[i]-'a']==NULL){
                Node* newNode = new Node();
                temp->arr[word[i]-'a'] = newNode;
            }
            temp = temp->arr[word[i]-'a'];
        }
        temp->flag = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->arr[word[i]-'a']!=NULL){
                temp = temp->arr[word[i]-'a'];
            }
            else return false;
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i=0;i<prefix.size();i++){
            if(temp->arr[prefix[i]-'a']!=NULL){
                temp = temp->arr[prefix[i]-'a'];
            }
            else return false;
        }
        return true;
    }

    void erase(string word){
        if(search(word)==false) return;

        Node* temp = root;

        for(int i=0;i<word.size();i++){
            temp = temp->arr[word[i]-'a'];
        }

        temp->flag=false;

    }
};

