// create a ds that supports the following functions:

-> insert, delete, find number of x in ds that satisfies x^y<=k


-> decide for each bit in the number moving from the msb to the lsb say
 x = a..........
 y = b..........
 k = c..........

 if(b==0 and c==0) -> a^0<=0 a has to be 0
 else if(b==1 and c==0) -> a^1<=0 a has to be 1
 else if(b==0 and c==1) -> a^0<=1 for a=0 add all and then move to a=1
 else if(b==1 and c==1) -> a^1<=1 for a=1 add all and then move to a=0

 make a count tree for all prefixes


 int query_cnt(int y,int k){
    int ans=0;
    Node* temp=root;

    for(int bit=31;i>=0;i--){

        if(y&(1<<bit)){
            if(k&(1<<bit)){
                ans+=temp->arr[1].cnt;
                temp=temp->arr[0];
            }
            else{
                temp=temp->arr[1];
            }
        }
        else{
            if(k&(1<<bit)){
                ans+=temp->arr[0].cnt;
                temp=temp->arr[1];
            }
            else{
                temp=temp->arr[0];
            }
        }
    }
    ans+=temp->cnt;
    return ans;
 }



 // spelling correction mechanism

 -> find all strings in set that have at most K position mismatch with S 

 vector<string> result;

 void search(Node* temp,int pos,int misMatch){
    if(misMatch>k) return;

    if(pos==s.size()){
        for(auto st:temp->pref){
            result.push_back(st);
        }
        return;
    }

    for(int i=0;i<26;i++){
        if(temp->arr[i]!=NULL){
            search(temp->arr[i],pos+1,misMatch+(i!=s[pos]-'a'));
        }
    }
 }

