import os  
import time  

def mute_spotify_ads():
    while True:
        # Detect ad via process (this might need tweaking)
        ads = os.popen('tasklist /fi "imagename eq Spotify.exe"').read()
        if "Ad" in ads:
            os.system("nircmd.exe mutesysvolume 1")  # Mute ads
        time.sleep(5)  # Check every few seconds

mute_spotify_ads()