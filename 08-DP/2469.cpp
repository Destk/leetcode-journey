class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        std::vector<double> res{};
        res.push_back(celsius+273.15);
        res.push_back(celsius * 1.8 + 32);
        return res;
    }
};
