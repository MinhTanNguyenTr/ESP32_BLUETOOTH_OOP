#include "StorageLogger.hpp"
#include "../utils/Debug.hpp"
void StorageLogger:: begin() {
    DBG("Storage", "Initialzie");
}
void StorageLogger:: saveLine(const String& filename, const String& line) {
    storage[filename].push_back(line);
    DBG("Storage","Save to: %s : %s", filename.c_str(), line.c_str());
}
String StorageLogger:: readAll(const String& filename){
    String out;
    if(storage.count(filename) == 0) return out;
    for(auto const& ln : storage[filename])
    {
        out +=ln+ "\n";
    }
    return out;
}
void StorageLogger:: clear(const String& filename){
    storage[filename].clear();
    DBG("Storage","Clear: %s ", filename.c_str());
}