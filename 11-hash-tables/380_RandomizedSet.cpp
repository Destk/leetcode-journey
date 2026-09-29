class RandomizedSet {
    private:
        std::vector<int> data{};
        std::unordered_map<int, int> el_ind{};
    public:
        RandomizedSet() {
            
        }
        
        bool insert(int val) {
            auto it = el_ind.find(val);
            if(it != el_ind.end()) return false;
            data.push_back(val);
            el_ind[val] = data.size()-1;
            return true;
        }
        
        bool remove(int val) {
            auto it = el_ind.find(val);
            if(it == el_ind.end()) return false;
            int ind = el_ind[val];
            int last_el = data.back();
            data[ind] = last_el;
            el_ind[last_el] = ind;
            data.pop_back();
            el_ind.erase(val);
            return true;
        }
        
        int getRandom() {
            if(data.empty()) return -1;
            int x = rand() % data.size();
            return data[x];  
        }
};
