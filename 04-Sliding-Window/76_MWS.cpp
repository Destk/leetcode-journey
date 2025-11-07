std::string minWindow(std::string s, std::string t) {
    if (t.empty() || s.empty()) return "";
    
    std::unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    
    int need_count = need.size(); // количество уникальных символов в t
    int have = 0; // сколько уникальных символов уже в нужном количестве
    
    int left = 0, right = 0;
    int min_len = INT_MAX;
    int start_pos = 0;
    
    while (right < s.length()) {
        // Добавляем символ справа
        char c = s[right];
        window[c]++;
        
        // Проверяем, достигли ли нужного количества для этого символа
        if (need.count(c) && window[c] == need[c]) {
            have++;
        }
        
        // Пытаемся сузить окно слева, пока условие выполняется
        while (have == need_count) {
            // Обновляем результат
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                start_pos = left;
            }
            
            // Убираем символ слева
            char left_char = s[left];
            window[left_char]--;
            if (need.count(left_char) && window[left_char] < need[left_char]) {
                have--;
            }
            left++;
        }
        
        right++;
    }
    
    return min_len == INT_MAX ? "" : s.substr(start_pos, min_len);
}