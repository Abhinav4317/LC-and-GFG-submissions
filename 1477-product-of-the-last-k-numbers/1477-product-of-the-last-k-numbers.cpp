class ProductOfNumbers {
public:
    vector<double> pnz;       
    vector<int> zcount;       
    int size;

    ProductOfNumbers() {
        size = 0;
    }

    void add(int num) {
        size++;
        double log_val = (num > 0) ? log(num) : 0; 

        if (pnz.empty()) 
            pnz.push_back(log_val);
        else 
            pnz.push_back(pnz.back() + log_val); 

        if (num == 0) {
            if (zcount.empty()) 
                zcount.push_back(1);
            else 
                zcount.push_back(zcount.back() + 1);
        } else {
            if (zcount.empty()) 
                zcount.push_back(0);
            else 
                zcount.push_back(zcount.back());
        }
    }

    int getProduct(int k) {
        int ind = size - k - 1;
        int sub = (ind >= 0) ? zcount[ind] : 0;
        int zc = zcount[size - 1] - sub;

        if (zc > 0) return 0;

        double log_product = pnz[size - 1] - (ind >= 0 ? pnz[ind] : 0); 
        return (int)round(exp(log_product)); 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
