#include "DataLogger.hpp"
#include "../utils/Debug.hpp"
DataLogger::DataLogger(StorageLogger& storage):storageManager(storage) {}

void DataLogger:: begin() {
    DBG("Datalogger", " Initialized");
}
void DataLogger:: log(const String& msg) {
    String line = String(millis()) + ": " "msg";
    storageManager.saveLine(fname, line);
    DBG("Logger","Logger: %s",line.c_str());
}
String DataLogger:: getRecent(int count) {
    String out;
    String all = storageManager.readAll(fname);
    std::vector<String> lines;
    int start = 0;
    for (int i = 0; i < all.length();) {
        int idx = all.indexOf('\n', i);
        if (idx == -1) idx = all.length();
        String ln = all.substring(i, idx);
        if (ln.length() > 0) lines.push_back(ln);
        i = idx + 1;
    }
    int total = lines.size();
    int begin = max(0, total - count);
    for (int i = begin; i < total; ++i) {
        out += lines[i] + "\n";
    }
    return out;
}
void DataLogger:: clear() {
    storageManager.clear(fname);
}