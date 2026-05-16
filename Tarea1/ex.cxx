include <vector>  // Para poder usar std::vector
double mean(const std::vector<double>& data) {
    if (data.empty()) return 0.0;
    
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    
    return sum / data.size();
}
double variance(const std::vector<double>& data) {
    if (data.size() <= 1) return 0.0;
    
    double m = mean(data);
    double sum_sq_diff = 0.0;
    
    for (double value : data) {
        double diff = value - m;
        sum_sq_diff += (diff * diff);
    }
    
    return sum_sq_diff / (data.size() - 1);
}