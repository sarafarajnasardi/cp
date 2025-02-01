sort(ans.begin(), ans.end(), [](const string &a, const string &b) {
        return a.length() < b.length();
    });