class PrefixTree {
    vector<PrefixTree*> vec;
    bool flag;

public:
    PrefixTree() {
        vec.resize(26,nullptr);
        flag = false;
    }
    
    void insert(string word) {
        PrefixTree* node = this;
        for(char ch:word) {
            if(!node->vec[ch-'a'])
                node->vec[ch-'a'] = new PrefixTree();
            node = node->vec[ch-'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        PrefixTree* node = this;
        for(char ch:word) {
            if(!node->vec[ch-'a'])
                return false;
            node = node->vec[ch-'a'];
        }
        if(node->flag)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* node = this;
        for(char ch:prefix) {
            if(!node->vec[ch-'a'])
                return false;
            node = node->vec[ch-'a'];
        }
        return true;
    }
};
