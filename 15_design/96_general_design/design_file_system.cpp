#include <string>
#include <unordered_map>
using namespace std;


class FileSystem {
private:
    unordered_map<string, int> paths;
public:
    FileSystem() {
        paths["/"] = 0;
    }
    bool createPath(string path, int value) {
        if (paths.count(path)) return false;
        // Check if the parent path exists
        int pos = path.find_last_of('/');
        string parent = path.substr(0, pos);
        if (!paths.count(parent)) return false;
        paths[path] = value;
        return true;
    }
    int get(string path) {
        if (!paths.count(path)) return -1;
        return paths[path];
    }
};