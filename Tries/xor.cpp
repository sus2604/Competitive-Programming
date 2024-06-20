class Node {
public:
    vector<Node*> arr;
    bool flag;
    int value;

    Node(){
        arr.resize(2,NULL);
        flag=false;
    }
};

Node* root = new Node();

void insert(int num){
    Node* temp = root;
    for(int bit=31;bit>=0;bit--){
        int bitVal = (num&(1<<bit))?1:0;
        if(temp->arr[bitVal]==NULL){
            Node* newNode = new Node();
            temp->arr[bitVal]=newNode;
        }
        temp=temp->arr[bitVal];
    }
    temp->flag=true;
    temp->value=num;
}

int findMinXOR(int num){
    Node* temp = root;
    for(int bit=31;bit>=0;bit--){
        int bitVal = (num&(1<<bit))?1:0;
        if(temp->arr[bitVal]!=NULL){
            temp = temp->arr[bitVal];
        }
        else if(temp->arr[!bitVal]!=NULL){
            temp = temp->arr[!bitVal];
        }
        else return INT_MAX;
    }
    return num^temp->value;
}

int findMaxXOR(int num){
    Node* temp = root;
    for(int bit=31;bit>=0;bit--){
        int bitVal = (num&(1<<bit))?1:0;
    
        if(temp->arr[!bitVal]!=NULL){
            temp=temp->arr[!bitVal];
        }
        else if(temp->arr[bitVal]!=NULL){
            temp=temp->arr[bitVal];
        }
        else return INT_MIN;
    }
    return num^temp->value;
}

int minXOR(vector<int> nums,int n){
    int min_ans = nums[0]^nums[1];

    insert(nums[0]);

    for(int i=1;i<n;i++){
        min_ans = min(min_ans,findMinXOR(nums[i]));
        insert(nums[i]);
    }
    return min_ans;
}