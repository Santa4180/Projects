import time
from plyer import notification

if __name__ == "__main__":
    while True:  # ✅ Fixed capitalization (True instead of true)
        notification.notify(  # ✅ Indented correctly
            title="Hey Pookie, Drink water",
            message="You have been sitting for 60 minutes, please drink some water",
            app_icon="C:\\Users\\dashs\\OneDrive\\Documents\\2241004180\\C++ Projects\\water.ico",
            timeout=2,
        )
        time.sleep(60*60)
