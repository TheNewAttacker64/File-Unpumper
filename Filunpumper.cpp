#include <iostream>
#include <fstream>
#include <vector>

void unpumper(std::string file_path) {
    std::ifstream file(file_path, std::ios::binary | std::ios::ate);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> content(size);
    if (file.read(content.data(), size)) {
        auto last_char = content.back();
        while (last_char == '\x30') {
            content.pop_back();
            last_char = content.back();
        }

        std::ofstream outfile(file_path, std::ios::binary);
        outfile.write(content.data(), content.size());
        std::cout << "[+] Done removing added bytes from " << file_path << std::endl;
    }
    else {
        std::cout << "[-] Error: could not read file " << file_path << std::endl;
    }
}
int main(int argc, char* argv[]) {
    std::cout << R"(
 /$$   /$$                                                                          
| $$  | $$                                                                          
| $$  | $$ /$$$$$$$   /$$$$$$  /$$   /$$ /$$$$$$/$$$$   /$$$$$$   /$$$$$$   /$$$$$$ 
| $$  | $$| $$__  $$ /$$__  $$| $$  | $$| $$_  $$_  $$ /$$__  $$ /$$__  $$ /$$__  $$
| $$  | $$| $$  \ $$| $$  \ $$| $$  | $$| $$ \ $$ \ $$| $$  \ $$| $$$$$$$$| $$  \__/
| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$ | $$ | $$| $$  | $$| $$_____/| $$      
|  $$$$$$/| $$  | $$| $$$$$$$/|  $$$$$$/| $$ | $$ | $$| $$$$$$$/|  $$$$$$$| $$      
 \______/ |__/  |__/| $$____/  \______/ |__/ |__/ |__/| $$____/  \_______/|__/      
                    | $$                              | $$                          
                    | $$                              | $$                          
                    |__/                              |__/                          
By TheAttacker  
github:https://github.com/TheNewAttacker64
)" << std::endl;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }

    std::string file_path = argv[1];
    unpumper(file_path);

    return 0;
}
