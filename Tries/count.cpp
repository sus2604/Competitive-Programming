class Node {
public:
    vector<Node*> arr;
    int count_full;
    int count_prefix;

public:
    Node(){
        count_full = 0;
        count_prefix = 0;
        arr.resize(26,NULL);
    }

};

class Trie {
    Node* root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->arr[word[i]-'a']==NULL){
                Node* newNode = new Node();
                temp->arr[word[i]-'a'] = newNode;
            }
            temp = temp->arr[word[i]-'a'];
            temp->count_prefix++;
        }
        temp->count_full++;
    }
    
    int countWordsEqualTo(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->arr[word[i]-'a']!=NULL){
                temp = temp->arr[word[i]-'a'];
            }
            else return 0;
        }
        return temp->count_full;
    }
    
    int countWordsStartingWith(string prefix) {
        Node* temp = root;
        for(int i=0;i<prefix.size();i++){
            if(temp->arr[prefix[i]-'a']!=NULL){
                temp = temp->arr[prefix[i]-'a'];
            }
            else return 0;
        }
        return temp->count_prefix;
    }

    void erase(string word) {
        Node* temp = root;

        if(search(word)==false) return;

        for(int i=0;i<word.size();i++){
            temp = temp->arr[word[i]-'a']
            temp->count_prefix--;
        }

        temp->count_full--;
    }
};

