#include <iostream>
#include <cstdlib>
#include <windows.h>

void mute_spotify_ads() {
    while (true) {
        
        std::string result = "";
        char buffer[128];
        FILE* pipe = _popen("tasklist /fi \"imagename eq Spotify.exe\"", "r");
        if (!pipe) {
            std::cerr << "Pip açılırken hata oluştu!" << std::endl;
            return;
        }

        
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result += buffer;
        }
        _pclose(pipe);

       
        if (result.find("Ad") != std::string::npos) {
            system("nircmd.exe mutesysvolume 1"); 
        }

        
        Sleep(5000);
    }
}

int main() {
    mute_spotify_ads();
    return 0;
}
