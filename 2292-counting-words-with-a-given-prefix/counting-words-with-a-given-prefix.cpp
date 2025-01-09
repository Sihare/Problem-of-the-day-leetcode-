class Solution {
public:
//Written by Nikhil Sihare
    struct trie{
        int count;
        trie*children[26];
    }; 
    trie* node(){
        trie*root=new trie();
        root->count=0;
        for(int i=0;i<26;i++){
            root->children[i]=NULL;
        }
        return root;
    }
    void insert(trie*root,string&word){
        trie*pointer=root;
        for(auto ch:word){
            int ind=ch-'a';
            if(pointer->children[ind]==NULL){
                pointer->children[ind]= node();

            }
            pointer=pointer->children[ind];
            pointer->count++;
        }
    }
    int solve(string &word,trie*root){
        trie*pointer=root;
         for(auto ch:word){
            int ind=ch-'a';
            if(pointer->children[ind]==NULL){
               return 0;

            }
            pointer=pointer->children[ind];
             
        }
        return pointer->count;
    }
    int prefixCount(vector<string>& words, string pref) {
        trie*root=node();
        for (auto&word:words){
            insert(root,word);
        }
        return solve(pref,root);
    }
};